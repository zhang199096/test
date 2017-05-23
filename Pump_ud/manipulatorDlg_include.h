//file***************************************************************************************************
//                                                                                                       
//                                                                                                       
//        manipulatorDlg_include.h for  Master                  
//                                                                                                       
//                                                                                                       
//*******************************************************************************************************
//    Please refer to the following document for more detials.                                           
//       "\..\20141218ģ��ͨѶЭ��.pdf "                
//       "\..\motionconrtol_Interface ����˵��_CN.pdf"                        
//       "\..\�Զ�ģʽ��������ͨѶ�������������_CN.pdf"                   
//                                                                                                       
//******* Copyright(C) 2015 GIBH ******************************************************************
//                                                                                                       
//      Ver 1.00    2015.01.14   Initial coding                                            Enjoy_Lu     
//*******************************************************************************************************

#ifndef __manipulatorDlg_include_h_
#define __manipulatorDlg_include_h_



//#include "stdafx.h"
// #include "manipulatorDlg.h"
// #include "manipulator.h"
#include "afxwin.h"
#include "Common.h"
#include "afxdialogex.h"

// #include "DIAControl_MainInterface.h"
// 
// #include "..//MotionControl//Clone_Linear//DIAparameter_Clone_Linear.h"
// #include "..//MotionControl//Clone_Optical//DIAparameter_Clone_Optical.h"
// #include "..//MotionControl//PlateEmpty_Destination//DIAparameter_PlateEmpty_Destination.h"
// #include "..//MotionControl//PlateWaste_Source//DIAparameter_PlateWaste_Source.h"
// #include "..//MotionControl//PlateTransfering//DIAparameter_PlateTransfering.h"
// 
// #include "..//MotionControl//Clone_Linear//DIAControl_Clone_Linear.h"
// #include "..//MotionControl//Clone_Optical//DIAControl_Clone_Optical.h"
// #include "..//MotionControl//PlateEmpty_Destination//DIAControl_PlateEmpty_Destination.h"
// #include "..//MotionControl//PlateWaste_Source//DIAControl_PlateWaste_Source.h"
// #include "..//MotionControl//PlateTransfering//DIAControl_PlateTransfering.h"
// 
// #include "..//MotionControl//Clone_Linear//DIACoordinate_Clone_Linear.h"
// #include "..//MotionControl//Clone_Optical//DIACoordinate_Clone_Optical.h"
// #include "..//MotionControl//PlateEmpty_Destination//DIACoordinate_PlateEmpty_Destination.h"
// #include "..//MotionControl//PlateWaste_Source//DIACoordinate_PlateWaste_Source.h"
// #include "..//MotionControl//PlateTransfering//DIACoordinate_PlateTransfering.h"
// 
// #include "..//MotionControl//UDP_Rerro.h"
// #include "..//MotionControl//UDP_Export.h"
#include <stdio.h>
#include "math.h"
#include "UDP_Rerro.h"
#include "UDP_Export.h"
#include "Common.h"
#include "DIA_CtrlPump.h"
#include "DIA_UDP.h"

extern DIA_CtrlPump m_CtrlPump;
extern DIA_UDP m_UDP;
// extern DIAControl_MainInterface m_Control_MainInterface;
// 
// extern DIAparameter_Clone_Linear m_parameter_Clone_Linear;
// extern DIAparameter_Clone_Optical m_parameter_Clone_Optical;
// extern DIAparameter_PlateEmpty_Destination m_parameter_PlateEmpty_Destination;
// extern DIAparameter_PlateWaste_Source m_parameter_PlateWaste_Source;
// extern DIAparameter_PlateTransfering m_parameter_PlateTransfering;
// 
// extern DIAControl_Clone_Linear m_Control_Clone_Linear;
// extern DIAControl_Clone_Optical m_Control_Clone_Optical;
// extern DIAControl_PlateEmpty_Destination m_Control_PlateEmpty_Destination;
// extern DIAControl_PlateWaste_Source m_Control_PlateWaste_Source;
// extern DIAControl_PlateTransfering m_Control_PlateTransfering;
// 
// extern DIACoordinate_Clone_Linear m_Coordinate_Clone_Linear;
// extern DIACoordinate_Clone_Optical m_Coordinate_Clone_Optical;
// extern DIACoordinate_PlateEmpty_Destination m_Coordinate_PlateEmpty_Destination;
// extern DIACoordinate_PlateWaste_Source m_Coordinate_PlateWaste_Source;
// extern DIACoordinate_PlateTransfering m_Coordinate_PlateTransfering;

extern HOMING			Homing;	
extern OVERALLSIGN		OverallSign;		// �����־
extern SYSTEM			System;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main;			//�����ṹ����
extern AREA_CONTROL	NC_AREAControl;
extern SELECTPOSITION Incubator_Position;

extern HOMING			Homing_Clone_Linear;	
extern OVERALLSIGN		OverallSign_Clone_Linear;		// �����־
extern SYSTEM			System_Clone_Linear;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_Clone_Linear;			//�����ṹ����
extern AREA_CONTROL		NC_AREAControl_Clone_Linear;
extern SELECTPOSITION Position_Clone_Linear;

extern HOMING			Homing_Clone_Optical;	
extern OVERALLSIGN		OverallSign_Clone_Optical;		// �����־
extern SYSTEM			System_Clone_Optical;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_Clone_Optical;			//�����ṹ����
extern AREA_CONTROL		NC_AREAControl_Clone_Optical;
extern SELECTPOSITION Position_Clone_Optical;

extern HOMING			Homing_PlateEmpty_Destination;	
extern OVERALLSIGN		OverallSign_PlateEmpty_Destination;		// �����־
extern SYSTEM			System_PlateEmpty_Destination;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateEmpty_Destination;			//�����ṹ����
extern AREA_CONTROL		NC_AREAControl_PlateEmpty_Destination;
extern SELECTPOSITION Position_PlateEmpty_Destination;

extern HOMING			Homing_PlateWaste_Source;	
extern OVERALLSIGN		OverallSign_PlateWaste_Source;		// �����־
extern SYSTEM			System_PlateWaste_Source;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateWaste_Source;			//�����ṹ����
extern AREA_CONTROL		NC_AREAControl_PlateWaste_Source;
extern SELECTPOSITION Position_PlateWaste_Source;

extern HOMING			Homing_PlateTransfering;	
extern OVERALLSIGN		OverallSign_PlateTransfering;		// �����־
extern SYSTEM			System_PlateTransfering;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateTransfering;			//�����ṹ����
extern AREA_CONTROL		NC_AREAControl_PlateTransfering;
extern SELECTPOSITION Position_PlateTransfering;

extern DOUBLEJOINTS ABS_COORDINATE_Clone_Linear; //绝对坐标
extern DOUBLEJOINTS MACH_COORDINATE_Clone_Linear; //编码器坐�?
extern DOUBLEJOINTS ABS_COORDINATE_Clone_Optical; //��������
extern DOUBLEJOINTS MACH_COORDINATE_Clone_Optical; //����������
extern DOUBLEJOINTS ABS_COORDINATE_PlateEmpty_Destination; //��������
extern DOUBLEJOINTS MACH_COORDINATE_PlateEmpty_Destination; //����������
extern DOUBLEJOINTS ABS_COORDINATE_PlateWaste_Source; //��������
extern DOUBLEJOINTS MACH_COORDINATE_PlateWaste_Source; //����������
extern DOUBLEJOINTS ABS_COORDINATE_PlateTransfering; //��������
extern DOUBLEJOINTS MACH_COORDINATE_PlateTransfering; //����������

extern union IO_OUT_REG 		CPLD_IO_OutRegister_Clone_Linear;
extern union IO_IN_REG			CPLD_IO_InRegister_Clone_Linear;
extern union SERVO_IO_IN_REG 	FPGA_SERVO_IO_InRegister_Clone_Linear;

extern union IO_OUT_REG 		CPLD_IO_OutRegister_Clone_Optical;
extern union IO_IN_REG			CPLD_IO_InRegister_Clone_Optical;
extern union SERVO_IO_IN_REG 	FPGA_SERVO_IO_InRegister_Clone_Optical;

extern union IO_OUT_REG 		CPLD_IO_OutRegister_PlateEmpty_Destination;
extern union IO_IN_REG			CPLD_IO_InRegister_PlateEmpty_Destination;
extern union SERVO_IO_IN_REG 	FPGA_SERVO_IO_InRegister_PlateEmpty_Destination;

extern union IO_OUT_REG 		CPLD_IO_OutRegister_PlateWaste_Source;
extern union IO_IN_REG			CPLD_IO_InRegister_PlateWaste_Source;
extern union SERVO_IO_IN_REG 	FPGA_SERVO_IO_InRegister_PlateWaste_Source;

extern union IO_OUT_REG 		CPLD_IO_OutRegister_PlateTransfering;
extern union IO_IN_REG			CPLD_IO_InRegister_PlateTransfering;
extern union SERVO_IO_IN_REG 	FPGA_SERVO_IO_InRegister_PlateTransfering;

extern union MAINCOMMANDSIGN_REG MainCommand_Register_Clone_Linear;
extern union MAINCOMMANDSIGN_REG MainCommand_Register_Clone_Optical;
extern union MAINCOMMANDSIGN_REG MainCommand_Register_PlateEmpty_Destination;
extern union MAINCOMMANDSIGN_REG MainCommand_Register_PlateWaste_Source;
extern union MAINCOMMANDSIGN_REG MainCommand_Register_PlateTransfering;

extern union MAINCOMMANDSIGN_REG Output_Register_Clone_Linear;
extern union MAINCOMMANDSIGN_REG Output_Register_Clone_Optical;
extern union MAINCOMMANDSIGN_REG Output_Register_PlateEmpty_Destination;
extern union MAINCOMMANDSIGN_REG Output_Register_PlateWaste_Source;
extern union MAINCOMMANDSIGN_REG Output_Register_PlateTransfering;

extern union MAINCOMMANDSIGN_REG Input_Register_Clone_Linear;
extern union MAINCOMMANDSIGN_REG Input_Register_Clone_Optical;
extern union MAINCOMMANDSIGN_REG Input_Register_PlateEmpty_Destination;
extern union MAINCOMMANDSIGN_REG Input_Register_PlateWaste_Source;
extern union MAINCOMMANDSIGN_REG Input_Register_PlateTransfering;

extern union MAINSTATUSSIGN_REG MainStatus_Register_Clone_Linear;
extern union MAINSTATUSSIGN_REG MainStatus_Register_Clone_Optical;
extern union MAINSTATUSSIGN_REG MainStatus_Register_PlateEmpty_Destination;
extern union MAINSTATUSSIGN_REG MainStatus_Register_PlateWaste_Source;
extern union MAINSTATUSSIGN_REG MainStatus_Register_PlateTransfering;

extern union MAINSTATUSSIGN_REG MainStatus_Exsit_PlateEmpty_Destination_Plate;
extern union MAINSTATUSSIGN_REG MainStatus_Exsit_PlateEmpty_Destination_Frame;
extern union MAINSTATUSSIGN_REG MainStatus_Exsit_PlateWaste_Source_Plate;
extern union MAINSTATUSSIGN_REG MainStatus_Exsit_PlateWaste_Source_Frame;

extern Uint32	MonitorBuffer1Cnt,MonitorBuffer2Cnt,MonitorBuffer3Cnt,MonitorBuffer4Cnt;

extern CString str_Information_Clone_Linear;
extern CString str_Information_Clone_Optical;
extern CString str_Information_PlateEmpty_Destination;
extern CString str_Information_PlateWaste_Source;
extern CString str_Information_PlateTransfering;
#endif

