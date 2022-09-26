/***************************  serial_52.C ***********************************/
// This program waits for a character from the keyboard, then it returns
// it back to the terminal screen and flashes a LED connected to P1.0
// AT89S52 microcontroller with 22.1184MHz crystal

#include <REG51.H>                /* special function register declarations   */
#include <stdio.h>                /* prototype declarations for I/O functions */

void Setup_S52();
unsigned char ch;
unsigned int i;
sbit LED = P1^0;
void flash_LED();

void main (void)
  {
   Setup_S52();
		printf ("Welcome to Embedded Systems Course\n");   //Print a message to the terminal screen
    flash_LED();
		
		while (1)
    {
      ch = getkey();		  // Get a character from the keyboard
      putchar(ch+1);			  // Displays it back to the terminal
      LED = 0;				  // Turn on the LED
      for(i=0;i<40000;i++);	  // Delay 1 S
      LED = 1;				  // Turn off the LED
      for(i=0;i<40000;i++);	  // Delay 1 S
  }
		
}

void Setup_S52()
{
    SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
    TMOD |= 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
    TH1   = 250;                /* TH1:  reload value for 9600 baud @ 22.1184MHz   */
    TR1   = 1;                  /* TR1:  timer 1 run                          */
    TI    = 1;                  /* TI:   set TI to send first char of UART    */
}


void flash_LED()
{
int j;
	for(j=0; j<5; j++)
	{	
			LED = 0;				  // Turn on the LED
      for(i=0;i<40000;i++);	  // Delay 1 S
      LED = 1;				  // Turn off the LED
      for(i=0;i<40000;i++);	  // Delay 1 S
	}
}