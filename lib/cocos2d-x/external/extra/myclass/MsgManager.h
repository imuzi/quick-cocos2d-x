//
//  MsgManger.h
//  coinflip
//
//  Created by lee on 8/13/13.
//
//

#ifndef __coinflip__MsgManger__
#define __coinflip__MsgManger__
#include "ODSocket.h"
#include <iostream>

#define HEAD_LEN 18
#define MSGID_POS 3
#define BLEN_POS 9

class MsgManager {
public:
    
    MsgManager();
    ~MsgManager();
    
//    int sizeofrecvbuffer;
//    int sizeofsendbuffer;
    static MsgManager* getInstance();
    
    int msgnum;
    unsigned char recvbuffer[1024*20];
    unsigned char sendbuffer[4049];
    bool isSuccess;

    
    void cleanBuffer();
    int mesgid;
    int mesgkind;
    int wbufferpos;
    int rbufferpos;
    
    int setHeadMsgId(int msgid);
    int setHeadMsgKind(int msgkind);
    
    int writeBodyShort(short value);
    int writeBodyByte(unsigned char value);
    int writeBodyInt(int value);
    int writeBodyLong(long long value);
    int writeBodyString(char* value);

    unsigned char*  getsendMsg();
    
    int getMsgId();
    int getBodyLen();
    
    bool getResult();

    
    
    short readBodyShort();
    unsigned char readBodyByte();
    int readBodyInt();
    long long readBodyLong();
    std::string readBodyString();

protected:
    ODSocket m_Socket;
    


};



#endif /* defined(__coinflip__MsgManger__) */
