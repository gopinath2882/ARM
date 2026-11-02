#include<LPC21XX.h>
void interupt0(void) __irq
{
EXTINT=0x01;
IOSET0=1<<0;
IOCLR0=1<<0;
VICVectAddr =0;
}


int main()
{
int count=0;
PINSEL1 |= 0x01;
IODIR0 |=1<<0;

VICIntSelect=0;

VICVectCntl0=(0X20)|14;
VICVectAddr0=(unsigned long int)interupt0;

EXTMODE=0x00;
EXTPOLAR=0x00;
 
 VICIntEnable=1<<14;
	while(1)
		count++;
}