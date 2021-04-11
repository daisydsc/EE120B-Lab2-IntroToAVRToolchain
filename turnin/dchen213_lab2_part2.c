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
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
				// Initialize PORTC output to 0’s
	unsigned char cntavail;//Temporary variable to hold the valur of cnt
	unsigned char tmpA = 0x00;//Temporary variable to hold the value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	cntavail = 0;
	if((tmpA & 0x01) == 0x00) {
		cntavail = cntavail + 1;
	}
	if((tmpA & 0x02) == 0x00) {
		cntavail = cntavail + 1;
	}
	if((tmpA & 0x04) == 0x00) {
		cntavail = cntavail + 1;
	}
	if((tmpA & 0x08) == 0x00) {
		cntavail = cntavail + 1;
	}
	PORTC = cntavail;//Writes port C's 8 pins with # of available parking spaces
    }
    return 0;
}
