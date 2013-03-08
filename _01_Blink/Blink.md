Blink
===

Blink is the "Hello World" for hardware. In this experiment we are going to look into create a flashing LED on the MSP430 using a delay function and a simple software pin toggle. In this project we will be using standard C with a few tricks.Below is starting code for the MSP430 and a few things that you'll need to understand. 

lets say in the below example PORT is equal to 0001 as a 4 bit number.


example 1: NOT
PORT = ~PORT
     = 1110

example 2: Addition
PORT = PORT + 1000
     = 1001

example 3: Bitwise OR
PORT = PORT | 1100
     = 1101

	 
There are many more examples "here":http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Compound_assignment_operators

Starting off code
==
=
``` C
/*  Blink LED example */

#include <msp430g2553.h>

#define PIN0 (0x01 << 0)  //RED Led
#define PIN6 (0x01 << 6)  //GREEN led.

/* * Delay function. **/
delay(unsigned int input) {
	int i;
	for (i = 0; i<input; i++) {
		__delay_cycles(1000); // 1ms aprrox. 
	}
}

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	// Direction of the port. (High means output Low means input)
	P1DIR = (PIN0 + PIN6); // 0100 0001
	// Port output. LEDs are on pin 0 and 6.			
	P1OUT = 0x01; // 0000 0001					

	while(1){

		// Start Code here!

	}
}
```

Once That is Complete Challenge Yourself
===


Make the two LED's alternate in their blinking.
eg That is, red, green, red, green, etc... 
Make one LED stay on for longer than the other.
eg Red for 1 second, Green for 0.5 second.
