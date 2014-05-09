/*
 * define file about portable socket class. 
 * description:this sock is suit both windows and linux
 * design:odison
 * e-mail:odison@126.com>
 * 
 */

#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_

#ifdef WIN32
	#include <winsock.h>
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include "errno.h"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <arpa/inet.h>


#include <locale>
#include <iostream>
#include <string>
#include <sstream>
using namespace std ;
	typedef int				SOCKET;

	//#pragma region define win32 const variable in linux
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
	//#pragma endregion
#endif


typedef std::string Str;
typedef std::wstring WStr;



#define BigtoLittle32(A) ((((uint32)(A) & 0xff000000) >> 24) | \
(((uint32)(A) & 0x00ff0000) >> 8) | \
(((uint32)(A) & 0x0000ff00) << 8) | \
(((uint32)(A) & 0x000000ff) << 24))

#define BigtoLittle16(A)   ((((uint16)(A) & 0xff00) >> 8) | \
(((uint16)(A) & 0x00ff) << 8))
typedef short int16;

typedef unsigned char int8;
typedef int int32;

typedef long int64;

static inline wstring widen( const string& str )
{
    wostringstream wstm ;
    wstm.imbue(std::locale("en_US.UTF-8"));
    const ctype<wchar_t>& ctfacet =
    use_facet< ctype<wchar_t> >( wstm.getloc() ) ;
    for( size_t i=0 ; i<str.size() ; ++i )
        wstm << ctfacet.widen( str[i] ) ;
    return wstm.str() ;
}

static inline string narrow( const wstring& str )
{
    ostringstream stm ;
    stm.imbue(std::locale("en_US"));
    const ctype<char>& ctfacet =
    use_facet< ctype<char> >( stm.getloc() ) ;
    for( size_t i=0 ; i<str.size() ; ++i )
        stm << ctfacet.narrow( str[i], 0 ) ;
    return stm.str() ;
}
//std::ostream& operator<<(std::ostream& f, const WStr& s);
//std::istream& operator>>(std::istream& f, WStr& s);


static inline void utf8toWStr(WStr& dest, const Str& src){
	dest.clear();
	wchar_t w = 0;
	int bytes = 0;
	wchar_t err = L'�';
	for (size_t i = 0; i < src.size(); i++){
		unsigned char c = (unsigned char)src[i];
		if (c <= 0x7f){//first byte
			if (bytes){
				dest.push_back(err);
				bytes = 0;
			}
			dest.push_back((wchar_t)c);
		}
		else if (c <= 0xbf){//second/third/etc byte
			if (bytes){
				w = ((w << 6)|(c & 0x3f));
				bytes--;
				if (bytes == 0)
					dest.push_back(w);
			}
			else
				dest.push_back(err);
		}
		else if (c <= 0xdf){//2byte sequence start
			bytes = 1;
			w = c & 0x1f;
		}
		else if (c <= 0xef){//3byte sequence start
			bytes = 2;
			w = c & 0x0f;
		}
		else if (c <= 0xf7){//3byte sequence start
			bytes = 3;
			w = c & 0x07;
		}
		else{
			dest.push_back(err);
			bytes = 0;
		}
	}
	if (bytes)
		dest.push_back(err);
}

static inline void wstrToUtf8(Str& dest, const WStr& src){
	dest.clear();
	for (size_t i = 0; i < src.size(); i++){
		wchar_t w = src[i];
		if (w <= 0x7f)
			dest.push_back((char)w);
		else if (w <= 0x7ff){
			dest.push_back(0xc0 | ((w >> 6)& 0x1f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else if (w <= 0xffff){
			dest.push_back(0xe0 | ((w >> 12)& 0x0f));
			dest.push_back(0x80| ((w >> 6) & 0x3f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else if (w <= 0x10ffff){
			dest.push_back(0xf0 | ((w >> 18)& 0x07));
			dest.push_back(0x80| ((w >> 12) & 0x3f));
			dest.push_back(0x80| ((w >> 6) & 0x3f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else
			dest.push_back('?');
	}
}

static inline Str dwstrToUtf8(const WStr& str){
	Str result;
	wstrToUtf8(result, str);
	return result;
}

static inline WStr dutf8toWStr(const Str& str){
	WStr result;
	utf8toWStr(result, str);
	return result;
}


static inline bool utf8test(){
    WStr w1;
    //for (wchar_t c = 1; c <= 0x10ffff; c++){
    for (wchar_t c = 0x100000; c <= 0x100002; c++){
        w1 += c;
    }
    Str s = dwstrToUtf8(w1);
    WStr w2 = dutf8toWStr(s);
    bool result = true;
    if (w1.length() != w2.length()){
        printf("length differs\n");
        //std::cout << "length differs" << std::endl;
        result = false;
    }
    
    printf("w1: %S\ns: %s\nw2: %S\n", w1.c_str(), s.c_str(), w2.c_str());
    
    for (size_t i = 0; i < w1.size(); i++)
        if (w1[i] != w2[i]){
            result = false;
            printf("character at pos %lx differs (expected %.8x got %.8x)\n", i, w1[i], w2[i]);
            //std::cout << "character at pos " << i  << " differs" << std::endl;
            break;
        }
    
    if (!result){
        printf("utf8 dump: \n");
        for (size_t i = 0; i < s.size(); i++)
            printf("%2x ", (unsigned char)s[i]);
    }
    
    return result;
}




static inline int8 readByte(unsigned char* buffer,int starpos){
            
    return (int8)buffer[starpos];
    
}

static inline int16 readShort(unsigned char* buffer,int starpos){
    
    return (int16)buffer[starpos]<<8|(int16)buffer[starpos+1];
    
}
static inline int32 readInt(unsigned char* buffer,int starpos){
    
    return (int32)buffer[starpos]<<24|(int32)buffer[starpos+1]<<16|(int32)buffer[starpos+2]<<8|(int32)buffer[starpos+3];
    
}

static inline long long readLong(unsigned char* buffer,int starpos){
    
    return (long long)buffer[starpos]<<56|(long long)buffer[starpos+1]<<48|(long long)buffer[starpos+2]<<40|(long long)buffer[starpos+3]<<32|(long long)buffer[starpos+4]<<24|(long long)buffer[starpos+5]<<16|(long long)buffer[starpos+6]<<8|(long long)buffer[starpos+7];
    
}


static inline std::string readString(unsigned char* buffer,int starpos){
    std::string ret;
    int16 str_len = readShort(buffer,starpos);
//    printf("str_len=%d\n",str_len);
    char* cstr =(char*)malloc(str_len+1);
    cstr[str_len]='\0';
    memcpy(cstr,buffer+starpos+2,str_len);
    ret = cstr;
    free(cstr);
    return ret;
}


static inline int writeByte(unsigned char* buffer,int starpos,unsigned char value){
    
    buffer[starpos] =(value)&0xff;
    return 1;
    
}
static inline int writeShort(unsigned char* buffer,int starpos,short value){
    buffer[starpos] =(value>>8)&0xff;
    buffer[starpos+1] =(value)&0xff;
    
    
//    buffer[starpos] =(value)&0xff;
//    buffer[starpos+1] =(value>>8)&0xff;
    return 1;
    
}
static inline int writeInt(unsigned char* buffer,int starpos,int value){
    buffer[starpos] =(value>>24)&0xff;
    buffer[starpos+1]=(value>>16)&0xff;
    buffer[starpos+2] =(value>>8)&0xff;
    buffer[starpos+3] =(value)&0xff;
    
//    buffer[starpos] =(value)&0xff;
//    buffer[starpos+1]=(value>>8)&0xff;
//    buffer[starpos+2] =(value>>16)&0xff;
//    buffer[starpos+3] =(value>>24)&0xff;
    return 1;
    
}

static inline int writeLong(unsigned char* buffer,int starpos,long long value){
    buffer[starpos] =(value>>56)&0xff;
    buffer[starpos+1]=(value>>48)&0xff;
    buffer[starpos+2] =(value>>40)&0xff;
    buffer[starpos+3] =(value>>32)&0xff;
    buffer[starpos+4] =(value>>24)&0xff;
    buffer[starpos+5] =(value>>16)&0xff;
    buffer[starpos+6] =(value>>8)&0xff;
    buffer[starpos+7] =(value)&0xff;
    return 1;
    
}

static inline int writeString(unsigned char* buffer,int starpos,char* value){

    writeShort(buffer,starpos,(short)strlen(value));
    memcpy(buffer+starpos+2, value, strlen(value));
    return 1;
}

static inline int writeMsgHead(unsigned char* buffer,int16 TAG,int8 msgkind,int32 msgid,int16 msgsnum,int32 blen,int16 bodykind,int16 unkonw,int8 uno){
//    printf("-----------------Sendbuffer>TAG=%d\n",TAG);
//     printf("-----------------Sendbuffer>msgkind=%d\n",msgkind);
//    printf("-----------------Sendbuffer>msgid=%d\n",msgid);
//    printf("-----------------Sendbuffer>msgsnum=%d\n",msgsnum);
//    printf("-----------------Sendbuffer>blen=%d\n",blen);
//    
//    printf("-----------------Sendbuffer>bodykind=%d\n",bodykind);
//
//    
//    printf("-----------------Sendbuffer>unkonw=%d\n",unkonw);
//    printf("-----------------Sendbuffer>uno=%d\n",uno);
    
    
    writeShort(buffer,0,(short)TAG);
    writeByte(buffer,2,(int8)msgkind);
    writeInt(buffer,3,(int)msgid);
    writeShort(buffer,7,(short)msgsnum);
    writeInt(buffer,9,(int)blen);
    writeShort(buffer,13,(short)bodykind);
    writeShort(buffer,15,(short)unkonw);
    writeByte(buffer,17,(int8)uno);
    
    return 1;
}


class ODSocket {

public:
	ODSocket(SOCKET sock = INVALID_SOCKET);
	~ODSocket();
    
	// Create socket object for snd/recv data
	bool Create(int af, int type, int protocol = 0);

    int RecvS(unsigned char* buf, int len, int flags);

    
	// Connect socket
	bool Connect(const char* ip, unsigned short port);
	//#region server
	// Bind socket
	bool Bind(unsigned short port);

	// Listen socket
	bool Listen(int backlog = 5); 

	// Accept socket
	bool Accept(ODSocket& s, char* fromip = NULL);
	//#endregion
	
	// Send socket
	int Send(const char* buf, int len, int flags = 0);

	// Recv socket
	int Recv(char* buf, int len, int flags = 0);
	//int Recv(int nSocketFd, char *RecvBuff, int ToRecvBytes, int RecvTimeout );
	// Close socket
	int Close();

	// Get errno
	int GetError();
	
	//#pragma region just for win32
	// Init winsock DLL 
	static int Init();	
	// Clean winsock DLL
	static int Clean();
	//#pragma endregion

	// Domain parse
	static bool DnsParse(const char* domain, char* ip);

	ODSocket& operator = (SOCKET s);

	operator SOCKET ();

protected:
	SOCKET m_sock;
    fd_set rfds;


};


#endif
