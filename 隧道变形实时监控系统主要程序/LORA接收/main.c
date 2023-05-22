#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h" 		 	 
#include "lcd.h"  
#include "key.h"     
#include "usmart.h" 
#include "malloc.h"
#include "sdio_sdcard.h"  
#include "w25qxx.h"    
#include "ff.h"  
#include "exfuns.h"   
#include "text.h"		
#include "usart3.h"
#include "string.h"
#include "touch.h"
#include "lora_app.h"

/************************************************
 ALIENTEK STM32F103������ ��չʵ��23
 ATK-LORA-01�޴�����ģ�����ʵ��  
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


//������
int main(void)
{	 	 

//	u8 key=0;
//	u8 fontok=0; 
  	
	delay_init();	    	                        //��ʱ������ʼ��	  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 	                        //���ڳ�ʼ��Ϊ9600
    //LCD_Init();	 
	//tp_dev.init();				                    //��ʼ��������
	LED_Init();
	//KEY_Init();
   // W25QXX_Init();			  	                    //��ʼ��W25Q128
	//my_mem_init(SRAMIN);		                    //��ʼ���ڲ��ڴ��
	//exfuns_init();				                    //Ϊfatfs��ر��������ڴ�  
 	//f_mount(fs[0],"0:",1); 	                        //����SD�� 
 	//f_mount(fs[1],"1:",1); 	                        //����FLASH.
//	key=KEY_Scan(0);  
//	if(key==KEY0_PRES&&((tp_dev.touchtype&0X80)==0))//ǿ��У׼
//	{
//		LCD_Clear(WHITE);		                    //����
//		TP_Adjust();  			                    //��ĻУ׼ 
//		TP_Save_Adjdata();	  
//		LCD_Clear(WHITE);		                    //����
//	}
//	fontok=font_init();		                        //����ֿ��Ƿ�OK
//	if(fontok||key==KEY1_PRES)	                    //��Ҫ�����ֿ�				 
//	{
//		LCD_Clear(WHITE);		                    //����
// 		POINT_COLOR=RED;		                    //��������Ϊ��ɫ	   	   	  
//		LCD_ShowString(60,50,200,16,16,"ALIENTEK STM32");
//		while(SD_Init())		                    //���SD��
//		{
//			LCD_ShowString(60,70,200,16,16,"SD Card Failed!");
//			delay_ms(200);
//			LCD_Fill(60,70,200+60,70+16,WHITE);
//			delay_ms(200);		    
//		}								 						    
//		LCD_ShowString(60,70,200,16,16,"SD Card OK");
//		LCD_ShowString(60,90,200,16,16,"Font Updating...");
//		key=update_font(20,110,16,"0:");           //��SD������
//		while(key)                                 //����ʧ��		
//		{			 		  
//			LCD_ShowString(60,110,200,16,16,"Font Update Failed!");
//			delay_ms(200);
//			LCD_Fill(20,110,200+20,110+16,WHITE);
//			delay_ms(200);		       
//		} 		  
//		LCD_ShowString(60,110,200,16,16,"Font Update Success!");
//		delay_ms(1500);	
//		LCD_Clear(WHITE);                         //����	       
//	}  
//	Lora_Test();//������
  LoRa_Init();
	u1_printf("123\r\n",123);
	LoRa_Set();
	u1_printf("456\r\n",456);
	while(1)
	{
	LoRa_ReceData();
	}
}

