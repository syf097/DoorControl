#include "reg52.h"
#include "delay.h"

sbit MOTOA = P1^0;
sbit MOTOB = P1^1;
sbit MOTOC = P1^2;
sbit MOTOD = P1^3; 	

#define SPEED 200 
#define ROUND 2000



void open()
{	
   unsigned char i;
	   for(i=0;i<ROUND;i++)
	   {
		MOTOA = 1;
		MOTOB = 0;
		MOTOC = 1;
		MOTOD = 1;
		Delay_Us(SPEED);

		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 0;
		Delay_Us(SPEED);

		MOTOA = 0;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 1;
		Delay_Us(SPEED);

		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 0;
		MOTOD = 1;
		Delay_Us(SPEED);	  
		}
	
		Delay_Ms(3000);
		
		for(i=0;i<ROUND;i++)
	   {
		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 0;
		MOTOD = 1;
		Delay_Us(SPEED);

		MOTOA = 0;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 1;
		Delay_Us(SPEED);

		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 0;
		Delay_Us(SPEED);

		MOTOA = 1;
		MOTOB = 0;
		MOTOC = 1;
		MOTOD = 1;
		Delay_Us(SPEED);
		  
		}					
	}
