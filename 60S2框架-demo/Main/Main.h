/*------------------------------------------------------------------*-

   Main.H (v1.00)

-*------------------------------------------------------------------*/

#ifndef _MAIN_H
#define _MAIN_H

//------------------------------------------------------------------
// WILL NEED TO EDIT THIS SECTION FOR EVERY PROJECT
//------------------------------------------------------------------

// Must include the appropriate microcontroller header file here 				 
#include "STC12C5A60S2.h"	  //将运行在STC15W系列系统移植到STC12系列！！！！！！！！！！！！！！
//------------------------------------------------------------------
// SHOULD NOT NEED TO EDIT THE SECTIONS BELOW
//------------------------------------------------------------------
typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;
 
/************************************ *****************/ 
#define NOP() {_nop_(); _nop_();}
#define RECID1  0
#define RECID2  1
#define RECLEN  2
#define RECCMD  3
#define RECBUF  4
#define RECSUM  5
 
/************************************* communication *****************/
#define OSC_FREQ (11059200UL)
#define OSC_PER_INST (12)
// 12 -- 2ms
// 24 -- 1ms
//  6 -- 4ms 

// 定义Comm发送缓冲区大小：
#define N_S1_SEND    2	   
#define N_S2_SEND    2	   
#define N_S3_SEND    2	  
#define N_S4_SEND    2

// 定义Comm接收缓冲区大小：
#define N_S1_RECV    4	  
#define N_S2_RECV    4	  
#define N_S3_RECV    4		 
#define N_S4_RECV    4
 
#define TRANBUFFLEN  40
#define RECVBUFFLEN  40
											   								    

/************************** EEROM ADDR ******************************/
#define  Addr_TerInfo       0x0000 
#define  Addr_TerInfoBak    0x0200

#define  Addr_SaveInfo_1    0x0400	
#define  Addr_SaveInfo_1Bak 0x0600
			
#define  Addr_SaveInfo_2    0x0800		
#define  Addr_SaveInfo_2Bak 0x0a00

#define  Addr_SaveInfo_3    0x0c00		
#define  Addr_SaveInfo_3Bak 0x0e00

#define  Addr_SaveInfo_4    0x1000		
#define  Addr_SaveInfo_4Bak 0x1200

#define  Addr_SaveInfo_5    0x1400		
#define  Addr_SaveInfo_5Bak 0x1600

#define  Addr_SaveInfo_6    0x1800		
#define  Addr_SaveInfo_6Bak 0x1a00

#define  Addr_SaveInfo_7    0x1c00		
#define  Addr_SaveInfo_7Bak 0x1e00

#define  Addr_SaveInfo_8    0x2000		
#define  Addr_SaveInfo_8Bak 0x2200

#define  Addr_SaveInfo_9    0x2400		
#define  Addr_SaveInfo_9Bak 0x2600

#define  Addr_SaveInfo_10    0x2800		
#define  Addr_SaveInfo_10Bak 0x2a00
											  

//////////////////////////////////////////////////////////////////

// Generic 8051/52 timer interrupts (used in most schedulers)
#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5
#define INTERRUPT_Ext_0_Overflow   0
#define INTERRUPT_Ext_1_Overflow   2
 
 
// Define initial Timer 0 / Timer 1 values for ~1 msec delay
																	  
#define T_d5ms (65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 2000)))    
#define T_d5ms_H (T_d5ms / 256)
#define T_d5ms_L (T_d5ms % 256)

#define T_01ms (65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 1000)))    
#define T_01ms_H (T_01ms / 256)
#define T_01ms_L (T_01ms % 256)
//
// Define initial Timer 0 / Timer 1 values for ~2 msec delay
#define T_02ms (65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 500)))    
#define T_02ms_H (T_02ms / 256)
#define T_02ms_L (T_02ms % 256)
//  
//
// Define initial Timer 0 / Timer 1 values for ~5 msec delay
#define T_05ms  (65536 - (uint)(OSC_FREQ / (OSC_PER_INST * 200)))    
#define T_05ms_H (T_05ms / 256)
#define T_05ms_L  (T_05ms % 256)
//  
 
#endif
					   
