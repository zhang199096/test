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

#define  	RealTimeRun				0				// ʵʱ����
#define  	SimulateRun				1				// ��������

#define		OPEN					1
#define		CLOSE					0

#define		ThreeAxis			0				//����
#define		FourAxis			1				//����
#define		FiveAxis			2				//����

#define		TRUE					1
#define		OK						1
#define		COMPLETE				1	
#define		FALSE					0
#define		NOT_COMPLETE				0

#define  	REF_XYZ			0	//����ϵΪ3 ����
#define  	REF_XYZA		1	//����ϵΪ3+A ����
#define  	REF_XYZB		2	//����ϵΪ3+B ����
#define  	REF_XYZC		3	//����ϵΪ3+C ����

#define	StepZero		0		//����0
#define	StepOne			1		//����1
#define	StepTwo			2		//����2
#define	StepThree		3		//����3

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
}VECTOR;     //�����嶼Ϊ��λʸ��


typedef struct
{
	Uint16		SearchRefSign;			// Ҫ�������ο����־
	Uint16		RefStep;				//�ο�����������
	UINT16AXIS	NeedFindAxisSign;		// ��Ҫ������ı�־
	UINT16AXIS	FindRefSign;			// ���ҵ�ĳ��ο����־
	Uint16		PreSearchRefSign;		// �����ο���ǰ��ʼ����־
	Uint16      Findzero;               //Ѱ�ҵ�����־added by mendy 2011/6/20
	Uint16 		getzero;				//���ڼ�¼�������added by mendy 2011/6/21
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
	//������ر���
	float64	Stotal;							//���������д��������г��� mm
	float64 Snow;							//�����������뵽��ǰ���뵱ǰ�岹�������г��� mm  
	float64 DeltaSnow;						//�ӵ�ǰ������㵽��ǰ���뵱ǰ�岹�������г��� mm  
	
	Uint32	I;					//�岹��� [1,+����)
	Uint32 	TotalN;				//�ܲ岹��	TotalN=T5/Tsample
	float64	Vs;					//��ǰ����G������������ٶ�. (mm/s)
	float64	Vm;					// ��ǰ����G�����趨�����ٶ�. (mm/s)
	float64	VmReal;				// ��ǰ����G����ʵ����������ٶ�. (mm/s)
	float64	Ve;					// ��ǰ����G�����յ������ٶ�. (mm/s)
	float64 VNow;				// ��ǰʵ�������ٶ�. (mm/s)
	float64	Sac;				//��ǰ������ٹ����������(mm)
	float64	Sm;					//��ǰ�������ٹ����������(mm)
	float64	Sde;				//��ǰ������ٹ����������(mm)

	float64	T1;					//��A��B����ʱ��	s
	float64	T2;					//��A��C����ʱ��	s
	float64	T3;					//��A��D����ʱ��	s
	float64	T4;					//��A��E����ʱ��	s
	float64	T5;					//��A��F����ʱ��	s

	float64	DeltaT1;			//AB����ʱ��	s
	float64	DeltaT2;			//BC����ʱ��	s
	float64	DeltaT3;			//CD����ʱ��	s
	float64	DeltaT4;			//DE����ʱ��	s
	float64	DeltaT5;			//EF����ʱ��	s
	
	float64	a_ac;				// ʵ�ʼ��ٶμ��ٶ�		
	float64	a_de;				// ʵ�ʼ��ٶμ��ٶ�
}AREA_CONTROL;

typedef struct
{	
	int		A4_Model;						//A4 ��ģ��ѡ��0-��Ч1-A 2-B 3-C
	int		VeerDeltaT; 				//DSPb0-38ת�����ʱ�䳣�� ����λ��s��    �趨��Χ[1,255]ms �����Ӧ[1-255]
	int 	a_SET;						//P149�����ٶ��ؼ����˶�ƽ̨���ٶ� ��λ��mm/s.s
	int		G0Speed;
	int 	G0FeedRate1;
	int 	G0FeedRate2;
	int 	G0FeedRate3;

	int 		SRefSpeed;						//P153 			�ο������������ٶȣ���λ:mm/s
	int 		SRefSpeedBack;					//P154 			�ο��㷵���ٶȣ���λ:mm/s
	int 			SRefBack;						//P153			�ο��㷵�ؾ��룬��λ:��С���뵥λ
	UINT40AXIS		REFPosition;
	UINT40AXIS		EncoderDIR;
	UINT40AXIS 		MotorChangeDir;//�л��������
	UINT40AXIS		EncoderCheckChoose;		//P000-P005������դ�߱�־	
	int		Tsample;				//P020��λ��s   �趨�岹���� [0.1,10]ms ,�����Ӧ[1,100]
	UINT40AXIS	MAXSpeed;				//P021-P023��������ƶ��ٶ� ��λ:mm/s	 or degree/s
	int		VeerDeltaV;				//DSPb0-32�յ㵥��仯�ٶ�(unit:mm/s)  �趨��Χ[1,25.5] �����Ӧ[1-255] 

	UINT40AXIS	Gap;						//P137-P142 ���϶ֵ,��λ: ��С���뵥λ

	//P120-P125
	Uint32 		LinearAxisMinUnit;			//��������С���뵥λ(��λ��nm)
	Uint32		RotaryAxisMinUnit;			//��ת����С���뵥λ(��λ��nd)
	Uint32		LinearAxisOutUnitEQU;		//���������ָ�λ����(��λ��nm/ָ�λ)
	Uint32		RotaryAxisOutUnitEQU;		//��ת�����ָ�λ����(��λ��nd/ָ�λ)
	float64 		UnitTo_mm;					//������λ�õ�λ�����mm   ��λ:  mm/unit
	float64 		UnitTo_d;					//��ת��λ�õ�λ�����d	    ��λ:  d/unit

	UINT40AXIS	AxisCompMaxL;				//P126-P130�����Բ��������ֵ [0-280]	
	UINT40AXIS Resolution;					//����ֱ�������

	INT40AXIS	Limit_Pos;
	INT40AXIS Limit_Neg;


	int 		a_A4_SET;			 			//P165			�趨A4 ���˶�ƽ̨���ٶ� ��λ��degree/s.s      
	int 		A4SRefSpeed;					 //P170
	int 		A4SRefSpeedBack;				//p171
	int 		A4SRefBack;						//p172
	int			A4_G0Speed;					//P173			A4 ��G0�ٶ� degree/s

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


	
	//��������
	//0:3��
	//1:4��
	short			MachineConfiguration;				
	short			ReferenceFrameMode;				//����ϵģ��
}SYSTEM;	//ϵͳ�����ṹ��

typedef struct
{
	Uint32 		SendCount;			//DSP��ǰ����ԭ����λ��ָ�룬���ظ�ARM������ʾ��������;
	Uint32 		CMD1,CMD2;			//������,ȷ��G��������
	INT40AXIS	StartPoint;			//���. ��λ����������С���뵥λ
	INT40AXIS	EndPoint;			//�յ�.  ��λ����������С���뵥λ
	float64 	Feedrate;			//�����ٶ�,��λ:mm/s
	Int16 		AxisMotionStyle;	//0��A4�᲻���У�1��A4�����С�3:���μ��ߵ�����IV�ᵥ�����У�4:IV�ᵥ��SPC	
	Uint32		HoldTime;		    //GO4 Hold Time
}GCODE;


typedef struct
{
	Uint16 				NCSign;  	// 0:ͨ��״̬  1:��׼���룻2:�������-JOG HANDLE REF��INI=0
	Uint16 				NCSign_bak;  	// 0:ͨ��״̬  1:��׼���룻2:�������-JOG HANDLE REF��INI=0

	//�ٶȿ�����ز���
	Uint16				EveryAxisCoinValid;			// ����COIN ����Ч��־
	Uint16				EveryAxisOverValid;			// ����OVER ����Ч��־
	Uint8				FeedrateOverride;			//������λ	[0-20]
	Uint16				XYZ_Over;               			// 1--��ɵ�ǰG����XYZ������                                   
	float64    				F;						//G�����趨�����ٶ�  (mm/s)
	Int32				FG0;					//G0�����趨�����ٶ� (mm/s)
	float64   				FG0_A4;						//A4��G0�����趨�����ٶ� (mm/s)

	// ���������ز���
	INT40AXIS			ABS_Coordinate;				// ��ǰ��������ֵunit:��С���뵥λ
	INT40AXIS			ABSORG_M_Coordinate;		// ��ǰ��������ԭ��Ļ�������ֵunit:��С���뵥λ
	Uint16				LastCodeOverSign;			//���һ�����������־  1������
	UINT16AXIS			SearchRefMoveSign;			//�ο�����ҷ���1������2������

	//��ر�־λ	
	Uint8				Initial_STDSign;				//��־�������г�ʼ����־
	Uint8				Initial_SPCSign;				//�ֶ����㶯���г�ʼ����־
	Uint16 				GetPositionSign;				//1--�ѻ���ȶ���������ֵ��־
	Uint16 				NeedGetPositionSign;				//1--�����ȶ���������ֵ��־
	Uint8 				NeedP2PRunSign;			//�㵽��(����/�������궨λ)���б�־
	Uint8 				P2PRunCompleteSign;		//�㵽��(����/�������궨λ)������ɱ�־

	Uint8 				NeedParameterWriteSign;		//����д���־
	Uint8 				ParameterWriteCompleteSign;//����д����ɱ�־

	Uint8 				NeedMicroEDataBaseSendSign;		
	Uint8 				MicroEDataBaseSendCompleteSign;

	//�˶����״̬
	Uint8				ServoOn;
	int 					m_OperationMode;
	int 					m_OperationMode_bak;
	Uint8 				JOGAxisSelect;

	//ͨ�����״̬
	bool 				PC_DSP_COM_OK;//false:ֹͣ; true:����
	bool 				m_ReciveSuccess;
	int 					m_ReciveSuccessCounter;
	int 					m_ReciveLostCounter;
	int 					receivecount;
	int					sendcount;

	Uint8				CanSendCodeSign;	//��λ�˿��Է��ʹ����־
	Uint32 				NeedSendCount;		//ARM��Ҫ���ʹ�������
	Uint32				STDSendCount;		//ARM/PC���ͱ�־����λ��ָ��
	Uint32				SPCSendCount;		//ARM/PC�����ֶ����㶯����λ��ָ��
	Uint32				LastSendCount;		//�ݴ�ARMʵ�ʷ��ʹ���λ��ָ��
	//��λ����������
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
UINT16AXIS		EncoderError;				// ���դ�߱���   1--����

	Uint16 		NCCodeBreak;				//ARM����G���벻����	
	Uint16 		RAMCodeCheckError;			//���л�����G����У�鱨��
	Uint16 		InterpolationOver;			//�岹����5mm����
	Uint16 		TrackRunOutError;			//�켣ƫ�뱨��
	Uint32 		RealRunCount;				//�ѽ�ȡ����������������
	
	Uint16 		SCIBComError;			// �������DSP ͨѶ����	CH20090828
	
	Uint16 		InsideRAMCheckError;		// �ڲ�RAM У�����
	Uint16 		OutsideRAMCheckError;		// �ⲿRAM У�����
	Uint16 		CompDataCheckError;			// �����Բ�������У�����	
	Uint16 		A4RunLockError;					// A4 ������ʱ��������
	Uint16 		A4StopUnlockError;				// A4 ��ֹͣʱ�ɿ�����
	
	Uint16 		MainErrorSign;				//�ܴ����־
	UINT16AXIS ServoAlarm;							//�ŷ�����		1:������Ч
}ERROR_Main;					//�����ṹ��


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
extern OVERALLSIGN		OverallSign;		// �����־
extern SYSTEM			System;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main;			//�����ṹ����
extern AREA_CONTROL	NC_AREAControl;
extern SELECTPOSITION Incubator_Position;

extern HOMING			Homing_Clone_Linear;	
extern OVERALLSIGN		OverallSign_Clone_Linear;		// �����־
extern SYSTEM			System_Clone_Linear;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_Clone_Linear;			//�����ṹ����

extern HOMING			Homing_Clone_Optical;	
extern OVERALLSIGN		OverallSign_Clone_Optical;		// �����־
extern SYSTEM			System_Clone_Optical;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_Clone_Optical;			//�����ṹ����

extern HOMING			Homing_PlateEmpty_Destination;	
extern OVERALLSIGN		OverallSign_PlateEmpty_Destination;		// �����־
extern SYSTEM			System_PlateEmpty_Destination;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateEmpty_Destination;			//�����ṹ����

extern HOMING			Homing_PlateWaste_Source;	
extern OVERALLSIGN		OverallSign_PlateWaste_Source;		// �����־
extern SYSTEM			System_PlateWaste_Source;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateWaste_Source;			//�����ṹ����

extern HOMING			Homing_PlateTransfering;	
extern OVERALLSIGN		OverallSign_PlateTransfering;		// �����־
extern SYSTEM			System_PlateTransfering;			//ϵͳ�����ṹ����
extern ERROR_Main		Error_main_PlateTransfering;			//�����ṹ����


extern INT40AXIS MonitorBuffer1[1000],MonitorBuffer2[1000];
