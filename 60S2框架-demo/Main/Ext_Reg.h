/******************* 软件陷阱 ********************/
extern bit     bdata    b_Soft_Trap1;
extern bit     bdata    b_Soft_Trap2; 
extern bit     bdata    b_SYS_RESET;  			   
extern uchar   xdata    SYS_RESET;          //复位信号
/************************* Error code *********/
extern uchar   xdata    Error_code;
extern uchar   xdata    m_Error[5];
/***************************************************************/
extern uchar   xdata   m_Vision;	    //产品版本
extern long    xdata   Gateway_Num;     //网关号
extern uchar    xdata   Floors;     	//楼号
extern uchar     xdata  Server_Floors_Start;  //服务器下发设置上传的开始楼号
extern uchar     xdata  Server_Floors_Stop;  //服务器下发设置上传的截止楼号
extern long    xdata   	Class;     	
extern uint    xdata   Send_Interval_Time;//发送间隔时间
extern uchar    xdata   STA_4;
extern uchar    xdata   STB_4;

extern long    xdata   m_Project;		//项目号
extern long    xdata   m_AreaCode;		//单位代码(区号)
extern long    xdata   m_UserCode;		//单位代码(用户编码)
extern long    xdata   m_BuildingNum;	//楼号	 	   


extern bit     bdata   b_PulseStatus;
extern uint    xdata   m_Pulsetime;
extern uint    xdata   m_PulseCount;
extern uint    xdata   n_PulseCount;

extern uchar   xdata    mLED1;
extern uchar   xdata    mLED2;
extern uchar   xdata    mLED3;
extern uchar   xdata    mLED4;

extern uchar   xdata    m_Param[16];				
/********************通讯 ************/
//-----------------------串口1-------------------------                     
//extern uchar   idata    S1_TranPtr;     
//extern uchar   idata    S1_TranLen;     
//extern uchar   xdata    S1_Tran_Buff[100]; 
//extern uchar   xdata    S1_Recv_Buff[100];
//extern bit     bdata    S1_bRS_SendPrce;      //不能更改
//extern bit     bdata    S1_bRS_GetRecv;
//extern uchar   idata    S1_RecvState;
//extern uchar   idata    S1_Recv_Idle_Count;		 
//extern uchar   idata    S1_RecvPtr ;


//-----------------------串口2-------------------------                     
//extern uchar   idata    S2_TranPtr;     
//extern uchar   idata    S2_TranLen;     
//extern uchar   xdata    S2_Tran_Buff[100]; 
//extern uchar   xdata    S2_Recv_Buff[100];
//extern bit     bdata    S2_bRS_SendPrce;      //不能更改
//extern bit     bdata    S2_bRS_GetRecv;
//extern uchar   idata    S2_RecvState;
//extern uchar   idata    S2_Recv_Idle_Count;		 
//extern uchar   idata    S2_RecvPtr ;


//-----------------------串口3-------------------------                     
//extern uchar   idata    S3_TranPtr;     
//extern uchar   idata    S3_TranLen;     
//extern uchar   xdata    S3_Tran_Buff[300]; 
//extern uchar   xdata    S3_Recv_Buff[50];
//extern bit     bdata    S3_bRS_SendPrce;      //不能更改
//extern bit     bdata    S3_bRS_GetRecv;
//extern uchar   idata    S3_RecvState;
//extern uchar   idata    S3_Recv_Idle_Count;		 
//extern uchar   idata    S3_RecvPtr ;

//-----------------------串口4-------------------------                     
//extern uchar   idata    S4_TranPtr;     
//extern uchar   idata    S4_TranLen;     
//extern uchar   xdata    S4_Tran_Buff[100]; 
//extern uchar   xdata    S4_Recv_Buff[100];
//extern bit     bdata    S4_bRS_SendPrce;      //不能更改
//extern bit     bdata    S4_bRS_GetRecv;
//extern uchar   idata    S4_RecvState;
//extern uchar   idata    S4_Recv_Idle_Count;		 
//extern uchar   idata    S4_RecvPtr ;


/***********************  全程时标  **********************/  
//extern uint    xdata    gTimeTick;  
extern ulong   xdata    Comm_TimeTick; 	      //时间间隔  			 		
extern uchar   xdata    m_Input_Count;
extern uchar   xdata 	Month_G	;
extern uchar   xdata 	Day_G	;
extern uint    xdata    Set_M_time;
extern ulong   xdata    Set_H_time;
extern uint    xdata    m_time;
extern ulong    xdata  	G_time;
extern uchar   xdata    time_State;

/**************************** EEROM *********/  
extern bit     bdata   b_SAVE_RECORD;  	      
extern bit     bdata   b_SAVE_CHARGE;
extern bit     bdata   b_SAVE_INFO;
extern bit     bdata   b_READ_INFO;
extern bit     bdata   m_Change;
extern uchar   xdata   m_ROM_Buff[32];


/*************************状态*************************************/
extern uchar   xdata  m_State ;
extern uchar   xdata  out_State ;
extern uchar   xdata  out_mode;
extern uchar   xdata  T_State;
extern uchar   xdata  I_State;
extern uchar   xdata  Oper_State;


//电能终端数据
extern  long xdata   I_a;	     //A相电流
extern  long xdata   I_b;	     //B相电流
extern  long xdata   I_c;	     //C相电流

extern  long xdata   V_a;	     //A相电压
extern  long xdata   V_b;	     //B相电压
extern  long xdata   V_c;	     //C相电压

extern  long xdata   P_a;	 	//A相功率
extern  long xdata   P_b;	 	//B相功率
extern  long xdata   P_c;	 	//C相功率

extern  long xdata   PF_a;		//A相功率因素
extern  long xdata   PF_b;		//B相功率因素
extern  long xdata   PF_c;		//C相功率因素

extern  long xdata   ELE;      //电量

//水箱终端数据
extern long xdata   Water_Temp1;//水箱1温度
extern long xdata   Water_Temp2;//水箱2温度
extern long xdata   Water_Level1;//水箱1水位
extern long xdata   Water_Level2;//水箱2水位
extern long xdata   Out_Temperature;//环境温度
extern long xdata   Out_Humidity;//环境湿度

//水表终端数据
extern long xdata   Water_Volume;//水量

//热泵终端数据
extern long xdata   Outlet_Temp1;//热泵出水温度1
extern long xdata   Outlet_Temp2;//热泵出水温度2
extern long xdata   Outlet_Temp3;//热泵出水温度3	
extern long xdata   I_Work_State1;//热泵工作状态1
extern long xdata   I_Work_State2;//热泵工作状态2
extern long xdata   I_Work_State3;//热泵工作状态3

//供水终端数据
extern long xdata   Backwater_Temp;//回水温度
extern long xdata   Comeout_Temp;//出水温度
extern long xdata   Backwater_Valve1;//回水阀1状态
extern long xdata   Backwater_Valve2;//回水阀2状态
extern long xdata   Supply_Pump1;//供水泵1状态
extern long xdata   Supply_Pump2;//供水泵2状态

//终端设备类型
extern long xdata  Device_type1;	//设备类型1(水箱)
extern long xdata  Device_type2;	//设备类型2(电表)
extern long xdata  Device_type3;	//设备类型3(水表)
extern long xdata  Device_type4;	//设备类型4(热泵)
extern long xdata  Device_type5;	//设备类型5(供水)

//设备ID号
extern long xdata Water_Tank_id;//水箱ID号
extern long xdata Electric_Meter_id;//电表ID号
extern long xdata Water_Meter_id;//水表ID号
extern long xdata Heat_Pump_id;//热泵ID号
extern long xdata Water_Supply_id;//供水ID号

extern uchar xdata StepGate;
extern uchar xdata StepGate_flag;
extern uchar idata Koncentrator_Delay;
extern uchar idata Step_Koncentrator;


extern uchar xdata my1;
extern uchar xdata my2;
extern uchar xdata my3;
extern uchar xdata my4;
extern uchar xdata my5;


extern unsigned int   idata   CRC;