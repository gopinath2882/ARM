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
 
unsigned char lut[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,'c'}}; 
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
int main()
{
	unsigned char k,FLAG=0;
	initial();
	IODIR0|=r1|r2|r3|r4;
	command(0x80);
	str("welcome to restaurant");
	while(1)
	{
		//table selecting 
			command(0x80);
		 k=key_value();
if(FLAG==0)
{
	
	if(k>=1&&k<=6)
		{
			switch(k)
			{
			case 1: str("Table 1"); break;
			case 2: str("Table 2"); break;
			case 3: str("Table 3"); break;
			case 4: str("Table 4"); break;
			case 5: str("Table 5"); break;
			case 6: str("Table 6"); break;
      }
			FLAG=1;
		}
}
else if(FLAG==1)
	{
		if(k>=7&&k<=15)	
		{
			switch(k)
			{
			case 7: str("Idly"); break;
			case 8: str("Dosa"); break;
			case 9: str("chutney"); break;
			case 10: str("Vada"); break;
			case 11: str("Pongal"); break;
			case 12: str("Chappati"); break;
			case 13: str("Puri"); break;	
			case 14: str("Sambar"); break;
			case 15: str("Sambar"); break;
      }	
		}
	}
if(k=='c')
{ 
	command(0x01);	
  FLAG=0;
}
		}
	}
