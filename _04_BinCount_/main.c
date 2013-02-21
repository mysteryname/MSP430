/*  Blink LED example */

#include <msp430g2553.h>

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.
#define PIN3 (0x01 << 3)  // Input switch

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (PIN6 + PIN0);			// Set the Direction of the Port, PIN6 and 0 are outputs and the rest are inputs.
	P1OUT = (PIN6);					// Turn the Green LED on.

	while(1){
	// Check if the Input has changed on PIN3.
	// If it has, Toggle the red LED.
		if( (PIN3 & P1IN) == 0){
			P1OUT = ~(PIN0 & P1OUT);
			__delay_cycles(1600); // This is used as a "Debounce" Otherwise the LED will flash too fast.
		}
	}
}
