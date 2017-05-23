//file***************************************************************************************************
//                                                                                                       
//                                                                                                       
//        UDP_Export.h for  Master                  
//                                                                                                       
//                                                                                                       
//*******************************************************************************************************
//               For UDP Communication (PC<=>DSP)                                                                                        
//******* Copyright(C) 2015 GIBH ******************************************************************
//                                                                                                       
//      Ver 1.00    2015.01.14   Initial coding                                            Enjoy_Lu     
//*******************************************************************************************************

#include "UDP_Rerro.h"  //add by zz
// #if defined( __cplusplus )
// extern "C" {
// #endif
// 
// #ifdef UDP_EXPORTS
// #define SDV_API extern  __declspec(dllexport)
// #else
// #define SDV_API extern  __declspec(dllimport)
// #endif
	/*SDV_API*/  long __stdcall UDP_InitNet(/*u_short Port*/);
	/*SDV_API*/	 long __stdcall UDP_SetConnetIp(unsigned char Ip_connet );
	/*SDV_API  long __stdcall UDP_SendData(char*Buffer,unsigned char Length,unsigned char Ip_flg );*/
	/*SDV_API*/  long __stdcall UDP_SendData(char*Buffer,unsigned int Length,unsigned char Ip_flg );
	/*SDV_API */ long __stdcall SetStreamHOOK(StreamProc lpStreamFun,void*pUserData);

// #if defined( __cplusplus )
// }
/*#endif*/
