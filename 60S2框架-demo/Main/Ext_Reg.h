/******************* ������� ********************/
extern bit     bdata    b_Soft_Trap1;
extern bit     bdata    b_Soft_Trap2; 
extern bit     bdata    b_SYS_RESET;  			   
extern uchar   xdata    SYS_RESET;          //��λ�ź�
/************************* Error code *********/
extern uchar   xdata    Error_code;
extern uchar   xdata    m_Error[5];
/***************************************************************/
extern uchar   xdata   m_Vision;	    //��Ʒ�汾
extern long    xdata   Gateway_Num;     //���غ�
extern uchar    xdata   Floors;     	//¥��
extern uchar     xdata  Server_Floors_Start;  //�������·������ϴ��Ŀ�ʼ¥��
extern uchar     xdata  Server_Floors_Stop;  //�������·������ϴ��Ľ�ֹ¥��
extern long    xdata   	Class;     	
extern uint    xdata   Send_Interval_Time;//���ͼ��ʱ��
extern uchar    xdata   STA_4;
extern uchar    xdata   STB_4;

extern long    xdata   m_Project;		//��Ŀ��
extern long    xdata   m_AreaCode;		//��λ����(����)
extern long    xdata   m_UserCode;		//��λ����(�û�����)
extern long    xdata   m_BuildingNum;	//¥��	 	   


extern bit     bdata   b_PulseStatus;
extern uint    xdata   m_Pulsetime;
extern uint    xdata   m_PulseCount;
extern uint    xdata   n_PulseCount;

extern uchar   xdata    mLED1;
extern uchar   xdata    mLED2;
extern uchar   xdata    mLED3;
extern uchar   xdata    mLED4;

extern uchar   xdata    m_Param[16];				
/********************ͨѶ ************/
//-----------------------����1-------------------------                     
//extern uchar   idata    S1_TranPtr;     
//extern uchar   idata    S1_TranLen;     
//extern uchar   xdata    S1_Tran_Buff[100]; 
//extern uchar   xdata    S1_Recv_Buff[100];
//extern bit     bdata    S1_bRS_SendPrce;      //���ܸ���
//extern bit     bdata    S1_bRS_GetRecv;
//extern uchar   idata    S1_RecvState;
//extern uchar   idata    S1_Recv_Idle_Count;		 
//extern uchar   idata    S1_RecvPtr ;


//-----------------------����2-------------------------                     
//extern uchar   idata    S2_TranPtr;     
//extern uchar   idata    S2_TranLen;     
//extern uchar   xdata    S2_Tran_Buff[100]; 
//extern uchar   xdata    S2_Recv_Buff[100];
//extern bit     bdata    S2_bRS_SendPrce;      //���ܸ���
//extern bit     bdata    S2_bRS_GetRecv;
//extern uchar   idata    S2_RecvState;
//extern uchar   idata    S2_Recv_Idle_Count;		 
//extern uchar   idata    S2_RecvPtr ;


//-----------------------����3-------------------------                     
//extern uchar   idata    S3_TranPtr;     
//extern uchar   idata    S3_TranLen;     
//extern uchar   xdata    S3_Tran_Buff[300]; 
//extern uchar   xdata    S3_Recv_Buff[50];
//extern bit     bdata    S3_bRS_SendPrce;      //���ܸ���
//extern bit     bdata    S3_bRS_GetRecv;
//extern uchar   idata    S3_RecvState;
//extern uchar   idata    S3_Recv_Idle_Count;		 
//extern uchar   idata    S3_RecvPtr ;

//-----------------------����4-------------------------                     
//extern uchar   idata    S4_TranPtr;     
//extern uchar   idata    S4_TranLen;     
//extern uchar   xdata    S4_Tran_Buff[100]; 
//extern uchar   xdata    S4_Recv_Buff[100];
//extern bit     bdata    S4_bRS_SendPrce;      //���ܸ���
//extern bit     bdata    S4_bRS_GetRecv;
//extern uchar   idata    S4_RecvState;
//extern uchar   idata    S4_Recv_Idle_Count;		 
//extern uchar   idata    S4_RecvPtr ;


/***********************  ȫ��ʱ��  **********************/  
//extern uint    xdata    gTimeTick;  
extern ulong   xdata    Comm_TimeTick; 	      //ʱ����  			 		
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


/*************************״̬*************************************/
extern uchar   xdata  m_State ;
extern uchar   xdata  out_State ;
extern uchar   xdata  out_mode;
extern uchar   xdata  T_State;
extern uchar   xdata  I_State;
extern uchar   xdata  Oper_State;


//�����ն�����
extern  long xdata   I_a;	     //A�����
extern  long xdata   I_b;	     //B�����
extern  long xdata   I_c;	     //C�����

extern  long xdata   V_a;	     //A���ѹ
extern  long xdata   V_b;	     //B���ѹ
extern  long xdata   V_c;	     //C���ѹ

extern  long xdata   P_a;	 	//A�๦��
extern  long xdata   P_b;	 	//B�๦��
extern  long xdata   P_c;	 	//C�๦��

extern  long xdata   PF_a;		//A�๦������
extern  long xdata   PF_b;		//B�๦������
extern  long xdata   PF_c;		//C�๦������

extern  long xdata   ELE;      //����

//ˮ���ն�����
extern long xdata   Water_Temp1;//ˮ��1�¶�
extern long xdata   Water_Temp2;//ˮ��2�¶�
extern long xdata   Water_Level1;//ˮ��1ˮλ
extern long xdata   Water_Level2;//ˮ��2ˮλ
extern long xdata   Out_Temperature;//�����¶�
extern long xdata   Out_Humidity;//����ʪ��

//ˮ���ն�����
extern long xdata   Water_Volume;//ˮ��

//�ȱ��ն�����
extern long xdata   Outlet_Temp1;//�ȱó�ˮ�¶�1
extern long xdata   Outlet_Temp2;//�ȱó�ˮ�¶�2
extern long xdata   Outlet_Temp3;//�ȱó�ˮ�¶�3	
extern long xdata   I_Work_State1;//�ȱù���״̬1
extern long xdata   I_Work_State2;//�ȱù���״̬2
extern long xdata   I_Work_State3;//�ȱù���״̬3

//��ˮ�ն�����
extern long xdata   Backwater_Temp;//��ˮ�¶�
extern long xdata   Comeout_Temp;//��ˮ�¶�
extern long xdata   Backwater_Valve1;//��ˮ��1״̬
extern long xdata   Backwater_Valve2;//��ˮ��2״̬
extern long xdata   Supply_Pump1;//��ˮ��1״̬
extern long xdata   Supply_Pump2;//��ˮ��2״̬

//�ն��豸����
extern long xdata  Device_type1;	//�豸����1(ˮ��)
extern long xdata  Device_type2;	//�豸����2(���)
extern long xdata  Device_type3;	//�豸����3(ˮ��)
extern long xdata  Device_type4;	//�豸����4(�ȱ�)
extern long xdata  Device_type5;	//�豸����5(��ˮ)

//�豸ID��
extern long xdata Water_Tank_id;//ˮ��ID��
extern long xdata Electric_Meter_id;//���ID��
extern long xdata Water_Meter_id;//ˮ��ID��
extern long xdata Heat_Pump_id;//�ȱ�ID��
extern long xdata Water_Supply_id;//��ˮID��

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