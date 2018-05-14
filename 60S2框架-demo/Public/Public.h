#include "..\Main\main.h"

#ifndef _PUBLIC_H_
#define _PUBLIC_H_
			   
// for ** Main **

// for ** Comm **						 
//-----------------------����1-------------------------//                     
extern uchar   xdata    S1_Tran_Buff[TRANBUFFLEN][N_S1_SEND]; 
extern uchar   xdata    S1_Recv_Buff[RECVBUFFLEN][N_S1_RECV];
extern bit     bdata    S1_b_SendPrce;        // ���ͱ�־	                    
extern uchar   idata    S1_SendPtr;           // ����ָ��    
extern uchar   idata    S1_SendPrcePtr;       // ���ʹ���ָ��                     
extern uchar   idata    S1_TranPtr;           // ����ָ��    
extern uchar   idata    S1_TranLen;           // ���ͳ���	  
extern uchar   idata    S1_RecvPtr;		      // ����ָ��		   
extern uchar   idata    S1_RecvPrcePtr;       // ���մ���ָ��
extern uchar   idata    S1_RecvState;		  // ����״̬	 
extern uchar   idata    S1_RecvCount;         // ���ռ���
extern uchar   idata    S1_RecvLen;           // ���ճ���
extern uchar   idata    S1_RecvSum;           // ����У���
extern uchar   idata    S1_Recv_Idle_Count;   // ���տ��м���	 
					   
//-----------------------����2-------------------------//                     
extern uchar   xdata    S2_Tran_Buff[TRANBUFFLEN][N_S2_SEND]; 
extern uchar   xdata    S2_Recv_Buff[RECVBUFFLEN][N_S2_RECV];
extern bit     bdata    S2_b_SendPrce;        // ���ͱ�־	                    
extern uchar   idata    S2_SendPtr;           // ����ָ��    
extern uchar   idata    S2_SendPrcePtr;       // ���ʹ���ָ�� 
extern uchar   idata    S2_TranPtr;           // ����ָ��   
extern uchar   idata    S2_TranLen;           // ���ͳ���	 
extern uchar   idata    S2_RecvPtr;		      // ����ָ��		   
extern uchar   idata    S2_RecvPrcePtr;       // ���մ���ָ��
extern uchar   idata    S2_RecvState;		  // ����״̬	 
extern uchar   idata    S2_RecvCount;         // ���ռ���
extern uchar   idata    S2_RecvLen;           // ���ճ���
extern uchar   idata    S2_RecvSum;           // ����У���
extern uchar   idata    S2_Recv_Idle_Count;   // ���տ��м���	


 

// for ** Input **

// for ** Output **
extern void BEEP_Set(uchar,uchar);

// for ** Memory **

// for ** Decision **

// for ** Error **


#endif								  				 		  