//file***************************************************************************************************
//                                                                                                       
//                                                                                                       
//        DIAserial.h for  Master                  
//                                                                                                       
//                                                                                                       
//*******************************************************************************************************
//				Just For Test
//******* Copyright(C) 2015 GIBH ******************************************************************
//                                                                                                       
//      Ver 1.00    2015.01.14   Initial coding                                            Enjoy_Lu     
//*******************************************************************************************************

#pragma once


#define RESERVE       0
#define RUN           1
#define REFERENCE     2
#define JOG           3
#define SIMULATION    4
#define IDLE          5
#define STOP          6
#define OTHER         7
#define SERVOCONTROL  8
#define MOTION_Machine 9
#define MOTION_ABS	  10
#define DSPPRAMETER_WRITE         11
#define PCPRAMETER_WRITE         12
#define INCUBATOR_POSITION		13
#define PLATEMPTY_DESTINATION_POSITION		13
#define PLATEWASTE_SOURCE_POSITION		13
#define CLONE_LINEAR_POSITION		13

#define NOCODERUN		0
#define STDCODERUN		1
#define SPCCODERUN		2

#define  	RealTimeRun				0				// 实时运行
#define  	SimulateRun				1				// 仿真运行

#define		OPEN					1
#define		CLOSE					0

#define		ThreeAxis			0				//三轴
#define		FourAxis			1				//四轴
#define		FiveAxis			2				//五轴

#define		TRUE					1
#define		OK						1
#define		COMPLETE				1	
#define		FALSE					0
#define		NOT_COMPLETE				0

#define  	REF_XYZ			0	//坐标系为3 坐标
#define  	REF_XYZA		1	//坐标系为3+A 坐标
#define  	REF_XYZB		2	//坐标系为3+B 坐标
#define  	REF_XYZC		3	//坐标系为3+C 坐标

#define	StepZero		0		//步骤0
#define	StepOne			1		//步骤1
#define	StepTwo			2		//步骤2
#define	StepThree		3		//步骤3

#define	ImageDataBuff_MOD		1000	

#define 	STDGCODE_MOD			40000
#define 	SPCGCODE_MOD			11
#define	DSPGCODEPACKET_MOD	40

#define	PlateShelfStationTotalNumber	10

//#define	CameraScanStepperTotalNumber_X	160
#define	CameraScanNoStepperTotalNumber_X	1
#define	CameraScanStepperTotalNumber_X	16
//#define	CameraScanStepperTotalNumber_X	5

//#define	CameraScanStepperTotalNumber_Y	100
//#define	CameraScanStepperTotalNumber_Y	15
#define	CameraScanStepperTotalNumber_Y	10
//#define	CameraScanStepperTotalNumber_Y	4


#define CameraModle_Software 0
#define CameraModle_External 1


typedef unsigned char    Uint8;
typedef unsigned short   Uint16;
typedef unsigned int     Uint32;
typedef unsigned long    Uint40;
typedef char             Int8;
typedef short            Int16;
typedef int              Int32;
typedef long             Int40;
typedef float           float32;
typedef double	     	float64;


typedef struct
{
	Int32 X;
	Int32 Y;
	Int32 Z;
	Int32 A;
	Int32 B;
	Int32 C;
}INT40AXIS;     

typedef struct
{
	Uint32 X;
	Uint32 Y;
	Uint32 Z;
	Uint32 A;
	Uint32 B;
	Uint32 C;
}UINT40AXIS;     

typedef struct
{
	Uint16 X;
	Uint16 Y;
	Uint16 Z;
	Uint16 A;
	Uint16 B;
	Uint16 C;
}UINT16AXIS;     

typedef struct
{
	Int16 X;
	Int16 Y;
	Int16 Z;
	Int16 A;
	Int16 B;
	Int16 C;
}INT16AXIS;     

typedef struct
{
	Uint8 X;
	Uint8 Y;
	Uint8 Z;
	Uint8 A;
	Uint8 B;
	Uint8 C;
}UINT8AXIS;   

typedef struct
{
	float64 X;
	float64 Y;
	float64 Z;
	float64 A;
	float64 B;
	float64 C;
}float64AXIS;     

typedef struct
{
	float64 X;
	float64 Y;
	float64 Z;	
	float64 A;
	float64 B;
	float64 C;
}VECTOR;     //所定义都为单位矢量


typedef struct
{
	Uint16		SearchRefSign;			// 要求搜索参考点标志
	Uint16		RefStep;				//参考点搜索步骤
	UINT16AXIS	NeedFindAxisSign;		// 需要搜索轴的标志
	UINT16AXIS	FindRefSign;			// 已找到某轴参考点标志
	Uint16		PreSearchRefSign;		// 搜索参考点前初始化标志
	Uint16      Findzero;               //寻找到零点标志added by mendy 2011/6/20
	Uint16 		getzero;				//用于记录零点坐标added by mendy 2011/6/21
}HOMING;


typedef struct
{
	float X;
	float Y;
	float Z;
	float A;
	float B;
	float C;
}DOUBLEJOINTS; 

typedef struct
{
	int X;
	int Y;
	int Z;
	int A;
	int B;
	int C;
}INTJOINTS; 

struct  SERVO_IO_IN_BITS 
{     // bits   description
	Uint32 XALM:1;				//BIT0: X_ALARM	 		1:VALID ALM
	Uint32 YALM:1;				//BIT1: Y_ALARM			1:VALID ALM
	Uint32 ZALM:1;				//BIT2: Z_ALARM			1:VALID ALM
	Uint32 AALM:1;				//BIT3: A_ALARM			1:VALID ALM
	Uint32 BALM:1;				//BIT4: B_ALARM			1:VALID ALM
	Uint32 UALM:1;				//BIT4: U_ALARM			1:VALID ALM
	Uint32 XCOIN:1;				//BIT0: X_COIN	 		1:VALID
	Uint32 YCOIN:1;				//BIT1: Y_COIN			1:VALID
	Uint32 ZCOIN:1;				//BIT2: Z_COIN			1:VALID
	Uint32 ACOIN:1;				//BIT3: A_COIN			1:VALID
	Uint32 BCOIN:1;				//BIT4: B_COIN			1:VALID
	Uint32 UCOIN:1;				//BIT4: U_COIN			1:VALID
	Uint32 XPOS:1;				//BIT0: X_POS_LIMIT	 	1:VALID
	Uint32 YPOS:1;				//BIT0: Y_POS_LIMIT	 	1:VALID
	Uint32 ZPOS:1;				//BIT0: Z_POS_LIMIT	 	1:VALID
	Uint32 APOS:1;				//BIT0: A_POS_LIMIT	 	1:VALID
	Uint32 BPOS:1;				//BIT0: B_POS_LIMIT	 	1:VALID
	Uint32 UPOS:1;				//BIT0: U_POS_LIMIT	 	1:VALID
	Uint32 XNEG:1;				//BIT0: X_NEG_LIMIT	 	1:VALID
	//Uint32 YNEG:1;				//BIT0: Y_NEG_LIMIT	 	1:VALID
	Uint32 BNEG:1;				//BIT0: B_NEG_LIMIT	 	1:VALID
	Uint32 ZNEG:1;				//BIT0: Z_NEG_LIMIT	 	1:VALID
	Uint32 ANEG:1;				//BIT0: A_NEG_LIMIT	 	1:VALID	
	//Uint32 BNEG:1;				//BIT0: B_NEG_LIMIT	 	1:VALID
	Uint32 YNEG:1;				//BIT0: Y_NEG_LIMIT	 	1:VALID
	Uint32 UNEG:1;				//BIT0: U_NEG_LIMIT	 	1:VALID

	Uint32 SXPOS:1;				//BIT0: X_POS_LIMIT	 	1:VALID
	Uint32 SYPOS:1;				//BIT0: Y_POS_LIMIT	 	1:VALID
	Uint32 SZPOS:1;				//BIT0: Z_POS_LIMIT	 	1:VALID
	Uint32 SAPOS:1;				//BIT0: A_POS_LIMIT	 	1:VALID
	Uint32 SXNEG:1;				//BIT0: X_NEG_LIMIT	 	1:VALID
	Uint32 SYNEG:1;				//BIT0: Y_NEG_LIMIT	 	1:VALID
	Uint32 SZNEG:1;				//BIT0: Z_NEG_LIMIT	 	1:VALID
	Uint32 SANEG:1;				//BIT0: A_NEG_LIMIT	 	1:VALID	
};

union SERVO_IO_IN_REG {
   Uint32               all;
   struct SERVO_IO_IN_BITS  bit;
};


struct  IO_OUT_BITS 
{   
	Uint16  OUT1:1;          
	Uint16  OUT2:1;	       
	Uint16  OUT3:1;	           
	Uint16  OUT4:1;	           
	Uint16  OUT5:1;	           
	Uint16  OUT6:1;			   
	Uint16  OUT7:1;			   
	Uint16  OUT8:1;	
	Uint16  OUT9:1;          
	Uint16  OUT10:1;	       
	Uint16  OUT11:1;	           
	Uint16  OUT12:1;	           
	Uint16  OUT13:1;	           
	Uint16  OUT14:1;			   
	Uint16  OUT15:1;			   
	Uint16  OUT16:1;	
};

union IO_OUT_REG {
   Uint16               all;
   struct IO_OUT_BITS  bit;
};

struct  IO_IN_BITS 
{     // bits   description
	Uint16 IN1:1;	
	Uint16 IN2:1;	
	Uint16 IN3:1;	
	Uint16 IN4:1;	
	Uint16 IN5:1;	
	Uint16 IN6:1;	
	Uint16 IN7:1;	
	Uint16 IN8:1;
	Uint16 IN9:1;
	Uint16 IN10:1;
	Uint16 IN11:1;	
	Uint16 IN12:1;	
	Uint16 IN13:1;	
	Uint16 IN14:1;	
	Uint16 IN15:1;	
	Uint16 IN16:1;
};
union IO_IN_REG {
   Uint16         all;
   struct IO_IN_BITS  bit;
};

extern union IO_OUT_REG 	CPLD_IO_OutRegister;
extern union IO_IN_REG		CPLD_IO_InRegister;

typedef struct
{
	//区域相关变量
	float64	Stotal;							//区域内所有代码总运行长度 mm
	float64 Snow;							//从区域起点代码到当前代码当前插补点总运行长度 mm  
	float64 DeltaSnow;						//从当前代码起点到当前代码当前插补点总运行长度 mm  
	
	Uint32	I;					//插补序号 [1,+无穷)
	Uint32 	TotalN;				//总插补数	TotalN=T5/Tsample
	float64	Vs;					//当前运行G代码起点运行速度. (mm/s)
	float64	Vm;					// 当前运行G代码设定运行速度. (mm/s)
	float64	VmReal;				// 当前运行G代码实际最高运行速度. (mm/s)
	float64	Ve;					// 当前运行G代码终点运行速度. (mm/s)
	float64 VNow;				// 当前实际运行速度. (mm/s)
	float64	Sac;				//当前代码加速过程所需距离(mm)
	float64	Sm;					//当前代码稳速过程所需距离(mm)
	float64	Sde;				//当前代码减速过程所需距离(mm)

	float64	T1;					//从A到B所用时间	s
	float64	T2;					//从A到C所用时间	s
	float64	T3;					//从A到D所用时间	s
	float64	T4;					//从A到E所用时间	s
	float64	T5;					//从A到F所用时间	s

	float64	DeltaT1;			//AB所用时间	s
	float64	DeltaT2;			//BC所用时间	s
	float64	DeltaT3;			//CD所用时间	s
	float64	DeltaT4;			//DE所用时间	s
	float64	DeltaT5;			//EF所用时间	s
	
	float64	a_ac;				// 实际加速段加速度		
	float64	a_de;				// 实际减速段加速度
}AREA_CONTROL;

typedef struct
{	
	int		A4_Model;						//A4 轴模型选择0-无效1-A 2-B 3-C
	int		VeerDeltaT; 				//DSPb0-38转向过程时间常数 （单位：s）    设定范围[1,255]ms 传输对应[1-255]
	int 	a_SET;						//P149根据速度重计算运动平台加速度 单位：mm/s.s
	int		G0Speed;
	int 	G0FeedRate1;
	int 	G0FeedRate2;
	int 	G0FeedRate3;

	int 		SRefSpeed;						//P153 			参考点正向搜索速度，单位:mm/s
	int 		SRefSpeedBack;					//P154 			参考点返回速度，单位:mm/s
	int 			SRefBack;						//P153			参考点返回距离，单位:最小输入单位
	UINT40AXIS		REFPosition;
	UINT40AXIS		EncoderDIR;
	UINT40AXIS 		MotorChangeDir;//切换电机方向
	UINT40AXIS		EncoderCheckChoose;		//P000-P005监测轴光栅尺标志	
	int		Tsample;				//P020单位：s   设定插补周期 [0.1,10]ms ,传输对应[1,100]
	UINT40AXIS	MAXSpeed;				//P021-P023各轴最大移动速度 单位:mm/s	 or degree/s
	int		VeerDeltaV;				//DSPb0-32拐点单轴变化速度(unit:mm/s)  设定范围[1,25.5] 传输对应[1-255] 

	UINT40AXIS	Gap;						//P137-P142 轴间隙值,单位: 最小输入单位

	//P120-P125
	Uint32 		LinearAxisMinUnit;			//线性轴最小输入单位(单位：nm)
	Uint32		RotaryAxisMinUnit;			//旋转轴最小输入单位(单位：nd)
	Uint32		LinearAxisOutUnitEQU;		//线性轴输出指令单位当量(单位：nm/指令单位)
	Uint32		RotaryAxisOutUnitEQU;		//旋转轴输出指令单位当量(单位：nd/指令单位)
	float64 		UnitTo_mm;					//线性轴位置单位换算成mm   单位:  mm/unit
	float64 		UnitTo_d;					//旋转轴位置单位换算成d	    单位:  d/unit

	UINT40AXIS	AxisCompMaxL;				//P126-P130非线性补偿数组最长值 [0-280]	
	UINT40AXIS Resolution;					//各轴分辨率设置

	INT40AXIS	Limit_Pos;
	INT40AXIS Limit_Neg;


	int 		a_A4_SET;			 			//P165			设定A4 轴运动平台加速度 单位：degree/s.s      
	int 		A4SRefSpeed;					 //P170
	int 		A4SRefSpeedBack;				//p171
	int 		A4SRefBack;						//p172
	int			A4_G0Speed;					//P173			A4 轴G0速度 degree/s

	Uint32		BarCodeSign;
	Uint32		Sensor1Sign;
	Uint32		Sensor2Sign;
	Uint32		Sensor3Sign;
	Uint32		Sensor4Sign;
	Uint32		Sensor5Sign;
	Uint32		Sensor6Sign;
	Uint32		Sensor7Sign;
	Uint32		Sensor8Sign;
	

	INT40AXIS PositionCoordinate1; 
	INT40AXIS PositionCoordinate2; 
	INT40AXIS PositionCoordinate3; 
	INT40AXIS PositionCoordinate4; 
	INT40AXIS PositionCoordinate5; 
	INT40AXIS PositionCoordinate6; 
	INT40AXIS PositionCoordinate7; 
	INT40AXIS PositionCoordinate8; 
	INT40AXIS PositionCoordinate9; 
	INT40AXIS PositionCoordinate10; 

	INT40AXIS SafeCoordinate;
	INT40AXIS BackCoordinate;
	INT40AXIS OffsetCoordinate;


	
	//机床配置
	//0:3轴
	//1:4轴
	short			MachineConfiguration;				
	short			ReferenceFrameMode;				//坐标系模型
}SYSTEM;	//系统参数结构组

typedef struct
{
	Uint32 		SendCount;			//DSP当前运行原代码位置指针，返回给ARM用于显示及其它用途
	Uint32 		CMD1,CMD2;			//命令字,确定G代码类型
	INT40AXIS	StartPoint;			//起点. 单位：线性轴最小输入单位
	INT40AXIS	EndPoint;			//终点.  单位：线性轴最小输入单位
	float64 	Feedrate;			//进给速度,单位:mm/s
	Int16 		AxisMotionStyle;	//0：A4轴不运行，1：A4轴运行。3:单段加线第三步IV轴单独运行；4:IV轴单独SPC	
	Uint32		HoldTime;		    //GO4 Hold Time
}GCODE;


typedef struct
{
	Uint16 				NCSign;  	// 0:通常状态  1:标准代码；2:特殊代码-JOG HANDLE REF；INI=0
	Uint16 				NCSign_bak;  	// 0:通常状态  1:标准代码；2:特殊代码-JOG HANDLE REF；INI=0

	//速度控制相关参数
	Uint16				EveryAxisCoinValid;			// 各轴COIN 都有效标志
	Uint16				EveryAxisOverValid;			// 各轴OVER 都有效标志
	Uint8				FeedrateOverride;			//进给档位	[0-20]
	Uint16				XYZ_Over;               			// 1--完成当前G代码XYZ轴运行                                   
	float64    				F;						//G代码设定进给速度  (mm/s)
	Int32				FG0;					//G0代码设定进给速度 (mm/s)
	float64   				FG0_A4;						//A4轴G0代码设定进给速度 (mm/s)

	// 坐标跟踪相关参数
	INT40AXIS			ABS_Coordinate;				// 当前绝对坐标值unit:最小输入单位
	INT40AXIS			ABSORG_M_Coordinate;		// 当前绝对坐标原点的机床坐标值unit:最小输入单位
	Uint16				LastCodeOverSign;			//最后一条代码走完标志  1－走完
	UINT16AXIS			SearchRefMoveSign;			//参考点查找方向。1：负向；2：正向

	//相关标志位	
	Uint8				Initial_STDSign;				//标志代码运行初始化标志
	Uint8				Initial_SPCSign;				//手动、点动运行初始化标志
	Uint16 				GetPositionSign;				//1--已获得稳定反馈坐标值标志
	Uint16 				NeedGetPositionSign;				//1--需获得稳定反馈坐标值标志
	Uint8 				NeedP2PRunSign;			//点到点(机床/绝对坐标定位)运行标志
	Uint8 				P2PRunCompleteSign;		//点到点(机床/绝对坐标定位)运行完成标志

	Uint8 				NeedParameterWriteSign;		//参数写入标志
	Uint8 				ParameterWriteCompleteSign;//参数写入完成标志

	Uint8 				NeedMicroEDataBaseSendSign;		
	Uint8 				MicroEDataBaseSendCompleteSign;

	//运动相关状态
	Uint8				ServoOn;
	int 					m_OperationMode;
	int 					m_OperationMode_bak;
	Uint8 				JOGAxisSelect;

	//通信相关状态
	bool 				PC_DSP_COM_OK;//false:停止; true:运行
	bool 				m_ReciveSuccess;
	int 					m_ReciveSuccessCounter;
	int 					m_ReciveLostCounter;
	int 					receivecount;
	int					sendcount;

	Uint8				CanSendCodeSign;	//上位端可以发送代码标志
	Uint32 				NeedSendCount;		//ARM需要发送代码条数
	Uint32				STDSendCount;		//ARM/PC发送标志代码位置指针
	Uint32				SPCSendCount;		//ARM/PC发送手动、点动代码位置指针
	Uint32				LastSendCount;		//暂存ARM实际发送代码位置指针
	//下位反馈接收条
	Uint32				STDReceiveDSPRunCount;//
	Uint32				SPCReceiveDSPRunCount;
	Uint32				STDReceiveDSPSendCount;
	Uint32				SPCReceiveDSPSendCount;	

	Uint8				LensStationNumber;

	Uint32				CaptureDataBuffCnt;
	Uint32				ConvertMon16DataBuffCnt;
	Uint32				ConvertImageDataToMatBuffCnt;
	Uint32				cvImageCopyBuffCnt;
	Uint32				cvImageSaveBuffCnt;
	Uint32				cvImageDisplayBuffCnt;
	Uint32				SaveCharDataBuffCnt;
	Uint32				ReadCharDataBuffCnt;
	Uint32				GetCharDataBuffCnt;
	Uint8				CameraTriggerMode;

	Uint8				CameraScanSign;
	Uint8				CameraStaticCaptureSign;
	Uint8				MicroEScanSign;
	Uint8				CameraSoftTriggerLedFlashSign;

	Uint32				MicroEDataBaseStartCnt;
	Uint32				MicroEDataBaseEndCnt;
	Uint32				MicroEDataBaseTotalCnt;
	Uint32				MicroEDataBaseStartCnt_DSP;
}OVERALLSIGN;

typedef struct
{
UINT16AXIS		EncoderError;				// 轴光栅尺报警   1--报警

	Uint16 		NCCodeBreak;				//ARM发送G代码不连续	
	Uint16 		RAMCodeCheckError;			//运行缓冲区G代码校验报警
	Uint16 		InterpolationOver;			//插补量超5mm报警
	Uint16 		TrackRunOutError;			//轨迹偏离报警
	Uint32 		RealRunCount;				//已截取错误数据运行条数
	
	Uint16 		SCIBComError;			// 主轴板与DSP 通讯报警	CH20090828
	
	Uint16 		InsideRAMCheckError;		// 内部RAM 校验错误
	Uint16 		OutsideRAMCheckError;		// 外部RAM 校验错误
	Uint16 		CompDataCheckError;			// 非线性补偿数据校验错误	
	Uint16 		A4RunLockError;					// A4 轴运行时锁紧报警
	Uint16 		A4StopUnlockError;				// A4 轴停止时松开报警
	
	Uint16 		MainErrorSign;				//总错误标志
	UINT16AXIS ServoAlarm;							//伺服报警		1:报警有效
}ERROR_Main;					//报警结构组


typedef struct
{
	Uint8	NeedSelectPositionSign;
	Uint8	CompleteSelectPositionSign;	
	Uint32 	Object1SelectNumber;
	Uint32 	Object2SelectNumber;
	Uint8 	Object1SelectNumber_bak;
	Uint8	NeedSelectBackSign;	
	Uint8	CompleteSelectBackSign;
	
	Uint16	SelectPositionStep;
	
	Uint8	NeedShelfScanSign;	
	Uint8	NeedPalletOutSign;
	Uint8	NeedPalletInSign;
	Uint8	NeedPlateStandbySign;
	Uint8	NeedPlateBackSign;
	Uint8	NeedPlateDragOutShelfSign;
	Uint8	NeedPlateDragBackShelfSign;
	Uint8	NeedFrameDragOutShelfSign;
	Uint8	NeedFrameDragBackShelfSign;

}SELECTPOSITION;

struct  MAINCOMMANDSIGN_BITS 
{     // bits   description
	Uint16 SIGN1:1;	
	Uint16 SIGN2:1;	
	Uint16 SIGN3:1;	
	Uint16 SIGN4:1;	
	Uint16 SIGN5:1;	
	Uint16 SIGN6:1;	
	Uint16 SIGN7:1;	
	Uint16 SIGN8:1;
	Uint16 SIGN9:1;
	Uint16 SIGN10:1;
	Uint16 SIGN11:1;	
	Uint16 SIGN12:1;	
	Uint16 SIGN13:1;	
	Uint16 SIGN14:1;	
	Uint16 SIGN15:1;	
	Uint16 SIGN16:1;
	Uint16 SIGN17:1;	
	Uint16 SIGN18:1;	
	Uint16 SIGN19:1;	
	Uint16 SIGN20:1;	
	Uint16 SIGN21:1;	
	Uint16 SIGN22:1;	
	Uint16 SIGN23:1;	
	Uint16 SIGN24:1;
	Uint16 SIGN25:1;
	Uint16 SIGN26:1;
	Uint16 SIGN27:1;	
	Uint16 SIGN28:1;	
	Uint16 SIGN29:1;	
	Uint16 SIGN30:1;	
	Uint16 SIGN31:1;	
	Uint16 SIGN32:1;
};
union MAINCOMMANDSIGN_REG {
   Uint16         all;
   struct MAINCOMMANDSIGN_BITS bit;
};

struct  MAINSTATUSSIGN_BITS 
{     // bits   description
	Uint16 SIGN1:1;	
	Uint16 SIGN2:1;	
	Uint16 SIGN3:1;	
	Uint16 SIGN4:1;	
	Uint16 SIGN5:1;	
	Uint16 SIGN6:1;	
	Uint16 SIGN7:1;	
	Uint16 SIGN8:1;
	Uint16 SIGN9:1;
	Uint16 SIGN10:1;
	Uint16 SIGN11:1;	
	Uint16 SIGN12:1;	
	Uint16 SIGN13:1;	
	Uint16 SIGN14:1;	
	Uint16 SIGN15:1;	
	Uint16 SIGN16:1;
	Uint16 SIGN17:1;	
	Uint16 SIGN18:1;	
	Uint16 SIGN19:1;	
	Uint16 SIGN20:1;	
	Uint16 SIGN21:1;	
	Uint16 SIGN22:1;	
	Uint16 SIGN23:1;	
	Uint16 SIGN24:1;
	Uint16 SIGN25:1;
	Uint16 SIGN26:1;
	Uint16 SIGN27:1;	
	Uint16 SIGN28:1;	
	Uint16 SIGN29:1;	
	Uint16 SIGN30:1;	
	Uint16 SIGN31:1;	
	Uint16 SIGN32:1;
};
union MAINSTATUSSIGN_REG {
   Uint16         all;
   struct MAINSTATUSSIGN_BITS bit;
};

extern HOMING			Homing;	
extern OVERALLSIGN		OverallSign;		// 总体标志
extern SYSTEM			System;			//系统参数结构对象
extern ERROR_Main		Error_main;			//报警结构对象
extern AREA_CONTROL	NC_AREAControl;
extern SELECTPOSITION Incubator_Position;

extern HOMING			Homing_Clone_Linear;	
extern OVERALLSIGN		OverallSign_Clone_Linear;		// 总体标志
extern SYSTEM			System_Clone_Linear;			//系统参数结构对象
extern ERROR_Main		Error_main_Clone_Linear;			//报警结构对象

extern HOMING			Homing_Clone_Optical;	
extern OVERALLSIGN		OverallSign_Clone_Optical;		// 总体标志
extern SYSTEM			System_Clone_Optical;			//系统参数结构对象
extern ERROR_Main		Error_main_Clone_Optical;			//报警结构对象

extern HOMING			Homing_PlateEmpty_Destination;	
extern OVERALLSIGN		OverallSign_PlateEmpty_Destination;		// 总体标志
extern SYSTEM			System_PlateEmpty_Destination;			//系统参数结构对象
extern ERROR_Main		Error_main_PlateEmpty_Destination;			//报警结构对象

extern HOMING			Homing_PlateWaste_Source;	
extern OVERALLSIGN		OverallSign_PlateWaste_Source;		// 总体标志
extern SYSTEM			System_PlateWaste_Source;			//系统参数结构对象
extern ERROR_Main		Error_main_PlateWaste_Source;			//报警结构对象

extern HOMING			Homing_PlateTransfering;	
extern OVERALLSIGN		OverallSign_PlateTransfering;		// 总体标志
extern SYSTEM			System_PlateTransfering;			//系统参数结构对象
extern ERROR_Main		Error_main_PlateTransfering;			//报警结构对象


extern INT40AXIS MonitorBuffer1[1000],MonitorBuffer2[1000];
