/*------------------------------------------------------------------*-
  
   hSCH51.h (v1.00)
 
-*------------------------------------------------------------------*/

#ifndef _hSCH51_H
#define _hSCH51_H

#include "..\main\Main.h"

// ------ Public data type declarations ----------------------------

// Store in DATA area, if possible, for rapid access  
// Total memory per task is 8 bytes
typedef data struct 
   {
   // Pointer to the task (must be a 'void (void)' function)
   void (code * pTask)(void);  

   // Delay (ticks) until the function will (next) be run
   // - see SCH_Add_Task() for further details
   uint Delay;       

   // Interval (ticks) between subsequent runs.
   // - see SCH_Add_Task() for further details
   uint Period;       

   // Incremented (by scheduler) when task is due to execute
   uchar RunMe;       

   // Set to 1 if task is co-operative
   // Set to 0 if task is pre-emptive
   uchar Co_op;     
   } sTaskH; 														//定义一个任务结构体类型

// ------ Public function prototypes -------------------------------

// Core scheduler functions
void  hSCH_Dispatch_Tasks(void);
uchar hSCH_Add_Task(void (code *)(void), uchar, uchar, bit);  
bit   hSCH_Delete_Task(uchar);
//void  hSCH_Report_Status(void);

// ------ Public constants -----------------------------------------

// The maximum number of tasks required at any one time
// during the execution of the program
//
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define hSCH_MAX_TASKS   (2)   
 
#endif
                              
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

