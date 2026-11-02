#include<LPC21XX.h>
#define pins 0xff
#define seg1 1<<8
#define seg2 1<<9
#define seg3 1<<10
#define seg4 1<<11
unsigned char dp1=0,dp2=0,dp3=0,dp4=0;
unsigned int arr[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
void float_display( int);
void delay_ms(unsigned int ms);
void float_value( float f)
{
	int temp=f;
	if((f>=0.0)&&(f<10.0))
	{
		temp=f*1000;
		dp1=0x80;
	}
	else if((f>=10.0)&&(f<100.0))
	{
		temp=f*100;
	   dp2=0x80;
	}
	else if((f>=100.0)&&(f<1000))
	{
		temp=f*10;
	   dp3=0x80;
	}
	float_display(temp);
}
void float_display(int temp)
{
	unsigned char dly;
	for(dly=0;dly<50;dly++)
{
IOCLR0=pins;
IOSET0=arr[temp/1000]^dp1;
 IOSET0=seg1;
delay_ms(5);
IOCLR0=seg1;
	
IOCLR0=pins;
IOSET0=arr[(temp/100)%10]^dp2;
IOSET0=seg2;
delay_ms(5);
IOCLR0=seg2;
	
IOCLR0=pins;
IOSET0=arr[(temp/10)%10]^dp3;
IOSET0=seg3;
delay_ms(5);
IOCLR0=seg3;

IOCLR0=pins;
IOSET0=arr[temp%10]^dp4;
IOSET0=seg4;
delay_ms(5);
IOCLR0=seg4;
 }
}


int main()
{
	IODIR0=pins|seg1|seg2|seg3|seg4;
while(1)
	float_value(28.28);
}
void delay_ms(unsigned int ms)
{
T0PR =15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0X03;
T0TCR=0X00;
}

