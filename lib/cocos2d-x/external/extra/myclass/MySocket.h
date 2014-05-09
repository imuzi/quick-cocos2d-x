//
//  MySocket.h
//  quickcocos2dx
//
//  Created by mac on 13-12-5.
//  Copyright (c) 2013年 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__MySocket__
#define __quickcocos2dx__MySocket__

#include <iostream>

#include"stdio.h"
#include "cocos2d.h"
#include "pthread.h"
#include <pthread.h>
#include "ODSocket.h"


#include <vector>
USING_NS_CC;
using namespace std;
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif




//联网框架 多地址联网 采用多线程方式 不采用单例模式

class MySocket {
    
    
    
public :
    

    MySocket();
    ~MySocket();
    static MySocket* getInstance();
    bool init(const char* ip,unsigned short port);
    void StartRequest(int cbMsgId);
    
    void closePThread();
    void destroy();
    

private:
    
    struct SocketData
    {
        int cbMsgId;    //需要服务器返回数据MSGID  不需要填0
        unsigned char* sendBuff;
        int sendLen;
        
    };
    
        
    //单次接受数据缓存
    unsigned char* recvBuff;

    void sendData(int cbMsgId,unsigned char* sendBuff,int length);
    
    

    pthread_mutex_t dataLock;
    pthread_t m_MagaerPThread;
    pthread_t m_RecvPThread;
    pthread_t m_MsgPThread;
    


    
    long mTimeOutCount;
        
    friend void* startMagagerThread(void* arg);
    friend void* startRecvThread(void* arg);
    friend void* startMsgThread(void* arg);
    
    bool sendMsg;
    
    bool isMsgThreadRun;
    bool isManagerThreadRun;
    bool isRecvThreadRun;
    ODSocket m_Socket;
    int mSocketStatus;


    vector<SocketData*> *mLinkData;   //多次连接请求数据



    
    int createMsgPThread();
    int createRecvPThread();
    int createManagerPThread();

    bool createSocket(const char *ip,unsigned short port);
    void closeSocket();
    void callback(int resultCode,int msgId,int length);
    void cleanData();
    void cleanDataAt(int index);
};




#endif /* defined(__quickcocos2dx__MySocket__) */
