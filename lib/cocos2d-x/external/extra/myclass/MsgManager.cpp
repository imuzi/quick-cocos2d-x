//
//  MsgManger.cpp
//  coinflip
//
//  Created by lee on 8/13/13.
//
//

#include "MsgManager.h"
MsgManager::MsgManager()
:mesgid(0)
, rbufferpos(0)
, mesgkind(0)
, wbufferpos(0)
, msgnum(0)
{
    memset(sendbuffer,0,sizeof(sendbuffer));
    memset(recvbuffer,0,sizeof(recvbuffer));
}
MsgManager::~MsgManager(){}
static MsgManager * m_amInstance;
MsgManager * MsgManager::getInstance()
{
    if ( m_amInstance == NULL )
    {
        m_amInstance = new MsgManager();
    }
    return m_amInstance;
}


void MsgManager::cleanBuffer(){
    memset(sendbuffer,0,sizeof(sendbuffer));
//    memset(recvbuffer,0,sizeof(recvbuffer));

}

int MsgManager::setHeadMsgId(int msgid){
    mesgid = msgid;
    printf("setHeadMsgId=%d\n",mesgid);
    
    return 1;
}

int MsgManager::setHeadMsgKind(int msgkind){
    memset(sendbuffer,0,sizeof(sendbuffer));
    wbufferpos = 0;
    mesgkind = msgkind;
    printf("setHeadMsgKind=%d\n",mesgkind);
    return 1;
}

int MsgManager::writeBodyByte(unsigned char value){
    printf("writeBodyByte=%d\n",value);
    writeByte(sendbuffer, HEAD_LEN+wbufferpos, (unsigned char) value);
    return wbufferpos+=1;
}

int MsgManager::writeBodyShort(short value){
    
    printf("writeBodyShort=%d\n",value);
    writeShort(sendbuffer, HEAD_LEN+wbufferpos, (short)value);
    return wbufferpos+=2;
}

int MsgManager::writeBodyInt(int value){
    printf("writeBodyInt=%d\n",value);
    writeInt(sendbuffer, HEAD_LEN+wbufferpos, (int) value);
    return wbufferpos+=4;
}

int MsgManager::writeBodyLong(long long value){
    printf("writeBodyLong=%lld\n",value);
    writeLong(sendbuffer, HEAD_LEN+wbufferpos, (long long)value);
    return wbufferpos+=8;
    
}


int MsgManager::writeBodyString(char *value){
    writeString(sendbuffer, HEAD_LEN+wbufferpos, value);
    printf("writeBodyString=%s\n",value);
    return wbufferpos+=(strlen(value)+2);
}


unsigned char* MsgManager::getsendMsg(){
    //引擎消息 客户端消息区分
//    printf("-----------------Sendbuffer>wbufferpos=%d\n",wbufferpos);
    writeMsgHead(sendbuffer, 'T'<<8|'E', mesgkind, mesgid, 0, wbufferpos, 0, 0, 0);
    
//    printf("#########sedbuffer.msgid=%d ",readInt(sendbuffer,MSGID_POS));
//    printf("#########sedbuffer.blen=%d ",readInt(sendbuffer, BLEN_POS));
    if (readInt(sendbuffer,MSGID_POS)==1301) {
        rbufferpos = 0;
        printf("sedbuffer.rolename=%s \n ",readString(sendbuffer, HEAD_LEN+rbufferpos).c_str());
//        printf("sedbuffer.rolekind=%d \n",readByte(sendbuffer, HEAD_LEN+rbufferpos));
//        printf("sedbuffer.device=%s \n",readString(sendbuffer, HEAD_LEN+rbufferpos).c_str());
    }

    return sendbuffer;
}

bool MsgManager::getResult()
{
    return isSuccess;
}

int MsgManager::getMsgId(){
   
    rbufferpos = 0;
    int messageid = readInt(recvbuffer,MSGID_POS);
    return messageid;
}
int MsgManager::getBodyLen(){
    int32 blen = readInt(recvbuffer, BLEN_POS);
    printf("blen=%d",blen);
    return blen;
}

unsigned char  MsgManager::readBodyByte(){
    unsigned char value = readByte(recvbuffer, HEAD_LEN+rbufferpos);
    printf("readBodyByte=%d\n",value);
    rbufferpos+=1;
    return value;
}

short MsgManager::readBodyShort(){
    short value = readShort(recvbuffer, HEAD_LEN+rbufferpos);
    printf("readBodyShort=%d\n",value);
    rbufferpos+=2;
    return value;
    
    
}
int MsgManager::readBodyInt(){
    int value = readInt(recvbuffer, HEAD_LEN+rbufferpos);
    printf("readBodyInt=%d\n",value);
    rbufferpos+= 4;
    return value;
    
}

long long MsgManager::readBodyLong(){
    long long value = readLong(recvbuffer, HEAD_LEN+rbufferpos);
    printf("readBodyLong=%lld\n",value);
    rbufferpos+= 8;
    return value;
    
}

std::string MsgManager::readBodyString(){
    std::string value = readString(recvbuffer, HEAD_LEN+rbufferpos);
    printf("readBodyString=%s\n",value.c_str());
    rbufferpos+= (value.length()+2);
    return value;

}

