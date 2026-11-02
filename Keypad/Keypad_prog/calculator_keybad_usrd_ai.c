#include<lpc21xx.h>
#include"delay.h"
#include"lcd_header.h"

//---------------rows
# define r1 1<<10
# define r2 1<<11
# define r3 1<<12
# define r4 1<<13
//---------------colums
# define c1 (IOPIN0&(1<<14))
# define c2 (IOPIN0&(1<<15))
# define c3 (IOPIN0&(1<<16))
# define c4 (IOPIN0&(1<<17))

unsigned char lut[4][4]={{1,2,3,'+'},{4,5,6,'-'},{7,8,9,'*'},{0,'c','=','/'}};
unsigned char row_value, col_value;
unsigned int key_value()
{
	while(1)
	{
	IOCLR0=r1|r2|r3|r4;
	while((c1&&c2&&c3&&c4)==1);    //wt until any key is press
	
	//----check row1
  IOCLR0=r1;
  IOSET0=r2|r3|r4;
  if((c1&&c2&&c3&&c4)==0)
 {
  row_value=0;
	  break;
 } 
 
	//----check row2
  IOCLR0=r2;
  IOSET0=r1|r3|r4;
  if((c1&&c2&&c3&&c4)==0)
 {
  row_value=1;
	  break;
 } 
 
 	//----check row3
  IOCLR0=r3;
  IOSET0=r2|r1|r4;
  if((c1&&c2&&c3&&c4)==0)
 {
  row_value=2;
	  break;
 }

 	//----check row4
  IOCLR0=r4;
  IOSET0=r2|r3|r1;
  if((c1&&c2&&c3&&c4)==0)
 {
  row_value=3;
	 break;
 }
}
//--------- check colums
    if(c1==0)
			col_value=0;
		
		else if(c2==0)
			col_value=1;
		
		else if(c3==0)
			col_value=2;
		
		else 
			col_value=3;	
		delay_ms(100);
		
		while((c1&&c2&&c3&&c4)==0);	
		return lut[row_value][col_value];
}
void str(char *s)
{
	while(*s)
		data(*s++);
}

int main()
{
	unsigned int op=0,a=0,b=0,flag=0,result=0;
	unsigned char k;
	initial();
	IODIR0 |= r1|r2|r3|r4;

	command(0x80);
	str("4x4 matrix");

	while(1)
	{
		command(0x80);
		k=key_value();

		if(k<=9)
		{
			if(flag==0)
				a=a*10+k;
			else
				b=b*10+k;
			int_no(k);
		}
		else if(k=='=')
		{
			if(op=='+') result=a+b;
			else if(op=='-') result=a-b;
			else if(op=='*') result=a*b;
			else if(op=='/' && b!=0) result=a/b;
			int_no(result);
		}
		else if(k=='c')
		{
			command(0x01);
			op=0;a=0;b=0;flag=0;result=0;
		}
		else
		{
			op=k;
			flag=1;
			data(op);
		}
	}
}
		
	
	
	
	

