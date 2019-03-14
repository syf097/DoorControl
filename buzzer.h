#include <REG52.H>    
#include <INTRINS.H>    
#include "delay.h"
#include "IR.h"

sbit IREA=P3^5;
sbit Beep = P1^5; 
void delay(unsigned char);
void int0();
void play();
