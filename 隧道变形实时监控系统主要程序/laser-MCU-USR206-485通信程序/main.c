#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "rs485.h"

/************************************************
 ALIENTEK��ӢSTM32������ʵ��4
 ���� ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


u8 u2data[22];
int rx_count=0;
int rx_count2=0;
u8 fina_data1[7];
int finaldata1,finaldata2;


void data_handle()
{
	  int x;
	
	  //laser1���ݴ���
    fina_data1[0]=u2data[4];//ʮλ��
		fina_data1[1]=u2data[5];//��λ��
		fina_data1[2]=u2data[7];//С�����һλdata[6]��С����.
		fina_data1[3]=u2data[8];//С�������λ
		fina_data1[4]=u2data[9];//С�������λ
	  fina_data1[5]=u2data[10];//С�������λ
	  
	  sscanf(fina_data1,"%d",&finaldata1);//�ַ���תint
	   delay_ms(10);
	  u2_printf("%d\r\n",finaldata1);  //print�ô���2������1�����ͼ���ģ��ͨѶ
//	  USART_SendData(USART2,finaldata1);
			USART_SendData(USART2,finaldata1);
//	   RS485_Send_Data(u2data,5);
	//USART_SendData(USART2,123);
	  u1_printf("%d\r\n",finaldata1);// send data to pc
//	  LCD_Fill(0,195,240,220,WHITE); //�����ʾ
//		Show_Str_Mid(10,195,u2data,16,240);//��ʾ���͵�����	
//		
		
		for(x=0;x<7;x++)//clear variaty fina_data1
		{
		 fina_data1[x]=0;
		}
		
		LED0=1;
		delay_ms(800);
		LED0=0;
		
}
	
 int main(void)
 {	
	static u8 num=0;
	u8 key=0;
  u16 testdata=02345;	 
 	u16 t;  
	u16 len;	
	u16 times=0;
	RS485_TX_EN=1;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 //���ڳ�ʼ��Ϊ115200 //usart2_init(115200);
	RS485_Init(115200);
	usart3_init(9600);
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	u1_printf("%d\r\n",finaldata1);
 	while(1)
	{	
		if(rx_count==1)
		{	
			data_handle();		
			num++;
		if(num==255) num=0;
		LED0=1;
		delay_ms(800);
		LED0=0;
		}   
		}
	}	 
 

