#ifndef NETCOMMUNICATE_H_
#define NETCOMMUNICATE_H_

/*******************************���Կ���***********************************/
#define DS_ASK_HAVE_READ_TYPE_SET       0//����Ϊ�������͵İ����ظ�PC�Ѿ��յ�����
#define DS_ASK_HAVE_READ_TYPE_READ      0//����Ϊ��ȡ�������͵İ����ظ�PC�Ѿ��յ�����

#define DS_DSPCONTROL                   1//DSP���Ƶ��Կ���

#define DS_PRINTF                       0//��ӡ�������Կ���
#define DS_PRINTF_MAIN                  0//��ӡ�������Կ���
#define DS_PRINTF_ASK                   0//��ӡ�������Կ���
#define DS_PRINTF_ELDEX                 0//��ӡ�������Կ���
#define DS_PRINTF_GPIO                  0//��ӡ�������Կ���
#define DS_PRINTF_IDEX                  0//��ӡ�������Կ���
#define DS_PRINTF_LANPER                0//��ӡ�������Կ���
#define DS_PRINTF_TECAN                 0//��ӡ�������Կ���
#define DS_PRINTF_F335                  0//��ӡ�������Կ���

#define DS_UART_PRINTF                  0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_MAIN             0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_ASK              0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_ELDEX            0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_GPIO             0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_IDEX             0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_LANPER           0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_TECAN            0//UART��ӡ�������Կ���
#define DS_UART_PRINTF_F335             0//UART��ӡ�������Կ���
#define DS_LED_TECAN                    1//LEDָʾ�����
#define DS_LOOP_CMD                     0//���ݰ��Ƿ����������
/***************************Э�����������С***********************************/
#define NET_MAX_BUF           20
/*******************************����״̬***********************************/
#define NET_FifoEmpty        (unsigned int)(0)//����״̬-FIFO�յ�
#define NET_FifoNonEmpty     (unsigned int)(1)//����״̬-FIFO�ǿ�
#define NET_Error_ObjInvalid (unsigned int)(2)//����״̬-���ƶ�����Ч
#define NET_ConrtolDone      (unsigned int)(3)//����״̬-���ƶ���ɹ�
#define NET_ReceiveTimeOut   (unsigned int)(4)//����״̬-�������ݳ�ʱ
#define NET_StackOut         (unsigned int)(5)//����״̬-�ṩ�洢�ռ䲻��
#define NET_TokenErr         (unsigned int)(6)//����״̬-���ƴ���
#define NET_ReceiveCutDown   (unsigned int)(7)//����״̬-���ݽ����ж�
#define NET_Deadly           (unsigned int)(8)//����״̬-�������
#define NET_CRCErr           (unsigned int)(9)//����״̬-CRCУ�����
#define NET_Data_Err         (unsigned int)(9)//����״̬-������Ч����

/*******************************Э��λ��***********************************/
//Э�����ֶ�λ�ö���
#if DS_LOOP_CMD//ʹ�ù�����
#define NUM_STARTTOKEN_LOCATION (0)//Э�������ʼ����λ��
#define NUM_LOOP_LOCATION       (1)//Э����й�����λ��
#define NUM_LEN_LOCATION        (2)//Э����ж��峤�ȵ�λ��
#define NUM_OBJ_LOCATION        (3)//Э����п��ƶ����λ��
#define NUM_CMD_LOCATION        (4)//Э����������ݵ�λ��
#define NUM_EXCEPT_DATA         (5)//Э����д�����Ч�����ֶ����4�ֽ���������ʼ����+������+����+CRC+��������
#define NUM_CRC_BEGIN           (1)//���ݰ���CRC��ʼУ��λ��
#define NUM_CRC_MORE            (2)//CRCУ��������ֶζ��4�ֽ�����(+������+�����ֽ�)
#define NUM_CRC_MORE2           (4)//CRCУ��ȴ������ֶζ��4ֱ������(+������+�����ֽ�+�����ֽ�+����ֱ��)
#define NUM_PACK_MORE           (7)//���ݰ��ȴ������ֶζ��4�ֽ�����(+��ʼ����+������+�����ֽ�+�����ֽ�+����ֱ��+CRC+ֹͣ����)
#define NUM_STOPTOKEN_LOCATION  (4)//Э�����ֹͣ����λ��(���ڰ�������������ֱ��ʹ��,��ҪЭͬʵ�����ݰ��л�ȡ��lenֵ)
#define NUM_CRC_LOCATION        (3)//Э�����CRCλ��(���ڰ�������������ֱ��ʹ��,��ҪЭͬʵ�����ݰ��л�ȡ��lenֵ)
#define MUN_ERROR               (7)//�����������
#else//�޹�����
#define NUM_STARTTOKEN_LOCATION (0)//Э�������ʼ����λ��
#define NUM_LOOP_LOCATION       (0)//Э����й�����λ��(��Ч)
#define NUM_LEN_LOCATION        (1)//Э����ж��峤�ȵ�λ��
#define NUM_OBJ_LOCATION        (2)//Э����п��ƶ����λ��
#define NUM_CMD_LOCATION        (3)//Э����������ݵ�λ��
#define NUM_EXCEPT_DATA         (4)//Э����д�����Ч�����ֶ����4�ֽ���������ʼ����+����+CRC+��������
#define NUM_CRC_BEGIN           (1)//���ݰ���CRC��ʼУ��λ��
#define NUM_CRC_MORE            (1)//CRCУ��������ֶζ��4�ֽ�����(+�����ֽ�)
#define NUM_CRC_MORE2           (3)//CRCУ��ȴ������ֶζ��4�ֽ�����(+�����ֽ�+�����ֽ�+����ֱ��)
#define NUM_PACK_MORE           (6)//���ݰ��ȴ������ֶζ��4�ֽ�����(+��ʼ����+�����ֽ�+�����ֽ�+����ֱ��+CRC+ֹͣ����)
#define NUM_STOPTOKEN_LOCATION  (3)//Э�����ֹͣ����λ��(���ڰ�������������ֱ��ʹ��,��ҪЭͬʵ�����ݰ��л�ȡ��lenֵ)
#define NUM_CRC_LOCATION        (2)//Э�����CRCλ��(���ڰ�������������ֱ��ʹ��,��ҪЭͬʵ�����ݰ��л�ȡ��lenֵ)
#define MUN_ERROR               (6)//�����������
#endif

#define NUM_ELDEX_DATA          1//ELDEX���ݰ��У����ݿ�ʼλ��
#define NUM_LANPER_DATA         1//LANPER���ݰ��У����ݿ�ʼλ��
#define NUM_IDEX_DATA           1//IDEX���ݰ��У����ݿ�ʼλ��
#define NUM_TECAN_ID            1//TECAN���ݰ��У��ӵ�ַ��ʼλ��
#define NUM_TECAN_DATA1         2//TECAN���ݰ��У�����1��ʼλ��
#define NUM_TECAN_DATA2         3//TECAN���ݰ��У�����2��ʼλ��
#define NUM_HAMILTON_ID         1//TECAN���ݰ��У��ӵ�ַ��ʼλ��
#define NUM_HAMILTON_DATA1      2//TECAN���ݰ��У�����1��ʼλ��
#define NUM_HAMILTON_DATA2      3//TECAN���ݰ��У�����2��ʼλ��

/*******************************���ƶ���,�����޸�***********************************/

#define E625  8
//#define MVPvalve 7
#define MDS    5
#define ELDEX1  0
#define ELDEX2  1
#define ELDEX3  2
#define ELDEX4  3
#define ELDEX5  4
//#define ELDEX6  5
#define ELDEX7  6
//#define ELDEX8  7
#define LANPER1 8
#define LANPER2 9
#define LANPER3 10
#define LANPER4 11
#define LANPER5 12
#define LANPER6 13
#define LANPER7 14
#define LANPER8 15
#define IDEX1   16
#define IDEX2   17
#define IDEX3   18
#define IDEX4   19
#define IDEX5   20
#define IDEX6   21
#define IDEX7   22
#define IDEX8   23
#define TECAN1  24
#define TECAN2  25
#define TECAN3  26
#define TECAN4  27
#define TECAN5  28
#define TECAN6  29
#define TECAN7  30
#define TECAN8  31
#define GPIOBIT64   32
#define GPIOABIT16  33
#define GPIOBBIT16  34
#define GPIOCBIT16  35
#define GPIODBIT16  36
#define GPIOBIT0    37
#define GPIOBIT1    (GPIOBIT0+1)
#define GPIOBIT2    (GPIOBIT0+2)
#define GPIOBIT3    (GPIOBIT0+3)
#define GPIOBIT4    (GPIOBIT0+4)
#define GPIOBIT5    (GPIOBIT0+5)
#define GPIOBIT6    (GPIOBIT0+6)
#define GPIOBIT7    (GPIOBIT0+7)
#define GPIOBIT8    (GPIOBIT0+8)
#define GPIOBIT9    (GPIOBIT0+9)
#define GPIOBIT10   (GPIOBIT0+10)
#define GPIOBIT11   (GPIOBIT0+11)
#define GPIOBIT12   (GPIOBIT0+12
#define GPIOBIT13   (GPIOBIT0+13)
#define GPIOBIT14   (GPIOBIT0+14
#define GPIOBIT15   (GPIOBIT0+15)
#define GPIOBIT16   (GPIOBIT0+16)
#define GPIOBIT17   (GPIOBIT0+17)
#define GPIOBIT18   (GPIOBIT0+18)
#define GPIOBIT19   (GPIOBIT0+19)
#define GPIOBIT20   (GPIOBIT0+20
#define GPIOBIT21   (GPIOBIT0+21)
#define GPIOBIT22   (GPIOBIT0+22)
#define GPIOBIT23   (GPIOBIT0+23)
#define GPIOBIT24   (GPIOBIT0+24)
#define GPIOBIT25   (GPIOBIT0+25)
#define GPIOBIT26   (GPIOBIT0+26)
#define GPIOBIT27   (GPIOBIT0+27)
#define GPIOBIT28   (GPIOBIT0+28)
#define GPIOBIT29   (GPIOBIT0+29)
#define GPIOBIT30   (GPIOBIT0+30)
#define GPIOBIT31   (GPIOBIT0+31)
#define GPIOBIT32   (GPIOBIT0+32)
#define GPIOBIT33   (GPIOBIT0+33)
#define GPIOBIT34   (GPIOBIT0+34)
#define GPIOBIT35   (GPIOBIT0+35)
#define GPIOBIT36   (GPIOBIT0+36)
#define GPIOBIT37   (GPIOBIT0+37)
#define GPIOBIT38   (GPIOBIT0+38)
#define GPIOBIT39   (GPIOBIT0+39)
#define GPIOBIT40   (GPIOBIT0+40)
#define GPIOBIT41   (GPIOBIT0+41)
#define GPIOBIT42   (GPIOBIT0+42)
#define GPIOBIT43   (GPIOBIT0+43)
#define GPIOBIT44   (GPIOBIT0+44)
#define GPIOBIT45   (GPIOBIT0+45)
#define GPIOBIT46   (GPIOBIT0+46)
#define GPIOBIT47   (GPIOBIT0+47)
#define GPIOBIT48   (GPIOBIT0+48)
#define GPIOBIT49   (GPIOBIT0+49)
#define GPIOBIT50   (GPIOBIT0+50)
#define GPIOBIT51   (GPIOBIT0+51)
#define GPIOBIT52   (GPIOBIT0+52)
#define GPIOBIT53   (GPIOBIT0+53)
#define GPIOBIT54   (GPIOBIT0+53)
#define GPIOBIT55   (GPIOBIT0+55)
#define GPIOBIT56   (GPIOBIT0+56)
#define GPIOBIT57   (GPIOBIT0+57)
#define GPIOBIT58   (GPIOBIT0+58)
#define GPIOBIT59   (GPIOBIT0+59
#define GPIOBIT60   (GPIOBIT0+60)
#define GPIOBIT61   (GPIOBIT0+61)
#define GPIOBIT62   (GPIOBIT0+62)
#define GPIOBIT63   (GPIOBIT0+63)
#define ULTRASONIC  (GPIOBIT63+1)
#define F3351       (ULTRASONIC+1)
#define TENPERATURE (F3351+1)
#define VOLTAGE     (TENPERATURE+1)
#define NET_HEAT	(VOLTAGE+1)
#define HAMILTON    (NET_HEAT+1) //0x6A
#define MVPvalve (HAMILTON+1)
#define WEIGH    (MVPvalve+1)  //108
#define ASKLASTDATA 109

#define GOABLE_PUMP_OBJ_BASE   (0xff00)//���������ĸ����ͱ�
#define GOABLE_PUMP_WHICH_BASE (0x00FF)//���������ļ�����
#define GOABLE_ELDEX_BASE      (0X1000)//bit[8-15]=0x10 ��ʾELDEX��·ͬʱ����   ����bit0-bint7�ֱ��ʾ1-8�ű�ʹ��
#define GOABLE_LANPER_BASE     (0X2000)//bit[8-15]=0x20 ��ʾLANPER��·ͬʱ���� ����bit0-bint7�ֱ��ʾ1-8�ű�ʹ��
#define GOABLE_IDEX_BASE       (0X3000)//bit[8-15]=0x30 ��ʾIDEX��·ͬʱ����     ����bit0-bint7�ֱ��ʾ1-8�ű�ʹ��
#define GOABLE_TECAN_BASE      (0X4000)//bit[8-15]=0x40 ��ʾTECAN��·ͬʱ����   ����bit0-bint7�ֱ��ʾ1-8�ű�ʹ��

/*******************************ȫ�ֿ�������*************************************/
#define STARTTOKEN          0x53542B2B//"ST++" ��ʼ����
#define STOPTOKEN           0X2d2d4f50//"--OP" ��������
#define ERROTOKEN           0X4552524F//"ERRO" ��������-�ظ�PC�ã���������������PC��DSP���ݰ���ĳЩָ�����û���ڹ涨��Χ�ڡ�����DSP���豸֮��ͨѶ�쳣��ɵġ�
#define CRCERROTOKEN        0x45435243//"ECRC" У���������-�ظ�PC��
#define LOSTERROTOKEN       0x4c4f5354//"LOST" ���ݰ������-�ظ�PC��
#define TOKEERROTOKEN       0X544f4b45//��TOKE�� ���Ƽ�����-�ظ�PC��
#define NOBJERROTOKEN       0X544f4b45//��NOBJ�� ��Ч��������-�ظ�PC��

/****************************��������*******************************************/
#define ERROR_ELDEX_SetRunState_Buile_Fail                     (0x45313030)//E100 ELDEX ��������-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetRunState_232_TimeOut                    (0x45313031)//E101 ELDEX ��������-232���ճ�ʱ
#define ERROR_ELDEX_SetRunState_PumpAsk_Buile_Fail             (0x45313032)//E102 Eldex ��������-���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetRunState_SetValuelInvalid               (0x45313033)//E103 Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetRunState_ReturnInvalid                  (0x45313034)//E104 Eldex ��������-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetStopState_Buile_Fail                    (0x45313035)//E105 ELDEX ������ͣ-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetStopState_232_TimeOut                   (0x45313036)//E106 ELDEX ������ͣ-232���ճ�ʱ
#define ERROR_ELDEX_SetStopState_PumpAsk_Buile_Fail            (0x45313037)//E107 Eldex ������ͣ-���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetStopState_SetValuelInvalid              (0x45313038)//E108 Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetStopState_ReturnInvalid                 (0x45313039)//E109 Eldex ������ͣ-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetFlowrate_Buile_Fail                     (0x45313061)//E10a ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetFlowrate_232_TimeOut                    (0x45313062)//E10b ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetFlowrate_PumpAsk_Buile_Fail             (0x45313063)//E10c Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetFlowrate_SetValuelInvalid               (0x45313064)//E10d Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetFlowrate_ReturnInvalid                  (0x45313065)//E10e Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetFlowrate_Buile_Fail                     (0x45313066)//E10f ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetFlowrate_232_TimeOut                    (0x45313067)//E10g ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetFlowrate_PumpAsk_Buile_Fail             (0x45313068)//E10h Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetFlowrate_SetValuelInvalid               (0x45313069)//E10i Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetFlowrate_ReturnInvalid                  (0x4531306a)//E10j Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetId_Buile_Fail                           (0x4531306b)//E10k ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetId_232_TimeOut                          (0x4531306c)//E10l ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetId_232_PumpAsk_Buile_Fail               (0x4531306d)//E10m Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetId_SetValuelInvalid                     (0x4531306e)//E10n Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetId_ReturnInvalid                        (0x4531306f)//E103o Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetPressure_Buile_Fail                     (0x45313060)//E10p ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetPressure_232_TimeOut                    (0x45313071)//E10q ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetPressure_PumpAsk_Buile_Fail             (0x45313072)//E10r Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetPressure_SetValuelInvalid               (0x45313073)//E10s Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetPressure_ReturnInvalid                  (0x45313074)//E10t Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetHeightPressureLimit_Buile_Fail          (0x45313075)//E10u ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetHeightPressureLimit_232_TimeOut         (0x45313076)//E10v ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetHeightPressureLimit_PumpAsk_Buile_Fail  (0x45313077)//E10w Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetHeightPressureLimit_SetValuelInvalid    (0x45313078)//E10x Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetHeightPressureLimit_ReturnInvalid       (0x45313079)//E10y Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetLowPressureLimit_Buile_Fail             (0x4531307a)//E10z ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetLowPressureLimit_232_TimeOut            (0x45313041)//E10A ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetLowPressureLimit_PumpAsk_Buile_Fail     (0x45313042)//E10B Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetLowPressureLimit_SetValuelInvalid       (0x45313043)//E10C Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetLowPressureLimit_ReturnInvalid          (0x45313044)//E10D Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetHeightPressureLimit_Buile_Fail          (0x45313045)//E10E ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetHeightPressureLimit_232_TimeOut         (0x45313046)//E10F ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetHeightPressureLimit_PumpAsk_Buile_Fail  (0x45313047)//E10G Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetHeightPressureLimit_SetValuelInvalid    (0x45313048)//E10H Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetHeightPressureLimit_ReturnInvalid       (0x45313049)//E10I Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetLowPressureLimit_Buile_Fail             (0x4531304A)//E10J ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetLowPressureLimit_232_TimeOut            (0x4531304B)//E10K ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetLowPressureLimit_PumpAsk_Buile_Fail     (0x4531304C)//E10L Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetLowPressureLimit_SetValuelInvalid       (0x4531304D)//E10M Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetLowPressureLimit_ReturnInvalid          (0x4531304E)//E10N Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetCompressComp_Buile_Fail                 (0x4531304F)//E10O ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetCompressComp_232_TimeOut                (0x45313050)//E10P ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetCompressComp_PumpAsk_Buile_Fail         (0x45313051)//E10Q Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetCompressComp_SetValuelInvalid           (0x45313052)//E10R Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetCompressComp_ReturnInvalid              (0x45313053)//E10S Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetCompressComp_Buile_Fail                 (0x45313054)//E10T ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetCompressComp_232_TimeOut                (0x45313055)//E10U ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetCompressComp_PumpAsk_Buile_Fail         (0x45313056)//E10V Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetCompressComp_SetValuelInvalid           (0x45313057)//E10W Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetCompressComp_ReturnInvalid              (0x45313058)//E10X Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetRefillRateFactor_Buile_Fail             (0x45313059)//E10Y ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetRefillRateFactor_232_TimeOut            (0x4531305A)//E10Z ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetRefillRateFactor_PumpAsk_Buile_Fail     (0x45313130)//E110 Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetRefillRateFactor_SetValuelInvalid       (0x45313131)//E111 Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetRefillRateFactor_ReturnInvalid          (0x45313132)//E112 Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����


#define ERROR_ELDEX_GetRefillRateFactor_Buile_Fail             (0x45313133)//E113 ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetRefillRateFactor_232_TimeOut            (0x45313134)//E114 ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetRefillRateFactor_PumpAsk_Buile_Fail     (0x45313135)//E115 Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetRefillRateFactor_SetValuelInvalid       (0x45313136)//E116 Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetRefillRateFactor_ReturnInvalid          (0x45313137)//E117 Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetDisablesKeypad_Buile_Fail               (0x45313138)//E118 ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetDisablesKeypad_232_TimeOut              (0x45313139)//E119 ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetDisablesKeypad_PumpAsk_Buile_Fail       (0x45313161)//E11a Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetDisablesKeypad_SetValuelInvalid         (0x45313162)//E11b Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetDisablesKeypad_ReturnInvalid            (0x45313163)//E11c Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetEnablesKeypad_Buile_Fail                (0x45313164)//E11d ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetEnablesKeypad_232_TimeOut               (0x45313165)//E11e ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetEnablesKeypad_PumpAsk_Buile_Fail        (0x45313166)//E11f Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetEnablesKeypad_SetValuelInvalid          (0x45313167)//E11g Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetEnablesKeypad_ReturnInvalid             (0x45313168)//E11h Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetPistonDiameter_Buile_Fail               (0x45313169)//E11i ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetPistonDiameter_232_TimeOut              (0x4531316a)//E11j ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetPistonDiameter_PumpAsk_Buile_Fail       (0x4531316b)//E11k Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetPistonDiameter_SetValuelInvalid         (0x4531316c)//E11l Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetPistonDiameter_ReturnInvalid            (0x4531316d)//E11m Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetPistonDiameter_Buile_Fail               (0x4531316e)//E11n ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetPistonDiameter_232_TimeOut              (0x4531317f)//E11o ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetPistonDiameter_PumpAsk_Buile_Fail       (0x45313170)//E11p Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetPistonDiameter_SetValuelInvalid         (0x45313171)//E11q Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetPistonDiameter_ReturnInvalid            (0x45313172)//E11r Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetStroke_Buile_Fail                       (0x45313173)//E11s ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetStroke_232_TimeOut                      (0x45313174)//E11t ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetStroke_PumpAsk_Buile_Fail               (0x45313175)//E11u Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetStroke_SetValuelInvalid                 (0x45313176)//E11v Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetStroke_ReturnInvalid                    (0x45313177)//E11w Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetStroke_Buile_Fail                       (0x45313178)//E11x ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetStroke_232_TimeOut                      (0x45313179)//E11y ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetStroke_PumpAsk_Buile_Fail               (0x4531317a)//E11z Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetStroke_SetValuelInvalid                 (0x45313141)//E11A Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetStroke_ReturnInvalid                    (0x45313142)//E11B Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetPumpMeterial_Buile_Fail                 (0x45313143)//E11C ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetPumpMeterial_232_TimeOut                (0x45313144)//E11D ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetPumpMeterial_PumpAsk_Buile_Fail         (0x45313145)//E11E Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetPumpMeterial_SetValuelInvalid           (0x45313146)//E11F Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetPumpMeterial_ReturnInvalid              (0x45313147)//E11G Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetPumpMeterial_Buile_Fail                 (0x45313148)//E11H ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetPumpMeterial_232_TimeOut                (0x45313149)//E11I ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetPumpMeterial_PumpAsk_Buile_Fail         (0x4531314A)//E11J Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetPumpMeterial_SetValuelInvalid           (0x4531314B)//E11K Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetPumpMeterial_ReturnInvalid              (0x4531314C)//E11L Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetFaultStatus_Buile_Fail                  (0x4531314D)//E11M ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetFaultStatus_232_TimeOut                 (0x4531314E)//E11N ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetFaultStatus_PumpAsk_Buile_Fail          (0x4531314F)//E11O Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetFaultStatus_SetValuelInvalid            (0x45313150)//E11P Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetFaultStatus_ReturnInvalid               (0x45313151)//E11Q Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetLedRedStopPump_Buile_Fail               (0x45313152)//E11R ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetLedRedStopPump_232_TimeOut              (0x45313153)//E11S ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetLedRedStopPump_PumpAsk_Buile_Fail       (0x45313154)//E11T Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetLedRedStopPump_SetValuelInvalid         (0x45313155)//E11U Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetLedRedStopPump_ReturnInvalid            (0x45313156)//E11V Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_GetInterfacePara_Buile_Fail                (0x45313157)//E11W ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_GetInterfacePara_232_TimeOut               (0x45313158)//E11X ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_GetInterfacePara_PumpAsk_Buile_Fail        (0x45313159)//E11Y Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_GetInterfacePara_SetValuelInvalid          (0x4531315A)//E11Z Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_GetInterfacePara_ReturnInvalid             (0x45313230)//E120 Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_ELDEX_SetRestCmdBuf_Buile_Fail                   (0x45313231)//E121 ELDEX -����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_ELDEX_SetRestCmdBuf_232_TimeOut                  (0x45313232)//E122 ELDEX -232���ճ�ʱ
#define ERROR_ELDEX_SetRestCmdBuf_PumpAsk_Buile_Fail           (0x45313233)//E123 Eldex -���ձûظ���Ϣ�������
#define ERROR_ELDEX_SetRestCmdBuf_SetValuelInvalid             (0x45313234)//E124 Eldex -PC���õ�ֵ��Ч
#define ERROR_ELDEX_SetRestCmdBuf_ReturnInvalid                (0x45313235)//E125 Eldex -����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_GPIO_NOT_READ_NOT_WRITE                          (0x45323030)//E200 Gpio�յ������Ƽ����Ƕ�����Ҳ����д����
#define ERROR_GPIOI_NVALIDDATA                                 (0x45323031)//E201 Gpio Pcд��Ч����-�ظ�PC��

#define ERROR_IDEX_MoveNewPos_Buile_Fail                       (0x45333030)//E300 IDEX-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_IDEX_MoveNewPos_IIC_TimeOut                      (0x45333031)//E301 IDEX -I2C���ճ�ʱ
#define ERROR_IDEX_MoveNewPos_PumpAsk_Buile_Fail               (0x45333032)//E302 IDEX -���ձûظ���Ϣ�������
#define ERROR_IDEX_MoveNewPos_SetValuelInvalid                 (0x45333033)//E303 IDEX -PC���õ�ֵ��Ч
#define ERROR_IDEX_MoveNewPos_ReturnInvalid                    (0x45333034)//E304 IDEX-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_Init_Buile_Fail                            (0x45343030)//E400 TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_Init_485_TimeOut                           (0x45343031)//E401 TECAN -485���ճ�ʱ
#define ERROR_TECAN_Init_PumpAsk_Buile_Fail                    (0x45343032)//E402 TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_Init_SetValuelInvalid                      (0x45343033)//E403 TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_Init_ReturnInvalid                         (0x45343034)//E404 TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_Ejtct_Buile_Fail                           (0x45343035)//E405 TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_Ejtct_485_TimeOut                          (0x45343036)//E406 TECAN -485���ճ�ʱ
#define ERROR_TECAN_Ejtct_PumpAsk_Buile_Fail                   (0x45343037)//E407 TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_Ejtct_SetValuelInvalid                     (0x45343038)//E408 TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_Ejtct_ReturnInvalid                        (0x45343039)//E409 TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_PosAbs_Buile_Fail                          (0x45343061)//E40a TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_PosAbs_485_TimeOut                         (0x45343062)//E40b TECAN -485���ճ�ʱ
#define ERROR_TECAN_PosAbs_PumpAsk_Buile_Fail                  (0x45343063)//E40c TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_PosAbs_SetValuelInvalid                    (0x45343064)//E40d TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_PosAbs_ReturnInvalid                       (0x45343065)//E40e TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_Aspirate_Buile_Fail                        (0x45343066)//E40f TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_Aspirate_485_TimeOut                       (0x45343067)//E40g TECAN -485���ճ�ʱ
#define ERROR_TECAN_Aspirate_PumpAsk_Buile_Fail                (0x45343068)//E40h TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_Aspirate_SetValuelInvalid                  (0x45343069)//E40i TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_Aspirate_ReturnInvalid                     (0x4534306a)//E40j TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_Distribute_Buile_Fail                      (0x4534306b)//E40k TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_Distribute_485_TimeOut                     (0x4534306c)//E40l TECAN -485���ճ�ʱ
#define ERROR_TECAN_Distribute_PumpAsk_Buile_Fail              (0x4534306d)//E40m TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_Distribute_SetValuelInvalid                (0x4534306e)//E40n TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_Distribute_ReturnInvalid                   (0x4534306f)//E40o TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_SetMaxSpeed_Buile_Fail                     (0x45343070)//E40p TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_SetMaxSpeed_485_TimeOut                    (0x45343071)//E40q TECAN -485���ճ�ʱ
#define ERROR_TECAN_SetMaxSpeed_PumpAsk_Buile_Fail             (0x45343072)//E40r TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_SetMaxSpeed_SetValuelInvalid               (0x45343073)//E40s TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_SetMaxSpeed_ReturnInvalid                  (0x45343074)//E40t TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_SetStartSpeed_Buile_Fail                   (0x45343075)//E40u TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_SetStartSpeed_485_TimeOut                  (0x45343076)//E40v TECAN -485���ճ�ʱ
#define ERROR_TECAN_SetStartSpeed_PumpAsk_Buile_Fail           (0x45343077)//E40w TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_SetStartSpeed_SetValuelInvalid             (0x45343078)//E40x TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_SetStartSpeed_ReturnInvalid                (0x45343079)//E40y TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_SetStopSpeed_Buile_Fail                    (0x4534307a)//E40z TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_SetStopSpeed_485_TimeOut                   (0x45343041)//E40A TECAN -485���ճ�ʱ
#define ERROR_TECAN_SetStopSpeed_PumpAsk_Buile_Fail            (0x45343042)//E40B TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_SetStopSpeed_SetValuelInvalid              (0x45343043)//E40C TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_SetStopSpeed_ReturnInvalid                 (0x45343044)//E40D TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_SetSlope_Buile_Fail                        (0x45343045)//E40E TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_SetSlope_485_TimeOut                       (0x45343046)//E40F TECAN -485���ճ�ʱ
#define ERROR_TECAN_SetSlope_PumpAsk_Buile_Fail                (0x45343047)//E40G TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_SetSlope_SetValuelInvalid                  (0x45343048)//E40H TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_SetSlope_ReturnInvalid                     (0x45343049)//E40I TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_SetBackImpulse_Buile_Fail                  (0x4534304a)//E40J TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_SetBackImpulse_485_TimeOut                 (0x4534304b)//E40K TECAN -485���ճ�ʱ
#define ERROR_TECAN_SetBackImpulse_PumpAsk_Buile_Fail          (0x4534304c)//E40K TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_SetBackImpulse_SetValuelInvalid            (0x4534304d)//E40M TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_SetBackImpulse_ReturnInvalid               (0x4534304e)//E40N TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_RSet_Buile_Fail                            (0x4534304f)//E40O TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_RSet_485_TimeOut                           (0x45343050)//E40P TECAN -485���ճ�ʱ
#define ERROR_TECAN_RSet_PumpAsk_Buile_Fail                    (0x45343051)//E40Q TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_RSet_SetValuelInvalid                      (0x45343052)//E40R TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_RSet_ReturnInvalid                         (0x45343053)//E40S TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_CLeanCmdBuf_Buile_Fail                     (0x45343054)//E40T TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_CLeanCmdBuf_485_TimeOut                    (0x45343055)//E40U TECAN -485���ճ�ʱ
#define ERROR_TECAN_CLeanCmdBuf_PumpAsk_Buile_Fail             (0x45343056)//E40V TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_CLeanCmdBuf_SetValuelInvalid               (0x45343057)//E40W TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_CLeanCmdBuf_ReturnInvalid                  (0x45343058)//E40X TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_TECAN_GetState_Buile_Fail                        (0x45343059)//E40Y TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_GetState_485_TimeOut                       (0x4534305A)//E40Z TECAN -485���ճ�ʱ
#define ERROR_TECAN_GetState_PumpAsk_Buile_Fail                (0x45343130)//E410 TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_GetState_SetValuelInvalid                  (0x45343131)//E411 TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_GetState_ReturnInvalid                     (0x45343132)//E412 TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����
#define ERROR_TECAN_GetState_ReturnStateInvalid                (0x45343133)//E413 TECAN-����ֵ״̬��Ϣ����ָ����Χ�ڣ��÷���״̬�쳣

#define ERROR_TECAN_NOREADY                                    (0x45343134)//E414
//add by zzz
#define ERROR_TECAN_FakeInit_Buile_Fail                        (0x45343135)//E415 TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_FakeInit_485_TimeOut                       (0x45343136)//E416 TECAN -485���ճ�ʱ
#define ERROR_TECAN_FakeInit_PumpAsk_Buile_Fail                (0x45343137)//E417 TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_FakeInit_SetValuelInvalid                  (0x45343138)//E418 TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_FakeInit_ReturnInvalid                     (0x45343139)//E419 TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����
#define ERROR_TECAN_FakeInit_ReturnStateInvalid                (0x45343161)//E41a TECAN-����ֵ״̬��Ϣ����ָ����Χ�ڣ��÷���״̬�쳣

#define ERROR_TECAN_MulCmdLoops_Buile_Fail                        (0x45343162)//E41b TECAN-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_TECAN_MulCmdLoops_485_TimeOut                       (0x45343163)//E41c TECAN -485���ճ�ʱ
#define ERROR_TECAN_MulCmdLoops_PumpAsk_Buile_Fail                (0x45343164)//E41d TECAN -���ձûظ���Ϣ�������
#define ERROR_TECAN_MulCmdLoops_SetValuelInvalid                  (0x45343165)//E41e TECAN -PC���õ�ֵ��Ч
#define ERROR_TECAN_MulCmdLoops_ReturnInvalid                     (0x45343166)//E41f TECAN-����ֵ����ָ�������ڣ�DSPϵͳ����
#define ERROR_TECAN_MulCmdLoops_ReturnStateInvalid                (0x45343167)//E41g TECAN-����ֵ״̬��Ϣ����ָ����Χ�ڣ��÷���״̬�쳣
//add by zzz

#define ERROR_LANPER_SetRunPar_Buile_Fail                      (0x45353030)//E500 LANPER-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_LANPER_SetRunPar_485_TimeOut                     (0x45353031)//E501 LANPER -485���ճ�ʱ
#define ERROR_LANPER_SetRunPar_PumpAsk_Buile_Fail              (0x45353032)//E502 LANPER -���ձûظ���Ϣ�������
#define ERROR_LANPER_SetRunPar_SetValuelInvalid                (0x45353033)//E503 LANPER -PC���õ�ֵ��Ч
#define ERROR_LANPER_SetRunPar_ReturnInvalid                   (0x45353034)//E504 LANPER-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_LANPER_GetRunPar_Buile_Fail                      (0x45353035)//E505 LANPER-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_LANPER_GetRunPar_485_TimeOut                     (0x45353036)//E506 LANPER -485���ճ�ʱ
#define ERROR_LANPER_GetRunPar_PumpAsk_Buile_Fail              (0x45353037)//E507 LANPER -���ձûظ���Ϣ�������
#define ERROR_LANPER_GetRunPar_SetValuelInvalid                (0x45353038)//E508 LANPER -PC���õ�ֵ��Ч
#define ERROR_LANPER_GetRunPar_ReturnInvalid                   (0x45353039)//E509 LANPER-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_LANPER_RSetId_Buile_Fail                         (0x45353061)//E50a LANPER-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_LANPER_RSetId_485_TimeOut                        (0x45353062)//E50b LANPER -485���ճ�ʱ
#define ERROR_LANPER_RSetId_PumpAsk_Buile_Fail                 (0x45353063)//E50c LANPER -���ձûظ���Ϣ�������
#define ERROR_LANPER_RSetId_SetValuelInvalid                   (0x45353064)//E50d LANPER -PC���õ�ֵ��Ч
#define ERROR_LANPER_RSetId_ReturnInvalid                      (0x45353065)//E50e LANPER-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_LANPER_GetId_Buile_Fail                          (0x45353066)//E50f LANPER-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_LANPER_GetId_485_TimeOut                         (0x45353067)//E50g LANPER -485���ճ�ʱ
#define ERROR_LANPER_GetId_PumpAsk_Buile_Fail                  (0x45353078)//E50h LANPER -���ձûظ���Ϣ�������
#define ERROR_LANPER_GetId_SetValuelInvalid                    (0x45353069)//E50i LANPER -PC���õ�ֵ��Ч
#define ERROR_LANPER_GetId_ReturnInvalid                       (0x4535306a)//E50j LANPER-����ֵ����ָ�������ڣ�DSPϵͳ����

/************************************** HAMILTON error code *****************************************************************************/
#define ERROR_HAMILTON_Init_Buile_Fail                            (0x45363030)//E600 HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Init_232_TimeOut                           (0x45363031)//E601 HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Init_PumpAsk_Buile_Fail                    (0x45363032)//E602 HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Init_SetValuelInvalid                      (0x45363033)//E603 HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Init_ReturnInvalid                         (0x45363034)//E604 HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_RepMsg_Buile_Fail                           (0x45363035)//E605 HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_RepMsg_232_TimeOut                          (0x45363036)//E606 HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail                   (0x45363037)//E607 HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_RepMsg_SetValuelInvalid                     (0x45363038)//E608 HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_RepMsg_ReturnInvalid                        (0x45363039)//E609 HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_PosAbs_Buile_Fail                          (0x45363061)//E60a HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_PosAbs_232_TimeOut                         (0x45363062)//E60b HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail                  (0x45363063)//E60c HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_PosAbs_SetValuelInvalid                    (0x45363064)//E60d HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_PosAbs_ReturnInvalid                       (0x45363065)//E60e HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_Pickup_Buile_Fail                        (0x45363066)//E60f HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Pickup_232_TimeOut                       (0x45363067)//E60g HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail                (0x45363068)//E60h HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Pickup_SetValuelInvalid                  (0x45363069)//E60i HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Pickup_ReturnInvalid                     (0x4536306a)//E60j HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_Dispense_Buile_Fail                      (0x4536306b)//E60k HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Dispense_232_TimeOut                     (0x4536306c)//E60l HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail              (0x4536306d)//E60m HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Dispense_SetValuelInvalid                (0x4536306e)//E60n HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Dispense_ReturnInvalid                   (0x4536306f)//E60o HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetMaxSpeed_Buile_Fail                     (0x45363070)//E60p HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetMaxSpeed_232_TimeOut                    (0x45363071)//E60q HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail             (0x45363072)//E60r HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid               (0x45363073)//E60s HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid                  (0x45363074)//E60t HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetStartSpeed_Buile_Fail                   (0x45363075)//E60u HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetStartSpeed_232_TimeOut                  (0x45363076)//E60v HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail           (0x45363077)//E60w HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid             (0x45363078)//E60x HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetStartSpeed_ReturnInvalid                (0x45363079)//E60y HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetStopSpeed_Buile_Fail                    (0x4536307a)//E60z HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetStopSpeed_232_TimeOut                   (0x45363041)//E60A HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail            (0x45363042)//E60B HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid              (0x45363043)//E60C HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetStopSpeed_ReturnInvalid                 (0x45363044)//E60D HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetAcceler_Buile_Fail                        (0x45363045)//E60E HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetAcceler_232_TimeOut                       (0x45363046)//E60F HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail                (0x45363047)//E60G HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetAcceler_SetValuelInvalid                  (0x45363048)//E60H HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetAcceler_ReturnInvalid                     (0x45363049)//E60I HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetBackSteps_Buile_Fail                  (0x4536304a)//E60J HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetBackSteps_232_TimeOut                 (0x4536304b)//E60K HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail          (0x4536304c)//E60K HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetBackSteps_SetValuelInvalid            (0x4536304d)//E60M HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetBackSteps_ReturnInvalid               (0x4536304e)//E60N HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_RSet_Buile_Fail                            (0x4536304f)//E60O HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_RSet_232_TimeOut                           (0x45363050)//E60P HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail                    (0x45363051)//E60Q HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_RSet_SetValuelInvalid                      (0x45363052)//E60R HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_RSet_ReturnInvalid                         (0x45363053)//E60S HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_TerminalCmd_Buile_Fail                     (0x45363054)//E60T HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_TerminalCmd_232_TimeOut                    (0x45363055)//E60U HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail             (0x45363056)//E60V HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_TerminalCmd_SetValuelInvalid               (0x45363057)//E60W HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_TerminalCmd_ReturnInvalid                  (0x45363058)//E60X HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_GetState_Buile_Fail                        (0x45363059)//E60Y HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_GetState_232_TimeOut                       (0x4536305A)//E60Z HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail                (0x45363130)//E610 HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_GetState_SetValuelInvalid                  (0x45363131)//E611 HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_GetState_ReturnInvalid                     (0x45363132)//E612 HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����
#define ERROR_HAMILTON_GetState_ReturnStateInvalid                (0x45363133)//E613 HAMILTON-����ֵ״̬��Ϣ����ָ����Χ�ڣ��÷���״̬�쳣
//add by zzz
#define ERROR_HAMILTON_Input_Buile_Fail                           (0x45363135)//E615 HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Input_232_TimeOut                          (0x45363136)//E616 HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Input_PumpAsk_Buile_Fail                   (0x45363137)//E617 HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Input_SetValuelInvalid                     (0x45363138)//E618 HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Input_ReturnInvalid                        (0x45363139)//E619 HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_Output_Buile_Fail                           (0x45363141)//E61A HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Output_232_TimeOut                          (0x45363142)//E61B HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Output_PumpAsk_Buile_Fail                   (0x45363143)//E61C HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Output_SetValuelInvalid                     (0x45363144)//E61D HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Output_ReturnInvalid                        (0x45363145)//E61E HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetCounterPos_Buile_Fail                           (0x45363146)//E61A HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetCounterPos_232_TimeOut                          (0x45363147)//E61B HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail                   (0x45363148)//E61C HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetCounterPos_SetValuelInvalid                     (0x45363149)//E61D HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetCounterPos_ReturnInvalid                        (0x4536314A)//E61E HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_RepDevStat_Buile_Fail                              (0x4536314B)//E61A HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_RepDevStat_232_TimeOut                             (0x4536314C)//E61B HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail                      (0x4536314D)//E61C HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_RepDevStat_SetValuelInvalid                        (0x4536314E)//E61D HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_RepDevStat_ReturnInvalid                           (0x4536314F)//E61E HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_MulCmdPosMove_Buile_Fail                           (0x45363150)//E61F HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_MulCmdPosMove_232_TimeOut                          (0x45363151)//E61G HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail                   (0x45363152)//E61H HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid                     (0x45363153)//E61I HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid                        (0x45363154)//E61K HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_SetSpeed_Buile_Fail                                (0x45363155)//E61L HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_SetSpeed_232_TimeOut                          	  (0x45363156)//E61M HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail                        (0x45363157)//E61N HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_SetSpeed_SetValuelInvalid                          (0x45363158)//E61O HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_SetSpeed_ReturnInvalid                             (0x45363159)//E61P HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_Comtinue_Buile_Fail                                (0x45363155)//E61L HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_Comtinue_232_TimeOut                          	  (0x45363156)//E61M HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_Comtinue_PumpAsk_Buile_Fail                        (0x45363157)//E61N HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_Comtinue_SetValuelInvalid                          (0x45363158)//E61O HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_Comtinue_ReturnInvalid                             (0x45363159)//E61P HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_HAMILTON_MulAbs_Buile_Fail                                  (0x4536315A)//E61Q HAMILTON-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_HAMILTON_MulAbs_232_TimeOut                          	      (0x4536315B)//E61R HAMILTON -232���ճ�ʱ
#define ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail                          (0x4536315C)//E61S HAMILTON -���ձûظ���Ϣ�������
#define ERROR_HAMILTON_MulAbs_SetValuelInvalid                            (0x4536315D)//E61T HAMILTON -PC���õ�ֵ��Ч
#define ERROR_HAMILTON_MulAbs_ReturnInvalid                               (0x4536315E)//E61U HAMILTON-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MVP_Init_Buile_Fail                                  (0x45373030)//E700 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MVP_Init_232_TimeOut                          	   (0x45373031)//E701 MVP -232���ճ�ʱ
#define ERROR_MVP_Init_Ask_Buile_Fail                          	   (0x45373032)//E702 MVP -���ձûظ���Ϣ�������
#define ERROR_MVP_Init_SetValuelInvalid                            (0x45373033)//E703 MVP -PC���õ�ֵ��Ч
#define ERROR_MVP_Init_ReturnInvalid                               (0x45373034)//E704 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MVP_Move_Buile_Fail                                  (0x45373035)//E705 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MVP_Move_232_TimeOut                          	   (0x45373036)//E706 MVP -232���ճ�ʱ
#define ERROR_MVP_Move_Ask_Buile_Fail                              (0x45373037)//E707 MVP -���ձûظ���Ϣ�������
#define ERROR_MVP_Move_SetValuelInvalid                            (0x45373038)//E708 MVP -PC���õ�ֵ��Ч
#define ERROR_MVP_Move_ReturnInvalid                               (0x45373039)//E709 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MVP_Report_Buile_Fail                                  (0x4537303A)//E700 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MVP_Report_232_TimeOut                          	     (0x4537303B)//E701 MVP -232���ճ�ʱ
#define ERROR_MVP_Report_Ask_Buile_Fail                              (0x4537303C)//E702 MVP -���ձûظ���Ϣ�������
#define ERROR_MVP_Report_SetValuelInvalid                            (0x4537303D)//E703 MVP -PC���õ�ֵ��Ч
#define ERROR_MVP_Report_ReturnInvalid                               (0x4537303E)//E704 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MVP_EnableCmd_Buile_Fail                                  (0x45373040)//E700 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MVP_EnableCmd_232_TimeOut                          	    (0x45373041)//E701 MVP -232���ճ�ʱ
#define ERROR_MVP_EnableCmd_Ask_Buile_Fail                              (0x45373042)//E702 MVP -���ձûظ���Ϣ�������
#define ERROR_MVP_EnableCmd_SetValuelInvalid                            (0x45373043)//E703 MVP -PC���õ�ֵ��Ч
#define ERROR_MVP_EnableCmd_ReturnInvalid                               (0x45373044)//E704 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MVP_RepStat_Buile_Fail                                  (0x45373045)//E700 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MVP_RepStat_232_TimeOut                          	      (0x45373046)//E701 MVP -232���ճ�ʱ
#define ERROR_MVP_RepStat_Ask_Buile_Fail                              (0x45373047)//E702 MVP -���ձûظ���Ϣ�������
#define ERROR_MVP_RepStat_SetValuelInvalid                            (0x45373048)//E703 MVP -PC���õ�ֵ��Ч
#define ERROR_MVP_RepStat_ReturnInvalid                               (0x45373049)//E704 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����


#define ERROR_MDS_SetFreq_Buile_Fail                                  (0x45373130)//E710 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MDS_SetFreq_232_TimeOut                          	      (0x45373131)//E711 MVP -232���ճ�ʱ
#define ERROR_MDS_SetFreq_Ask_Buile_Fail                          	  (0x45373132)//E712 MVP -���ձûظ���Ϣ�������
#define ERROR_MDS_SetFreq_SetValuelInvalid                            (0x45373133)//E713 MVP -PC���õ�ֵ��Ч
#define ERROR_MDS_SetFreq_ReturnInvalid                               (0x45373134)//E714 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MDS_SetPow_Buile_Fail                                  (0x45373135)//E715 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MDS_SetPow_232_TimeOut                          	     (0x45373136)//E716 MVP -232���ճ�ʱ
#define ERROR_MDS_SetPow_Ask_Buile_Fail                              (0x45373137)//E717 MVP -���ձûظ���Ϣ�������
#define ERROR_MDS_SetPow_SetValuelInvalid                            (0x45373138)//E718 MVP -PC���õ�ֵ��Ч
#define ERROR_MDS_SetPow_ReturnInvalid                               (0x45373139)//E719 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MDS_SetdBm_Buile_Fail                                (0x4537313A)//E710 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MDS_SetdBm_232_TimeOut                          	   (0x4537313B)//E711 MVP -232���ճ�ʱ
#define ERROR_MDS_SetdBm_Ask_Buile_Fail                            (0x4537313C)//E712 MVP -���ձûظ���Ϣ�������
#define ERROR_MDS_SetdBm_SetValuelInvalid                          (0x4537313D)//E713 MVP -PC���õ�ֵ��Ч
#define ERROR_MDS_SetdBm_ReturnInvalid                             (0x4537313E)//E714 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MDS_SetSwitch_Buile_Fail                             (0x45373140)//E710 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MDS_SetSwitch_232_TimeOut                            (0x45373141)//E711 MVP -232���ճ�ʱ
#define ERROR_MDS_SetSwitch_Ask_Buile_Fail                         (0x45373142)//E712 MVP -���ձûظ���Ϣ�������
#define ERROR_MDS_SetSwitch_SetValuelInvalid                       (0x45373143)//E713 MVP -PC���õ�ֵ��Ч
#define ERROR_MDS_SetSwitch_ReturnInvalid                          (0x45373144)//E714 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define ERROR_MDS_RepPara_Buile_Fail                             (0x45373145)//E710 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_MDS_RepPara_232_TimeOut                            (0x45373146)//E711 MVP -232���ճ�ʱ
#define ERROR_MDS_RepPara_Ask_Buile_Fail                         (0x45373147)//E712 MVP -���ձûظ���Ϣ�������
#define ERROR_MDS_RepPara_SetValuelInvalid                       (0x45373148)//E713 MVP -PC���õ�ֵ��Ч
#define ERROR_MDS_RepPara_ReturnInvalid                          (0x45373149)//E714 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

/****************************************Weigh*******************************************/
#define ERROR_Weigh_ReportWeigh_Buile_Fail                                  (0x4538303A)//E700 MVP-����ָ�����DSP�ṩ�ڴ治�㣩
#define ERROR_Weigh_ReportWeigh_485_TimeOut                          	    (0x4538303B)//E701 MVP -232���ճ�ʱ
#define ERROR_Weigh_ReportWeigh_Ask_Buile_Fail                              (0x4538303C)//E702 MVP -���ձûظ���Ϣ�������
#define ERROR_Weigh_ReportWeigh_SetValuelInvalid                            (0x4538303D)//E703 MVP -PC���õ�ֵ��Ч
#define ERROR_Weigh_ReportWeigh_ReturnInvalid                               (0x4538303E)//E704 MVP-����ֵ����ָ�������ڣ�DSPϵͳ����

#define Weigh_MSG_MAX_SIZE 20
extern Uint32 WEIGHGetWeight(Uint8 WhichCom,Uint32 index);
Uint32 WeighBuildGetWeight(Uint32 devAddr,char *msbuf,Uint32 bufsize);
Uint16 CRC_GetModbus16(Uint8 *pdata, int len);
Uint16 GetCrc_16(Uint8 * pData, int nLength,
	Uint16 init, const
	Uint16 *ptable);
/****************************Eldex�䶯�ÿ�������********************************/
#define ELDEX_SET_RUN       0X00005255//��RU��   ����
#define ELDEX_SET_STOP      0X00005354//��ST��   ��ͣ
#define ELDEX_SET_SPEED     0X00005346//��SF��   ��������
#define ELDEX_GET_SPEED     0X00005246//��RF��   ��ȡ����
#define ELDEX_GET_ID        0X00004944//"ID"   ��ȡID��
#define ELDEX_GET_PRESSURE  0X00005250//"RP"   ��ȡ��ѹ��
#define ELDEX_SET_H         0X00005348//"SH"   ����ѹ������
#define ELDEX_SET_L         0X0000534C//"SL"   ����ѹ������
#define ELDEX_GET_H         0X00005248//"RH"   ��ȡѹ������
#define ELDEX_GET_L         0X0000524C//"RL"   ��ȡѹ������
#define ELDEX_SET_CS        0X00005343//"SC"   ����ѹ������ϵ��
#define ELDEX_GET_CS        0X00005243//"RC"   ��ȡѹ������ϵ��
#define ELDEX_SET_SR        0X00005352//"SR"
#define ELDEX_GET_RR        0X00005252//"RR"
#define ELDEX_DISABLE_KB    0X00004B44//"KD"   ���ü���
#define ELDEX_ENABLE_KB     0X00004B45//"KE"   ʹ�ܼ���
#define ELDEX_SET_DIAMETER  0X00005344//"SD"   ���û���ֱ��
#define ELDEX_GET_DIAMETER  0X00005244//"RD"   ��ȡ����ֱ��
#define ELDEX_SET_STROKE    0X00005353//"SS"   ���û������
#define ELDEX_GET_STROKE    0X00005253//"RS"   ��ȡ�������
#define ELDEX_SET_MATERIAL  0X0000534D//"SM"
#define ELDEX_GET_MATERIAL  0X0000524D//"RM"
#define ELDEX_GET_ERROR     0X00005258//"RX"   ��ȡ����
#define ELDEX_SET_STOPLED   0X00005358//"SX"   ֹͣ�ò�����LED
#define ELDEX_GET_INFO      0X00005249//"RI"   ��ȡ��Ϣ
#define ELDEX_CLEAR_CMDFIFO 0X0000005A//"Z"    ����������
/****************************LanPer�䶯�ÿ�������********************************/
#define LANPER_SET_RUN_PAR  0x0000574a//"WJ"   PC���ñ����в���
#define LANPER_RED_RUN_PAR  0x0000524a//"RJ"   PC��ȡ�����в���
#define LANPER_SET_NEW_ADD  0x00574944//"WID"  PC���ñ��µ�ַ����Ŀ�У��õ�ַֻ��������Ϊ��1�����ṩ��λλ��1��������������������ַ���������
//#define LANPER_RSET_ID      0x57524944//"WRID"PC ��λ�䶯�õ�ַΪ��1��//Э��汾2ɾ��
#define LANPER_RED_ID       0x00524944//"RID"  PC��ȡ���µ�ַ
#define LANPER_SET_ID       0x00534944//"SID"  PC���ñ��µ�ַ//Э��汾2���
#define LANPER_ADDR_1               1//        pump default address1,�����䶯��ʹ�õ���485����ʽ���䣬1200-485-1����
#define LANPER_ADDR_BROADCAST      31//        pump broadcast address
/****************************Idex���䷧����ָ��********************************/
#define IDEX_RUN_POSITION   0X00000050//��P��    PCָ����λ��
#define IDEX_SET_PROFILE    0X0000004F//��O��    PC����profile
#define IDEX_SET_NEWID      0X0000004E//��N��    PC�����µ�ַ
#define IDEX_SET_CMDMODE    0X00000046//��F��    PC�趨����ģʽ
#define IDEX_SET_UARTBUND   0X00000058//��X��    PC�趨UART������
#define IDEX_RUN_HOME       0X0000004D//��M��    PC����Ϊ
#define IDEX_READ_POSITION  0X00000053//��S��    PC��ȡ��λ��
#define IDEX_READ_PROFILE   0X00000051//��Q��    PC��ȡprofile
#define IDEX_READ_FIRMWARE  0X00000052//��R��    PC��ȡ�̼���Ϣ
#define IDEX_READ_LASTERRO  0X00000045//��E��    PC��ȡ���һ������
#define IDEX_READ_CMDMODE   0X00000044//��D��    PC������ģʽ
#define LANPER_ADDR_WRITE        0x0E//        I2Cд��ַ       LANPER��  IDEX_WRITEADDR
#define LANPER_ADDR_READ         0x0F//        I2C����ַ
/****************************Tecan���䷧����ָ��********************************/
#define TECAN_INIT         0x00002F57//"/W"     PC���ñ������ٶ�
#define TECAN_FAKEINIT	   0x00002F7A//"/z"		PC���üٳ�ʼ��
#define TECAN_EJECT        0x00002F45//"/E"     ����һ������ͷ
#define TECAN_POS_ABS      0x00002F41//"/A"     ���þ���λ��
#define TECAN_ASPIRATE     0x00002F50//"/P"     �����ȡ
#define TECAN_DISTRIBUTE   0x00002F44//"/D"     ����ͷ�
#define TECAN_MAX_SPEED    0x00002F56//"/V"     ��������ٶ�
#define TECAN_START_SPEED  0x00002F76//"/v"     ���������ٶ�
#define TECAN_STOP_SPEED   0x00002F63//"/c"     ���ö����ٶ�
#define TECAN_SLOPE        0x00002F4C//"/L"     �����¶�
#define TECAN_BACK_IMPULSE 0x00002F4B//"/K"     ���ú����
#define TECAN_MULCMDLOOPS  0x00002F47//"/G"     ������ѭ��ģʽ��������ϴ�룩
#define TECAN_    0x00002F//"/>"
#define TECAN_    0x00002F//"/R"
#define TECAN_    0x00002F//"/X"
#define TECAN_    0x00002F//"/G"
#define TECAN_    0x00002F//"/g"
#define TECAN_    0x00002F//"/M"
#define TECAN_    0x00002F//"/H"
#define TECAN_REST_DEV    0x00002F21//"/!" ��λ�豸
#define TECAN_    0x00002F//"/s"
#define TECAN_    0x00002F//"/e"
#define TECAN_CLEAN_CMD    0x00002F43//"/C"����������
#define TECAN_GET_STATE    0x00002F51//"/Q"�����豸״̬
#define TECAN_    0x00002F//"/&"
#define TECAN_    0x00002F//"/<"
#define TECAN_    0x00002F//"/:"
#define TECAN_    0x00002F//"/="
#define TECAN_    0x00002F//"/?"
#define TECAN_    0x00002F//"/?76"
#define TECAN_    0x00002F//"/?77"
#define TECAN_    0x00002F//"/#"*/
/****************************GOIO����ָ��********************************/
#define READIO              0x5245494f//"REIO" ��IO
#define WRITEIO             0x5752494f//"WRIO" дIO
/****************************F335����ָ��********************************/
#define READF335            0x52454633//"REF3" ��F335

#define READUL          	0x5245554C//"REUL" ��������52,45,55,4c,

#define READTE          	0x52455445//"RETE" ���¶�

#define GTVO				0x4754564f //"GTVO"  ��ȡ�趨��ѹ
/****************************HEAT����˿��������********************************/
#define HEAT            	0x48454154//"HEAT" ��λ�����Ʒ���˿
/****************************Hamilton���䷧����ָ��********************************/
#define HAMILTON_INIT      0x0000685A//"/ZR"    <ascii:"hZ"> PC���ñ������ٶ�
#define HAMILTON_POS_ABS   0x00006841//"/AR,aR"    <ascii:"hA">�ƶ�������λ��
#define HAMILTON_DISPENSE  0x00006850//"/DR,dR"    <ascii:"hD">���������˶�
#define HAMILTON_PICKUP    0x00006844//"/PR,PR"    <ascii:"hP">���������˶�
#define HAMILTON_INPUT     0x00006849//"/IR"    <ascii:"hI">�������뷧��
#define HAMILTON_OUTPUT    0x0000684F//"/OR"    <ascii:"hO">�����������
#define HAMILTON_ACCELER   0x0000684C//"/LxR"	<ascii:"hL">���û������ٶ�
#define HAMILTON_START_SPEED   0x00006876//"/vxR"	<ascii:"hv">������ʼ�ٶ�
#define HAMILTON_MAX_SPEED 0x00006856//"/VxR"	<ascii:"hV">��������ٶ�
#define HAMILTON_STOP_SPEED 0x00006863//"/cxR"	<ascii:"hc">���ý����ٶ�
#define HAMILTON_SET_SPEED  0x00006853	//"/SxR"	<ascii:"hS">�����ٶ�
#define HAMILTON_RET_STEPS  0x0000684B//"/KR,kR"    <ascii:"hK">���ú����
#define HAMILTON_GET_STATUS 0x00006851//"/QR"    <ascii:"hQ">��ѯ״̬
#define HAMILTON_SET_CNTPOS 0x0000687A//"/zR"    <ascii:"hz">��������λ�ñ�����
#define HAMILTON_REP_DEVSTA 0x0000683F//"/?xR"    <ascii:"h?">��ѯ�������Ϣ
#define HAMILTON_MUL_CMDPOS 0x0000686D//"/xxxxxxx"<ascii:"hm">������ģʽ����������������Լ�������
#define HAMILTON_MUL_CMDLOOP 0x00006847//"/xxxxxxxG"<ascii:"hG">������ģʽ�����Կ���ѭ����������������������Լ�������
#define HAMILTON_MUL_ABSLOOP 0x00006842//"/xxxxxxx"<ascii:"hB">������ģʽ�����Կ���ѭ����������������������Լ�������
#define HAMILTON_TERMINAL   0x00006854//"/TR"<ascii:"hT">������ģʽ�����Կ���ѭ����������������������Լ�������
#define HAMILTON_CONTINUE   0x00006852//"/R"<ascii:"hR">������ģʽ�����Կ���ѭ����������������������Լ�������
/******************************MVP����ָ��********************************/
#define MVPINIT            0x004D5649
#define MVPGOVA            0x004D5647
#define MVPRPOS   		   0x004D5652
#define MVPENCM            0x004D5645
#define MVPRPST            0x004D5653
/******************************Weigh����ָ��********************************/
#define GETWEUGHT              0x00574757    //��ȡ����
#define GETGALWEIGH            0x00574747    //��ȡ���г���������
#define WEIGHSETADDR           0x00575341	 //�ı��ַ
#define WEIGHGETBAUD   		   0x00574742    //��ȡ������
/******************************MDS����ָ��*********************************/
#define MDSSETF            0x004D4446    //MDF-- set Freq
#define MDSSETD            0x004D4444	 //MDD -- set dBm
#define MDSSETP   		   0x004D4450    //MDP -- set Power
#define MDSSETS            0x004D4453    //MDS -- set switch
#define MDSREP			   0x004D4452    //MDR -- report para
/****************************�������ָ��********************************/

/****************************�������ָ��********************************/
#define E625MOVPOS         0x004D4F56
#define E625RPOPOS         0x00504F53
#define ASKL                0x41534b4c//"ASKL" PC���󷵻���һ��ָ��






//�ڲ��������������ݰ���������ʱ�ռ�
 //extern Uint32                  buf_Response[NET_MAX_BUF];//Ӧ��ռ�


#endif /* NETCOMMUNICATE_H_ */
