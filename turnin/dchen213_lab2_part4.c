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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as outputs/Initialize PORTC output to 0’s
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char tmpB = 0x00;//Temporary variable to hold the valur of B
	unsigned char tmpA = 0x00;//Temporary variable to hold the value of A
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = ((tmpA + tmpB + tmpC) >> 2) & 0xFC;
	if((tmpA + tmpB + tmpC) > 0x8C){
		tmpD = tmpD + 1;
	}
	if((tmpC - tmpA) > 0x50 || (tmpA - tmpC) > 0x50) {
		tmpD = tmpD + 2;
	}
	PORTD = tmpD;//Writes port C's 8 pins with # of available parking spaces
    }
    return 0;
}
