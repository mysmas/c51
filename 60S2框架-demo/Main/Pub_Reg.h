/******************* ������� ********************/
bit     bdata    b_Soft_Trap1;
bit     bdata    b_Soft_Trap2; 
bit     bdata    b_SYS_RESET;  			   
uchar   xdata    SYS_RESET;          //��λ�ź�
/************************* Error code *********/
uchar   xdata    Error_code;
uchar   xdata    m_Error[5];
/***************************************************************/
uchar   xdata   m_Vision;	    //��Ʒ�汾
long    xdata   Gateway_Num;	//���غ�
uchar    xdata   Floors;     	//¥��
uchar     xdata  Server_Floors_Start;  //�������·������ϴ��Ŀ�ʼ¥��
uchar     xdata  Server_Floors_Stop;  //�������·������ϴ��Ľ�ֹ¥��
long    xdata   Class;
uint    xdata   Send_Interval_Time;//���ͼ��ʱ��
uchar   xdata   STA_4;
uchar   xdata   STB_4;
   
long    xdata   m_Project;		//��Ŀ��
long    xdata   m_AreaCode;		//��λ����(����)
long    xdata   m_UserCode;		//��λ����(�û�����)
long    xdata   m_BuildingNum;	//¥��	

bit     bdata   b_PulseStatus;
uint    xdata   m_Pulsetime;
uint    xdata   m_PulseCount;
uint    xdata   n_PulseCount;

uchar   xdata    mLED1;
uchar   xdata    mLED2;
uchar   xdata    mLED3;
uchar   xdata    mLED4;

uchar   xdata    m_Param[16];				
/********************ͨѶ ************/
//-----------------------����1-------------------------                     
//uchar   idata    S1_TranPtr;     
//uchar   idata    S1_TranLen;     
//uchar   xdata    S1_Tran_Buff[100]; 
//uchar   xdata    S1_Recv_Buff[100];
//bit     bdata    S1_bRS_SendPrce;      //���ܸ���
//bit     bdata    S1_bRS_GetRecv;
//uchar   idata    S1_RecvState;
//uchar   idata    S1_Recv_Idle_Count;		 
//uchar   idata    S1_RecvPtr ;


//-----------------------����2-------------------------                     
//uchar   idata    S2_TranPtr;     
//uchar   idata    S2_TranLen;     
//uchar   xdata    S2_Tran_Buff[100]; 
//uchar   xdata    S2_Recv_Buff[100];
//bit     bdata    S2_bRS_SendPrce;      //���ܸ���
//bit     bdata    S2_bRS_GetRecv;
//uchar   idata    S2_RecvState;
//uchar   idata    S2_Recv_Idle_Count;		 
//uchar   idata    S2_RecvPtr ;


//-----------------------����3-------------------------                     
//uchar   idata    S3_TranPtr;     
//uchar   idata    S3_TranLen;     
//uchar   xdata    S3_Tran_Buff[300]; 
//uchar   xdata    S3_Recv_Buff[50];
//bit     bdata    S3_bRS_SendPrce;      //���ܸ���
//bit     bdata    S3_bRS_GetRecv;
//uchar   idata    S3_RecvState;
//uchar   idata    S3_Recv_Idle_Count;		 
//uchar   idata    S3_RecvPtr ;

//-----------------------����4-------------------------                     
//uchar   idata    S4_TranPtr;     
//uchar   idata    S4_TranLen;     
//uchar   xdata    S4_Tran_Buff[100]; 
//uchar   xdata    S4_Recv_Buff[100];
//bit     bdata    S4_bRS_SendPrce;      //���ܸ���
//bit     bdata    S4_bRS_GetRecv;
//uchar   idata    S4_RecvState;
//uchar   idata    S4_Recv_Idle_Count;		 
//uchar   idata    S4_RecvPtr ;


/***********************  ȫ��ʱ��  **********************/  
uint    xdata    gTimeTick;  
ulong   xdata    Comm_TimeTick; 	      //ʱ����  			 		
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


/*************************״̬*************************************/
uchar   xdata  m_State ;
uchar   xdata  out_State ;
uchar   xdata  out_mode;
uchar   xdata  T_State;
uchar   xdata  I_State;
uchar   xdata  Oper_State;

//�����ն�����
 long xdata   I_a;	     //A�����
 long xdata   I_b;	     //B�����
 long xdata   I_c;	     //C�����

 long xdata   V_a;	     //A���ѹ
 long xdata   V_b;	     //B���ѹ
 long xdata   V_c;	     //C���ѹ

 long xdata   P_a;	 	//A�๦��
 long xdata   P_b;	 	//B�๦��
 long xdata   P_c;	 	//C�๦��

 long xdata   PF_a;		//A�๦������
 long xdata   PF_b;		//B�๦������
 long xdata   PF_c;		//C�๦������

 long xdata   ELE;      //����

//ˮ���ն�����
long xdata   Water_Temp1;//ˮ��1�¶�
long xdata   Water_Temp2;//ˮ��2�¶�
long xdata   Water_Level1;//ˮ��1ˮλ
long xdata   Water_Level2;//ˮ��2ˮλ
long xdata   Out_Temperature;//�����¶�
long xdata   Out_Humidity;//����ʪ��

//ˮ���ն�����
long xdata   Water_Volume;//ˮ��

//�ȱ��ն�����
long xdata   Outlet_Temp1;//�ȱó�ˮ�¶�1
long xdata   Outlet_Temp2;//�ȱó�ˮ�¶�2
long xdata   Outlet_Temp3;//�ȱó�ˮ�¶�3	
long xdata   I_Work_State1;//�ȱù���״̬1
long xdata   I_Work_State2;//�ȱù���״̬2
long xdata   I_Work_State3;//�ȱù���״̬3

//��ˮ�ն�����
long xdata   Backwater_Temp;//��ˮ�¶�
long xdata   Comeout_Temp;//��ˮ�¶�
long xdata   Backwater_Valve1;//��ˮ��1״̬
long xdata   Backwater_Valve2;//��ˮ��2״̬
long xdata   Supply_Pump1;//��ˮ��1״̬
long xdata   Supply_Pump2;//��ˮ��2״̬

//�ն��豸����
long xdata  Device_type1;	//�豸����1(ˮ��)
long xdata  Device_type2;	//�豸����2(���)
long xdata  Device_type3;	//�豸����3(ˮ��)
long xdata  Device_type4;	//�豸����4(�ȱ�)
long xdata  Device_type5;	//�豸����5(��ˮ)


//�豸ID��
long xdata Water_Tank_id;//ˮ��ID��
long xdata Electric_Meter_id;//���ID��
long xdata Water_Meter_id;//ˮ��ID��
long xdata Heat_Pump_id;//�ȱ�ID��
long xdata Water_Supply_id;//��ˮID��


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