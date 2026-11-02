#include"header.h"

int main()
{
	 config();
	while(1)
	{
	 rx=receive();
	 transmit(rx^=32);	
	}
	
}
