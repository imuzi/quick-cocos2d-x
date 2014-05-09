#include "NetManager.h"
#include "DialogLayer.h"
// register lua engine
//    pathToSave = CCFileUtils::sharedFileUtils()->getWritablePath();
//    pathToSave += "tmpdirr";
//
//    string envvx = "";
//    envvx.append(pathToSave);
//    envvx.append("/res/");
//
//    string envvxx = "";
//    envvxx.append(pathToSave);
//    envvxx.append("/");
//    vector<string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
//    "127.0.0.1"
//    "192.168.1.119"
//    ODSocket cSocket(false);
//    std::wstring w_char = L"whatafuck";
//    std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8conv;
//    CCLog("w_char = %s",utf8conv.to_bytes(w_char).c_str()) ;
//   std::wstring u = L"123abc가1나1다";
//    std::cout << "Wide string containts " << u.size() << " characters\n";
//
//    std::string s = "123abc가1나1다";
//    std::cout << "Narrow string contains " << s.length() << " bytes\n";
//
//    std::setlocale(LC_ALL, "");
//    std::cout << "Which can be converted to "
//    << std::mbstowcs(NULL, s.c_str(), s.size())
//    << " wide characters in the current locale,\n";


//        buffer[0] =(xxx>>24)&0xff;
//        buffer[1]=(xxx>>16)&0xff;
//        buffer[0] =(TAG>>8)&0xff;
//        buffer[1] =(TAG)&0xff;
//
//        buffer[2] =(2)&0xff;
//
//        buffer[3] =(100>>24)&0xff;
//        buffer[4]=(100>>16)&0xff;
//        buffer[5] =(100>>8)&0xff;
//        buffer[6] =(100)&0xff;
//
//        buffer[7] =(100>>8)&0xff;
//        buffer[8] =(100)&0xff;
//
//        buffer[9] =((strlen(txxx)+2)>>24)&0xff;
//        buffer[10]=((strlen(txxx)+2)>>16)&0xff;
//        buffer[11] =((strlen(txxx)+2)>>8)&0xff;
//        buffer[12] =((strlen(txxx)+2))&0xff;
//
//        buffer[13] =(0>>8)&0xff;
//        buffer[14] =(0)&0xff;
//
//        buffer[15] =(0>>8)&0xff;
//        buffer[16] =(0)&0xff;
//
//         buffer[17] =(0)&0xff;


//        buffer[18] =(xxx>>24)&0xff;
//        buffer[19]=(xxx>>16)&0xff;
//        buffer[20] =(xxx>>8)&0xff;
//        buffer[21] =(xxx)&0xff;
//        std::string hex = "whatafuck";
//        std::stringstream convertStream;
//
// if you have something like "0c 45 a1 bf" -> delete blanks
//        hex.erase( std::remove(hex.begin(), hex.end(), ' '), hex.end() );
//
//        int offset = 0, i = 0;
//        while (offset < hex.length())
//        {
//            unsigned int bufferi;
//
//            convertStream << std::hex << hex.substr(offset, 2);
//            convertStream >> std::hex >> bufferi;
//            CCLog("%d",i);
//            buffer[18+i] = static_cast<unsigned char>(bufferi);
//
//            offset += 2;
//            i++;
//
//            // empty the stringstream
//            convertStream.str(std::string());
//            convertStream.clear();
//        }
//        buffer[18] = (buf[0])&0xff;

//        >> 5)&0x07)|0xF0
//        buffer[19] = (buf[1])&0xff;
//        buffer[20] = (buf[2])&0xff;
//        buffer[21] = (buf[3])&0xff;
//        buffer[22] = (buf[4])&0xff;
//        buffer[19] = (buf[1])&0xff;
//        buffer[20] = (buf[2])&0xff;
//        buffer[21] = (buf[3])&0xff;
//        buffer[22] = buf[0]&0xff;


//        buffer[18] =(strlen(txxx)>>8)&0xff;
//        buffer[19] =(strlen(txxx))&0xff;
//        memcpy(buffer+20, txxx, strlen(txxx));




NetManager::NetManager()
:_tid(NULL)
{

  
	//socket.Init();
	//socket.Create(AF_INET,SOCK_STREAM,0);

//	this->senddata=new com::RPC;
//	this->getdata=new com::RPC;
//
//    hostip = "";
//    port = 0;
//    //pthread_mutex_init(&mutex,NULL);
//    CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(NetManager::ContectLong), "connectAgain", NULL);
}

NetManager::~NetManager()
{
//    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "connectAgain");
}
static NetManager* m_pInstance;
NetManager* NetManager::getInstance()
{
    if ( m_pInstance == NULL ){
        m_pInstance = new NetManager();
    }
    return m_pInstance;
}

bool NetManager::ContectLong(const char *ip, unsigned short port) {
    m_Socket.Init();
	m_Socket.Create(AF_INET,SOCK_STREAM,0);
    
	int contectFailNum = 3;
	bool ConnectState = false;
	while(!ConnectState&&contectFailNum>0)
	{
		CCLog("contectFailNum =%d",contectFailNum);
        
		if(!m_Socket.Connect(ip,port) )
		{
			CCLog("contect fail");
			contectFailNum--;
            
			if(contectFailNum<=0) {
                return false;
            }
            sleep(2);
            if (contectFailNum==2) {   
            }
           
		}else {
            CCLog("connect！");
            ConnectState = true;
        }
	}
    return true;
}

void*  SendAndRecvData(void* data) {
//	char tmpArr[4096];
//	memset(tmpArr,0,sizeof(tmpArr));
//    
//	//char* data=tmpArr;
//	int temp= 15;
//    int recvLength = 0;
//    //int temp1 = usingstring(tmpArr);
//	CCLog("_______________________-3");
//	{
//		int flag = m_Socket.Send(tmpArr,temp,0);
//        if (flag == -1) {
//            m_Socket.Close();
//            m_Socket.Clean();
//           
//            return false;
//        }
//        CCLog("~~~~~~~~~~~flag:%d",flag);
//		char  recvBuf[4096] = "";
//		int num = sizeof(recvBuf);
//		while(num == sizeof(recvBuf))
//		{
//			CCLog("_______________________-3.3");
//            cc_timeval preTime;
//            CCTime::gettimeofdayCocos2d(&preTime, NULL);
//            
////            netFlag = true;
//			num =m_Socket.Recv(recvBuf,sizeof(recvBuf),0);	//返回字节长度
////            netFlag = false;
//
    
//            cc_timeval nowTime;
//            CCTime::gettimeofdayCocos2d(&nowTime, NULL);
//            double time = CCTime::timersubCocos2d(&preTime, &nowTime);
//            
//            if (time>2000) {
//               
//                m_Socket.Close();
//                m_Socket.Clean();
//               
//                return false;
//            }
//            CCLog("interval:%f",time);
//            
//			if(num<0)
//			{
//				return false;
//			}
//            
//            
//			if(recvLength == 0)
//			{
//            }
//		}
//	}
//	return true;
    NetManager * self = (NetManager*)data;
    if (self->_tid)
    {
        printf("tidnulllll");
        delete self->_tid;
        self->_tid = NULL;
    }
    //-------
    MsgManager * msg = MsgManager::getInstance();
    int num = 0;
    printf("pthreadtesting~~~");
    while (true) {
        num += self->m_Socket.Recv((char*)msg->recvbuffer+num,sizeof(msg->recvbuffer)-num, 0);
        CCLog("Recvingbufsize===%dnum/n",num);
        if (num<-1) {
            return false;
        }
        
        if (num<HEAD_LEN) {
            CCLog("head=%d",num);
            continue;
        }
        if (num<(HEAD_LEN+msg->getBodyLen())) {
            CCLog("body=%d",num);
            continue;
        }
        else{
            int l = num - msg->getBodyLen();
            num =l;
            //可以通过消息体的容量来判断要不要LOADING````` 消息容量比较大就loading
            
            CCScriptEngineManager::sharedManager()->getScriptEngine()->executeGlobalFunction("ParseMessagers");       //消息完整收完 移除loading
//            CCNotificationCenter::sharedNotificationCenter()->postNotification("RECVED",(CCObject*)NULL);
            printf("CCNotificationCenter::sharedNotificationCenter()->postNotification(RECVED);");
//             解析完成
            printf("msg->msgnum == %d",msg->msgnum);
//            if (msg->msgnum==0||msg->msgnum<=-1){
//            
//                if (CCDirector::sharedDirector()->getRunningScene()->getChildByTag(100)) {
//                    //                CCDirector::sharedDirector()->getRunningScene()->getChildByTag(100)->getChildByTag(11)->stopAllActions();
//                    CCDirector::sharedDirector()->getRunningScene()->removeChildByTag(100,true);
//                    printf("->getRunningScene()->removeChildByTag(100,true)");
//                }
//            
//            }
            
            
            
           
            
            break;
        }
    }
    
   

    
    
    
//    return true;
    return NULL;

}

bool NetManager::SendAndRecvnLoginData(int msgid, char *name, int code, int recnum){
    MsgManager * msg = MsgManager::getInstance();
    msg->setHeadMsgId(msgid);
    msg->writeBodyString(name);
    msg->writeBodyInt(code);
    msg->writeBodyInt(recnum);
    
    
//    SendData(msg->getsendMsg());
//    CCLog("oksend=%d",flag);
//    RecvData();oksendoksend

    return true;
}

int NetManager::SendData(){
    
//    printf("sedbuffer.msgid=%d ",readInt(sendbuffer, 3));
//    printf("sedbuffer.blen=%d ",readInt(sendbuffer, 9));
    int flag = m_Socket.Send((char*)MsgManager::getInstance()->getsendMsg(), HEAD_LEN+MsgManager::getInstance()->wbufferpos,0);
    CCLog("oksend=%d",flag);
    
    
 //添加loading
    
//    if (CCDirector::sharedDirector()->getRunningScene()->getChildByTag(100)) {
//       printf("````getRunningScene`````");
//    }else {
//    
//    DialogLayer * loadlayer = DialogLayer::create();
//        printf("````1`````");
//    CCLabelTTF * loadinglable = CCLabelTTF::create("Loading....", "Arial", 49);
//    loadinglable->setPosition(ccp(480,320));
//        printf("````2`````");
//    loadinglable->setColor(ccc3(120, 200, 166));
//        printf("````3`````");
////    loadinglable->runAction(CCRepeatForever::create(CCEaseSineInOut::create(CCSequence::create(CCFadeIn::create(0.4), CCDelayTime::create(0.2),CCFadeOut::create(0.5),NULL))));
//    printf("````````4`");
//    loadlayer->addChild(loadinglable,0,11);
//        printf("`````5````");
//    CCDirector::sharedDirector()->getRunningScene()->addChild(loadlayer,11,100);
//        printf("``````6```");
//    }
    return flag;
    

}

bool NetManager::RecvData(){
//    MsgManager * msg = MsgManager::getInstance();
//    int num = 0;
//    
//    while (true) {
//        num += m_Socket.Recv((char*)msg->recvbuffer+num,sizeof(msg->recvbuffer)-num, 0);
//        CCLog("Recvingbufsize===%dnum/n",num);
//        if (num<-1) {
//            return false;
//        }
//        
//        if (num<HEAD_LEN) {
//            CCLog("head=%d",num);
//            continue;
//        }
//        if (num<(HEAD_LEN+msg->getBodyLen())) {
//            CCLog("body=%d",num);
//            continue;
//        }
//        else{
//            int l = num - msg->getBodyLen();
//            num =l;
//            break;
//        }
//    }
//    return true;
    
    
    
    printf("NETMANGER:RECVDATA()");
    
    _tid = new pthread_t();
    pthread_create(&(*_tid), NULL,SendAndRecvData, this);
    
    return true;
}

