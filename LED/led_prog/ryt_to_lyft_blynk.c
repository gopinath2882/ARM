#include<LPC21XX.H>
void delay(unsigned int ms)
{	   
unsigned int i;
 for(;ms>0;ms--)																   
for(i=12000;i>0;i--);
}
int main()
{
while(1)
{
int n=0;
while(n++<4)
{
if(n==1)
 { 
 IODIR0=0x1;
 IOCLR0=0x1;
 delay(500);
 IOSET0=0x1;
 delay(500);
}
else if(n==2)
 { 
 IODIR0=0x2;
 IOCLR0=0x2;
 delay(500);
 IOSET0=0x2;
 delay(500);
}
else if(n==3)
 { 
 IODIR0=0x4;
 IOCLR0=0x4;
 delay(500);
 IOSET0=0x4;
 delay(500);
}
else if(n==4)
 {
 IODIR0=0x8; 
 IOCLR0=0x8;
 delay(500);
 IOSET0=0x8;
 delay(500);
}
}
}
}