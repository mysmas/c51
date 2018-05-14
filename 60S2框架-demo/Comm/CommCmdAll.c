#include "CommCmdAll.h"
#include "CommCmdS1.h"
#include "CommCmdS2.h"
#include "serialS1.h"
#include "serialS2.h"  					  
#include "..\main\ext_reg.h" 
#include "..\main\port.h"  		 
#include "..\public\public.h"


void CommCmdAll_Init()
{
	SerialS1_Init(); 
	SerialS2_Init();	   
 

	CommCmdS1_Init();  
	CommCmdS2_Init();	 

}
void SerialAll_Update()
{					   
    SerialS1_Update(); 
    SerialS2_Update();	   
 
}

void CommCmdAll_Update()
{
	CommCmdS1_Update();	
	CommCmdS2_Update();	  
 
}

