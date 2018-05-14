#include "serialS1.h" 		   
#include "..\public\public.h"
#include <intrins.h>	    	 

//-----------------------串口1-------------------------//   
uchar   xdata    S1_Tran_Buff[TRANBUFFLEN][N_S1_SEND]; 
uchar   xdata    S1_Recv_Buff[RECVBUFFLEN][N_S1_RECV];
bit     bdata    S1_b_SendPrce;        // 发送标志	                    
uchar   idata    S1_SendPtr;           // 发送指针    
uchar   idata    S1_SendPrcePtr;       // 发送处理指针 
uchar   idata    S1_TranPtr;           // 传送指针   
uchar   idata    S1_TranLen;           // 传送长度	 
uchar   idata    S1_RecvPtr;		   // 接收指针		   
uchar   idata    S1_RecvPrcePtr;       // 接收处理指针
uchar   idata    S1_RecvState;		   // 接收状态	 
uchar   idata    S1_RecvCount;         // 接收计数
uchar   idata    S1_RecvLen;           // 接收长度
uchar   idata    S1_RecvSum;           // 接收校验和
uchar   idata    S1_Recv_Idle_Count;   // 接收空闲计数	 

////////////////////////////////////////////////////////

void SerialS1_Init()
{							  
	//2400bps@11.0592MHz		  	   			  
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD |= 0x20;		//
	TL1 = 0xFD;				//TL1 = 0x80;		    //设定定时初值
	TH1 = 0xFD;				//TH1 = 0xFB;		    //设定定时初值		 
	TR1 = 1;		    //启动定时器1	   	   
	ES = 0;				//禁止串口中断，使用查询方式
}


void SerialS1_Update()
{
// 发送
	if(TI == 1)
	{
		TI = 0;
		if(S1_TranPtr < S1_TranLen)
		{ 
			SBUF = S1_Tran_Buff[S1_TranPtr][S1_SendPrcePtr];   
			S1_TranPtr++;  
		} 
		else
		{  
			NOP();
			S1_b_SendPrce = 0; 	           
			if((++S1_SendPrcePtr)>=N_S1_SEND)
            {  S1_SendPrcePtr = 0;  }  
			NOP();     
		}
	}    

 // 接收
	if((S1_Recv_Idle_Count++)>20)
	{
		S1_Recv_Idle_Count = 0;
		S1_RecvState = 0 ;
	}
	
	if(RI == 1)
	{
		RI = 0;        
		S1_Recv_Idle_Count = RECID1;	   
		
		switch(S1_RecvState)			  
		{
			case RECID1:
                if((SBUF == 0xaa)||(SBUF == 0xbb))
				{			  						
					S1_RecvState = RECID2;		
				}									
		 	  break;						 

            case RECID2:		   
				if(SBUF == 0x83)
				{ 					   
					S1_RecvState = RECLEN;  	 
				}
				else
				{
				 	S1_RecvState = RECID1;
				}
		  	  break;

			case RECLEN:
				S1_RecvLen = SBUF;	
                if((S1_RecvLen>=RECVBUFFLEN)||(S1_RecvLen<2))
                {
                  S1_RecvState = RECID1;  
                }
				else
				{
                  S1_RecvSum = S1_RecvLen;	  
			      S1_RecvCount = 0;
                  S1_RecvState = RECBUF; 	 
				}
			  break;		

			case RECBUF:
                S1_Recv_Buff[S1_RecvCount][S1_RecvPtr] = SBUF; 
                S1_RecvSum = S1_RecvSum^SBUF;   
                S1_RecvCount++;
                if((S1_RecvCount+1)>=S1_RecvLen)
                {
                  S1_RecvState = RECSUM;	    
                }	  
			  break;
			 
			case RECSUM:
               if(S1_RecvSum == SBUF)
                {   		  		 
                   if((++S1_RecvPtr)>=N_S1_RECV)
                     { S1_RecvPtr = 0; }	  
                } 
                S1_RecvState = RECID1;	
								
			  break;
			   		
			default:
				S1_RecvState = 0;
			  break;
		}
	} 
}


/*------------------------------------------------------------------*/
void SerialS1_Send()
{  				    
	uchar i,len; 
	
	if(S1_b_SendPrce) return;  // 不能更改,省略	    
	
	if(S1_GetSendCount()==0) return;
	
	len = S1_Tran_Buff[2][S1_SendPrcePtr]; 
	if((len>=TRANBUFFLEN)||(len<2))
	{
	  if((++S1_SendPrcePtr)>=N_S1_SEND)
	  { S1_SendPrcePtr = 0; }
	  return;
	} 
	
	S1_Tran_Buff[0][S1_SendPrcePtr] = 0xbb;		   
	S1_Tran_Buff[1][S1_SendPrcePtr] = 0x83;
	S1_Tran_Buff[2][S1_SendPrcePtr] = len+1; 
	S1_Tran_Buff[len+3][S1_SendPrcePtr] = len+1;  //从长度字开始校验
	for(i=0;i<len;i++)
	 {
	    S1_Tran_Buff[len+3][S1_SendPrcePtr] ^= S1_Tran_Buff[i+3][S1_SendPrcePtr];
	 }
	S1_TranPtr = 0;
	S1_TranLen = len+4;  // 0xbb,0x83,len,bcc (4Bytes)
	S1_b_SendPrce = 1;  
	
	TI = 1; //重要 	  
}

//（1）、发送缓冲区中待处理信息信息数
uchar S1_GetSendCount()
{
   if(S1_SendPtr >= S1_SendPrcePtr)
    {  
	   return (S1_SendPtr - S1_SendPrcePtr); 
	}
   else
    { 
	  return (N_S1_SEND + S1_SendPtr - S1_SendPrcePtr + 1); 
	}
}

//（2）、接收缓冲区中待处理信息信息数
uchar S1_GetRecvCount()
{ 
   if(S1_RecvPtr >= S1_RecvPrcePtr)
    { 
	  return (S1_RecvPtr - S1_RecvPrcePtr);  
	}
   else
    { 
	  return (N_S1_RECV + S1_RecvPtr - S1_RecvPrcePtr + 1); 
	}
} 		

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


