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
		if(Beep==0)		//ָ��ɨ�迪��
		{
			Uart_Init();			//��ʼ������
			Delay_Ms(200);          //��ʱ500MS���ȴ�ָ��ģ�鸴λ
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