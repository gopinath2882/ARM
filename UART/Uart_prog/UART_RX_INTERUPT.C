#include "header.h"
#include <lpc21xx.h>
 void uart_interupt(void) __irq;
 void interupt_config()
 {
	 VICIntSelect=0;
	 VICVectCntl0=(0x20)|6;
	 VICVectAddr0=(unsigned long) uart_interupt;
	 VICIntEnable=1<<6;
	 U0IER=(1<<1)|(1<<0);
 }
 
 void uart_interupt(void) __irq
 {
 char TEMP= U0IIR;
 if(TEMP==0x4)
 U0THR=U0RBR;
 	
	VICVectAddr=0;
 }
 
 int main()
 {
	 config();
	 interupt_config();
	 	 IODIR0=(1<<5);
	 while(1)
	 {
	if(((IOPIN0>>14)&1)==0)	
		IOCLR0=1<<5;
	else
		IOSET0=1<<5;
	 }		 
 
 }
 
 
