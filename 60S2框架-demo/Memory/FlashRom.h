#include "..\main\main.h"
#include <intrins.h>		 
  

void  ISP_IAP_enable(void);
void  ISP_IAP_disable(void);

///////////////////////////////////////////////////////////////////////////////
void   FlashRom_Erase(uint sector_addr);
uchar  FlashRom_Read_1Byte(uint byte_addr);
uchar  FlashRom_Read_32Bytes(uint byte_addr, uchar *array); 
uchar  FlashRom_Write_32Bytes(uint begin_addr, uchar *array);
  	    	     
void  FlashRom_Init();			  
void  FlashRom_Format();
void  FlashRom_SaveInfo();
void  FlashSave_Sector(uchar x);
uchar FlashRom_Read(uchar x);





