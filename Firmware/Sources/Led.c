/** @file Led.c
 * See Led.h for description.
 * @author Adrien RICCIARDI
 */
#include <Led.h>
#include <xc.h>

//-------------------------------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------------------------------
void LedInitialize(void)
{
	// Set pin as digital I/O
	ANSELBbits.ANSB0 = 0;

	// Make sure led is turned off
	LATBbits.LATB0 = 0;

	// Configure led pin direction as output
	TRISBbits.TRISB0 = 0;

	// Configure the timer 0 module to trigger an interrupt every 250ms
	T0CON1 = 0x45; // Use Fosc/4 as source clock, synchronize the timer input with Fosc/4, configure a 1:32 prescaler
	T0CON0 = 0x10; // Disable the timer for now, configure the timer as 16-bit, select a 1:1 postscaler

	// Enable timer 0 interrupt
	PIE0bits.TMR0IE = 1;
}

void LedSetState(TLedState State)
{
	switch (State)
	{
		case LED_STATE_OFF:
			T0CON0bits.T0EN = 0; // Stop led blinking if any
			LATBbits.LATB0 = 0;
			break;

		case LED_STATE_ON:
			T0CON0bits.T0EN = 0; // Stop led blinking if any
			LATBbits.LATB0 = 1;
			break;

		case LED_STATE_BLINKING:
			// Reset timer counter
			TMR0L = 0;
			TMR0H = 0;
			// Start led blinking
			T0CON0bits.T0EN = 1;
			break;
	}
}

void LedInterruptHandler(void)
{
	// Toggle led state
	LATBbits.LATB0 = !LATBbits.LATB0;

	// Clear interrupt flag
	PIR0bits.TMR0IF = 0;
}
