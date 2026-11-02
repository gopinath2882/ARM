#include<LPC21XX.H>
void delay(unsigned int ms)
{
	int i;
	for(;ms>0;ms--)
	for(i=12000;i>0;i--);
}
int main()
{ 
int count=0;
	IODIR0=1<<0;
	while(count++ <10)
	{
		IOCLR0=1<<0;
		delay(500);
		IOSET0=1<<0;
		delay(500);
	}
}