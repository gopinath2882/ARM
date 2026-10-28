#include<LPC21XX.H>
#define LCD  0xff<<0
#define RS 1<<8
#define E 1<<9
void initial();
void command(unsigned char);
void data(unsigned char);
void delay(unsigned int);
void initial()
{
	IODIR0=LCD|RS|E;
	command(0x01);
	command(0x02);
	command(0x0c);
	command(0x38);
}
void command(unsigned char cmd)
{
	IOCLR0=LCD;
	IOSET0=cmd;
	IOCLR0=RS;
	IOSET0=E;
	delay(2);
	IOCLR0=E;
}
void data(unsigned char d)
{
IOCLR0=LCD;
IOSET0=d;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
void delay(unsigned int MS)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<MS);
	T0TCR=0x03;
	T0TCR=0x00;
}

int main()
{
	initial();
	command(0x80);
	data('A');
}







