/*	Author: dchen213
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as input
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
				// Initialize PORTB output to 0’s
	unsigned char tmpB = 0x00;//Temporary variable to hold the valur of B
	unsigned char tmpA = 0x00;//Temporary value to hold the value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x03;
	if(tmpA == 0x01) {
		tmpB = 0x01;
	} else {
		tmpB = 0x00;
	}
	PORTB = tmpB;//Writes port B's 8 pins with values on port A's 8 pins
    }
    return 0;
}
