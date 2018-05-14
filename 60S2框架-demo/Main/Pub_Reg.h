/******************* 软件陷阱 ********************/
bit     bdata    b_Soft_Trap1;
bit     bdata    b_Soft_Trap2; 
bit     bdata    b_SYS_RESET;  			   
uchar   xdata    SYS_RESET;          //复位信号
/************************* Error code *********/
uchar   xdata    Error_code;
uchar   xdata    m_Error[5];
/***************************************************************/
uchar   xdata   m_Vision;	    //产品版本
long    xdata   Gateway_Num;	//网关号
uchar    xdata   Floors;     	//楼号
uchar     xdata  Server_Floors_Start;  //服务器下发设置上传的开始楼号
uchar     xdata  Server_Floors_Stop;  //服务器下发设置上传的截止楼号
long    xdata   Class;
uint    xdata   Send_Interval_Time;//发送间隔时间
uchar   xdata   STA_4;
uchar   xdata   STB_4;
   
long    xdata   m_Project;		//项目号
long    xdata   m_AreaCode;		//单位代码(区号)
long    xdata   m_UserCode;		//单位代码(用户编码)
long    xdata   m_BuildingNum;	//楼号	

bit     bdata   b_PulseStatus;
uint    xdata   m_Pulsetime;
uint    xdata   m_PulseCount;
uint    xdata   n_PulseCount;

uchar   xdata    mLED1;
uchar   xdata    mLED2;
uchar   xdata    mLED3;
uchar   xdata    mLED4;

uchar   xdata    m_Param[16];				
/********************通讯 ************/
//-----------------------串口1-------------------------                     
//uchar   idata    S1_TranPtr;     
//uchar   idata    S1_TranLen;     
//uchar   xdata    S1_Tran_Buff[100]; 
//uchar   xdata    S1_Recv_Buff[100];
//bit     bdata    S1_bRS_SendPrce;      //不能更改
//bit     bdata    S1_bRS_GetRecv;
//uchar   idata    S1_RecvState;
//uchar   idata    S1_Recv_Idle_Count;		 
//uchar   idata    S1_RecvPtr ;


//-----------------------串口2-------------------------                     
//uchar   idata    S2_TranPtr;     
//uchar   idata    S2_TranLen;     
//uchar   xdata    S2_Tran_Buff[100]; 
//uchar   xdata    S2_Recv_Buff[100];
//bit     bdata    S2_bRS_SendPrce;      //不能更改
//bit     bdata    S2_bRS_GetRecv;
//uchar   idata    S2_RecvState;
//uchar   idata    S2_Recv_Idle_Count;		 
//uchar   idata    S2_RecvPtr ;


//-----------------------串口3-------------------------                     
//uchar   idata    S3_TranPtr;     
//uchar   idata    S3_TranLen;     
//uchar   xdata    S3_Tran_Buff[300]; 
//uchar   xdata    S3_Recv_Buff[50];
//bit     bdata    S3_bRS_SendPrce;      //不能更改
//bit     bdata    S3_bRS_GetRecv;
//uchar   idata    S3_RecvState;
//uchar   idata    S3_Recv_Idle_Count;		 
//uchar   idata    S3_RecvPtr ;

//-----------------------串口4-------------------------                     
//uchar   idata    S4_TranPtr;     
//uchar   idata    S4_TranLen;     
//uchar   xdata    S4_Tran_Buff[100]; 
//uchar   xdata    S4_Recv_Buff[100];
//bit     bdata    S4_bRS_SendPrce;      //不能更改
//bit     bdata    S4_bRS_GetRecv;
//uchar   idata    S4_RecvState;
//uchar   idata    S4_Recv_Idle_Count;		 
//uchar   idata    S4_RecvPtr ;


/***********************  全程时标  **********************/  
uint    xdata    gTimeTick;  
ulong   xdata    Comm_TimeTick; 	      //时间间隔  			 		
uchar   xdata    m_Input_Count;
uchar   xdata 	Month_G	;
uchar   xdata 	Day_G	;
uint    xdata    Set_M_time;
ulong   xdata    Set_H_time;
uint    xdata    m_time;
ulong    xdata  	G_time;
uchar   xdata    time_State;

/**************************** EEROM *********/  
bit     bdata   b_SAVE_RECORD;  	      
bit     bdata   b_SAVE_CHARGE;
bit     bdata   b_SAVE_INFO;
bit     bdata   b_READ_INFO;
bit     bdata   m_Change;
uchar   xdata   m_ROM_Buff[32];


/*************************状态*************************************/
uchar   xdata  m_State ;
uchar   xdata  out_State ;
uchar   xdata  out_mode;
uchar   xdata  T_State;
uchar   xdata  I_State;
uchar   xdata  Oper_State;

//电能终端数据
 long xdata   I_a;	     //A相电流
 long xdata   I_b;	     //B相电流
 long xdata   I_c;	     //C相电流

 long xdata   V_a;	     //A相电压
 long xdata   V_b;	     //B相电压
 long xdata   V_c;	     //C相电压

 long xdata   P_a;	 	//A相功率
 long xdata   P_b;	 	//B相功率
 long xdata   P_c;	 	//C相功率

 long xdata   PF_a;		//A相功率因素
 long xdata   PF_b;		//B相功率因素
 long xdata   PF_c;		//C相功率因素

 long xdata   ELE;      //电量

//水箱终端数据
long xdata   Water_Temp1;//水箱1温度
long xdata   Water_Temp2;//水箱2温度
long xdata   Water_Level1;//水箱1水位
long xdata   Water_Level2;//水箱2水位
long xdata   Out_Temperature;//环境温度
long xdata   Out_Humidity;//环境湿度

//水表终端数据
long xdata   Water_Volume;//水量

//热泵终端数据
long xdata   Outlet_Temp1;//热泵出水温度1
long xdata   Outlet_Temp2;//热泵出水温度2
long xdata   Outlet_Temp3;//热泵出水温度3	
long xdata   I_Work_State1;//热泵工作状态1
long xdata   I_Work_State2;//热泵工作状态2
long xdata   I_Work_State3;//热泵工作状态3

//供水终端数据
long xdata   Backwater_Temp;//回水温度
long xdata   Comeout_Temp;//出水温度
long xdata   Backwater_Valve1;//回水阀1状态
long xdata   Backwater_Valve2;//回水阀2状态
long xdata   Supply_Pump1;//供水泵1状态
long xdata   Supply_Pump2;//供水泵2状态

//终端设备类型
long xdata  Device_type1;	//设备类型1(水箱)
long xdata  Device_type2;	//设备类型2(电表)
long xdata  Device_type3;	//设备类型3(水表)
long xdata  Device_type4;	//设备类型4(热泵)
long xdata  Device_type5;	//设备类型5(供水)


//设备ID号
long xdata Water_Tank_id;//水箱ID号
long xdata Electric_Meter_id;//电表ID号
long xdata Water_Meter_id;//水表ID号
long xdata Heat_Pump_id;//热泵ID号
long xdata Water_Supply_id;//供水ID号


uchar xdata StepGate;
uchar xdata StepGate_flag;
uchar idata Koncentrator_Delay;
uchar idata Step_Koncentrator;


uchar xdata my1;
uchar xdata my2;
uchar xdata my3;
uchar xdata my4;
uchar xdata my5;

unsigned int   idata   CRC;