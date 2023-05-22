#include "led.h"
#include "delay.h"
#include "sys.h"
#include "adc.h"
#include "timer.h"
#include "usart1.h"
#include "LCD1602.h"
#include "string.h"
#include "stdio.h"
#include "dht11.h"

char send_data[]="PPM:000,HUM:000,Temp:00.0C\r\n";
/* USER CODE BEGIN PV */
// these variables are volatile because they are used during the interrupt service routine!
#define true 1
#define false 0
int BPM;                   // used to hold the pulse rate
int Signal;                // holds the incoming raw data
int IBI = 600;             // holds the time between beats, must be seeded! 
unsigned char Pulse = false;     // true when pulse wave is high, false when it's low
unsigned char QS = false;        // becomes true when Arduoino finds a beat.
int rate[10];                    // array to hold last ten IBI values
unsigned long sampleCounter = 0;          // used to determine pulse timing
unsigned long lastBeatTime = 0;           // used to find IBI
int P =512;                      // used to find peak in pulse wave, seeded
int T = 512;                     // used to find trough in pulse wave, seeded
int thresh = 512;                // used to find instant moment of heart beat, seeded
int amp = 100;                   // used to hold amplitude of pulse waveform, seeded
int Num;
unsigned char firstBeat = true;        // used to seed rate array so we startup with reasonable BPM
unsigned char secondBeat = false;      // used to seed rate array so we startup with reasonable BPM
/* USER CODE END PV */

void Change_data_handle(void);
void  SHOW_AND_BAOJING_Handle(void);
u8 KEY_SCAN(void);             //��������


u8 key,PPM,Temperature,HUM;
u16 PPM_MAX=60,Temperature_MAX=40,HUM_MAX=70;//������ʪ�����޳�ʼֵ

unsigned char Alarm_Buf[16]="Warning";
char buf[30];

extern unsigned char RxCounter,Usart1RecBuf[64];
extern char bUsart1RecFlag;


int main(void)
{	
//  u16 test,test_adc;
//	unsigned cnt;
	    	 //��ʱ������ʼ��	  
//	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	KEY_IO_Init();                                                                                
//	TIM2_Int_Init(1000-1,72-1);  //��ʱ����ʼ������ʱ1MS
//	//Tout = ((arr+1)*(psc+1))/Tclk ;  72000/72=1000us
//	//Tclk:��ʱ������Ƶ��(��λMHZ)
//	//Tout:��ʱ�����ʱ��(��λus)
//	delay_ms(300);
//	Usart1_Init(9600);
//  DHT11_Init();	//DHT11��ʼ��
//	RELAY_Init();//�̵�����ʼ��
//  BEEP_DISENABLE();   //��������ʼ��
//	LCD_Init();          // 1602��ʼ�� 
//	Adc_Init();  //ADC��ʼ��

	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //�˿�����
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 
		
	 delay_init();	
  while(1)
	{
 GPIO_ResetBits(GPIOA,GPIO_Pin_7); 	
		delay_ms(500);
 GPIO_SetBits(GPIOA,GPIO_Pin_7); 	
		
	
		



			delay_ms(500);
  }
}


