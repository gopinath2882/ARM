#include "header.h"
 
 void uart_interupt(void) __irq;
 void interupt_config()
 {
	 VICIntSelect=0;
	 VICVectCntl0=(0x20)|6;
	 VICVectAddr0=(unsigned long) uart_interupt;
	 VICIntEnable=1<<6;
	 U0IER=1<<1;
 }
 
 void uart_interupt() __irq
 {
 U0THR='A';
	VICVectAddr=0;
 }
 
 int main()
 {
	 IODIR0=(1<<5);
	 config();
	 interupt_config();
	 U0THR='A';
	 while(1);
	/* {
	if(((IOPIN0>>14)&1)==0)	
		IOCLR0=1<<5;
	else
		IOSET0=1<<5;
	 }		 
	*/ 
 }
 
 
