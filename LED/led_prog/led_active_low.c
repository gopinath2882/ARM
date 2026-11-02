#include<LPC21XX.H>
void delay(unsigned int ms)
{
	int i;
	for(;ms>0;ms--)
	for(i=12000;i>0;i--);
}
int main()
{
	int count=10
	IO0DIR=1<<0;
	while(count-->0)
	{
		IO0CLR=1<<0;
		delay(500);
		IO0SET=1<<0;
		delay(500);
		
	}

}
