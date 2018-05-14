#include "Main.h" 
#include "Ext_Reg.h"
#include "Pub_Reg.h"                 // ���ݶ���
#include "port.h"                    // �˿ڶ���
#include "hsch51.h"                  // �ж϶���
#include "0_02_11h.h"                // ��ʱ��   			   
#include "..\input\input.h"	         // ���뼯��		  
#include "..\output\output.h"        // �������  	 
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
	EX1 = 0;   // ��ֹ�ⲿ�ж�1�ж�    	   
	EX1 = 1;
}
*/
///////////////////////////////////////////////////////////////////

void main(void)
{  						  
	AUXR = 0x00;//    ʹ��XRAM	      �ⲿRAM		  	
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

		   		   	    
    Dispatch_Init();    		   //������ȳ�ʼ��
    hSCH_Init_T0();   									//�жϳ�ʼ��
    hSCH_Add_Task(Comm_Update, 0, 1, 0);  // 2ms		//������� ��ͨ�Ž��̣���ʱ���������ڣ�������ռ��
    hSCH_Add_Task(Dispatch_Update, 0,100, 1);   //100*2ms = 200ms(ʵ�� 2016-03-20)	
	                                             
    //�����ƻ�����
    hSCH_Start();			   //����������ȷ�����ж�
															    
    while(1)
	{
		hSCH_Dispatch_Tasks();				//������Ⱥ���
	}
}									  
							   
void Comm_Update()							//ͨ��ͨ��
{  
   SerialAll_Update();	    
}

void Dispatch_Update()						 //���ȸ���
{         				   	   
	WDT_CONTR = 0x35;   		   
	
	// 0.����������
	if(!b_Soft_Trap1) 
	 { b_SYS_RESET = 1; }
	if(b_Soft_Trap2)  
	 { b_SYS_RESET = 1; } 
	if(b_SYS_RESET)   
	 { while(1); } 								 //�����������壬��ס���ȴ����Ź���λ
	 		
    // 1.���� 	 				    
	Input_Update();	
			   
	// 2.�߼�
	Decision_Update();		 

	// 3.������
	Error_Update();

	// 4.�ڴ�
	Memory_Update();		 
							  
	// 5.ͨѶ
	CommCmdAll_Update(); 

	// 6.���
	Output_Update();	
		  
	gTimeTick++;
	if(gTimeTick>=10)
	{	    
	   gTimeTick = 0;	
	    
    }
}					  

void Dispatch_Init() 	 
{ 				
   // �������			  
   b_SYS_RESET  = 0; 
   b_Soft_Trap1 = 1;
   b_Soft_Trap2 = 0;      
	   
   // ��ʼ��
   Memory_Init();	   							
   Output_Init(); 		  
   Input_Init();       
   CommCmdAll_Init();  
   Decision_Init();
   Error_Init();	
   
   gTimeTick = 0;    			 	 
}

					 
 


