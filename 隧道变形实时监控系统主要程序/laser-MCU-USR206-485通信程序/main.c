#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "rs485.h"

/************************************************
 ALIENTEK精英STM32开发板实验4
 串口 实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


u8 u2data[22];
int rx_count=0;
int rx_count2=0;
u8 fina_data1[7];
int finaldata1,finaldata2;


void data_handle()
{
	  int x;
	
	  //laser1数据处理
    fina_data1[0]=u2data[4];//十位数
		fina_data1[1]=u2data[5];//个位数
		fina_data1[2]=u2data[7];//小数点后一位data[6]是小数点.
		fina_data1[3]=u2data[8];//小数点后两位
		fina_data1[4]=u2data[9];//小数点后三位
	  fina_data1[5]=u2data[10];//小数点后四位
	  
	  sscanf(fina_data1,"%d",&finaldata1);//字符串转int
	   delay_ms(10);
	  u2_printf("%d\r\n",finaldata1);  //print用串口2，串口1用来和激光模块通讯
//	  USART_SendData(USART2,finaldata1);
			USART_SendData(USART2,finaldata1);
//	   RS485_Send_Data(u2data,5);
	//USART_SendData(USART2,123);
	  u1_printf("%d\r\n",finaldata1);// send data to pc
//	  LCD_Fill(0,195,240,220,WHITE); //清除显示
//		Show_Str_Mid(10,195,u2data,16,240);//显示发送的数据	
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
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 //串口初始化为115200 //usart2_init(115200);
	RS485_Init(115200);
	usart3_init(9600);
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
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
 

