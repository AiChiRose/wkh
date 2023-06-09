验器材:
	战舰V3/精英STM32F103开发板
	
实验目的:
	学习ATK-LORA-01无线串口模块的使用。
	
硬件资源:
	1,DS0、DS1(连接在PB5、PE5)
	2,串口1(波特率:115200,PA9/PA10连接在板载USB转串口芯片CH340上面)
	3,ALIENTEK 2.8/3.5/4.3/7寸TFTLCD模块(通过FSMC驱动,FSMC_NE4接LCD片选/A10接RS)
	4,按键KEY0(PE4)/KEY1(PE3)/KEY_UP(PA0,也称之为WK_UP)
	5,SD卡,通过SDIO(SDIO_D0~D4(PC8~PC11),SDIO_SCK(PC12),SDIO_CMD(PD2))连接 
	6,W25Q128(SPI FLASH芯片,连接在SPI2上)
	7,24C02
	8,ATK-LORA-01模块1个.
	
	ATK-LORA-01模块与战舰/精英板连接方式：
	ATK-LORA-01          战舰/精英STM32开发板
             VCC<------------>5V 
             GND<------------>GND 
             TXD<------------>PB11
	     RXD<------------>PB10
	     AUX<------------>PA4
	     MD0<------------>PA15
			 
		
实验现象:
	本实验功能简介：本实验用于测试ATK-LORA-01无线串口模块，工作流程如下：
        上电后，先检测模块是否存在（通过配置进入配置功能，发送AT指令），存在则进入主菜单，
        主菜单会显示模块需要配置的参数以及进入通信，通过开发板按键KEY0、KEY1、KEY_UP进行
        功能的操作。按下按键KEY1、或KEY0，上下箭头选择要配置的参数或者选择进入通信。若选
        中的是“配置参数”：当按下KEY_UP按键，会选中该项（下方显示下划线），这时通过按下
        KEY1或KEY0可以对参数进行配置，配置完后再次按下KEY_UP按键，可退出该项的选中（下滑线取消）。

        若选择“进入通信”选项。按下KEY_UP按键，则会进入无线通信测试界面，模块会根据主菜
        单中用户设置的参数进行配置（在配置功能（串口波特率：115200，8位数据位、1位停止位、
        无校验位）发送AT指令，配置完后需重新切换回无线通信下串口配置），参数配置结束后，
        DS1绿灯会闪烁，屏幕左上方会显示模块的当前配置：模块地址、通信信道、空中速率、发射
        功率、工作模式以及发送状态。屏幕右上方则提示，KEY_UP返回主菜单、KEY1发送数据。
    
        若发送状态设置的是：“定向传输”，则会显示多一个选项：“KEY0设置参数”。设置参数目
        的主要是设置发送目标设备的“地址”和“信道”。按下KEY0后，会显示输入框，提示用户输
        入目标地址，地址最大值为65535，输入结束后按下“确定”，会提示继续输入目标信道，信道
        最大值为31。再次按下“确定”则返回无线通信测试界面。按下KEY1则对目标设备发送数据，
        DS0红灯会指示数据发送或接收的状态。
  
        红灯亮：表示数据开始发送或数据开始接收。红灯灭：则表示数据发送完毕或者数据接收完成。
        发送和接收的数据会显示在屏幕上，同时接收到的数据会串口输出。按下KEY_UP，则返回主菜单界面。
       

注意事项:
	1,4.3寸和7寸屏需要比较大电流,USB供电可能不足,请用外部电源适配器(推荐外接12V 1A电源).
	2,本例程在LCD_Init函数里面(在ILI93xx.c),用到了printf,如果不初始化串口1,将导致液晶无法显示!! 
	3,字库更新时,需自备标准SD卡一张(即大卡,也可以用TF卡+卡套). 
	4,字库更新,需自备SD卡一个,并拷贝光盘:6，SD卡根目录文件 对应使用板子下的，里面的所有内容到SD卡根目录,                 然后将SD卡插到开发板.
	5,如果触摸屏不准，请按住KEY0不放，然后按复位，松开复位，进入触摸屏校准。此时松开KEY0，执行校准，即可                 对屏幕进行校准。
   

--------------------------------------------------------------------------------------------
◆其他重要连接：
  开发板光盘资料下载地址（视频+文档+源码等）：http://www.openedv.com/posts/list/13912.htm
  添加微信公众平台方法：http://www.openedv.com/posts/list/45157.htm
  

◆友情提示：如果您想以后及时免费的收到正点原子所有开发板资料更新增加通知，请关注微信公众平台：

 2种添加方法：（动动手提升您的学习效率，惊喜不断哦）
（1）打开微信->添加朋友->公众号->输入“正点原子”->点击关注
（2）打开微信->添加朋友->输入“alientek_stm32"->点击关注

 具体微信添加方法，请参考帖子：http://www.openedv.com/posts/list/45157.htm



			正点原子@ALIENTEK 
			广州市星翼电子科技有限公司
			电话：020-38271790
			传真：020-36773971
			购买：http://eboard.taobao.com
			公司网站：www.alientek.com
			技术论坛：www.openedv.com
		