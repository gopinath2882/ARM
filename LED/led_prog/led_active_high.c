#include<LPC21XX.H>
//void delay(unsigned int ms);
/*{
	int i;
for(;ms>0;ms--)
for(i=0;i<12000;i++);
}*/
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
IO0DIR=1<<0;
while(1)
{
IO0SET=1<<0;
delay_ms(500);
IO0CLR=1<<0;
delay_ms(500);
}
}


