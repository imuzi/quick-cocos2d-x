//
//  NetManager.h
//  coinflip
//
//  Created by lee on 8/13/13.
//
//
#ifndef __NetManager__
#define __NetManager__
#include<string>
#include"stdio.h"
#include "cocos2d.h"
#include "pthread.h"
#include "MsgManager.h"
#include <pthread.h>


#include <vector>
USING_NS_CC;
using namespace std;

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
#include <jni.h> 
#include "platform/android/jni/JniHelper.h" 
#include <android/log.h> 
#endif



class NetManager 
{
public:
    NetManager();
	~NetManager();
    
    
    
    pthread_t *_tid;
    
    static NetManager* getInstance();
    bool ContectLong(const char* ip, unsigned short port);
    
    friend void* SendAndRecvData(void * data);

    bool SendAndRecvnLoginData(int msgid,char* name,int code,int recnum);
    ODSocket m_Socket;
    
    bool RecvData();
    int SendData();

};
#endif
