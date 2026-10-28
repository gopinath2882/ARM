#include"lcd_header.h"
// to display A to Z in  lcd  first  place only
/*
int main()
{
	unsigned char ch='A';
	initial();
	while (ch<='Z')
	{
		command(0x80);
		data(ch++);
	  delay(500);
	}
}
 */ 


// to display A to Z in  next to next in  lcd 
int main()
{
	unsigned char ch='A';
	initial();
	command(0x80);
	while (ch<='Z')
	{
		data(ch++);
	}
}
