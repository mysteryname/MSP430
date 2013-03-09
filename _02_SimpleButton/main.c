/*  Blink LED example */

#include <msp430g2553.h>
#include "main.h"

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.
#define PIN3 (0x01 << 3)  // Input switch

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (PIN6 + PIN0);			// Set the Direction of the Port, PIN6 and 0 are outputs and the rest are inputs.
	P1REN = (PIN3);                     //Activate the resistor in the MSP40
	P1OUT = (PIN6 + PIN3);		        // Turn the Green LED on and set the Pin3 to be a pull up resistor

	while(1){
	// Check if the Input has changed on PIN3.
	// If it has, Toggle the red LED.
		if( (PIN3 & P1IN) == 0){
			P1OUT ^= PIN0; // Simple Toggle single pin.
			delay(200); // This is used as a "Debounce" Otherwise the LED will flash too fast.
		}
	}
}
