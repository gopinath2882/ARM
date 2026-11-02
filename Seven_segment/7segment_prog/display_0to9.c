#include<LPC21XX.h>
#define pins 0xff<<0
unsigned int arr[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
void delay_ms(unsigned int ms)
{
T0PR =15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0X03;
T0TCR=0X00;
}
int main()
{
	unsigned int digit=0;
	IODIR0=pins;
	while(digit<10)
	{
		IOCLR0=pins;
		IOSET0=arr[digit++];
		delay_ms(500);
	}
	}
