//
//  MySocket.cpp
//  quickcocos2dx
//
//  Created by mac on 13-12-5.
//  Copyright (c) 2013年 qeeplay.com. All rights reserved.
//

#include "MySocket.h"
#include "MsgManager.h"

#define HEAD_LEN  18
#define MSGID_POS 3
#define BLEN_POS 9


//socket 管理器状态 0:可连接  1:连接中   2:连接成功  3:超时   4:发送失败  5:接收失败  6:阻塞
#define SOCKET_ENABLE   0
#define SOCKET_LINKING  1
#define SOCKET_SUCCESS  2
#define SOCKET_TIMEOUT  3
#define SOCKET_SEND_FAILED   4
#define SOCKET_RECV_FAILED   5


//超时时间 
#define TIMEOUT_TIME 60*30//5*30





MySocket::MySocket()
{
    m_MagaerPThread = NULL;
    mSocketStatus = SOCKET_ENABLE;
    recvBuff = NULL;
    mLinkData = NULL;

}

MySocket::~MySocket()
{
    
}
static MySocket* m_pInstance;


MySocket* MySocket::getInstance()
{
    if ( m_pInstance == NULL ){
        m_pInstance = new MySocket();
    }
    return m_pInstance;
}



void* startMagagerThread(void* arg)
{
    MySocket* mysocket = (MySocket*)arg;
    
    while (mysocket->isManagerThreadRun)
    {
        if (mysocket->mLinkData!=NULL && mysocket->mLinkData->size() > 0 && !mysocket->sendMsg)
        {
 
            if (mysocket->mSocketStatus == SOCKET_ENABLE)
            {
                pthread_mutex_lock(&mysocket->dataLock);
                int flag = mysocket->m_Socket.Send((char*)mysocket->mLinkData->at(0)->sendBuff, mysocket->mLinkData->at(0)->sendLen,0);
                printf("MySocket send buffer msgid = %d, length=%d, flag = %d \n",readInt(mysocket->mLinkData->at(0)->sendBuff,MSGID_POS),mysocket->mLinkData->at(0)->sendLen,flag);
                if (mysocket->mLinkData->at(0)->cbMsgId == 0) {
                    mysocket->cleanDataAt(0);
                    mysocket->mSocketStatus = SOCKET_ENABLE;
                }
                else
                {
                    if (flag==-1)
                        mysocket->callback(SOCKET_SEND_FAILED,mysocket->mLinkData->at(0)->cbMsgId, 0);
                    else{
                        mysocket->mSocketStatus = SOCKET_LINKING;
                    }
                }
                pthread_mutex_unlock(&mysocket->dataLock);
            }
            else if (mysocket->mSocketStatus == SOCKET_LINKING)
            {
                if (mysocket->mTimeOutCount>TIMEOUT_TIME)
                {
                    pthread_mutex_lock(&mysocket->dataLock);
                    //处理超时
                    printf("MySocket time out!!! id = %d\n",mysocket->mLinkData->at(0)->cbMsgId);
                    mysocket->callback(SOCKET_TIMEOUT, mysocket->mLinkData->at(0)->cbMsgId,0);
                    mysocket->mTimeOutCount = 0;
                    pthread_mutex_unlock(&mysocket->dataLock);
                }
                else
                {
//                    printf("mysocket->mTimeOutCount=%d\n",mysocket->mTimeOutCount);
                    mysocket->mTimeOutCount++;
                }
            }
        }
        usleep(200*1000);
    }
    return NULL;
}


void MySocket::cleanDataAt(int index)
{
    if (mLinkData->size()>0)
    {
        vector<SocketData*>::iterator iter = mLinkData->begin()+index;
        if (mLinkData->at(index)->sendBuff != NULL)
        {
            free(mLinkData->at(index)->sendBuff);
            mLinkData->at(index)->sendBuff = NULL;
        }
        mLinkData->erase(iter);
    }
    printf("MySocket clean curSize = %zd \n",mLinkData->size());
}

void* startMsgThread(void* arg)
{
    MySocket* mysocket = (MySocket*)arg;
    while (mysocket->isMsgThreadRun) {
        if (mysocket->sendMsg)
        {
            pthread_mutex_lock(&mysocket->dataLock);
            CCScriptEngineManager::sharedManager()->getScriptEngine()->executeString("require'LNetManager':ParseMessagers()") ;
            printf("Send Notify Msg!!!\n");
            usleep(500*1000);
            mysocket->sendMsg = false;
            pthread_mutex_unlock(&mysocket->dataLock);
        }
        usleep(200*1000);
    }
    return NULL;
}

int MySocket::createMsgPThread()
{
    int errCode = 0;
    isMsgThreadRun = true;
    sendMsg = false;
    mTimeOutCount = 0;
    do{
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        CC_BREAK_IF(errCode!=0);
        //但是上面这个函数其他内容则主要为你创建的线程设定为分离式
        errCode = pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);

        if (errCode!=0) {
            pthread_attr_destroy(&tAttr);
            break;
        }
        errCode = pthread_create(&m_MsgPThread,&tAttr,startMsgThread,this);
    }while (0);
    
    return errCode;
}


void MySocket::callback(int resultCode,int msgId,int length)
{
    cleanDataAt(0);
    printf("MySocket callback resultCode = %d, msgId = %d, length = %d \n",resultCode,msgId,length);
    memset(MsgManager::getInstance()->recvbuffer, 0, sizeof(MsgManager::getInstance()->recvbuffer));
    if (resultCode == SOCKET_SUCCESS)
    {
        MsgManager::getInstance()->isSuccess = true;
        memcpy(MsgManager::getInstance()->recvbuffer, recvBuff, length);
    }
    else
    {
        writeInt(MsgManager::getInstance()->recvbuffer,MSGID_POS,msgId);
        MsgManager::getInstance()->isSuccess = false;
    }
    
    sendMsg = true;
    
    if (recvBuff!=NULL)
    {
        free(recvBuff);
        recvBuff=NULL;
    }
    mTimeOutCount = 0;
    mSocketStatus = SOCKET_ENABLE;
}





void* startRecvThread(void* arg)
{
    MySocket* mysocket = (MySocket*)arg;
    while (mysocket->isRecvThreadRun)
    {
        if (mysocket->recvBuff==NULL && !mysocket->sendMsg) {
            unsigned char head[HEAD_LEN];
            int headLen = mysocket->m_Socket.RecvS(head, HEAD_LEN , 0);
            if (HEAD_LEN == headLen)
            {
                int msgLen = readInt(head, BLEN_POS);
                int msgId = readInt(head, MSGID_POS);
                
                mysocket->recvBuff = new unsigned char[msgLen+HEAD_LEN];
                memset(mysocket->recvBuff, 0, msgLen+HEAD_LEN);
                memcpy(mysocket->recvBuff, head, HEAD_LEN);
                int index = 0;
                while (true)
                {
                    index+=mysocket->m_Socket.RecvS(mysocket->recvBuff+HEAD_LEN+index, msgLen-index, 0);
                    if (index<0)
                    {
                        pthread_mutex_lock(&mysocket->dataLock);
                        mysocket->callback(SOCKET_RECV_FAILED, msgId ,0);
                        pthread_mutex_unlock(&mysocket->dataLock);
                        break;
                    }
                    else if (index<msgLen)
                        continue;
                    else
                    {
                        pthread_mutex_lock(&mysocket->dataLock);
                        mysocket->callback(SOCKET_SUCCESS, msgId , msgLen+HEAD_LEN);
                        pthread_mutex_unlock(&mysocket->dataLock);
                        break;
                    }
                }
            }
        }
        usleep(200*1000);
    }
    return NULL;
}

int MySocket::createRecvPThread()
{
    int errCode = 0;
    isRecvThreadRun = true;
    do{
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        CC_BREAK_IF(errCode!=0);
        //但是上面这个函数其他内容则主要为你创建的线程设定为分离式
        errCode = pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);
        if (errCode!=0) {
            pthread_attr_destroy(&tAttr);
            break;
        }
        errCode = pthread_create(&m_RecvPThread,&tAttr,startRecvThread,this);
    }while (0);
    
    return errCode;
}



int MySocket::createManagerPThread()
{
    int errCode = 0;
    isManagerThreadRun = true;
    mLinkData = new vector<SocketData*>();
    do{
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        CC_BREAK_IF(errCode!=0);
        
        //但是上面这个函数其他内容则主要为你创建的线程设定为分离式
        errCode = pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);
        if (errCode!=0) {
            pthread_attr_destroy(&tAttr);
            break;
        }
        errCode = pthread_create(&m_MagaerPThread,&tAttr,startMagagerThread,this);
    }while (0);
    
    return errCode;
}

void MySocket::cleanData()
{
    mLinkData->clear();
    free(mLinkData);
    mLinkData = NULL;
}

void MySocket::closePThread()
{
    isManagerThreadRun = false;
    pthread_cancel(m_MagaerPThread);
    pthread_detach(m_MagaerPThread);
    
    isRecvThreadRun = false;
    pthread_cancel(m_RecvPThread);
    pthread_detach(m_RecvPThread);
    
    isMsgThreadRun = false;
    pthread_cancel(m_MsgPThread);
    pthread_detach(m_MsgPThread);
}


void MySocket::closeSocket()
{
    m_Socket.Close();
}

void MySocket::destroy()
{
    closePThread();
    closeSocket();
    cleanData();
}




bool MySocket::createSocket(const char *ip,unsigned short port)
{
    m_Socket.Init();
	m_Socket.Create(AF_INET,SOCK_STREAM,0);
    
    int contectFailNum = 3;
	bool ConnectState = false;
	while(!ConnectState&&contectFailNum>0)
	{
        bool result = m_Socket.Connect(ip, port);
        CCLog("createSocket result = %d",result);

		if(!result)
		{
			contectFailNum--;
			if(contectFailNum<=0)
            {
                CCLog("createSocket failed!");
                return false;
            }
            sleep(2);
        }
        else
            ConnectState = true;
	}
    CCLog("createSocket success!");
    return true;
}


bool MySocket::init(const char *ip,unsigned short port)
{
    
    CCLog("MySocket::init");
    //create and connect socket
    if (!createSocket(ip,port))
       return false;
    
    dataLock = PTHREAD_MUTEX_INITIALIZER;
    

    
    //create socket manager thread
    createManagerPThread();

    //create socket recv thread
    createRecvPThread();
    
    //create msg notify thread
    createMsgPThread();
    
    return true;
}


void MySocket::sendData(int cbMsgId,unsigned char* sendBuff,int length)
{
    pthread_mutex_lock(&dataLock);
    
    SocketData* data = new SocketData();
    data->cbMsgId=cbMsgId;
    data->sendLen=length;
    data->sendBuff = (unsigned char*)malloc(length);
    memcpy(data->sendBuff,sendBuff,length);
    mLinkData->push_back(data);
    
    pthread_mutex_unlock(&dataLock);
    
    printf("MsgManager::getInstance()->sendbuffer=%s\n",MsgManager::getInstance()->sendbuffer);
    printf("MySocket send new id = %d\n",readInt(MsgManager::getInstance()->sendbuffer,MSGID_POS));



}


void MySocket::StartRequest(int cbMsgId)
{
    sendData(cbMsgId,MsgManager::getInstance()->getsendMsg(),HEAD_LEN+MsgManager::getInstance()->wbufferpos);
}





                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 