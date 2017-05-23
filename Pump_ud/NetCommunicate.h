#ifndef NETCOMMUNICATE_H_
#define NETCOMMUNICATE_H_

/*******************************调试开关***********************************/
#define DS_ASK_HAVE_READ_TYPE_SET       0//命令为设置类型的包，回复PC已经收到包了
#define DS_ASK_HAVE_READ_TYPE_READ      0//命令为读取数据类型的包，回复PC已经收到包了

#define DS_DSPCONTROL                   1//DSP控制调试开关

#define DS_PRINTF                       0//打印函数调试开关
#define DS_PRINTF_MAIN                  0//打印函数调试开关
#define DS_PRINTF_ASK                   0//打印函数调试开关
#define DS_PRINTF_ELDEX                 0//打印函数调试开关
#define DS_PRINTF_GPIO                  0//打印函数调试开关
#define DS_PRINTF_IDEX                  0//打印函数调试开关
#define DS_PRINTF_LANPER                0//打印函数调试开关
#define DS_PRINTF_TECAN                 0//打印函数调试开关
#define DS_PRINTF_F335                  0//打印函数调试开关

#define DS_UART_PRINTF                  0//UART打印函数调试开关
#define DS_UART_PRINTF_MAIN             0//UART打印函数调试开关
#define DS_UART_PRINTF_ASK              0//UART打印函数调试开关
#define DS_UART_PRINTF_ELDEX            0//UART打印函数调试开关
#define DS_UART_PRINTF_GPIO             0//UART打印函数调试开关
#define DS_UART_PRINTF_IDEX             0//UART打印函数调试开关
#define DS_UART_PRINTF_LANPER           0//UART打印函数调试开关
#define DS_UART_PRINTF_TECAN            0//UART打印函数调试开关
#define DS_UART_PRINTF_F335             0//UART打印函数调试开关
#define DS_LED_TECAN                    1//LED指示灯输出
#define DS_LOOP_CMD                     0//数据包是否包含滚动码
/***************************协议包缓冲区大小***********************************/
#define NET_MAX_BUF           20
/*******************************错误状态***********************************/
#define NET_FifoEmpty        (unsigned int)(0)//返回状态-FIFO空的
#define NET_FifoNonEmpty     (unsigned int)(1)//返回状态-FIFO非空
#define NET_Error_ObjInvalid (unsigned int)(2)//返回状态-控制对象无效
#define NET_ConrtolDone      (unsigned int)(3)//返回状态-控制对象成功
#define NET_ReceiveTimeOut   (unsigned int)(4)//返回状态-接收数据超时
#define NET_StackOut         (unsigned int)(5)//返回状态-提供存储空间不足
#define NET_TokenErr         (unsigned int)(6)//返回状态-令牌错误
#define NET_ReceiveCutDown   (unsigned int)(7)//返回状态-数据接收中断
#define NET_Deadly           (unsigned int)(8)//返回状态-程序错误
#define NET_CRCErr           (unsigned int)(9)//返回状态-CRC校验错误
#define NET_Data_Err         (unsigned int)(9)//返回状态-数据无效错误

/*******************************协议位置***********************************/
//协议中字段位置定义
#if DS_LOOP_CMD//使用滚动码
#define NUM_STARTTOKEN_LOCATION (0)//协议包中起始令牌位置
#define NUM_LOOP_LOCATION       (1)//协议包中滚动码位置
#define NUM_LEN_LOCATION        (2)//协议包中定义长度的位置
#define NUM_OBJ_LOCATION        (3)//协议包中控制对象的位置
#define NUM_CMD_LOCATION        (4)//协议包命令数据的位置
#define NUM_EXCEPT_DATA         (5)//协议包中处理有效命令字段外的4字节数量，起始令牌+滚动码+长度+CRC+结束令牌
#define NUM_CRC_BEGIN           (1)//数据包中CRC开始校验位置
#define NUM_CRC_MORE            (2)//CRC校验比数据字段多的4字节数量(+滚动码+长度字节)
#define NUM_CRC_MORE2           (4)//CRC校验比纯数据字段多的4直接数量(+滚动码+长度字节+对象字节+令牌直接)
#define NUM_PACK_MORE           (7)//数据包比纯数字字段多的4字节数量(+起始令牌+滚动码+长度字节+对象字节+令牌直接+CRC+停止令牌)
#define NUM_STOPTOKEN_LOCATION  (4)//协议包中停止令牌位置(由于包长不定，不能直接使用,需要协同实际数据包中获取的len值)
#define NUM_CRC_LOCATION        (3)//协议包中CRC位置(由于包长不定，不能直接使用,需要协同实际数据包中获取的len值)
#define MUN_ERROR               (7)//错误包包长度
#else//无滚动码
#define NUM_STARTTOKEN_LOCATION (0)//协议包中起始令牌位置
#define NUM_LOOP_LOCATION       (0)//协议包中滚动码位置(无效)
#define NUM_LEN_LOCATION        (1)//协议包中定义长度的位置
#define NUM_OBJ_LOCATION        (2)//协议包中控制对象的位置
#define NUM_CMD_LOCATION        (3)//协议包命令数据的位置
#define NUM_EXCEPT_DATA         (4)//协议包中处理有效命令字段外的4字节数量，起始令牌+长度+CRC+结束令牌
#define NUM_CRC_BEGIN           (1)//数据包中CRC开始校验位置
#define NUM_CRC_MORE            (1)//CRC校验比数据字段多的4字节数量(+长度字节)
#define NUM_CRC_MORE2           (3)//CRC校验比纯数据字段多的4字节数量(+长度字节+对象字节+令牌直接)
#define NUM_PACK_MORE           (6)//数据包比纯数字字段多的4字节数量(+起始令牌+长度字节+对象字节+令牌直接+CRC+停止令牌)
#define NUM_STOPTOKEN_LOCATION  (3)//协议包中停止令牌位置(由于包长不定，不能直接使用,需要协同实际数据包中获取的len值)
#define NUM_CRC_LOCATION        (2)//协议包中CRC位置(由于包长不定，不能直接使用,需要协同实际数据包中获取的len值)
#define MUN_ERROR               (6)//错误包包长度
#endif

#define NUM_ELDEX_DATA          1//ELDEX数据包中，数据开始位置
#define NUM_LANPER_DATA         1//LANPER数据包中，数据开始位置
#define NUM_IDEX_DATA           1//IDEX数据包中，数据开始位置
#define NUM_TECAN_ID            1//TECAN数据包中，子地址开始位置
#define NUM_TECAN_DATA1         2//TECAN数据包中，数据1开始位置
#define NUM_TECAN_DATA2         3//TECAN数据包中，数据2开始位置
#define NUM_HAMILTON_ID         1//TECAN数据包中，子地址开始位置
#define NUM_HAMILTON_DATA1      2//TECAN数据包中，数据1开始位置
#define NUM_HAMILTON_DATA2      3//TECAN数据包中，数据2开始位置

/*******************************控制对象,请勿修改***********************************/

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

#define GOABLE_PUMP_OBJ_BASE   (0xff00)//标明控制哪个类型泵
#define GOABLE_PUMP_WHICH_BASE (0x00FF)//标明控制哪几个泵
#define GOABLE_ELDEX_BASE      (0X1000)//bit[8-15]=0x10 表示ELDEX多路同时控制   其中bit0-bint7分别表示1-8号泵使能
#define GOABLE_LANPER_BASE     (0X2000)//bit[8-15]=0x20 表示LANPER多路同时控制 其中bit0-bint7分别表示1-8号泵使能
#define GOABLE_IDEX_BASE       (0X3000)//bit[8-15]=0x30 表示IDEX多路同时控制     其中bit0-bint7分别表示1-8号泵使能
#define GOABLE_TECAN_BASE      (0X4000)//bit[8-15]=0x40 表示TECAN多路同时控制   其中bit0-bint7分别表示1-8号泵使能

/*******************************全局控制令牌*************************************/
#define STARTTOKEN          0x53542B2B//"ST++" 起始令牌
#define STOPTOKEN           0X2d2d4f50//"--OP" 结束令牌
#define ERROTOKEN           0X4552524F//"ERRO" 错误令牌-回复PC用，这个错误肯能由于PC到DSP数据包中某些指令参数没有在规定范围内、或者DSP到设备之间通讯异常造成的。
#define CRCERROTOKEN        0x45435243//"ECRC" 校验错误令牌-回复PC用
#define LOSTERROTOKEN       0x4c4f5354//"LOST" 数据包不完成-回复PC用
#define TOKEERROTOKEN       0X544f4b45//“TOKE” 令牌检测错误-回复PC用
#define NOBJERROTOKEN       0X544f4b45//“NOBJ” 无效操作对象-回复PC用

/****************************错误令牌*******************************************/
#define ERROR_ELDEX_SetRunState_Buile_Fail                     (0x45313030)//E100 ELDEX 设置运行-编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetRunState_232_TimeOut                    (0x45313031)//E101 ELDEX 设置运行-232接收超时
#define ERROR_ELDEX_SetRunState_PumpAsk_Buile_Fail             (0x45313032)//E102 Eldex 设置运行-接收泵回复信息编译错误
#define ERROR_ELDEX_SetRunState_SetValuelInvalid               (0x45313033)//E103 Eldex -PC设置的值无效
#define ERROR_ELDEX_SetRunState_ReturnInvalid                  (0x45313034)//E104 Eldex 设置运行-返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetStopState_Buile_Fail                    (0x45313035)//E105 ELDEX 设置暂停-编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetStopState_232_TimeOut                   (0x45313036)//E106 ELDEX 设置暂停-232接收超时
#define ERROR_ELDEX_SetStopState_PumpAsk_Buile_Fail            (0x45313037)//E107 Eldex 设置暂停-接收泵回复信息编译错误
#define ERROR_ELDEX_SetStopState_SetValuelInvalid              (0x45313038)//E108 Eldex -PC设置的值无效
#define ERROR_ELDEX_SetStopState_ReturnInvalid                 (0x45313039)//E109 Eldex 设置暂停-返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetFlowrate_Buile_Fail                     (0x45313061)//E10a ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetFlowrate_232_TimeOut                    (0x45313062)//E10b ELDEX -232接收超时
#define ERROR_ELDEX_SetFlowrate_PumpAsk_Buile_Fail             (0x45313063)//E10c Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetFlowrate_SetValuelInvalid               (0x45313064)//E10d Eldex -PC设置的值无效
#define ERROR_ELDEX_SetFlowrate_ReturnInvalid                  (0x45313065)//E10e Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetFlowrate_Buile_Fail                     (0x45313066)//E10f ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetFlowrate_232_TimeOut                    (0x45313067)//E10g ELDEX -232接收超时
#define ERROR_ELDEX_GetFlowrate_PumpAsk_Buile_Fail             (0x45313068)//E10h Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetFlowrate_SetValuelInvalid               (0x45313069)//E10i Eldex -PC设置的值无效
#define ERROR_ELDEX_GetFlowrate_ReturnInvalid                  (0x4531306a)//E10j Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetId_Buile_Fail                           (0x4531306b)//E10k ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetId_232_TimeOut                          (0x4531306c)//E10l ELDEX -232接收超时
#define ERROR_ELDEX_GetId_232_PumpAsk_Buile_Fail               (0x4531306d)//E10m Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetId_SetValuelInvalid                     (0x4531306e)//E10n Eldex -PC设置的值无效
#define ERROR_ELDEX_GetId_ReturnInvalid                        (0x4531306f)//E103o Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetPressure_Buile_Fail                     (0x45313060)//E10p ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetPressure_232_TimeOut                    (0x45313071)//E10q ELDEX -232接收超时
#define ERROR_ELDEX_GetPressure_PumpAsk_Buile_Fail             (0x45313072)//E10r Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetPressure_SetValuelInvalid               (0x45313073)//E10s Eldex -PC设置的值无效
#define ERROR_ELDEX_GetPressure_ReturnInvalid                  (0x45313074)//E10t Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetHeightPressureLimit_Buile_Fail          (0x45313075)//E10u ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetHeightPressureLimit_232_TimeOut         (0x45313076)//E10v ELDEX -232接收超时
#define ERROR_ELDEX_SetHeightPressureLimit_PumpAsk_Buile_Fail  (0x45313077)//E10w Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetHeightPressureLimit_SetValuelInvalid    (0x45313078)//E10x Eldex -PC设置的值无效
#define ERROR_ELDEX_SetHeightPressureLimit_ReturnInvalid       (0x45313079)//E10y Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetLowPressureLimit_Buile_Fail             (0x4531307a)//E10z ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetLowPressureLimit_232_TimeOut            (0x45313041)//E10A ELDEX -232接收超时
#define ERROR_ELDEX_SetLowPressureLimit_PumpAsk_Buile_Fail     (0x45313042)//E10B Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetLowPressureLimit_SetValuelInvalid       (0x45313043)//E10C Eldex -PC设置的值无效
#define ERROR_ELDEX_SetLowPressureLimit_ReturnInvalid          (0x45313044)//E10D Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetHeightPressureLimit_Buile_Fail          (0x45313045)//E10E ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetHeightPressureLimit_232_TimeOut         (0x45313046)//E10F ELDEX -232接收超时
#define ERROR_ELDEX_GetHeightPressureLimit_PumpAsk_Buile_Fail  (0x45313047)//E10G Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetHeightPressureLimit_SetValuelInvalid    (0x45313048)//E10H Eldex -PC设置的值无效
#define ERROR_ELDEX_GetHeightPressureLimit_ReturnInvalid       (0x45313049)//E10I Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetLowPressureLimit_Buile_Fail             (0x4531304A)//E10J ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetLowPressureLimit_232_TimeOut            (0x4531304B)//E10K ELDEX -232接收超时
#define ERROR_ELDEX_GetLowPressureLimit_PumpAsk_Buile_Fail     (0x4531304C)//E10L Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetLowPressureLimit_SetValuelInvalid       (0x4531304D)//E10M Eldex -PC设置的值无效
#define ERROR_ELDEX_GetLowPressureLimit_ReturnInvalid          (0x4531304E)//E10N Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetCompressComp_Buile_Fail                 (0x4531304F)//E10O ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetCompressComp_232_TimeOut                (0x45313050)//E10P ELDEX -232接收超时
#define ERROR_ELDEX_SetCompressComp_PumpAsk_Buile_Fail         (0x45313051)//E10Q Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetCompressComp_SetValuelInvalid           (0x45313052)//E10R Eldex -PC设置的值无效
#define ERROR_ELDEX_SetCompressComp_ReturnInvalid              (0x45313053)//E10S Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetCompressComp_Buile_Fail                 (0x45313054)//E10T ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetCompressComp_232_TimeOut                (0x45313055)//E10U ELDEX -232接收超时
#define ERROR_ELDEX_GetCompressComp_PumpAsk_Buile_Fail         (0x45313056)//E10V Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetCompressComp_SetValuelInvalid           (0x45313057)//E10W Eldex -PC设置的值无效
#define ERROR_ELDEX_GetCompressComp_ReturnInvalid              (0x45313058)//E10X Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetRefillRateFactor_Buile_Fail             (0x45313059)//E10Y ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetRefillRateFactor_232_TimeOut            (0x4531305A)//E10Z ELDEX -232接收超时
#define ERROR_ELDEX_SetRefillRateFactor_PumpAsk_Buile_Fail     (0x45313130)//E110 Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetRefillRateFactor_SetValuelInvalid       (0x45313131)//E111 Eldex -PC设置的值无效
#define ERROR_ELDEX_SetRefillRateFactor_ReturnInvalid          (0x45313132)//E112 Eldex -返回值不在指定访问内，DSP系统故障


#define ERROR_ELDEX_GetRefillRateFactor_Buile_Fail             (0x45313133)//E113 ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetRefillRateFactor_232_TimeOut            (0x45313134)//E114 ELDEX -232接收超时
#define ERROR_ELDEX_GetRefillRateFactor_PumpAsk_Buile_Fail     (0x45313135)//E115 Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetRefillRateFactor_SetValuelInvalid       (0x45313136)//E116 Eldex -PC设置的值无效
#define ERROR_ELDEX_GetRefillRateFactor_ReturnInvalid          (0x45313137)//E117 Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetDisablesKeypad_Buile_Fail               (0x45313138)//E118 ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetDisablesKeypad_232_TimeOut              (0x45313139)//E119 ELDEX -232接收超时
#define ERROR_ELDEX_SetDisablesKeypad_PumpAsk_Buile_Fail       (0x45313161)//E11a Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetDisablesKeypad_SetValuelInvalid         (0x45313162)//E11b Eldex -PC设置的值无效
#define ERROR_ELDEX_SetDisablesKeypad_ReturnInvalid            (0x45313163)//E11c Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetEnablesKeypad_Buile_Fail                (0x45313164)//E11d ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetEnablesKeypad_232_TimeOut               (0x45313165)//E11e ELDEX -232接收超时
#define ERROR_ELDEX_SetEnablesKeypad_PumpAsk_Buile_Fail        (0x45313166)//E11f Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetEnablesKeypad_SetValuelInvalid          (0x45313167)//E11g Eldex -PC设置的值无效
#define ERROR_ELDEX_SetEnablesKeypad_ReturnInvalid             (0x45313168)//E11h Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetPistonDiameter_Buile_Fail               (0x45313169)//E11i ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetPistonDiameter_232_TimeOut              (0x4531316a)//E11j ELDEX -232接收超时
#define ERROR_ELDEX_SetPistonDiameter_PumpAsk_Buile_Fail       (0x4531316b)//E11k Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetPistonDiameter_SetValuelInvalid         (0x4531316c)//E11l Eldex -PC设置的值无效
#define ERROR_ELDEX_SetPistonDiameter_ReturnInvalid            (0x4531316d)//E11m Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetPistonDiameter_Buile_Fail               (0x4531316e)//E11n ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetPistonDiameter_232_TimeOut              (0x4531317f)//E11o ELDEX -232接收超时
#define ERROR_ELDEX_GetPistonDiameter_PumpAsk_Buile_Fail       (0x45313170)//E11p Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetPistonDiameter_SetValuelInvalid         (0x45313171)//E11q Eldex -PC设置的值无效
#define ERROR_ELDEX_GetPistonDiameter_ReturnInvalid            (0x45313172)//E11r Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetStroke_Buile_Fail                       (0x45313173)//E11s ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetStroke_232_TimeOut                      (0x45313174)//E11t ELDEX -232接收超时
#define ERROR_ELDEX_SetStroke_PumpAsk_Buile_Fail               (0x45313175)//E11u Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetStroke_SetValuelInvalid                 (0x45313176)//E11v Eldex -PC设置的值无效
#define ERROR_ELDEX_SetStroke_ReturnInvalid                    (0x45313177)//E11w Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetStroke_Buile_Fail                       (0x45313178)//E11x ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetStroke_232_TimeOut                      (0x45313179)//E11y ELDEX -232接收超时
#define ERROR_ELDEX_GetStroke_PumpAsk_Buile_Fail               (0x4531317a)//E11z Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetStroke_SetValuelInvalid                 (0x45313141)//E11A Eldex -PC设置的值无效
#define ERROR_ELDEX_GetStroke_ReturnInvalid                    (0x45313142)//E11B Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetPumpMeterial_Buile_Fail                 (0x45313143)//E11C ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetPumpMeterial_232_TimeOut                (0x45313144)//E11D ELDEX -232接收超时
#define ERROR_ELDEX_SetPumpMeterial_PumpAsk_Buile_Fail         (0x45313145)//E11E Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetPumpMeterial_SetValuelInvalid           (0x45313146)//E11F Eldex -PC设置的值无效
#define ERROR_ELDEX_SetPumpMeterial_ReturnInvalid              (0x45313147)//E11G Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetPumpMeterial_Buile_Fail                 (0x45313148)//E11H ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetPumpMeterial_232_TimeOut                (0x45313149)//E11I ELDEX -232接收超时
#define ERROR_ELDEX_GetPumpMeterial_PumpAsk_Buile_Fail         (0x4531314A)//E11J Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetPumpMeterial_SetValuelInvalid           (0x4531314B)//E11K Eldex -PC设置的值无效
#define ERROR_ELDEX_GetPumpMeterial_ReturnInvalid              (0x4531314C)//E11L Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetFaultStatus_Buile_Fail                  (0x4531314D)//E11M ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetFaultStatus_232_TimeOut                 (0x4531314E)//E11N ELDEX -232接收超时
#define ERROR_ELDEX_GetFaultStatus_PumpAsk_Buile_Fail          (0x4531314F)//E11O Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetFaultStatus_SetValuelInvalid            (0x45313150)//E11P Eldex -PC设置的值无效
#define ERROR_ELDEX_GetFaultStatus_ReturnInvalid               (0x45313151)//E11Q Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetLedRedStopPump_Buile_Fail               (0x45313152)//E11R ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetLedRedStopPump_232_TimeOut              (0x45313153)//E11S ELDEX -232接收超时
#define ERROR_ELDEX_SetLedRedStopPump_PumpAsk_Buile_Fail       (0x45313154)//E11T Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetLedRedStopPump_SetValuelInvalid         (0x45313155)//E11U Eldex -PC设置的值无效
#define ERROR_ELDEX_SetLedRedStopPump_ReturnInvalid            (0x45313156)//E11V Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_GetInterfacePara_Buile_Fail                (0x45313157)//E11W ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_GetInterfacePara_232_TimeOut               (0x45313158)//E11X ELDEX -232接收超时
#define ERROR_ELDEX_GetInterfacePara_PumpAsk_Buile_Fail        (0x45313159)//E11Y Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_GetInterfacePara_SetValuelInvalid          (0x4531315A)//E11Z Eldex -PC设置的值无效
#define ERROR_ELDEX_GetInterfacePara_ReturnInvalid             (0x45313230)//E120 Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_ELDEX_SetRestCmdBuf_Buile_Fail                   (0x45313231)//E121 ELDEX -编译指令错误（DSP提供内存不足）
#define ERROR_ELDEX_SetRestCmdBuf_232_TimeOut                  (0x45313232)//E122 ELDEX -232接收超时
#define ERROR_ELDEX_SetRestCmdBuf_PumpAsk_Buile_Fail           (0x45313233)//E123 Eldex -接收泵回复信息编译错误
#define ERROR_ELDEX_SetRestCmdBuf_SetValuelInvalid             (0x45313234)//E124 Eldex -PC设置的值无效
#define ERROR_ELDEX_SetRestCmdBuf_ReturnInvalid                (0x45313235)//E125 Eldex -返回值不在指定访问内，DSP系统故障

#define ERROR_GPIO_NOT_READ_NOT_WRITE                          (0x45323030)//E200 Gpio收到的令牌即不是读令牌也不是写令牌
#define ERROR_GPIOI_NVALIDDATA                                 (0x45323031)//E201 Gpio Pc写无效数据-回复PC用

#define ERROR_IDEX_MoveNewPos_Buile_Fail                       (0x45333030)//E300 IDEX-编译指令错误（DSP提供内存不足）
#define ERROR_IDEX_MoveNewPos_IIC_TimeOut                      (0x45333031)//E301 IDEX -I2C接收超时
#define ERROR_IDEX_MoveNewPos_PumpAsk_Buile_Fail               (0x45333032)//E302 IDEX -接收泵回复信息编译错误
#define ERROR_IDEX_MoveNewPos_SetValuelInvalid                 (0x45333033)//E303 IDEX -PC设置的值无效
#define ERROR_IDEX_MoveNewPos_ReturnInvalid                    (0x45333034)//E304 IDEX-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_Init_Buile_Fail                            (0x45343030)//E400 TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_Init_485_TimeOut                           (0x45343031)//E401 TECAN -485接收超时
#define ERROR_TECAN_Init_PumpAsk_Buile_Fail                    (0x45343032)//E402 TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_Init_SetValuelInvalid                      (0x45343033)//E403 TECAN -PC设置的值无效
#define ERROR_TECAN_Init_ReturnInvalid                         (0x45343034)//E404 TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_Ejtct_Buile_Fail                           (0x45343035)//E405 TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_Ejtct_485_TimeOut                          (0x45343036)//E406 TECAN -485接收超时
#define ERROR_TECAN_Ejtct_PumpAsk_Buile_Fail                   (0x45343037)//E407 TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_Ejtct_SetValuelInvalid                     (0x45343038)//E408 TECAN -PC设置的值无效
#define ERROR_TECAN_Ejtct_ReturnInvalid                        (0x45343039)//E409 TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_PosAbs_Buile_Fail                          (0x45343061)//E40a TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_PosAbs_485_TimeOut                         (0x45343062)//E40b TECAN -485接收超时
#define ERROR_TECAN_PosAbs_PumpAsk_Buile_Fail                  (0x45343063)//E40c TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_PosAbs_SetValuelInvalid                    (0x45343064)//E40d TECAN -PC设置的值无效
#define ERROR_TECAN_PosAbs_ReturnInvalid                       (0x45343065)//E40e TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_Aspirate_Buile_Fail                        (0x45343066)//E40f TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_Aspirate_485_TimeOut                       (0x45343067)//E40g TECAN -485接收超时
#define ERROR_TECAN_Aspirate_PumpAsk_Buile_Fail                (0x45343068)//E40h TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_Aspirate_SetValuelInvalid                  (0x45343069)//E40i TECAN -PC设置的值无效
#define ERROR_TECAN_Aspirate_ReturnInvalid                     (0x4534306a)//E40j TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_Distribute_Buile_Fail                      (0x4534306b)//E40k TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_Distribute_485_TimeOut                     (0x4534306c)//E40l TECAN -485接收超时
#define ERROR_TECAN_Distribute_PumpAsk_Buile_Fail              (0x4534306d)//E40m TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_Distribute_SetValuelInvalid                (0x4534306e)//E40n TECAN -PC设置的值无效
#define ERROR_TECAN_Distribute_ReturnInvalid                   (0x4534306f)//E40o TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_SetMaxSpeed_Buile_Fail                     (0x45343070)//E40p TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_SetMaxSpeed_485_TimeOut                    (0x45343071)//E40q TECAN -485接收超时
#define ERROR_TECAN_SetMaxSpeed_PumpAsk_Buile_Fail             (0x45343072)//E40r TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_SetMaxSpeed_SetValuelInvalid               (0x45343073)//E40s TECAN -PC设置的值无效
#define ERROR_TECAN_SetMaxSpeed_ReturnInvalid                  (0x45343074)//E40t TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_SetStartSpeed_Buile_Fail                   (0x45343075)//E40u TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_SetStartSpeed_485_TimeOut                  (0x45343076)//E40v TECAN -485接收超时
#define ERROR_TECAN_SetStartSpeed_PumpAsk_Buile_Fail           (0x45343077)//E40w TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_SetStartSpeed_SetValuelInvalid             (0x45343078)//E40x TECAN -PC设置的值无效
#define ERROR_TECAN_SetStartSpeed_ReturnInvalid                (0x45343079)//E40y TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_SetStopSpeed_Buile_Fail                    (0x4534307a)//E40z TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_SetStopSpeed_485_TimeOut                   (0x45343041)//E40A TECAN -485接收超时
#define ERROR_TECAN_SetStopSpeed_PumpAsk_Buile_Fail            (0x45343042)//E40B TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_SetStopSpeed_SetValuelInvalid              (0x45343043)//E40C TECAN -PC设置的值无效
#define ERROR_TECAN_SetStopSpeed_ReturnInvalid                 (0x45343044)//E40D TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_SetSlope_Buile_Fail                        (0x45343045)//E40E TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_SetSlope_485_TimeOut                       (0x45343046)//E40F TECAN -485接收超时
#define ERROR_TECAN_SetSlope_PumpAsk_Buile_Fail                (0x45343047)//E40G TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_SetSlope_SetValuelInvalid                  (0x45343048)//E40H TECAN -PC设置的值无效
#define ERROR_TECAN_SetSlope_ReturnInvalid                     (0x45343049)//E40I TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_SetBackImpulse_Buile_Fail                  (0x4534304a)//E40J TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_SetBackImpulse_485_TimeOut                 (0x4534304b)//E40K TECAN -485接收超时
#define ERROR_TECAN_SetBackImpulse_PumpAsk_Buile_Fail          (0x4534304c)//E40K TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_SetBackImpulse_SetValuelInvalid            (0x4534304d)//E40M TECAN -PC设置的值无效
#define ERROR_TECAN_SetBackImpulse_ReturnInvalid               (0x4534304e)//E40N TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_RSet_Buile_Fail                            (0x4534304f)//E40O TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_RSet_485_TimeOut                           (0x45343050)//E40P TECAN -485接收超时
#define ERROR_TECAN_RSet_PumpAsk_Buile_Fail                    (0x45343051)//E40Q TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_RSet_SetValuelInvalid                      (0x45343052)//E40R TECAN -PC设置的值无效
#define ERROR_TECAN_RSet_ReturnInvalid                         (0x45343053)//E40S TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_CLeanCmdBuf_Buile_Fail                     (0x45343054)//E40T TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_CLeanCmdBuf_485_TimeOut                    (0x45343055)//E40U TECAN -485接收超时
#define ERROR_TECAN_CLeanCmdBuf_PumpAsk_Buile_Fail             (0x45343056)//E40V TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_CLeanCmdBuf_SetValuelInvalid               (0x45343057)//E40W TECAN -PC设置的值无效
#define ERROR_TECAN_CLeanCmdBuf_ReturnInvalid                  (0x45343058)//E40X TECAN-返回值不在指定访问内，DSP系统故障

#define ERROR_TECAN_GetState_Buile_Fail                        (0x45343059)//E40Y TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_GetState_485_TimeOut                       (0x4534305A)//E40Z TECAN -485接收超时
#define ERROR_TECAN_GetState_PumpAsk_Buile_Fail                (0x45343130)//E410 TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_GetState_SetValuelInvalid                  (0x45343131)//E411 TECAN -PC设置的值无效
#define ERROR_TECAN_GetState_ReturnInvalid                     (0x45343132)//E412 TECAN-返回值不在指定访问内，DSP系统故障
#define ERROR_TECAN_GetState_ReturnStateInvalid                (0x45343133)//E413 TECAN-返回值状态信息不在指定范围内，泵返回状态异常

#define ERROR_TECAN_NOREADY                                    (0x45343134)//E414
//add by zzz
#define ERROR_TECAN_FakeInit_Buile_Fail                        (0x45343135)//E415 TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_FakeInit_485_TimeOut                       (0x45343136)//E416 TECAN -485接收超时
#define ERROR_TECAN_FakeInit_PumpAsk_Buile_Fail                (0x45343137)//E417 TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_FakeInit_SetValuelInvalid                  (0x45343138)//E418 TECAN -PC设置的值无效
#define ERROR_TECAN_FakeInit_ReturnInvalid                     (0x45343139)//E419 TECAN-返回值不在指定访问内，DSP系统故障
#define ERROR_TECAN_FakeInit_ReturnStateInvalid                (0x45343161)//E41a TECAN-返回值状态信息不在指定范围内，泵返回状态异常

#define ERROR_TECAN_MulCmdLoops_Buile_Fail                        (0x45343162)//E41b TECAN-编译指令错误（DSP提供内存不足）
#define ERROR_TECAN_MulCmdLoops_485_TimeOut                       (0x45343163)//E41c TECAN -485接收超时
#define ERROR_TECAN_MulCmdLoops_PumpAsk_Buile_Fail                (0x45343164)//E41d TECAN -接收泵回复信息编译错误
#define ERROR_TECAN_MulCmdLoops_SetValuelInvalid                  (0x45343165)//E41e TECAN -PC设置的值无效
#define ERROR_TECAN_MulCmdLoops_ReturnInvalid                     (0x45343166)//E41f TECAN-返回值不在指定访问内，DSP系统故障
#define ERROR_TECAN_MulCmdLoops_ReturnStateInvalid                (0x45343167)//E41g TECAN-返回值状态信息不在指定范围内，泵返回状态异常
//add by zzz

#define ERROR_LANPER_SetRunPar_Buile_Fail                      (0x45353030)//E500 LANPER-编译指令错误（DSP提供内存不足）
#define ERROR_LANPER_SetRunPar_485_TimeOut                     (0x45353031)//E501 LANPER -485接收超时
#define ERROR_LANPER_SetRunPar_PumpAsk_Buile_Fail              (0x45353032)//E502 LANPER -接收泵回复信息编译错误
#define ERROR_LANPER_SetRunPar_SetValuelInvalid                (0x45353033)//E503 LANPER -PC设置的值无效
#define ERROR_LANPER_SetRunPar_ReturnInvalid                   (0x45353034)//E504 LANPER-返回值不在指定访问内，DSP系统故障

#define ERROR_LANPER_GetRunPar_Buile_Fail                      (0x45353035)//E505 LANPER-编译指令错误（DSP提供内存不足）
#define ERROR_LANPER_GetRunPar_485_TimeOut                     (0x45353036)//E506 LANPER -485接收超时
#define ERROR_LANPER_GetRunPar_PumpAsk_Buile_Fail              (0x45353037)//E507 LANPER -接收泵回复信息编译错误
#define ERROR_LANPER_GetRunPar_SetValuelInvalid                (0x45353038)//E508 LANPER -PC设置的值无效
#define ERROR_LANPER_GetRunPar_ReturnInvalid                   (0x45353039)//E509 LANPER-返回值不在指定访问内，DSP系统故障

#define ERROR_LANPER_RSetId_Buile_Fail                         (0x45353061)//E50a LANPER-编译指令错误（DSP提供内存不足）
#define ERROR_LANPER_RSetId_485_TimeOut                        (0x45353062)//E50b LANPER -485接收超时
#define ERROR_LANPER_RSetId_PumpAsk_Buile_Fail                 (0x45353063)//E50c LANPER -接收泵回复信息编译错误
#define ERROR_LANPER_RSetId_SetValuelInvalid                   (0x45353064)//E50d LANPER -PC设置的值无效
#define ERROR_LANPER_RSetId_ReturnInvalid                      (0x45353065)//E50e LANPER-返回值不在指定访问内，DSP系统故障

#define ERROR_LANPER_GetId_Buile_Fail                          (0x45353066)//E50f LANPER-编译指令错误（DSP提供内存不足）
#define ERROR_LANPER_GetId_485_TimeOut                         (0x45353067)//E50g LANPER -485接收超时
#define ERROR_LANPER_GetId_PumpAsk_Buile_Fail                  (0x45353078)//E50h LANPER -接收泵回复信息编译错误
#define ERROR_LANPER_GetId_SetValuelInvalid                    (0x45353069)//E50i LANPER -PC设置的值无效
#define ERROR_LANPER_GetId_ReturnInvalid                       (0x4535306a)//E50j LANPER-返回值不在指定访问内，DSP系统故障

/************************************** HAMILTON error code *****************************************************************************/
#define ERROR_HAMILTON_Init_Buile_Fail                            (0x45363030)//E600 HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Init_232_TimeOut                           (0x45363031)//E601 HAMILTON -232接收超时
#define ERROR_HAMILTON_Init_PumpAsk_Buile_Fail                    (0x45363032)//E602 HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Init_SetValuelInvalid                      (0x45363033)//E603 HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Init_ReturnInvalid                         (0x45363034)//E604 HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_RepMsg_Buile_Fail                           (0x45363035)//E605 HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_RepMsg_232_TimeOut                          (0x45363036)//E606 HAMILTON -232接收超时
#define ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail                   (0x45363037)//E607 HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_RepMsg_SetValuelInvalid                     (0x45363038)//E608 HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_RepMsg_ReturnInvalid                        (0x45363039)//E609 HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_PosAbs_Buile_Fail                          (0x45363061)//E60a HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_PosAbs_232_TimeOut                         (0x45363062)//E60b HAMILTON -232接收超时
#define ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail                  (0x45363063)//E60c HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_PosAbs_SetValuelInvalid                    (0x45363064)//E60d HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_PosAbs_ReturnInvalid                       (0x45363065)//E60e HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_Pickup_Buile_Fail                        (0x45363066)//E60f HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Pickup_232_TimeOut                       (0x45363067)//E60g HAMILTON -232接收超时
#define ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail                (0x45363068)//E60h HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Pickup_SetValuelInvalid                  (0x45363069)//E60i HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Pickup_ReturnInvalid                     (0x4536306a)//E60j HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_Dispense_Buile_Fail                      (0x4536306b)//E60k HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Dispense_232_TimeOut                     (0x4536306c)//E60l HAMILTON -232接收超时
#define ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail              (0x4536306d)//E60m HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Dispense_SetValuelInvalid                (0x4536306e)//E60n HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Dispense_ReturnInvalid                   (0x4536306f)//E60o HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetMaxSpeed_Buile_Fail                     (0x45363070)//E60p HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetMaxSpeed_232_TimeOut                    (0x45363071)//E60q HAMILTON -232接收超时
#define ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail             (0x45363072)//E60r HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid               (0x45363073)//E60s HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid                  (0x45363074)//E60t HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetStartSpeed_Buile_Fail                   (0x45363075)//E60u HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetStartSpeed_232_TimeOut                  (0x45363076)//E60v HAMILTON -232接收超时
#define ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail           (0x45363077)//E60w HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid             (0x45363078)//E60x HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetStartSpeed_ReturnInvalid                (0x45363079)//E60y HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetStopSpeed_Buile_Fail                    (0x4536307a)//E60z HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetStopSpeed_232_TimeOut                   (0x45363041)//E60A HAMILTON -232接收超时
#define ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail            (0x45363042)//E60B HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid              (0x45363043)//E60C HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetStopSpeed_ReturnInvalid                 (0x45363044)//E60D HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetAcceler_Buile_Fail                        (0x45363045)//E60E HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetAcceler_232_TimeOut                       (0x45363046)//E60F HAMILTON -232接收超时
#define ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail                (0x45363047)//E60G HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetAcceler_SetValuelInvalid                  (0x45363048)//E60H HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetAcceler_ReturnInvalid                     (0x45363049)//E60I HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetBackSteps_Buile_Fail                  (0x4536304a)//E60J HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetBackSteps_232_TimeOut                 (0x4536304b)//E60K HAMILTON -232接收超时
#define ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail          (0x4536304c)//E60K HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetBackSteps_SetValuelInvalid            (0x4536304d)//E60M HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetBackSteps_ReturnInvalid               (0x4536304e)//E60N HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_RSet_Buile_Fail                            (0x4536304f)//E60O HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_RSet_232_TimeOut                           (0x45363050)//E60P HAMILTON -232接收超时
#define ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail                    (0x45363051)//E60Q HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_RSet_SetValuelInvalid                      (0x45363052)//E60R HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_RSet_ReturnInvalid                         (0x45363053)//E60S HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_TerminalCmd_Buile_Fail                     (0x45363054)//E60T HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_TerminalCmd_232_TimeOut                    (0x45363055)//E60U HAMILTON -232接收超时
#define ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail             (0x45363056)//E60V HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_TerminalCmd_SetValuelInvalid               (0x45363057)//E60W HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_TerminalCmd_ReturnInvalid                  (0x45363058)//E60X HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_GetState_Buile_Fail                        (0x45363059)//E60Y HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_GetState_232_TimeOut                       (0x4536305A)//E60Z HAMILTON -232接收超时
#define ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail                (0x45363130)//E610 HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_GetState_SetValuelInvalid                  (0x45363131)//E611 HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_GetState_ReturnInvalid                     (0x45363132)//E612 HAMILTON-返回值不在指定访问内，DSP系统故障
#define ERROR_HAMILTON_GetState_ReturnStateInvalid                (0x45363133)//E613 HAMILTON-返回值状态信息不在指定范围内，泵返回状态异常
//add by zzz
#define ERROR_HAMILTON_Input_Buile_Fail                           (0x45363135)//E615 HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Input_232_TimeOut                          (0x45363136)//E616 HAMILTON -232接收超时
#define ERROR_HAMILTON_Input_PumpAsk_Buile_Fail                   (0x45363137)//E617 HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Input_SetValuelInvalid                     (0x45363138)//E618 HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Input_ReturnInvalid                        (0x45363139)//E619 HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_Output_Buile_Fail                           (0x45363141)//E61A HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Output_232_TimeOut                          (0x45363142)//E61B HAMILTON -232接收超时
#define ERROR_HAMILTON_Output_PumpAsk_Buile_Fail                   (0x45363143)//E61C HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Output_SetValuelInvalid                     (0x45363144)//E61D HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Output_ReturnInvalid                        (0x45363145)//E61E HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetCounterPos_Buile_Fail                           (0x45363146)//E61A HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetCounterPos_232_TimeOut                          (0x45363147)//E61B HAMILTON -232接收超时
#define ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail                   (0x45363148)//E61C HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetCounterPos_SetValuelInvalid                     (0x45363149)//E61D HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetCounterPos_ReturnInvalid                        (0x4536314A)//E61E HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_RepDevStat_Buile_Fail                              (0x4536314B)//E61A HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_RepDevStat_232_TimeOut                             (0x4536314C)//E61B HAMILTON -232接收超时
#define ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail                      (0x4536314D)//E61C HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_RepDevStat_SetValuelInvalid                        (0x4536314E)//E61D HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_RepDevStat_ReturnInvalid                           (0x4536314F)//E61E HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_MulCmdPosMove_Buile_Fail                           (0x45363150)//E61F HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_MulCmdPosMove_232_TimeOut                          (0x45363151)//E61G HAMILTON -232接收超时
#define ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail                   (0x45363152)//E61H HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid                     (0x45363153)//E61I HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid                        (0x45363154)//E61K HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_SetSpeed_Buile_Fail                                (0x45363155)//E61L HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_SetSpeed_232_TimeOut                          	  (0x45363156)//E61M HAMILTON -232接收超时
#define ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail                        (0x45363157)//E61N HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_SetSpeed_SetValuelInvalid                          (0x45363158)//E61O HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_SetSpeed_ReturnInvalid                             (0x45363159)//E61P HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_Comtinue_Buile_Fail                                (0x45363155)//E61L HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_Comtinue_232_TimeOut                          	  (0x45363156)//E61M HAMILTON -232接收超时
#define ERROR_HAMILTON_Comtinue_PumpAsk_Buile_Fail                        (0x45363157)//E61N HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_Comtinue_SetValuelInvalid                          (0x45363158)//E61O HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_Comtinue_ReturnInvalid                             (0x45363159)//E61P HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_HAMILTON_MulAbs_Buile_Fail                                  (0x4536315A)//E61Q HAMILTON-编译指令错误（DSP提供内存不足）
#define ERROR_HAMILTON_MulAbs_232_TimeOut                          	      (0x4536315B)//E61R HAMILTON -232接收超时
#define ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail                          (0x4536315C)//E61S HAMILTON -接收泵回复信息编译错误
#define ERROR_HAMILTON_MulAbs_SetValuelInvalid                            (0x4536315D)//E61T HAMILTON -PC设置的值无效
#define ERROR_HAMILTON_MulAbs_ReturnInvalid                               (0x4536315E)//E61U HAMILTON-返回值不在指定访问内，DSP系统故障

#define ERROR_MVP_Init_Buile_Fail                                  (0x45373030)//E700 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MVP_Init_232_TimeOut                          	   (0x45373031)//E701 MVP -232接收超时
#define ERROR_MVP_Init_Ask_Buile_Fail                          	   (0x45373032)//E702 MVP -接收泵回复信息编译错误
#define ERROR_MVP_Init_SetValuelInvalid                            (0x45373033)//E703 MVP -PC设置的值无效
#define ERROR_MVP_Init_ReturnInvalid                               (0x45373034)//E704 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MVP_Move_Buile_Fail                                  (0x45373035)//E705 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MVP_Move_232_TimeOut                          	   (0x45373036)//E706 MVP -232接收超时
#define ERROR_MVP_Move_Ask_Buile_Fail                              (0x45373037)//E707 MVP -接收泵回复信息编译错误
#define ERROR_MVP_Move_SetValuelInvalid                            (0x45373038)//E708 MVP -PC设置的值无效
#define ERROR_MVP_Move_ReturnInvalid                               (0x45373039)//E709 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MVP_Report_Buile_Fail                                  (0x4537303A)//E700 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MVP_Report_232_TimeOut                          	     (0x4537303B)//E701 MVP -232接收超时
#define ERROR_MVP_Report_Ask_Buile_Fail                              (0x4537303C)//E702 MVP -接收泵回复信息编译错误
#define ERROR_MVP_Report_SetValuelInvalid                            (0x4537303D)//E703 MVP -PC设置的值无效
#define ERROR_MVP_Report_ReturnInvalid                               (0x4537303E)//E704 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MVP_EnableCmd_Buile_Fail                                  (0x45373040)//E700 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MVP_EnableCmd_232_TimeOut                          	    (0x45373041)//E701 MVP -232接收超时
#define ERROR_MVP_EnableCmd_Ask_Buile_Fail                              (0x45373042)//E702 MVP -接收泵回复信息编译错误
#define ERROR_MVP_EnableCmd_SetValuelInvalid                            (0x45373043)//E703 MVP -PC设置的值无效
#define ERROR_MVP_EnableCmd_ReturnInvalid                               (0x45373044)//E704 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MVP_RepStat_Buile_Fail                                  (0x45373045)//E700 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MVP_RepStat_232_TimeOut                          	      (0x45373046)//E701 MVP -232接收超时
#define ERROR_MVP_RepStat_Ask_Buile_Fail                              (0x45373047)//E702 MVP -接收泵回复信息编译错误
#define ERROR_MVP_RepStat_SetValuelInvalid                            (0x45373048)//E703 MVP -PC设置的值无效
#define ERROR_MVP_RepStat_ReturnInvalid                               (0x45373049)//E704 MVP-返回值不在指定访问内，DSP系统故障


#define ERROR_MDS_SetFreq_Buile_Fail                                  (0x45373130)//E710 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MDS_SetFreq_232_TimeOut                          	      (0x45373131)//E711 MVP -232接收超时
#define ERROR_MDS_SetFreq_Ask_Buile_Fail                          	  (0x45373132)//E712 MVP -接收泵回复信息编译错误
#define ERROR_MDS_SetFreq_SetValuelInvalid                            (0x45373133)//E713 MVP -PC设置的值无效
#define ERROR_MDS_SetFreq_ReturnInvalid                               (0x45373134)//E714 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MDS_SetPow_Buile_Fail                                  (0x45373135)//E715 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MDS_SetPow_232_TimeOut                          	     (0x45373136)//E716 MVP -232接收超时
#define ERROR_MDS_SetPow_Ask_Buile_Fail                              (0x45373137)//E717 MVP -接收泵回复信息编译错误
#define ERROR_MDS_SetPow_SetValuelInvalid                            (0x45373138)//E718 MVP -PC设置的值无效
#define ERROR_MDS_SetPow_ReturnInvalid                               (0x45373139)//E719 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MDS_SetdBm_Buile_Fail                                (0x4537313A)//E710 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MDS_SetdBm_232_TimeOut                          	   (0x4537313B)//E711 MVP -232接收超时
#define ERROR_MDS_SetdBm_Ask_Buile_Fail                            (0x4537313C)//E712 MVP -接收泵回复信息编译错误
#define ERROR_MDS_SetdBm_SetValuelInvalid                          (0x4537313D)//E713 MVP -PC设置的值无效
#define ERROR_MDS_SetdBm_ReturnInvalid                             (0x4537313E)//E714 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MDS_SetSwitch_Buile_Fail                             (0x45373140)//E710 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MDS_SetSwitch_232_TimeOut                            (0x45373141)//E711 MVP -232接收超时
#define ERROR_MDS_SetSwitch_Ask_Buile_Fail                         (0x45373142)//E712 MVP -接收泵回复信息编译错误
#define ERROR_MDS_SetSwitch_SetValuelInvalid                       (0x45373143)//E713 MVP -PC设置的值无效
#define ERROR_MDS_SetSwitch_ReturnInvalid                          (0x45373144)//E714 MVP-返回值不在指定访问内，DSP系统故障

#define ERROR_MDS_RepPara_Buile_Fail                             (0x45373145)//E710 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_MDS_RepPara_232_TimeOut                            (0x45373146)//E711 MVP -232接收超时
#define ERROR_MDS_RepPara_Ask_Buile_Fail                         (0x45373147)//E712 MVP -接收泵回复信息编译错误
#define ERROR_MDS_RepPara_SetValuelInvalid                       (0x45373148)//E713 MVP -PC设置的值无效
#define ERROR_MDS_RepPara_ReturnInvalid                          (0x45373149)//E714 MVP-返回值不在指定访问内，DSP系统故障

/****************************************Weigh*******************************************/
#define ERROR_Weigh_ReportWeigh_Buile_Fail                                  (0x4538303A)//E700 MVP-编译指令错误（DSP提供内存不足）
#define ERROR_Weigh_ReportWeigh_485_TimeOut                          	    (0x4538303B)//E701 MVP -232接收超时
#define ERROR_Weigh_ReportWeigh_Ask_Buile_Fail                              (0x4538303C)//E702 MVP -接收泵回复信息编译错误
#define ERROR_Weigh_ReportWeigh_SetValuelInvalid                            (0x4538303D)//E703 MVP -PC设置的值无效
#define ERROR_Weigh_ReportWeigh_ReturnInvalid                               (0x4538303E)//E704 MVP-返回值不在指定访问内，DSP系统故障

#define Weigh_MSG_MAX_SIZE 20
extern Uint32 WEIGHGetWeight(Uint8 WhichCom,Uint32 index);
Uint32 WeighBuildGetWeight(Uint32 devAddr,char *msbuf,Uint32 bufsize);
Uint16 CRC_GetModbus16(Uint8 *pdata, int len);
Uint16 GetCrc_16(Uint8 * pData, int nLength,
	Uint16 init, const
	Uint16 *ptable);
/****************************Eldex蠕动泵控制令牌********************************/
#define ELDEX_SET_RUN       0X00005255//“RU”   运行
#define ELDEX_SET_STOP      0X00005354//“ST”   暂停
#define ELDEX_SET_SPEED     0X00005346//“SF”   设置流速
#define ELDEX_GET_SPEED     0X00005246//“RF”   读取流速
#define ELDEX_GET_ID        0X00004944//"ID"   读取ID号
#define ELDEX_GET_PRESSURE  0X00005250//"RP"   读取泵压力
#define ELDEX_SET_H         0X00005348//"SH"   设置压力上限
#define ELDEX_SET_L         0X0000534C//"SL"   设置压力下限
#define ELDEX_GET_H         0X00005248//"RH"   读取压力上限
#define ELDEX_GET_L         0X0000524C//"RL"   读取压力下限
#define ELDEX_SET_CS        0X00005343//"SC"   设置压力补偿系数
#define ELDEX_GET_CS        0X00005243//"RC"   读取压力补偿系数
#define ELDEX_SET_SR        0X00005352//"SR"
#define ELDEX_GET_RR        0X00005252//"RR"
#define ELDEX_DISABLE_KB    0X00004B44//"KD"   禁用键盘
#define ELDEX_ENABLE_KB     0X00004B45//"KE"   使能键盘
#define ELDEX_SET_DIAMETER  0X00005344//"SD"   设置活塞直径
#define ELDEX_GET_DIAMETER  0X00005244//"RD"   读取活塞直径
#define ELDEX_SET_STROKE    0X00005353//"SS"   设置活塞冲程
#define ELDEX_GET_STROKE    0X00005253//"RS"   读取活塞冲程
#define ELDEX_SET_MATERIAL  0X0000534D//"SM"
#define ELDEX_GET_MATERIAL  0X0000524D//"RM"
#define ELDEX_GET_ERROR     0X00005258//"RX"   读取故障
#define ELDEX_SET_STOPLED   0X00005358//"SX"   停止泵并电亮LED
#define ELDEX_GET_INFO      0X00005249//"RI"   读取信息
#define ELDEX_CLEAR_CMDFIFO 0X0000005A//"Z"    清除命令缓冲区
/****************************LanPer蠕动泵控制令牌********************************/
#define LANPER_SET_RUN_PAR  0x0000574a//"WJ"   PC设置泵运行参数
#define LANPER_RED_RUN_PAR  0x0000524a//"RJ"   PC读取泵运行参数
#define LANPER_SET_NEW_ADD  0x00574944//"WID"  PC设置泵新地址本项目中，泵地址只可以设置为“1”，提供复位位“1”，不开放设置其他地址，避免混乱
//#define LANPER_RSET_ID      0x57524944//"WRID"PC 复位蠕动泵地址为“1”//协议版本2删除
#define LANPER_RED_ID       0x00524944//"RID"  PC读取泵新地址
#define LANPER_SET_ID       0x00534944//"SID"  PC设置泵新地址//协议版本2添加
#define LANPER_ADDR_1               1//        pump default address1,兰格蠕动泵使用的是485总线式传输，1200-485-1发送
#define LANPER_ADDR_BROADCAST      31//        pump broadcast address
/****************************Idex分配阀控制指牌********************************/
#define IDEX_RUN_POSITION   0X00000050//“P”    PC指定阀位置
#define IDEX_SET_PROFILE    0X0000004F//“O”    PC设置profile
#define IDEX_SET_NEWID      0X0000004E//“N”    PC设置新地址
#define IDEX_SET_CMDMODE    0X00000046//“F”    PC设定命令模式
#define IDEX_SET_UARTBUND   0X00000058//“X”    PC设定UART波特率
#define IDEX_RUN_HOME       0X0000004D//“M”    PC阀归为
#define IDEX_READ_POSITION  0X00000053//“S”    PC读取阀位置
#define IDEX_READ_PROFILE   0X00000051//“Q”    PC读取profile
#define IDEX_READ_FIRMWARE  0X00000052//“R”    PC读取固件信息
#define IDEX_READ_LASTERRO  0X00000045//“E”    PC读取最后一个错误
#define IDEX_READ_CMDMODE   0X00000044//“D”    PC读命令模式
#define LANPER_ADDR_WRITE        0x0E//        I2C写地址       LANPER？  IDEX_WRITEADDR
#define LANPER_ADDR_READ         0x0F//        I2C读地址
/****************************Tecan分配阀控制指牌********************************/
#define TECAN_INIT         0x00002F57//"/W"     PC设置泵运行速度
#define TECAN_FAKEINIT	   0x00002F7A//"/z"		PC设置假初始化
#define TECAN_EJECT        0x00002F45//"/E"     顶出一次性针头
#define TECAN_POS_ABS      0x00002F41//"/A"     设置绝对位置
#define TECAN_ASPIRATE     0x00002F50//"/P"     相对吸取
#define TECAN_DISTRIBUTE   0x00002F44//"/D"     相对释放
#define TECAN_MAX_SPEED    0x00002F56//"/V"     设置最高速度
#define TECAN_START_SPEED  0x00002F76//"/v"     设置启动速度
#define TECAN_STOP_SPEED   0x00002F63//"/c"     设置断流速度
#define TECAN_SLOPE        0x00002F4C//"/L"     设置坡度
#define TECAN_BACK_IMPULSE 0x00002F4B//"/K"     设置后冲量
#define TECAN_MULCMDLOOPS  0x00002F47//"/G"     多命令循环模式（多用于洗针）
#define TECAN_    0x00002F//"/>"
#define TECAN_    0x00002F//"/R"
#define TECAN_    0x00002F//"/X"
#define TECAN_    0x00002F//"/G"
#define TECAN_    0x00002F//"/g"
#define TECAN_    0x00002F//"/M"
#define TECAN_    0x00002F//"/H"
#define TECAN_REST_DEV    0x00002F21//"/!" 复位设备
#define TECAN_    0x00002F//"/s"
#define TECAN_    0x00002F//"/e"
#define TECAN_CLEAN_CMD    0x00002F43//"/C"清除命令缓冲区
#define TECAN_GET_STATE    0x00002F51//"/Q"请求设备状态
#define TECAN_    0x00002F//"/&"
#define TECAN_    0x00002F//"/<"
#define TECAN_    0x00002F//"/:"
#define TECAN_    0x00002F//"/="
#define TECAN_    0x00002F//"/?"
#define TECAN_    0x00002F//"/?76"
#define TECAN_    0x00002F//"/?77"
#define TECAN_    0x00002F//"/#"*/
/****************************GOIO控制指牌********************************/
#define READIO              0x5245494f//"REIO" 读IO
#define WRITEIO             0x5752494f//"WRIO" 写IO
/****************************F335控制指牌********************************/
#define READF335            0x52454633//"REF3" 读F335

#define READUL          	0x5245554C//"REUL" 读超声波52,45,55,4c,

#define READTE          	0x52455445//"RETE" 读温度

#define GTVO				0x4754564f //"GTVO"  获取设定电压
/****************************HEAT发热丝控制令牌********************************/
#define HEAT            	0x48454154//"HEAT" 上位机控制发热丝
/****************************Hamilton分配阀控制指牌********************************/
#define HAMILTON_INIT      0x0000685A//"/ZR"    <ascii:"hZ"> PC设置泵运行速度
#define HAMILTON_POS_ABS   0x00006841//"/AR,aR"    <ascii:"hA">移动到绝对位置
#define HAMILTON_DISPENSE  0x00006850//"/DR,dR"    <ascii:"hD">活塞往上运动
#define HAMILTON_PICKUP    0x00006844//"/PR,PR"    <ascii:"hP">活塞往下运动
#define HAMILTON_INPUT     0x00006849//"/IR"    <ascii:"hI">设置输入阀门
#define HAMILTON_OUTPUT    0x0000684F//"/OR"    <ascii:"hO">设置输出阀门
#define HAMILTON_ACCELER   0x0000684C//"/LxR"	<ascii:"hL">设置活塞加速度
#define HAMILTON_START_SPEED   0x00006876//"/vxR"	<ascii:"hv">设置起始速度
#define HAMILTON_MAX_SPEED 0x00006856//"/VxR"	<ascii:"hV">设置最大速度
#define HAMILTON_STOP_SPEED 0x00006863//"/cxR"	<ascii:"hc">设置结束速度
#define HAMILTON_SET_SPEED  0x00006853	//"/SxR"	<ascii:"hS">设置速度
#define HAMILTON_RET_STEPS  0x0000684B//"/KR,kR"    <ascii:"hK">设置后冲量
#define HAMILTON_GET_STATUS 0x00006851//"/QR"    <ascii:"hQ">查询状态
#define HAMILTON_SET_CNTPOS 0x0000687A//"/zR"    <ascii:"hz">重启活塞位置编码器
#define HAMILTON_REP_DEVSTA 0x0000683F//"/?xR"    <ascii:"h?">查询泵相关信息
#define HAMILTON_MUL_CMDPOS 0x0000686D//"/xxxxxxx"<ascii:"hm">多命令模式。配置输入输出口以及吸排量
#define HAMILTON_MUL_CMDLOOP 0x00006847//"/xxxxxxxG"<ascii:"hG">多命令模式。可以控制循环次数，配置输入输出口以及吸排量
#define HAMILTON_MUL_ABSLOOP 0x00006842//"/xxxxxxx"<ascii:"hB">多命令模式。可以控制循环次数，配置输入输出口以及吸排量
#define HAMILTON_TERMINAL   0x00006854//"/TR"<ascii:"hT">多命令模式。可以控制循环次数，配置输入输出口以及吸排量
#define HAMILTON_CONTINUE   0x00006852//"/R"<ascii:"hR">多命令模式。可以控制循环次数，配置输入输出口以及吸排量
/******************************MVP控制指令********************************/
#define MVPINIT            0x004D5649
#define MVPGOVA            0x004D5647
#define MVPRPOS   		   0x004D5652
#define MVPENCM            0x004D5645
#define MVPRPST            0x004D5653
/******************************Weigh控制指令********************************/
#define GETWEUGHT              0x00574757    //获取重量
#define GETGALWEIGH            0x00574747    //获取所有称重器重量
#define WEIGHSETADDR           0x00575341	 //改变地址
#define WEIGHGETBAUD   		   0x00574742    //获取波特率
/******************************MDS控制指令*********************************/
#define MDSSETF            0x004D4446    //MDF-- set Freq
#define MDSSETD            0x004D4444	 //MDD -- set dBm
#define MDSSETP   		   0x004D4450    //MDP -- set Power
#define MDSSETS            0x004D4453    //MDS -- set switch
#define MDSREP			   0x004D4452    //MDR -- report para
/****************************特殊控制指牌********************************/

/****************************特殊控制指牌********************************/
#define E625MOVPOS         0x004D4F56
#define E625RPOPOS         0x00504F53
#define ASKL                0x41534b4c//"ASKL" PC请求返回上一条指令






//内部参数，用于数据包分析是临时空间
 //extern Uint32                  buf_Response[NET_MAX_BUF];//应答空间


#endif /* NETCOMMUNICATE_H_ */
