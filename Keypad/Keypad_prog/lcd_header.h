#include<LPC21XX.H>
#define LCD  0xff<<0
#define RS 1<<8
#define E 1<<9
void initial(void);
void command(unsigned char);
void data(unsigned char);
void delay(unsigned int);
void str( unsigned char*);
void int_no( int no);

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

//___________________int fn_________
void int_no( int no)
{
unsigned char i=0;
char ar[5];
 
if(no==0)
data('0');

else if(no<0)
{
data('-');
no=-no;// to change -ve value to +ve
}
else
{

while(no)
{
 ar[i++]=no%10;
no/=10;
}
while(i>0)
{
data(ar[--i]+48);
}
}
}

//char more than 16
void str( unsigned char* st)
{
 unsigned char pos=0x80;
while(*st)
{
data(*st++);
pos++;
	if(pos==0x8f)
	command(0xc0);
}
}
//_____________________









