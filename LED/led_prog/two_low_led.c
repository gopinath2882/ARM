#include<LPC21XX.H>
#define led  0x3 << 15//both crt to select pin
// #define led (1 << 15) | (1 << 16)
void delay(unsigned ms)
{
	int i;
	for(;ms>0;ms--)
	for(i=12000;i>0;i--);
}
int main()
{
	IODIR0=led;
	while(1)
	{
		IOCLR0=led;
		delay(500);
		IOSET0=led;
		delay(500);
	}
}
