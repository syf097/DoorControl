#include <REG52.H>
#include <intrins.h>
#include "uart.h"
#include "delay.h"
#include "FPM10A.h"
#include "buzzer.h"
#include "IR.h"



void main()
{
	while(1)
	{
		if(Beep==0)		//指纹扫描开门
		{
			Uart_Init();			//初始化串口
			Delay_Ms(200);          //延时500MS，等待指纹模块复位
			FPM10A_Find_Fingerprint();				
		}
		else
		{
			IREA=0;
			IrInit()
			play();		
		}
		IREA=1;
		PCON=0x02;
	}
}