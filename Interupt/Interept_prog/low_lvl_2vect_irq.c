#include<LPC21XX.h>
void interupt1(void) __irq;
void interupt0(void) __irq
{
EXTINT=0X01; // ? Clear EINT0 flag
IOSET0=1<<0;
IOCLR0=1<<0;
VICVectAddr=0;
}
void interupt1(void) __irq
{
EXTINT=0X04; // ? Clear EINT2 flag 
IOSET0=1<<1;
IOCLR0=1<<1;
VICVectAddr=0;
}

int main()
{
int count=0;
PINSEL1|=0x01;// Configure P1.16 as EINT0
PINSEL0|=(1<<31);// Configure P0.15 as EINT2
IODIR0=0x3;

VICIntSelect=0;

VICVectCntl0=(0x20)|14; // Slot 0 = EINT0 (channel 14)
VICVectAddr0=(unsigned long)interupt0;

VICVectCntl1=(0x20)|16;// Slot 1 = EINT2 (channel 16)
VICVectAddr1=(unsigned long)interupt1;

EXTMODE=0x00;
EXTPOLAR=0x00;
 
VICIntEnable=(1<<14)|(1<<16);

while(1)
count++;
}


