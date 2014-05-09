#include "ODSocket.h"
#include <stdio.h>
#include <signal.h>
#ifdef WIN32
	#pragma comment(lib, "wsock32")
#endif


//void ODSocket::utf8toWStr(WStr& dest, const Str& src){
//	dest.clear();
//	wchar_t w = 0;
//	int bytes = 0;
//	wchar_t err = L'�';
//	for (size_t i = 0; i < src.size(); i++){
//		unsigned char c = (unsigned char)src[i];
//		if (c <= 0x7f){//first byte
//			if (bytes){
//				dest.push_back(err);
//				bytes = 0;
//			}
//			dest.push_back((wchar_t)c);
//		}
//		else if (c <= 0xbf){//second/third/etc byte
//			if (bytes){
//				w = ((w << 6)|(c & 0x3f));
//				bytes--;
//				if (bytes == 0)
//					dest.push_back(w);
//			}
//			else
//				dest.push_back(err);
//		}
//		else if (c <= 0xdf){//2byte sequence start
//			bytes = 1;
//			w = c & 0x1f;
//		}
//		else if (c <= 0xef){//3byte sequence start
//			bytes = 2;
//			w = c & 0x0f;
//		}
//		else if (c <= 0xf7){//3byte sequence start
//			bytes = 3;
//			w = c & 0x07;
//		}
//		else{
//			dest.push_back(err);
//			bytes = 0;
//		}
//	}
//	if (bytes)
//		dest.push_back(err);
//}
//
//void ODSocket::wstrToUtf8(Str& dest, const WStr& src){
//	dest.clear();
//	for (size_t i = 0; i < src.size(); i++){
//		wchar_t w = src[i];
//		if (w <= 0x7f)
//			dest.push_back((char)w);
//		else if (w <= 0x7ff){
//			dest.push_back(0xc0 | ((w >> 6)& 0x1f));
//			dest.push_back(0x80| (w & 0x3f));
//		}
//		else if (w <= 0xffff){
//			dest.push_back(0xe0 | ((w >> 12)& 0x0f));
//			dest.push_back(0x80| ((w >> 6) & 0x3f));
//			dest.push_back(0x80| (w & 0x3f));
//		}
//		else if (w <= 0x10ffff){
//			dest.push_back(0xf0 | ((w >> 18)& 0x07));
//			dest.push_back(0x80| ((w >> 12) & 0x3f));
//			dest.push_back(0x80| ((w >> 6) & 0x3f));
//			dest.push_back(0x80| (w & 0x3f));
//		}
//		else
//			dest.push_back('?');
//	}
//}
//
//Str ODSocket::dwstrToUtf8(const WStr& str){
//	Str result;
//	wstrToUtf8(result, str);
//	return result;
//}
//
//WStr ODSocket::dutf8toWStr(const Str& str){
//	WStr result;
//	utf8toWStr(result, str);
//	return result;
//}
//
//
//bool ODSocket::utf8test(){
//    WStr w1;
//    //for (wchar_t c = 1; c <= 0x10ffff; c++){
//    for (wchar_t c = 0x100000; c <= 0x100002; c++){
//        w1 += c;
//    }
//    Str s = dwstrToUtf8(w1);
//    WStr w2 = dutf8toWStr(s);
//    bool result = true;
//    if (w1.length() != w2.length()){
//        printf("length differs\n");
//        //std::cout << "length differs" << std::endl;
//        result = false;
//    }
//    
//    printf("w1: %S\ns: %s\nw2: %S\n", w1.c_str(), s.c_str(), w2.c_str());
//    
//    for (size_t i = 0; i < w1.size(); i++)
//        if (w1[i] != w2[i]){
//            result = false;
//            printf("character at pos %lx differs (expected %.8x got %.8x)\n", i, w1[i], w2[i]);
//            //std::cout << "character at pos " << i  << " differs" << std::endl;
//            break;
//        }
//    
//    if (!result){
//        printf("utf8 dump: \n");
//        for (size_t i = 0; i < s.size(); i++)
//            printf("%2x ", (unsigned char)s[i]);
//    }
//    
//    return result;
//}
//
//




ODSocket::ODSocket(SOCKET sock)
{
	m_sock = sock;
}

ODSocket::~ODSocket()
{
}

int ODSocket::Init()
{
#ifdef WIN32
	/*
	http://msdn.microsoft.com/zh-cn/vstudio/ms741563(en-us,VS.85).aspx

	typedef struct WSAData { 
		WORD wVersion;								//winsock version
		WORD wHighVersion;							//The highest version of the Windows Sockets specification that the Ws2_32.dll can support
		char szDescription[WSADESCRIPTION_LEN+1]; 
		char szSystemStatus[WSASYSSTATUS_LEN+1]; 
		unsigned short iMaxSockets; 
		unsigned short iMaxUdpDg; 
		char FAR * lpVendorInfo; 
	}WSADATA, *LPWSADATA; 
	*/
	WSADATA wsaData;
	//#define MAKEWORD(a,b) ((WORD) (((BYTE) (a)) | ((WORD) ((BYTE) (b))) << 8)) 
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);//win sock start up
	if ( ret ) {
//		cerr << "Initilize winsock error !" << endl;
		return -1;
	}
#endif
	
	return 0;
}
//this is just for windows
int ODSocket::Clean()
{
#ifdef WIN32
		return (WSACleanup());
#endif
		return 0;
}

ODSocket& ODSocket::operator = (SOCKET s)
{
	m_sock = s;
	return (*this);
}

ODSocket::operator SOCKET ()
{
	return m_sock;
}
//create a socket object win/lin is the same
// af:
bool ODSocket::Create(int af, int type, int protocol)
{
	m_sock = socket(af, type, protocol);
	if ( m_sock == INVALID_SOCKET ) {
		return false;
	}
	return true;
}
static void u_alarm_handler(int) {
    
}

bool ODSocket::Connect(const char* ip, unsigned short port)
{
	struct sockaddr_in svraddr;
	svraddr.sin_family = AF_INET;
	svraddr.sin_addr.s_addr = inet_addr(ip);
	svraddr.sin_port = htons(port);
    
//    signal(SIGALRM, u_alarm_handler);
//    //sigset(SIGALRM, u_alarm_handler);
//    alarm(2);
//    int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
//    alarm(0);
//    sigrelse(SIGALRM);
    
    void (*was)(int);
    
    was =signal(SIGALRM, u_alarm_handler);
    alarm(2);
    int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
    alarm(0);
    signal(SIGALRM,was);
	
	if ( ret == SOCKET_ERROR ) {
        
		return false;
	}
    
	return true;
}
//bool ODSocket::Connect(const char* ip, unsigned short port)
//{
//    struct sockaddr_in svraddr;
//	svraddr.sin_family = AF_INET;
//	svraddr.sin_addr.s_addr = inet_addr(ip);
//	svraddr.sin_port = htons(port);
//    int flags;
//    
//    flags = fcntl(m_sock,F_GETFL,0);//获取建立的sockfd的当前状态（非阻塞）
//    fcntl(m_sock,F_SETFL,flags|O_NONBLOCK);
//    
//    int ret=0;
//    
//    if ( ( ret = connect( m_sock, ( struct sockaddr *)&svraddr , sizeof(struct sockaddr)) ) < 0 )
//    {
//        if(errno != EINPROGRESS)
//            return true;
//    }
//    if(ret==0)
//    {
//        printf("connect completed immediately");
//        return true;
//    }
//    
//    struct timeval tval;
//    fd_set wset,rset;
//    
//    FD_ZERO(&rset);
//    FD_SET(m_sock,&rset);
//    
//    FD_ZERO(&wset);
//    FD_SET(m_sock,&wset);
//    
//    tval.tv_sec = 2;
//    tval.tv_usec = 0;
//    int error;
//    socklen_t len;
//    if(( ret = select(m_sock+1, &rset, &wset, NULL,&tval)) <= 0)
//    {
//        printf("time out connect error");
//        close(m_sock);
//        return false;
//    }
//    if ( FD_ISSET(m_sock,&rset) || FD_ISSET(m_sock,&wset) )
//    {
//        len = sizeof(error);
//        int temp = getsockopt(m_sock,SOL_SOCKET,SO_ERROR,&error,&len);
//        if (temp == 0) {
//            return true;
//        }
//        if( temp <0 )
//            return false;
//    }
//    return false;
//}

bool ODSocket::Bind(unsigned short port)
{
    
//	struct sockaddr_in svraddr;
//	svraddr.sin_family = AF_INET;
//	svraddr.sin_addr.s_addr = INADDR_ANY;
//	svraddr.sin_port = htons(port);
//
//	int opt =  1;
//	if ( setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0 ) 
//		return false;
//
//	int ret = bind(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
//	if ( ret == SOCKET_ERROR ) {
//		return false;
//	}
//	return true;
}
//for server
bool ODSocket::Listen(int backlog)
{
	int ret = listen(m_sock, backlog);
	if ( ret == SOCKET_ERROR ) {
		return false;
	}
	return true;
}

bool ODSocket::Accept(ODSocket& s, char* fromip)
{
	struct sockaddr_in cliaddr;
	socklen_t addrlen = sizeof(cliaddr);
	SOCKET sock = accept(m_sock, (struct sockaddr*)&cliaddr, &addrlen);
	if ( sock == SOCKET_ERROR ) {
		return false;
	}

	s = sock;
	if ( fromip != NULL )
		sprintf(fromip, "%s", inet_ntoa(cliaddr.sin_addr));

	return true;
}

int ODSocket::Send(const char* buf, int len, int flags)
{
	int bytes;
	int count = 0;
//    struct timeval timeout ;
//	timeout.tv_sec = 1;
//	timeout.tv_usec =0;
//    
//    setsockopt(m_sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));
	while ( count < len ) {
//        cout<<sizeof(long);
//        cout<<sizeof(int);
		bytes = send(m_sock, buf + count, len - count, flags);

		if ( bytes == -1 || bytes == 0 )
			return -1;
		count += bytes;
	} 

	return count;
}



int ODSocket::RecvS(unsigned char* buf, int len, int flags)
{
    return recv(m_sock, buf, len, flags);
}



//int ODSocket::Recv(int nSocketFd, char *RecvBuff, int ToRecvBytes, int RecvTimeout )
//{
//	struct timeval tv;
//	fd_set rfds;
//	int rsd, ret = 0;
//
//	if ( nSocketFd < 0 )
//		return 0;
//
//	FD_ZERO (&rfds);
//	FD_SET (nSocketFd, &rfds);
//
//	tv.tv_sec = RecvTimeout;
//	tv.tv_usec = 0;
//
//	rsd = select (nSocketFd + 1, &rfds, NULL, NULL, (RecvTimeout>0) ? &tv : (struct timeval *)NULL );
//	if (rsd == -1)
//	{
//		printf ( "select error %s\n", strerror(errno) );
//		return -1;
//	}
//	else if (rsd == 0)
//	{
//		printf ( "select timeout\n" );
//		return 0;
//	}
//	/*else if (rsd == 1){}*/
//
//	signal ( SIGALRM, timeout_alarm );
//	alarm ( RecvTimeout );
//
//	ret = RECVN ( nSocketFd, RecvBuff, ToRecvBytes );
//
//	alarm ( 0 );
//}

int ODSocket::Recv(char* buf, int len, int flags)
{
	struct timeval timeout ;
	timeout.tv_sec = 6010;
	timeout.tv_usec =2000;
    setsockopt(m_sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));

    
//    void (*was)(int);
//    
//    was =signal(SIGALRM, u_alarm_handler);
//    alarm(1);
    int ret = recv(m_sock, buf, len, flags);
//    alarm(0);
//    signal(SIGALRM,was);
    
	return ret;
}

//int ODSocket::Recv(char* buf, int len, int flags)
//{
//	return (recv(m_sock, buf, len, flags));
//}

int ODSocket::Close()
{
#ifdef WIN32
	return (closesocket(m_sock));
#else
	return (close(m_sock));
#endif
}

int ODSocket::GetError()
{
#ifdef WIN32
	return (WSAGetLastError());
#else
	return (errno);
#endif
}

bool ODSocket::DnsParse(const char* domain, char* ip)
{
	struct hostent* p;
	if ( (p = gethostbyname(domain)) == NULL )
		return false;
		
	sprintf(ip, 
		"%u.%u.%u.%u",
		(unsigned char)p->h_addr_list[0][0], 
		(unsigned char)p->h_addr_list[0][1], 
		(unsigned char)p->h_addr_list[0][2], 
		(unsigned char)p->h_addr_list[0][3]);
	
	return true;
}
