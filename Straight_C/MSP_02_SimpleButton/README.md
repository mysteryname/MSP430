MSP430 Switch
===

Aim

To Toggle an LED when the button is pressed.

Introduction

Now that you have a LED flashing every second or some other combination of the LEDs flashing. There is so much more that this chip can do. First off we will be starting with a simple push button switch. This switch allows the launchpad to be more interactive with programming.

Things that you'll need to know are listed in the following:
* [Pull Up Resistors.](http://en.wikipedia.org/wiki/Pull-up_resistor)
* [Breadboard](http://en.wikipedia.org/wiki/Breadboard)
* [Contact Bounce](http://en.wikipedia.org/wiki/Switch#Contact_bounce)
* [Understanding I/O on a micro Controller](http://www.coactionos.com/embedded-design/98-gpio-output-pin-modes.html)

In this experiment we want a tactile switch to toggle an LED, This can be done by polling the input pin on the micro controller and waiting for a change. This is generally considered back practise in the industry as this process consumes a lot of CPU cycle just watching for a change in state. This will be addressed later in experiments. Once the switch has been pressed, the MSP430 can then change the state of the LED. 

To check if there is a change in the state of a pin, in the code you need to read the Port. This can be done with the following:
```C
Temp = P1IN;
```
Where Temp is a previously defined variable and P1IN is PORT 1's input register. When reading the state of a Port it will take a �snapshot� of the states of all the bits on the port and save them into the variable Temp. At this stage you can do what you need to get the data. 

Starting Code
```C

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (PIN6 + PIN0);			// Set the Direction of the Port, PIN6 and 0 are outputs and the rest are inputs.
	P1REN = (PIN3);                     //Activate the resistor in the MSP40
	P1OUT = (PIN6 + PIN3);		        // Turn the Green LED on and set the Pin3 to be a pull up resistor

	while(1){
	// Check if the Input has changed on PIN3.
	// If it has, Toggle the red LED.
		if(<INSERT CHECK HERE>){
			P1OUT ^= PIN0; // Simple Toggle single pin.
			delay(200); // This is used as a "Debounce" Otherwise the LED will flash too fast.
		}
	}
}
```
