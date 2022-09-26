#include<reg51.h>
#define Input	P2 	
sbit myBit=P1^0;

void	setup(void)											
{
	Input=0xFF;
	TMOD=0x02;
}

void delay(void)												
{
	TR0=1;
	while(TF0==0);
	TR0=1;
	TF0=0;
}

void main()
{
	unsigned char f;
	setup();
	
							
	while(1)
	{
			f=(P2^0 & 1) + (P2^1 & 2) + (P2^2 & 4) + (P2^3 & 8) + 
				(P2^4 & 16) + (P2^5 & 32) + (P2^6 & 64) + (P2^7 & 128) ;  
		  TH0=-(1000/(f*(1.085)*2)) ;  
			myBit ^= 1;          
			delay();	              																					
	}
}



