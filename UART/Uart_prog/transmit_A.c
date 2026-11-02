#include<LPC21XX.h>
void config(void);
void transmit(unsigned char tx)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=tx;
}

int main ()
{
	config();
	while(1)
	{
	 transmit('A');
	}
}

void config()
{
	PINSEL0=0x05;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x03;
}

