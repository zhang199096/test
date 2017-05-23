#if 0
/*file***********************************************************************/
/*                                                                          */
/*                                                                          */
/*        USR_PRM.H : Common header of JL-080 access driver                 */
/*                                                                          */

/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*       [Defines]                                                          */
/*          Definetion of JL-080 User Parameter                             */
/*                                                                          */
/*                                                                          */
/******** Copyright(C) 2008 Yaskawa Electric Corporation ********************/
/*                                                                          */
/*      Ver 1.00    2008.01.08   Initial coding    N.Arai                   */
/****************************************************************************/

#define LINK_SIZE			16			/* Link data size [in words] 16 means 32 bytes(Please do not change it) */
#define SLV_ST_MAX			14			/* Maximum Number of Slaves */
#define T_MCYC				4000		/* Transmission cycle[0.25us] */
#define T_CYC				240			/* Time slot[0.25us] */
#define BYTE_MODE			17			/* Packet size */
#define MAX_RTRY			1			/* Max. number of Retries per Transmission cycle */
#define C2M_CH				0			/* Time slot for C2 Master(0:not use, 1:use) */
#define COM_TIME			1			/* Communication Cycle[multiple of Transmission Cycle] */
#define MY_ADDRESS			0x01		/* My Address(C1 Master) */
#define DEV_RATIO			0			/* INT1 dividing ratio(for INT2 output) */
#define	USR_WDT				0			// Watch dog timer [0ms]; if wdt=0, WDT function disabled    ---for test
#define HOST_IF_REGS_ADDR	0xb0000000	/* JL-080 register start address   --EMIF CE3*/
#endif

