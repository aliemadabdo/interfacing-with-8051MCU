#include<reg51.h>

#define Input	P2 		//input port

sbit generated_Frequency_logic = P1^0;

void	sysInit(void)											//function to initialize p2 as input port
{
	Input=0xFF;
}

void timerMode(void)										//function to initialize timer mode
{
	TMOD=0x01;
}

void delay(void)												//a function to generate a delay for each cycle
{
	TR0=1;
	while(TF0==0);
	TR0=1;
	TF0=0;
}

void main()
{	
	sysInit();											//function to initialize p2 as input port
	timerMode();											//function to initialize timer mode
//	Input=0x80; //debugging //TH&TL=hex of them-368/freq
	while(1)
	{
		while (Input != 0xFF)
		{																
			switch( Input )
			{
					case 0xFE:															//1KHz
							TH0=0xFE; TL0=0x34; break;
					
					case 0xFD:															//2KHz
							TH0=0xFF; TL0=0x1A; break;
					
					case 0xFB:															//3KHz
							TH0=0xFF; TL0=0x67; break;
			
					case 0xF7:                     				 //4KHz
							TH0=0xFF; TL0=0x8D; break;
					
					case 0xEF:															//5KHz
							TH0=0xFF; TL0=0xA4; break;
					
					case 0xDF:															//6KHz
							TH0=0xFF; TL0=0xB4; break;
					
					case 0xBF:															//7KHz
							TH0=0xFF; TL0=0xBF; break;
					
					case 0x7F:															//8KHz
							TH0=0xFF; TL0=0xC7; break;
			}
			
			generated_Frequency_logic ^= 1;          
			delay();	              																					
		}
	}
}
