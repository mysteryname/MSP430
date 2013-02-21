/*  LED Line Follower
 
 */

#include <msp430g2553.h>

// P1.4 0
// P1.5 1
// P2.0 2
// P2.1 3
// LEDs..

/* * Delay function. **/
delay(unsigned int d) {
	int i;
	for (i = 0; i<d; i++) {
		__delay_cycles(1000); // 1ms aprrox.
	}
}




void Binary(int i){
//    P1OUT = ~(P1OUT & BIT4) ;//&& (0x1 & i));
//    P1OUT = ~(P1OUT & BIT5) ;//&& (0x2 & i));
//    P2OUT = ~(P2OUT & BIT0); //&& (0x4 & i));
    P2OUT = ~(P2OUT & BIT1); //&& (0x8 & i));
}


int main(void) {
    int count;
    
    
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (BIT6 + BIT4 + BIT5);			// Set the Direction of the Port, BIT6 and 0 are outputs and the rest are inputs.
    //P2DIR = (BIT0 + BIT1);
    //P2OUT = 0;
    P1OUT = 0;
	P1OUT = (P1OUT & BIT6);					// Turn the Green LED on.

	while(1){
	// Check if the Input has changed on BIT3.
	// If it has, Toggle the red LED.
		if( (BIT3 & P1IN) == 0){
			P1OUT = ~(BIT4 & P1OUT);
			delay(500); // This is used as a "Debounce" Otherwise the LED will flash too fast.
            //Binary(count); count = count << 1
            //if (count > 0x8) count = 0x01;
		}
	}
}
