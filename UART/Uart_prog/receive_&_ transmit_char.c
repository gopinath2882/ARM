#include<LPC21XX.h>
void config(void);
unsigned char rx;
unsigned char receive(void);

void transmit(unsigned char tx)
{
	while(((U0LSR>>5)&1)==0);
	U0THR=tx;
}

unsigned char receive(void)
{
	while((U0LSR&1)==0);
	return U0RBR;
}

int main ()
{
	config();
	while(1)
	{
	 rx=receive();
	 transmit(rx);
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

