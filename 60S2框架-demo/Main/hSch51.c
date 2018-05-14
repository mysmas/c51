#include "..\main\Main.h"
#include "..\main\Port.h"
#include "..\main\ext_reg.h"

#include "hSch51.h"

sTaskH hSCH_tasks_G[hSCH_MAX_TASKS];		//结构体定义的数组
 
									  
static void hSCH_Go_To_Sleep(void);


void hSCH_Dispatch_Tasks(void) 				 //任务调度
{
   uchar Index;								  //
   for (Index = 0; Index < hSCH_MAX_TASKS; Index++)
      {
      if ((hSCH_tasks_G[Index].Co_op) && (hSCH_tasks_G[Index].RunMe > 0)) 	  //
         {
         (*hSCH_tasks_G[Index].pTask)();  // Run the task				//
          hSCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag	  
         if (hSCH_tasks_G[Index].Period == 0)							//
            {
            hSCH_tasks_G[Index].pTask = 0;								//
            }
         }
      }

   hSCH_Go_To_Sleep();          
}


uchar hSCH_Add_Task(void (code* Fn_p)(), // Task function pointer						
                   uchar   Del,    // Num ticks 'til task first runs 
                   uchar   Per,    // Num ticks between repeat runs
                   bit     Co_op)  // Co_op / pre_emp
{
   uchar Index = 0;
   
   // First find a gap in the array (if there is one)
   while ((hSCH_tasks_G[Index].pTask != 0) && (Index < hSCH_MAX_TASKS))
      {
      Index++;
      } 
   
   // Have we reached the end of the list?   
   if (Index == hSCH_MAX_TASKS)
      {
       return hSCH_MAX_TASKS;  
      }
      
   // If we're here, there is a space in the task array
   hSCH_tasks_G[Index].pTask = Fn_p;
     
   hSCH_tasks_G[Index].Delay  = Del;
   hSCH_tasks_G[Index].Period = Per;

   hSCH_tasks_G[Index].Co_op = Co_op;

   hSCH_tasks_G[Index].RunMe  = 0;

   return Index; // return position of task (to allow later deletion)
}

/* 
bit hSCH_Delete_Task(uchar Task_index) 
{
   bit Return_code;

   if (hSCH_tasks_G[Task_index].pTask == 0)
      {										    
         Return_code = 1;  // RETURN_ERROR;
      }
   else
      {
         Return_code = 0;  //RETURN_NORMAL;
      }      
   
   hSCH_tasks_G[Task_index].pTask   = 0;
   hSCH_tasks_G[Task_index].Delay   = 0;
   hSCH_tasks_G[Task_index].Period  = 0;

   hSCH_tasks_G[Task_index].RunMe   = 0;

   return Return_code;       // return status
}
*/

void hSCH_Go_To_Sleep()
{
   PCON |= 0x01;    
}



