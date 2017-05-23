#ifndef DSP6713_RUN_NC_H
#define DSP6713_RUN_NC_H

#define IRQNUM_PLUSE   10   // pluse 
#define IRQNUM_MBUS    11   //M2 M3 BUS
#define IRQNUM_PWR     12   //power down

#define IRQNUM_PLUSE1   	10   // LPMEN1 
#define IRQNUM_PLUSE2    	11   // LPMEN2
#define IRQNUM_PLUSE3     	12   // LPMEN3
#define IRQNUM_PLUSE4     	13   // LPMEN4

//#define IRQ_DISABLE(num)  Hwi_disableInterrupt(num)
//#define IRQ_ENABLE(num)   Hwi_enableInterrupt(num)

#define	  FPGA_MAX_F		64000000/2		//FPGA时钟频率

//ͨ�ñ����ͱ�־
extern SYSTEM			System;			//ϵͳ�����ṹ����
extern ERROR				Error;			//�����ṹ����
extern OVERALLSIGN		OverallSign;		// �����־
extern DACONVERT  		DA_Convert1;

extern GCODE			GCodeBuffer[STDGCODE_MOD];	// G-code �ṹ��������
extern GCODE			SPCGCodeBuffer[SPCGCODE_MOD];	//SPC G-code �ṹ��������
extern GCODE			NCAreaGCodeBuffer[STDGCODE_MOD];	//���������뻺������
extern GCODE			AddLineGCodeBuffer_Incubator[ADDGCODEINCUBATOR_MOD];			//����20���������������䶨λ
extern UINT16AXIS 	LastPrecalMoveSign;	// ��ǰ���ƶ�����
extern UINT16AXIS 	NowPrecalMoveSign;	// ���ڵ��ƶ�����

extern NC_RUN_SIGN		NCRunSign;	//����������Ⱥ״̬��ͨѶ״̬�ṹ����
extern NC_RUN_SIGN 		AddGCodePositionSign;		//����incubator position�Ӵ���;

//���ڱ�׼G����
extern NC_RUN_SIGN		STDNCSign;			//NC�������б�־�ͱ���
extern NC_RUN_SIGN		SPCNCSign;			//NC�������б�־�ͱ���

//��������
//�ο�������
extern REFERENCE	Reference;		

extern AxisCompensation AxisCompBuffer[COMPBUFFERLENGTH];


//���ڱ�׼ STD G����
void 	STD_run_G04(void);
void 	STD_run_G100(void);		//����F AND S ����
void 	STD_run_G101(void);		//����M����
void 	STD_run_G102(void);		//����ڼ��
void 	STD_run_G103(void);		//����ڿ���
void 	STD_run_G104(void);		//ӫ�����
void 	STD_run_G105(void);		//����ɨ����ʼ���������
void 	STD_run_G106(void);		//��ѹ����
void 	STD_run_G107(void);		//���������ʱ��
void 	STD_run_G108(void);		//װ�ء�ж��tipͷ
void 	STD_run_G109(void);		//��Һ����Һ����Һ
void 	STD_run_G110(void);		//���Ļ�����
void 	STD_run_G111(void);		//�񶯼���ģ��
void 	STD_run_G112(void);		//���������
void 	STD_run_G113(void) ;		//AOTF ����
void 	STD_run_G114(void) ;		//PMT


Uint16 STD_run_M03(void);		// ����ɨ��
Uint16 STD_run_M04(void);		// sensor1
Uint16 STD_run_M05(void);		// sensor2
Uint16 STD_run_M06(void);		// sensor3

Uint16 get_and_check_coordinate(void);//CH0701  ��ö������겢��β����ж�
extern INT40AXIS ABSCoordinate_to_MachineCoordinate(INT40AXIS AbsCoordinate);		//CH0701
extern INT40AXIS MachineCoordinate_to_ABSCoordinate(INT40AXIS MachineCoordinate);			//CH0701


//�˶������ӳ�����
Uint16 LimitAxisSpeed(AREA_CONTROL *AREAControl,GCODE *AreaGcodeBufferPointer, NC_RUN_SIGN *AreaRunNCSign);		//�ٶ��޶��ж�����  CH0605

//�ο���������ʼ��
extern Uint16 SearchReference(void);
extern Uint16 SearchReference_Beta(void);


// �����жϳ���ʼ��
extern Uint16 STD_check_track_run_over(void);		//�жϹ켣�Ƿ�ƫ��λ��  
extern Uint16 SPC_check_track_run_over(void);		//�жϹ켣�Ƿ�ƫ��λ��  
extern Uint16 get_error_data(void);	//��ó���ʱ������

extern Uint16 NC_Run_Gcode(void);	//���д���


#endif  // end of DSP6713_RUN_NC_H definition


