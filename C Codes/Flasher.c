#include <reg51.h>
#define Input	P2
sbit Led = P1^0;
sbit SW = P2^0;
void Delay_1_sec();
void main()
{
	Input = 0xFF; // tO program the port as an Input
	while(1)
	{
    //while( SW == 0)
		{
           Led = 0;          
           Delay_1_sec();                 
           Led = 1;           
           Delay_1_sec(); 
		}
	}
}
void Delay_1_sec()
{
	unsigned char i, j, k;
		for( i = 7; i > 0; i--)
			for( j = 255; j > 0; j--)
				for( k = 255; k > 0; k--)
						;
}
