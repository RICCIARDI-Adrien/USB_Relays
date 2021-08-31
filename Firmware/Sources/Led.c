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
}

void LedSetState(unsigned char Is_Lighted)
{
	LATBbits.LATB0 = Is_Lighted;
}
