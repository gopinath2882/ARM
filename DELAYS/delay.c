#include<LPC21XX.h>
void delay_sec(unsigned int);
void delay_ms(unsigned int);

void delay_ms(unsigned int ms)
{
T0PR =15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0X03;
T0TCR=0X00;
}
void delay_sec(unsigned int sec)
{
T0PR =15000000-1;
T0TCR=0x01;
while(T0TC<sec);
T0TCR=0X03;
T0TCR=0X00;
}
int main()
{
	delay_ms(5);
	delay_sec(1);
	while(1);
}

