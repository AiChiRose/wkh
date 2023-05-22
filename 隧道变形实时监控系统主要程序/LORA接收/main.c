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
 ALIENTEK STM32F103开发板 扩展实验23
 ATK-LORA-01无串口线模块测试实验  
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


//主函数
int main(void)
{	 	 

//	u8 key=0;
//	u8 fontok=0; 
  	
	delay_init();	    	                        //延时函数初始化	  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(9600);	 	                        //串口初始化为9600
    //LCD_Init();	 
	//tp_dev.init();				                    //初始化触摸屏
	LED_Init();
	//KEY_Init();
   // W25QXX_Init();			  	                    //初始化W25Q128
	//my_mem_init(SRAMIN);		                    //初始化内部内存池
	//exfuns_init();				                    //为fatfs相关变量申请内存  
 	//f_mount(fs[0],"0:",1); 	                        //挂载SD卡 
 	//f_mount(fs[1],"1:",1); 	                        //挂载FLASH.
//	key=KEY_Scan(0);  
//	if(key==KEY0_PRES&&((tp_dev.touchtype&0X80)==0))//强制校准
//	{
//		LCD_Clear(WHITE);		                    //清屏
//		TP_Adjust();  			                    //屏幕校准 
//		TP_Save_Adjdata();	  
//		LCD_Clear(WHITE);		                    //清屏
//	}
//	fontok=font_init();		                        //检查字库是否OK
//	if(fontok||key==KEY1_PRES)	                    //需要更新字库				 
//	{
//		LCD_Clear(WHITE);		                    //清屏
// 		POINT_COLOR=RED;		                    //设置字体为红色	   	   	  
//		LCD_ShowString(60,50,200,16,16,"ALIENTEK STM32");
//		while(SD_Init())		                    //检测SD卡
//		{
//			LCD_ShowString(60,70,200,16,16,"SD Card Failed!");
//			delay_ms(200);
//			LCD_Fill(60,70,200+60,70+16,WHITE);
//			delay_ms(200);		    
//		}								 						    
//		LCD_ShowString(60,70,200,16,16,"SD Card OK");
//		LCD_ShowString(60,90,200,16,16,"Font Updating...");
//		key=update_font(20,110,16,"0:");           //从SD卡更新
//		while(key)                                 //更新失败		
//		{			 		  
//			LCD_ShowString(60,110,200,16,16,"Font Update Failed!");
//			delay_ms(200);
//			LCD_Fill(20,110,200+20,110+16,WHITE);
//			delay_ms(200);		       
//		} 		  
//		LCD_ShowString(60,110,200,16,16,"Font Update Success!");
//		delay_ms(1500);	
//		LCD_Clear(WHITE);                         //清屏	       
//	}  
//	Lora_Test();//主测试
  LoRa_Init();
	u1_printf("123\r\n",123);
	LoRa_Set();
	u1_printf("456\r\n",456);
	while(1)
	{
	LoRa_ReceData();
	}
}

