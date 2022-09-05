////////////////////////////////////////
//	blinkR30.c
//	Blinks LEDs wired to P9_25 (and others) by writing register R30 on the PRU
//	Wiring:	P9_16 connects to the plus lead of an LED.  The negative lead of the
//			LED goes to a 220 Ohm resistor.  The other lead of the resistor goes
//			to ground.
//	Setup:	None
//	See:	prugpio.h to see which pins attach to R30
//	PRU:	pru1_1
////////////////////////////////////////
#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"
#include "prugpio.h"
#include "

volatile register unsigned int __R30;
volatile register unsigned int __R31;

void main(void) {
	// Select which pins to toggle.  These are all on pru1_1
	uint32_t gpio = 0xffff;

	while(1) {
		__R30 |= gpio;					// Set the GPIO pin to 1
		__delay_cycles(500000000/5);    // Wait 1/2 second
		__R30 &= ~gpio;					// Clear the GPIO pin
		__delay_cycles(500000000/5); 
		}
	__halt();
}

// No need to turn off triggers or set pin direction

