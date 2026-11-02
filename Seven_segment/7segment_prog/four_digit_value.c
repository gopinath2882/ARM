#include<LPC21XX.h>
#define pins 0xff
#define seg1 1<<8
#define seg2 1<<9
#define seg3 1<<10
#define seg4 1<<11
unsigned char arr[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
//void four_digit(unsigned int);
void delay_ms(unsigned int);
void four_digit(unsigned int n)
{
unsigned char i;
for(i=0;i<50;i++)
{
IOCLR0=pins;
IOSET0=arr[(n/1000)%10];
IOSET0=seg1;
delay_ms(5);
IOCLR0=seg1;

IOCLR0=pins;
IOSET0=arr[(n/100)%10];
IOSET0=seg2;
delay_ms(5);
IOCLR0=seg2;
 
IOCLR0=pins;
IOSET0=arr[(n/10)%10];
IOSET0=seg3;
delay_ms(5);
IOCLR0=seg3;

IOCLR0=pins;
IOSET0=arr[n%10];
IOSET0=seg4;
delay_ms(5);
IOCLR0=seg4;}
}

int main()
{
IODIR0=pins|seg1|seg2|seg3|seg4;
while(1)
four_digit(2882);
}
void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0X1;
	while(T0TC<ms);
	T0TCR=0X3;
  T0TCR=0X0;
}


