#include"lcd_header.h"
void float_no(float f)
{
	int temp=f;
	int_no(temp);
	data('.');
	temp=(f-temp)*100;
	int_no(temp);
}

int main()
{
	initial();
	command(0x80);
	float_no(29.37);
}

