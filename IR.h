#include <reg52.h>
#include <intrins.h>
#include "uart.h"
#include "delay.h"


unsigned char IrValue[6];
bit _Signal;
void IrInit();
void ReadIr();