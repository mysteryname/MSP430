/*  LED Line Follower
 *
 * Hardware Set up
 * 4 LEDs, One Per Port. Coneected to the Following:
 * P1.4 == LED 0
 * P1.5 == LED 2
 * P2.0 == LED 4
 * P2.1 == LED 8
 */ 

#include <msp430g2553.h>
#include "main.h"


void Binary(int i){
	P1OUT &= ~(BIT4 + BIT5);
	P2OUT &= ~(BIT0 + BIT1);
	if ( 0x01 & i ) P1OUT |= BIT4;
	if ( 0x02 & i ) P1OUT |= BIT5;
	if ( 0x04 & i )	P2OUT |= BIT0;
	if ( 0x08 & i )	P2OUT |= BIT1;
}


int main(void) { 
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (BIT6 + BIT4 + BIT5);			// Set the Direction of the Port, BIT6 and 0 are outputs and the rest are inputs.
    P2DIR = (BIT0 + BIT1);
	P1OUT |= BIT6;					// Turn the Green LED on.
	int k = 0;
	while(1){
	// Check if the Input has changed on BIT3.
	// If it has, Toggle the red LED.
		delay(200);
		Binary(k++);
		if (k > 16) k=0;
	}
}


