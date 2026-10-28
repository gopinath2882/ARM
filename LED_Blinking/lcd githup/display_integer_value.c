#include"lcd_header.h"
/*
void int_no(unsigned  int no)
{
unsigned char i=0;
char ar[5];
 
if(no==0)
data('0');

else if(no<0)
{
data('-');
no=-no;// y this one
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
}*/
int main()
{
initial();
command(0x80);
int_no(1234);
}

