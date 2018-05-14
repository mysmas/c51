#include "CommCmdS1.h"
#include "serialS1.h"
#include "..\main\port.h" 
#include "..\Output\led.h"
#include "..\public\public.h" 	

/****************************************/
void CommCmdS1_Init()
{					 	
	S1_SendPtr = 0;     		  	  
    S1_SendPrcePtr = 0;    		
	S1_TranPtr = 0;     
	S1_TranLen = 0;     
	S1_RecvPtr = 0;
	S1_RecvPrcePtr = 0;
	S1_RecvState = 0;
	S1_b_SendPrce = 0;
	S1_Recv_Idle_Count = 0;	   
}


void CommCmdS1_Update()  
{      	   
   uchar  j,k;	   		 
    
   if(S1_GetRecvCount()==0) { return; }		  
//	   
   k = S1_RecvPrcePtr;
   if((++S1_RecvPrcePtr)>=N_S1_RECV)
     {  S1_RecvPrcePtr = 0; }
 	 		

	
  switch(S1_Recv_Buff[0][k])
  {											
    case  0xc0:	   // 返回编码  ok	单机连接		 
	     
				 S1_Tran_Buff[2][S1_SendPtr] = 7;  
         S1_Tran_Buff[3][S1_SendPtr] = 0xc0; 	
					for(j=0;j<S1_Tran_Buff[2][S1_SendPtr]-1;j++)
						{				  	  
							S1_Tran_Buff[4+j][S1_SendPtr] = j;
						}									 	 

						if((++S1_SendPtr) >= N_S1_SEND)
						{ S1_SendPtr = 0; }	
						SerialS1_Send(); 
						
						
		break;
				 
				 case  0xFF:
					 				 S1_Tran_Buff[2][S1_SendPtr] = 7;  
         S1_Tran_Buff[3][S1_SendPtr] = 0xFF; 	
					for(j=0;j<S1_Tran_Buff[2][S1_SendPtr]-1;j++)
						{				  	  
							S1_Tran_Buff[4+j][S1_SendPtr] = j;
						}									 	 
						
						S1_Tran_Buff[7][S1_SendPtr] = S1_Recv_Buff[4][k];
						S1_Tran_Buff[8][S1_SendPtr] = S1_Recv_Buff[5][k];
						S1_Tran_Buff[9][S1_SendPtr] = S1_Recv_Buff[6][k];
						if((++S1_SendPtr) >= N_S1_SEND)
						{ S1_SendPtr = 0; }	
						SerialS1_Send(); 
																			
					 break;
	
	  
	default:

	  break;
   } 
   				 	
}
