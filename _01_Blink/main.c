/*  Blink LED example */

#include <msp430g2553.h>
#include "main.h"

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	// Direction of the port. (High means output Low means input)
	P1DIR = (PIN0 + PIN6); // 0100 0001
	// Port output. LEDs are on pin 0 and 6.			
	P1OUT = 0x01; // 0000 0001					

	while(1){
		/* Below is the use of only two ports, to change.
		 * PORT1 = NOT ((PIN0+PIN6) AND PORT1)
		 * Rembering digital systems we get. Assuming PORT1 == 0000 0001
		 * PORT1 = (0000 0001 +  0100 0000) &  NOT 0000 0001)
		 * PORT1 =  0100 0001 & ~0000 0001 // Add the binary together (pin6 and 0)
		 * PORT1 =  0100 0001 &  1111 1110 // Not the port1
		 * PORT1 =  0100 0000 // AND the binary and port
		 */
		P1OUT = ((PIN0 + PIN6) & ~P1OUT);
		delay(500);
	}
}

