		// The sfr statement defines a special function register:
		sfr		Input = P2;						
		//The BIT statement assigns an address to the specified symbol. 
		SW 		BIT     P2.0;
		LED     BIT     P1.0;		
		
		ORG		0H				
		MOV		SP,	#2FH			; at startup SP = 07H but is preferable to change it		
		MOV		Input, #0FFH
		
HERE:	JB 		SW, HERE	
LOOP:	clr		LED
		ACALL	Delay_1_sec
		setb	LED
		ACALL	Delay_1_sec		
		SJMP	HERE
Delay_1_sec: 	
		MOV R5, #3 
LOOP1: 	MOV R6, #255  
LOOP2: 	MOV R7, #255  
LOOP3:	DJNZ R7, LOOP3 ;inner loop 
		DJNZ R6, LOOP2 ;middle loop 
		DJNZ R5, LOOP1 ;outer loop				
		RET		
				
		END
			