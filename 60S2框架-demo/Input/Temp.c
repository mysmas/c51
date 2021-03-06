#include "Temp.h"
#include "..\main\port.h"
#include "..\main\ext_reg.h"
#include <intrins.h>			     

/*Define ADC operation const for ADC_CONTR*/
#define ADC_POWER   0x80            //ADC power control bit
#define ADC_FLAG    0x10            //ADC complete flag
#define ADC_START   0x08            //ADC start control bit
#define ADC_SPEEDLL 0x00            //420 clocks
#define ADC_SPEEDL  0x20            //280 clocks
#define ADC_SPEEDH  0x40            //140 clocks
#define ADC_SPEEDHH 0x60            //70 clocks	 

							  
uint code Temp[130]={
		    44, 47, 50, 53, 56, 59, 62, 65, 69, 72,	 //-11~-20			10
		    76, 80, 84, 89, 93, 98,102,112,118,123,   //-1~-10			20
           129,135,142,148,154,160,167,174,182,189,	   //0~9			30
		   196,204,212,220,228,236,244,253,262,270,    //10~19     		40
   		   280,288,299,309,318,327,337,346,357,367,	   //20~29		    50
		   377,393,398,408,419,429,439,450,460,470,	   //30~39			60
		   480,491,501,511,521,531,541,551,561,571,	   //40~49			70
		   581,591,600,609,619,627,637,645,654,663,	   //50~59			80
		   671,680,688,695,704,712,719,727,734,742,	   //60~69			90
		   748,756,762,769,775,781,788,793,799,805,	   //70~79			100
		   810,816,821,827,831,837,841,846,850,858,	   //80~89			110
		   861,866,869,873,877,881,885,888,895,896,    //90~99		120
		   899,899,901,902,904,905,906,907,908,910     //100~109
		   };

uint code HTG_Temp[130]={
		   958,955,952,948,945,942,938,934,930,926,	 //-20~-11			10
		   922,918,913,909,904,899,894,889,884,879,   //-10~-1			20
           873,868,862,856,850,844,838,831,825,818,	   //0~9			30
		   811,804,797,790,783,776,768,761,753,745,    //10~19     		40
   		   737,729,721,713,705,697,688,680,671,663,	   //20~29		    50
		   654,646,637,628,620,612,602,593,585,575,	   //30~39			60
		   567,558,550,541,532,524,515,506,498,489,	   //40~49			70
		   481,472,464,456,448,440,432,424,416,408,	   //50~59			80
		   400,393,385,378,371,363,356,349,343,336,	   //60~69			90
		   329,323,316,310,304,298,291,286,281,274,	   //70~79			100
		   268,263,257,252,247,242,237,232,227,222,	   //80~89			110
		   218,213,209,204,200,196,191,187,183,180,    //90~99			120
		   176,172,168,165,161,158,155,151,148,145     //100~109
		   };  

uint code H_Temp[130]={
            29, 30, 32, 33, 35, 37, 38, 40, 42, 44,	   //0~9			10
		    46, 48, 51, 53, 55, 58, 60, 63, 66, 69,    //10~19     		20
   		    72, 75, 78, 81, 85, 88, 92, 95, 99,103,	   //20~29		    30
		   107,111,115,120,124,129,134,139,143,149,	   //30~39			40
		   154,159,165,170,176,182,188,194,200,206,	   //40~49			50
		   213,219,226,233,239,246,253,260,268,275,	   //50~59			60
		   282,290,297,305,313,320,329,337,345,352,	   //60~69			70
		   361,369,377,385,393,401,418,426,435,443,	   //70~79			80
		   451,460,468,476,484,493,501,509,517,525,	   //80~89			90
		   534,541,549,557,565,573,583,588,596,603,    //90~100			100
		   611,618,626,633,640,647,654,661,668,674,	   //100~109		110
		   681,688,693,701,707,713,719,725,730,737,    //110~119		120
		   742,748,753,759,763,770,775,780,785,790	   //120~129
		   };
		   
uint code THG_Humi[100] = {							  // 上拉4.7K 湿度 
           190,200,210,225,231,236,242,247,253,259,		  // 0 -- 10
           265,270,276,281,287,292,297,303,308,313,		  // 10 -- 19
		   319,324,330,335,340,346,351,356,362,367,		  // 20 -- 29
		   373,378,383,389,394,399,405,410,415,421,		  // 30 -- 39
		   426,432,437,442,448,453,458,464,469,475,		  // 40 -- 49
		   480,485,491,496,501,507,512,518,523,528,		  // 50 -- 59
		   534,539,544,550,555,561,566,571,577,582,		  // 60 -- 69
		   587,593,598,604,609,614,620,625,630,636,		  // 70 -- 79
		   641,646,652,657,663,668,673,679,684,689,		  // 80 -- 89
		   695,700,706,711,716,722,727,733,738,744		  // 90 -- 100	
		   }; 	  
		   	   																	  		    
				
void Temp_Init()
{  	
	uchar i;		
	P1ASF = 0xff;                   // 1111 1110, 		 
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
	for(i=0;i<50;i++){ NOP(); }		 
}
 
void Temp_Update()
{
	uint AD_data;

	AD_data = 1024 - AD_Transform(0);					 //室外温度
	Outdoor_Temperature = AD_Temp(AD_data,2)+ m_Param[4] - 148;

	AD_data = AD_Transform(1);
	Outdoor_Humidity =  AD_data/6.144 + m_Param[4] - 128;//室外湿度

	AD_data = AD_Transform(3);
	if(AD_data > 50)	{Supply_Pump =1;}
	else	{Supply_Pump =0;}

	AD_data = 1024 - AD_Transform(4);  				     //水箱温度
	Water_Temperature = AD_Temp(AD_data,2) + m_Param[2] - 148; 

	AD_data = AD_Transform(5) ;				             //水位高度
	Tem_data[1] = AD_data/34 + m_Param[3] - 128;
} 

uint  AD_Transform(char ch)
{
	uint i;
	uint tmp_Temp=0; 
	
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START; 
	for(i=0;i<10;i++){NOP();} 
	// 启动A/D转换, 
	while (!(ADC_CONTR & ADC_FLAG));//Wait complete flag   等待完成标志
	ADC_CONTR &= ~ADC_FLAG;         //Close ADC
	
	tmp_Temp = ADC_RES;		   
	tmp_Temp = tmp_Temp<<2;
	tmp_Temp = tmp_Temp|(ADC_RESL&0x03);
	if (tmp_Temp<10){tmp_Temp=0;}
	
	return 	tmp_Temp;
}
  	
uchar AD_Temp(uint m_data,uchar x)
{
	uchar max=130 ,min = 1,mid;
	
	if(m_data<43)
	{
		min=0xff;
		return min;
	}
	
	while(min <= max)
	{ 
		mid = (max + min) / 2;
		switch(x)
		{
			case  0:
				if(m_data > Temp[mid]){min = mid + 1;} 
				else { max = mid - 1;}
			break;
		
			case  1:
				if(m_data > H_Temp[mid]){min = mid + 1;} 
				else { max = mid - 1;}
				if(min<8) {min=8;}
			break;
			
			case  2:
				if(m_data > (1024-HTG_Temp[mid])){min = mid + 1;} 
				else { max = mid - 1;}
			break;
			
			case  3:
				if(m_data > THG_Humi[mid]){min = mid + 1;} 
				else { max = mid - 1;}
			break;  			
		}       
	}    	
	return min;     
}
							  