#include<LPC21XX.h>
void interupt(void) __irq
{
if((VICIRQStatus>>14)&1)
{
EXTINT=0X01; // ? Clear EINT0 flag
IOSET0=1<<0;
IOCLR0=1<<0;
VICVectAddr=0;
}
else if((VICIRQStatus>>16)&1)
{
EXTINT=0X04;  //Clear EINT2 flag
IOSET0=1<<1;
IOCLR0=1<<1;
VICVectAddr=0;
}
}
int main()
{
int count=0;
PINSEL1|=0x01;// Configure P1.16 as EINT0
PINSEL0|=(1<<31);// Configure P0.15 as EINT2
IODIR0=0x3;

VICIntSelect=0;
VICDefVectAddr=(unsigned long)interupt;

EXTMODE=0x00;
EXTPOLAR=0x00;
 
VICIntEnable=(1<<14)|(1<<16);

while(1)
count++;
}


