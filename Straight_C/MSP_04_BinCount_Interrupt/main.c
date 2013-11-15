/*  LED Line Follower
 *
 * Hardware Set up
 * 4 LEDs, One Per Port. Connected to the Following:
 * P1.4 == LED 0
 * P1.5 == LED 2
 * P2.0 == LED 4
 * P2.1 == LED 8
 */ 

#include <msp430g2553.h>

#include "delay.h"


void Binary(int i){
	P1OUT &= ~(BIT4 + BIT5);
	P2OUT &= ~(BIT0 + BIT1);
  // Turn the LEDs off, to be refreshed below.
	if ( 0x01 & i ) P1OUT |= BIT4;
	if ( 0x02 & i ) P1OUT |= BIT5;
	if ( 0x04 & i )	P2OUT |= BIT0;
	if ( 0x08 & i )	P2OUT |= BIT1;
  // the above four lines are doing a bitwise and on the counter.
  // the counter will count from 0x0 to 0xF. If the counter is 0xF all of the
  // above "if" statements are true, lighting up all the LEDs.
  // 0x7, will light up the first three LEDs.
}


int main(void) { 
  // Stop the watch dog timer.
	WDTCTL = WDTPW | WDTHOLD;		
  // Set the Direction of the Port, The below ports are now outputs.
	P1DIR = (BIT6 + BIT4 + BIT5);			
  P2DIR = (BIT0 + BIT1);
  // Turn the Green LED on.
	P1OUT |= BIT6;	
  
  // Using an unsigned char as the counter, this will reduce code space.
  // Integers are far too large for most general counters.
  // If using an integer the code is 242bytes, Using unsigned char the code is 236bytes
	unsigned char k = 0;
	while(1){
		delay(200);
		Binary(k++);
		if (k > 16){
      k=0;
      // Toggle the  green LED on and off once the counter has overflown.
      P1OUT = ~BIT6; 
    }
	}
}


