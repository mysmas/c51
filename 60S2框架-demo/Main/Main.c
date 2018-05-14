#include "Main.h" 
#include "Ext_Reg.h"
#include "Pub_Reg.h"                 // 数据定义
#include "port.h"                    // 端口定义
#include "hsch51.h"                  // 中断定义
#include "0_02_11h.h"                // 定时器   			   
#include "..\input\input.h"	         // 输入集合		  
#include "..\output\output.h"        // 输出集合  	 
#include "..\Comm\CommCmdAll.h"			 
#include "..\Memory\memory.h"				 
#include "..\Memory\flashrom.h"	    
#include "..\Decision\Decision.h"
#include "..\Error\Error.h"
#include "..\public\public.h"


void Comm_Update(void);
void Dispatch_Init(void);
void Dispatch_Update(void);  

///////////////////////////////////////////////////////////////////
/*
void Power_Down(void) interrupt INTERRUPT_Ext_1_Overflow  
{
	EX1 = 0;   // 禁止外部中断1中断    	   
	EX1 = 1;
}
*/
///////////////////////////////////////////////////////////////////

void main(void)
{  						  
	AUXR = 0x00;//    使用XRAM	      外部RAM		  	
    WDT_CONTR = 0x37;  							   
 
	P0M1 = 0x20;    // 0010 0000 b  
	P0M0 = 0xc0;    // 1100 0000 b       
	
	P1M1 = 0x00;    // 0000 0000 b    
	P1M0 = 0x00;    // 0000 0000 b
	
	P2M1 = 0x00;    // 0001 0000 b
	P2M0 = 0x01;    // 1100 0000 b     
	
	P3M1 = 0x00;    // 0100 0000 b
	P3M0 = 0x10;    // 0000 0000 b   
	
	P4M1 = 0x00;    // 0000 0000 b
	P4M0 = 0x3c;    // 0011 1100 b

		   		   	    
    Dispatch_Init();    		   //任务调度初始化
    hSCH_Init_T0();   									//中断初始化
    hSCH_Add_Task(Comm_Update, 0, 1, 0);  // 2ms		//添加任务 （通信进程，延时，运行周期，不给抢占）
    hSCH_Add_Task(Dispatch_Update, 0,100, 1);   //100*2ms = 200ms(实测 2016-03-20)	
	                                             
    //启动计划程序
    hSCH_Start();			   //开启任务调度服务的中断
															    
    while(1)
	{
		hSCH_Dispatch_Tasks();				//任务调度函数
	}
}									  
							   
void Comm_Update()							//通用通信
{  
   SerialAll_Update();	    
}

void Dispatch_Update()						 //调度更新
{         				   	   
	WDT_CONTR = 0x35;   		   
	
	// 0.检查软件陷阱
	if(!b_Soft_Trap1) 
	 { b_SYS_RESET = 1; }
	if(b_Soft_Trap2)  
	 { b_SYS_RESET = 1; } 
	if(b_SYS_RESET)   
	 { while(1); } 								 //如果有软件陷阱，则卡住，等待看门狗复位
	 		
    // 1.输入 	 				    
	Input_Update();	
			   
	// 2.逻辑
	Decision_Update();		 

	// 3.错误检查
	Error_Update();

	// 4.内存
	Memory_Update();		 
							  
	// 5.通讯
	CommCmdAll_Update(); 

	// 6.输出
	Output_Update();	
		  
	gTimeTick++;
	if(gTimeTick>=10)
	{	    
	   gTimeTick = 0;	
	    
    }
}					  

void Dispatch_Init() 	 
{ 				
   // 软件陷阱			  
   b_SYS_RESET  = 0; 
   b_Soft_Trap1 = 1;
   b_Soft_Trap2 = 0;      
	   
   // 初始化
   Memory_Init();	   							
   Output_Init(); 		  
   Input_Init();       
   CommCmdAll_Init();  
   Decision_Init();
   Error_Init();	
   
   gTimeTick = 0;    			 	 
}

					 
 


