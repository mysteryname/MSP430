/*  Blink LED example */

#include <msp430g2553.h>

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
}
