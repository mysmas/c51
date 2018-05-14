#include "serialS2.h" 		  
#include "..\main\port.h"
#include "..\public\public.h"
#include <intrins.h>

#define  S2RI   0x01		   // S2CON.0
#define  S2TI   0x02		   // S2CON.1	 	    	 

//-----------------------串口2-------------------------//   
uchar   xdata    S2_Tran_Buff[TRANBUFFLEN][N_S2_SEND]; 
uchar   xdata    S2_Recv_Buff[RECVBUFFLEN][N_S2_RECV];
bit     bdata    S2_b_SendPrce;        // 发送标志	                    
uchar   idata    S2_SendPtr;           // 发送指针    
uchar   idata    S2_SendPrcePtr;       // 发送处理指针 
uchar   idata    S2_TranPtr;           // 传送指针   
uchar   idata    S2_TranLen;           // 传送长度	 
uchar   idata    S2_RecvPtr;		   // 接收指针		   
uchar   idata    S2_RecvPrcePtr;       // 接收处理指针
uchar   idata    S2_RecvState;		   // 接收状态	 
uchar   idata    S2_RecvCount;         // 接收计数
uchar   idata    S2_RecvLen;           // 接收长度
uchar   idata    S2_RecvSum;           // 接收校验和
uchar   idata    S2_Recv_Idle_Count;   // 接收空闲计数	 

////////////////////////////////////////////////////////

void SerialS2_Init()
{							  
	AUXR &= 0xF7;		//
	S2CON = 0x50;		//
	AUXR |= 0x04;		//
	BRT = 0xDC;		//
	AUXR |= 0x10;		//
}


void SerialS2_Update()
{
// 发送
	if(S2CON&S2TI)
	{
		S2CON &= ~S2TI;
		if(S2_TranPtr < S2_TranLen)
		{ 	 
		    NOP();
			S2BUF = S2_Tran_Buff[S2_TranPtr][S2_SendPrcePtr];   
			S2_TranPtr++;  
		} 
		else
		{  			   
			S2_b_SendPrce = 0; 	           
			if((++S2_SendPrcePtr)>=N_S2_SEND)
            {  S2_SendPrcePtr = 0;  }  
			NOP();     
		}
	}    

 // 接收
	if((S2_Recv_Idle_Count++)>20)
	{
		S2_Recv_Idle_Count = 0;
		S2_RecvState = 0 ;
	}
	
	if(S2CON&S2RI)	    //
	{				    		   
		S2CON &= ~S2RI;	      
		S2_Recv_Idle_Count = RECID1;	   
			  	   
		switch(S2_RecvState)			  
		{
			case RECID1:
                if((S2BUF == 0xaa)||(S2BUF == 0xbb))
				{			  						
					S2_RecvState = RECID2;										
				}									
		 	  break;						 

            case RECID2:		   
				if(S2BUF == 0x83)
				{ 					   
					S2_RecvState = RECLEN;  	 
				}
				else
				{
				 	S2_RecvState = RECID1;
				}
		  	  break;

			case RECLEN:
				S2_RecvLen = S2BUF;	
                if((S2_RecvLen>=RECVBUFFLEN)||(S2_RecvLen<2))
                {
                  S2_RecvState = RECID1;  
                }
				else
				{
                  S2_RecvSum = S2_RecvLen;	  
			      S2_RecvCount = 0;
                  S2_RecvState = RECBUF; 	 
				}
			  break;		

			case RECBUF:
                S2_Recv_Buff[S2_RecvCount][S2_RecvPtr] = S2BUF; 
                S2_RecvSum = S2_RecvSum^S2BUF;   
                S2_RecvCount++;
                if((S2_RecvCount+1)>=S2_RecvLen)
                {
                  S2_RecvState = RECSUM;	    
                }	  
			  break;
			 
			case RECSUM:
               if(S2_RecvSum == S2BUF)
                {   		  		 
                   if((++S2_RecvPtr)>=N_S2_RECV)
                     { S2_RecvPtr = 0; }	  
                } 
                S2_RecvState = RECID1;			
			  break;
			   		
			default:
				S2_RecvState = 0;
			  break;
		}
	} 
}


/*------------------------------------------------------------------*/
void SerialS2_Send()
{  				    
	uchar i,len; 
	
	if(S2_b_SendPrce) return;  // 不能更改,省略	    
	
	if(S2_GetSendCount()==0) return;
	
	len = S2_Tran_Buff[2][S2_SendPrcePtr]; 
	if((len>=TRANBUFFLEN)||(len<2))
	{
	  if((++S2_SendPrcePtr)>=N_S2_SEND)
	  { S2_SendPrcePtr = 0; }
	  return;
	} 
	
	S2_Tran_Buff[0][S2_SendPrcePtr] = 0xbb;		   
	S2_Tran_Buff[1][S2_SendPrcePtr] = 0x83;
	S2_Tran_Buff[2][S2_SendPrcePtr] = len+1; 
	S2_Tran_Buff[len+3][S2_SendPrcePtr] = len+1;  //从长度字开始校验
	for(i=0;i<len;i++)
	 {
	    S2_Tran_Buff[len+3][S2_SendPrcePtr] ^= S2_Tran_Buff[i+3][S2_SendPrcePtr];
	 }
	S2_TranPtr = 0;
	S2_TranLen = len+4;  // 0xbb,0x83,len,bcc (4Bytes)
	S2_b_SendPrce = 1;  
	
	S2CON |= S2TI; //重要 	  
}

//（1）、发送缓冲区中待处理信息信息数
uchar S2_GetSendCount()
{
   if(S2_SendPtr >= S2_SendPrcePtr)
    {  
	   return (S2_SendPtr - S2_SendPrcePtr); 
	}
   else
    { 
	  return (N_S2_SEND + S2_SendPtr - S2_SendPrcePtr + 1); 
	}
}

//（2）、接收缓冲区中待处理信息信息数
uchar S2_GetRecvCount()
{ 
   if(S2_RecvPtr >= S2_RecvPrcePtr)
    { 
	  return (S2_RecvPtr - S2_RecvPrcePtr);  
	}
   else
    { 
	  return (N_S2_RECV + S2_RecvPtr - S2_RecvPrcePtr + 1); 
	}
} 	
	
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/ 

