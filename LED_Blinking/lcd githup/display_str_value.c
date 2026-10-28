#include"lcd_header.h"

//char less than 16
/*void str(char* st)
{
while(*s)
command(0x80);//chech this lkine with and without
data(*s++);
}*/


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


int main()
{
initial();
	command(0x80);

str("GOPI WRKS IN TEXAS INSTRUMENT");
}
