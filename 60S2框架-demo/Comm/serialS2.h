#include "..\main\Main.h" 

#ifndef _SERIALS2_H_
#define _SERIALS2_H_    

void  SerialS2_Init();  
void  SerialS2_Update();
void  SerialS2_Send();								    
uchar S2_GetSendCount();
uchar S2_GetRecvCount();

#endif