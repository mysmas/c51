/*------------------------------------------------------------------*-

   *** THIS IS A *HYBRID* SCHEDULER FOR STANDARD 8051 / 8052 ***

-*------------------------------------------------------------------*/

#include "0_02_11h.h"   
#include "..\main\ext_reg.h"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTaskH hSCH_tasks_G[hSCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
//extern uchar xdata Error_code_G;

/*------------------------------------------------------------------*-
  hSCH_Init_T0()
 -*------------------------------------------------------------------*/
void hSCH_Init_T0(void) 							 //定时器 开中断
{
/*   uchar i;

   for (i = 0; i < hSCH_MAX_TASKS; i++) 
      {
        hSCH_Delete_Task(i);
      }
*/

   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   TH0    = T_02ms_H;  // load timer 0 high byte 
   TL0    = T_02ms_L;  // load timer 0 low byte 
   
   ET0   = 1;  // Timer 0 interrupt is enabled
   TR0   = 1;  // Start Timer 0

}

void hSCH_Start(void) 
{
   EA = 1; 
}


void hSCH_Update(void) interrupt INTERRUPT_Timer_0_Overflow  				  //任务调度更新中断服务程序
{
   uchar Index; 

   TH0    = T_02ms_H;  // load timer 0 high byte 
   TL0    = T_02ms_L;  // load timer 0 low byte   

   for (Index = 0; Index < hSCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (hSCH_tasks_G[Index].pTask)			  //
         {
         if (hSCH_tasks_G[Index].Delay == 0)	  //
            {
            // The task is due to run
            // 
            if (hSCH_tasks_G[Index].Co_op)		   
               {
               // If it is a co-operative task, increment the RunMe flag
               hSCH_tasks_G[Index].RunMe += 1;  	//
               }
            else
               {
               // If it is a pre-emptive task, run it IMMEDIATELY
               (*hSCH_tasks_G[Index].pTask)();  // Run the task			 //

               hSCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag //

               // Periodic tasks will be run again (see below)
               // - if this is a 'one shot' task, remove it from the array
               if (hSCH_tasks_G[Index].Period == 0)		 //
                  {
                  hSCH_tasks_G[Index].pTask  = 0;		  //
                  }
                }

							if (hSCH_tasks_G[Index].Period)				 //
								{
									 // Schedule periodic tasks to run again
									 hSCH_tasks_G[Index].Delay = hSCH_tasks_G[Index].Period;		//
								}
							}
						 else
								{
								// Not yet ready to run: just decrement the delay 
								hSCH_tasks_G[Index].Delay -= 1;									//
								}
						}         
      }
}   
								 
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
