#include "..\main\Main.h" 

#ifndef _SERIALS1_H_
#define _SERIALS1_H_
	 				  
void  SerialS1_Init();  
void  SerialS1_Update();
void  SerialS1_Send();								    
uchar S1_GetSendCount();
uchar S1_GetRecvCount();

#endif


