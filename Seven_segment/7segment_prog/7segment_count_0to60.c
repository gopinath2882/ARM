#include<LPC21XX.h>
#define pins 0xff<<0
#define seg1 1<<8
#define seg2 1<<9
unsigned int arr[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
void two_digit(int);
void delay_ms(unsigned int ms)
{
T0PR =15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0X03;
T0TCR=0X00;
}
void two_digit(int b)
{
unsigned char dly;
for (dly=0;dly<100;dly++)
{
  IOCLR0=pins;
	IOSET0=arr[b/10];
	IOSET0=seg1;
	delay_ms(5);
	IOCLR0=seg1;
	
	IOCLR0=pins;
	IOSET0=arr[b%10];
	IOSET0=seg2;
	delay_ms(5);
	IOCLR0=seg2;
}
}
int main()
{
    int sec=0;
    IODIR0=pins|seg1|seg2;
	while(sec<60)
	{
	two_digit(sec++);
	if(sec==60)
	sec=0;
  }
}
