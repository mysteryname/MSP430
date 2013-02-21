/*  Blink LED example */

#include <msp430g2553.h>

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.
#define PIN3 (0x01 << 3)  // Input switch

#define PIN1 (0x01 << 1) 
#define PIN2 (0x01 << 2) // using non ordered pins to stop cheating 
#define PIN4 (0x01 << 4) 
#define PIN5 (0x01 << 5) 
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (PIN6 + PIN0);			// Set the Direction of the Port, PIN6 and 0 are outputs and the rest are inputs.
	P1OUT = (PIN6);					// Turn the Green LED on.
	char i=0; 						// counter 
	while(1){
	// Check if the Input has changed on PIN3.
	// If it has, Toggle the red LED.
		if( (PIN3 & P1IN) == 0){
			// add debounce somewhere 
			i+=1; // should this be i=i+1 for clarity ?
			P1OUT=0;
			if (0x01 & i ==1) P1OUT^=PIN1;			
			if (0x02 & i ==1) P1OUT^=PIN2;
			if (0x04 & i ==1) P1OUT^=PIN4;
			if (0x08 & i ==1) P1OUT^=PIN5;
			__delay_cycles(16000); // This is used as a "Debounce" Otherwise the LED will flash too fast.
		}
	}
}
