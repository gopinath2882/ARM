#include<LPC21XX.h>
void config(void);
void transmit(unsigned char tx)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=tx;
}

int main ()
{
	unsigned char ch='A';
	config();
	while(ch<='Z')
	{
	 transmit(ch++);
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

