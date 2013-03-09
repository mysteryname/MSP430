/*  LED Line Follower
 *
 * Hardware Set up
 * 4 LEDs, One Per Port. Coneected to the Following:
 * P1.4 == LED 0
 * P1.5 == LED 2
 * P2.0 == LED 4
 * P2.1 == LED 8
 *
 * Analog input P1.3
 * (Trim Pot at the Time of coding)
 */ 
 
 

#include <msp430g2553.h>
#include "main.h"

#define INPUT_1 INCH_4
#define INPUT_2 INCH_5

unsigned int value=0;

void Binary(int i){
	P1OUT &= ~(BIT4 + BIT5);
	P2OUT &= ~(BIT0 + BIT1);
	if ( 0x01 & i ) P1OUT |= BIT4;
	if ( 0x02 & i ) P1OUT |= BIT5;
	if ( 0x04 & i )	P2OUT |= BIT0;
	if ( 0x08 & i )	P2OUT |= BIT1;
}

/*
// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void){
  __bic_SR_register_on_exit(CPUOFF);        // Return to active mode
}
*/

void ConfigureAdc(void){
  /* Configure ADC  Channel */

   ADC10CTL1 = INCH_3 + ADC10DIV_3;                        	// Temp Sensor ADC10CLK/4
   ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON;       // Ref voltage/sample & hold time/
   ADC10AE0 |= BIT3;                                        // reference generator ON/ADC10 ON
   __delay_cycles(1000);                   					// Wait for ADC Ref to settle 
   
}




int main(void) { 
	WDTCTL = WDTPW | WDTHOLD;		// Stop the watch dog timer.
	P1DIR = (BIT6 + BIT4 + BIT5);			// Set the Direction of the Port, BIT6, 4 and 5 are outputs and the rest are inputs.
    P2DIR = (BIT0 + BIT1); 
	P1OUT |= BIT6;					// Turn the Green LED on.
	P1SEL |= BIT3;  				// Selection for the 
	ConfigureAdc();
	int k = 0;
	
	while(1){
	// Check if the Input has changed on BIT3.
	// If it has, Toggle the red LED.
		ADC10CTL0 |= ENC + ADC10SC;
		//__bis_SR_register(CPUOFF + GIE);        // LPM0 with interrupts enabled
		while (ADC10CTL1 & BUSY);
		
		value = ADC10MEM/10 + 100;
		delay(value);
		Binary(k++);
		if (k > 16) k=0;
		
	}
}


