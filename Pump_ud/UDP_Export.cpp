//file***************************************************************************************************
//                                                                                                       
//                                                                                                       
//        UDP_Export.cpp for  Master                  
//                                                                                                       
//                                                                                                       
//*******************************************************************************************************
//               For UDP Communication (PC<=>DSP)                                                                                        
//******* Copyright(C) 2015 GIBH ******************************************************************
//                                                                                                       
//      Ver 1.00    2015.01.14   Initial coding                                            Enjoy_Lu     
//*******************************************************************************************************

#pragma once
#include "stdafx.h"
#include "UDP_Rerro.h"
#include "UDP_Export.h"
#include <WinSock2.h> 
#pragma comment(lib,"ws2_32.lib") 
SOCKET sino_socket;
HANDLE sdv_hThread;
HANDLE sdv_hThread1;
StreamProc gCallBack;
void*pUserData1;
SOCKADDR_IN addrFrom;
SOCKADDR_IN addrscoket5;
SOCKADDR_IN addrFrom1[255];
SOCKADDR_IN Send_addr[255];
char connet_buf[2];
int test_sock(SOCKADDR_IN kk);

static DWORD WINAPI UDP_ThreadProc1(void* pCtrl) ;
static DWORD WINAPI UDP_ThreadProc2(void* pCtrl) ;
//unsigned char Sendbuffer[300];
unsigned char Sendbuffer[1024];
HANDLE	sdv_hTerminate1= CreateEvent(NULL, TRUE, FALSE, NULL);
long __stdcall UDP_InitNet(/*u_short Port*/)
{
	WSADATA wsData;
	SOCKADDR_IN addrscoket;
	int retdate;
	WSAStartup(MAKEWORD(2,2),&wsData);
	sino_socket=socket(AF_INET,SOCK_DGRAM,0);
	if(INVALID_SOCKET==sino_socket)
	{
		return SDV_RESULT_SOCK_ERR;
	}
// 	connet_buf[0] = 0x77;
// 	connet_buf[1] = 0x77;
	connet_buf[0]=0xcc;
	connet_buf[1]=0xcc;
	bool opt=true;
	memset(Send_addr,0,sizeof(SOCKADDR_IN));
// 	addrscoket5.sin_addr.S_un.S_addr=inet_addr("192.168.1.191");
// 	addrscoket5.sin_family=AF_INET;
// 	addrscoket5.sin_port=htons(5000);
	//addrscoket.sin_addr.S_un.S_addr=
	addrscoket.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrscoket.sin_family=AF_INET;
	addrscoket.sin_port = htons(5050);
	setsockopt(sino_socket,SOL_SOCKET,SO_BROADCAST,(char FAR*)&opt,sizeof(opt));
	retdate=bind(sino_socket,(SOCKADDR*)&addrscoket,sizeof(SOCKADDR));
	if(retdate==SOCKET_ERROR)
	{
		closesocket(sino_socket);
		return SDV_RESULT_BIND_ERR;
	}
	return SDV_RESULT_OK;
}

long  __stdcall SetStreamHOOK(StreamProc lpStreamFun,void*pUserData)
{
	if (lpStreamFun==NULL)
	{
		return SDV_RESULT_HOOK_ERR;
	}
	gCallBack=lpStreamFun;
	pUserData1=pUserData;
	SetEvent(sdv_hTerminate1);
	sdv_hThread=CreateThread(NULL,0,UDP_ThreadProc1,NULL,0,NULL);
	sdv_hThread1=CreateThread(NULL,0,UDP_ThreadProc2,NULL,0,NULL);
	if (sdv_hThread==FALSE||sdv_hThread1==FALSE)
		return SDV_RESULT_THREAD_ERR;
	else
	{
		CloseHandle(sdv_hThread);
		return  SDV_RESULT_OK;

	}
}

DWORD WINAPI	UDP_ThreadProc1(void* pCtrl)
{

	SOCKET sock=sino_socket;
	int lengh=sizeof(SOCKADDR);
	int retval;
	UCHAR m_Ip;
	//DWORD        bytes; 
	UCHAR recvBuffer[1000];
	UCHAR mm_buf[1000]={0};
	int recvBufferLength=0;

	while(WaitForSingleObject(sdv_hTerminate1,INFINITE) == WAIT_OBJECT_0)
	{
		retval=recvfrom(sock,(char*)recvBuffer,1000, 0,(SOCKADDR*)&addrFrom,&lengh);
 		if ((recvBuffer[0]!=0xaa&&recvBuffer[0]!=0xcc)&&(recvBuffer[1]!=0xaa&&recvBuffer[1]!=0xcc))
 			continue;
		m_Ip=unsigned char((addrFrom.sin_addr.S_un.S_addr)>>24);
		//addrFrom.sin_port=htons(addrFrom.sin_port);
		//addrFrom.sin_addr.S_un.S_addr=htonl(addrFrom.sin_addr.S_un.S_addr);
		addrFrom1[m_Ip]=addrFrom;
		if(recvBuffer[0]==0xcc&&recvBuffer[1]==0xcc)
			continue;
		mm_buf[0]=m_Ip;

		mm_buf[1]=(recvBuffer[3]*4)&0xff;
		mm_buf[2]=((recvBuffer[3]*4)&0x0ff00)>>8;
		recvBufferLength = recvBuffer[3]*4;
		memcpy(&mm_buf[3],&recvBuffer[4],recvBufferLength);
		(*gCallBack)(mm_buf,pUserData1);
	}
		return FALSE;
}
#if 0
{

	SOCKET sock=sino_socket;
	int lengh=sizeof(SOCKADDR);
	int retval;
	UCHAR m_Ip;
	DWORD        bytes; 
	UCHAR recvBuffer[300];
	UCHAR mm_buf[300]={0};

	while(WaitForSingleObject(sdv_hTerminate1,INFINITE) == WAIT_OBJECT_0)
	{
		retval=recvfrom(sock,(char*)recvBuffer,300, 0,(SOCKADDR*)&addrFrom,&lengh);
 		if ((recvBuffer[0]!=0xaa&&recvBuffer[0]!=0xcc)&&(recvBuffer[1]!=0xaa&&recvBuffer[1]!=0xcc))
 			continue;
		m_Ip=unsigned char((addrFrom.sin_addr.S_un.S_addr)>>24);
		//addrFrom.sin_port=htons(addrFrom.sin_port);
		//addrFrom.sin_addr.S_un.S_addr=htonl(addrFrom.sin_addr.S_un.S_addr);
		addrFrom1[m_Ip]=addrFrom;
		if(recvBuffer[0]==0xcc&&recvBuffer[1]==0xcc)
			continue;
		mm_buf[0]=m_Ip;
		mm_buf[1]=(UCHAR)recvBuffer[3]*4;
		memcpy(&mm_buf[2],&recvBuffer[4],mm_buf[1]);
		(*gCallBack)(mm_buf,pUserData1);
	}
		return FALSE;
}
#endif

DWORD WINAPI	UDP_ThreadProc2(void* pCtrl)
{
	while(1)
	{
		for(int i=0;i<255;i++)
		{
			if (Send_addr[i].sin_addr.S_un.S_addr!=0)
			{
				int ret=sendto(sino_socket,connet_buf,2,0,(SOCKADDR*)&(Send_addr[i]),sizeof(SOCKADDR));

			}
			Sleep(10);
		}
		
		
	}
}
long __stdcall UDP_SendData(char*Buffer,unsigned int Length,unsigned char Ip_flg  )
{
	int Num;
	Sendbuffer[0]=0xaa;
	Sendbuffer[1]=0xaa;
	Sendbuffer[2]=(Length/4);
	Sendbuffer[3]=(Length/4);
	if (Buffer!=NULL)
	{
		memcpy(&Sendbuffer[4],Buffer,Length);
		Num=sendto(sino_socket,(char*)Sendbuffer,Length+4,0,(SOCKADDR*)&(addrFrom1[Ip_flg]),sizeof(SOCKADDR));
		if (Num<0)
		{
			return 0;
		}
		else
		return Num;
	}
	return 0;
}
#if 0
{
	int Num;
	Sendbuffer[0]=0xaa;
	Sendbuffer[1]=0xaa;
	Sendbuffer[2]=(Length/4);
	Sendbuffer[3]=(Length/4);
	if (Buffer!=NULL)
	{
		memcpy(&Sendbuffer[4],Buffer,Length);
		Num=sendto(sino_socket,(char*)Sendbuffer,Length+4,0,(SOCKADDR*)&(addrFrom1[Ip_flg]),sizeof(SOCKADDR));
		if (Num<0)
		{
			return 0;
		}
		else
		return Num;
	}
}
#endif

long __stdcall UDP_SetConnetIp(unsigned char Ip_connet )
{
	if (Ip_connet>0&&Ip_connet<255)
	{
		Send_addr[Ip_connet].sin_family=AF_INET;
		Send_addr[Ip_connet].sin_port=htons(5000);
		Send_addr[Ip_connet].sin_addr.S_un.S_addr=(Ip_connet<<24)|0x01a8c0;
		return SDV_RESULT_OK;
	}
	
	return SDV_RESULT_CMD_ERR;
}
