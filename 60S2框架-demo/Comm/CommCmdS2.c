#include "CommCmdS2.h"
#include "serialS2.h"
//#include "serialS1.h"		   
#include "..\main\port.h"  		  	 
#include "..\public\public.h" 

/****************************************/
void CommCmdS2_Init()	   //485 串口2 到电能质量检测仪
{ 
	S2_SendPtr = 0;     		  	  
    S2_SendPrcePtr = 0;    		
	S2_TranPtr = 0;     
	S2_TranLen = 0;     
	S2_RecvPtr = 0;
	S2_RecvPrcePtr = 0;
	S2_RecvState = 0;
	S2_b_SendPrce = 0;
	S2_Recv_Idle_Count = 0;	 							 	 								  
}
 

void CommCmdS2_Update()  	 //485 串口2 到电能质量检测仪
{	
   uchar  j,k;	   		 
    
   if(S2_GetRecvCount()==0) { return; }		  
	   
   k = S2_RecvPrcePtr;
   if((++S2_RecvPrcePtr)>=N_S2_RECV)
     {  S2_RecvPrcePtr = 0; }
 	 								 
  switch(S2_Recv_Buff[0][k])
  {											
    case  0xc0:	   // 返回编码  ok	单机连接		 
	     S2_Tran_Buff[2][S2_SendPtr] = 7;  
         S2_Tran_Buff[3][S2_SendPtr] = 0xc0; 	
		 for(j=0;j<	S2_Tran_Buff[2][S2_SendPtr]-1;j++)
		 {				  	  
	        S2_Tran_Buff[4+j][S2_SendPtr] = j;
		 }									 	 

         if((++S2_SendPtr) >= N_S2_SEND)
	       { S2_SendPtr = 0; }	
		 SerialS2_Send();  
	  break;
	  
	default:
	  
	  break;
   }  
}

