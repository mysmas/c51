#include "..\Main\main.h"

#ifndef _PUBLIC_H_
#define _PUBLIC_H_
			   
// for ** Main **

// for ** Comm **						 
//-----------------------串口1-------------------------//                     
extern uchar   xdata    S1_Tran_Buff[TRANBUFFLEN][N_S1_SEND]; 
extern uchar   xdata    S1_Recv_Buff[RECVBUFFLEN][N_S1_RECV];
extern bit     bdata    S1_b_SendPrce;        // 发送标志	                    
extern uchar   idata    S1_SendPtr;           // 发送指针    
extern uchar   idata    S1_SendPrcePtr;       // 发送处理指针                     
extern uchar   idata    S1_TranPtr;           // 传送指针    
extern uchar   idata    S1_TranLen;           // 传送长度	  
extern uchar   idata    S1_RecvPtr;		      // 接收指针		   
extern uchar   idata    S1_RecvPrcePtr;       // 接收处理指针
extern uchar   idata    S1_RecvState;		  // 接收状态	 
extern uchar   idata    S1_RecvCount;         // 接收计数
extern uchar   idata    S1_RecvLen;           // 接收长度
extern uchar   idata    S1_RecvSum;           // 接收校验和
extern uchar   idata    S1_Recv_Idle_Count;   // 接收空闲计数	 
					   
//-----------------------串口2-------------------------//                     
extern uchar   xdata    S2_Tran_Buff[TRANBUFFLEN][N_S2_SEND]; 
extern uchar   xdata    S2_Recv_Buff[RECVBUFFLEN][N_S2_RECV];
extern bit     bdata    S2_b_SendPrce;        // 发送标志	                    
extern uchar   idata    S2_SendPtr;           // 发送指针    
extern uchar   idata    S2_SendPrcePtr;       // 发送处理指针 
extern uchar   idata    S2_TranPtr;           // 传送指针   
extern uchar   idata    S2_TranLen;           // 传送长度	 
extern uchar   idata    S2_RecvPtr;		      // 接收指针		   
extern uchar   idata    S2_RecvPrcePtr;       // 接收处理指针
extern uchar   idata    S2_RecvState;		  // 接收状态	 
extern uchar   idata    S2_RecvCount;         // 接收计数
extern uchar   idata    S2_RecvLen;           // 接收长度
extern uchar   idata    S2_RecvSum;           // 接收校验和
extern uchar   idata    S2_Recv_Idle_Count;   // 接收空闲计数	


 

// for ** Input **

// for ** Output **
extern void BEEP_Set(uchar,uchar);

// for ** Memory **

// for ** Decision **

// for ** Error **


#endif								  				 		  