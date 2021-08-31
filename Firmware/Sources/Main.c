/** @file Main.c
 * Entry point and main loop.
 * @author Adrien RICCIARDI
 */
#include <Relay.h>
#include <xc.h>

//-------------------------------------------------------------------------------------------------
// Microcontroller configuration
//-------------------------------------------------------------------------------------------------
// CONFIG1 register
#pragma config FCMEN = OFF, CSWEN = OFF, CLKOUTEN = OFF, RSTOSC = HFINT32, FEXTOSC = OFF // Disable fail-safe clock monitor, disable clock switch, disable clock out on OSC2 pin, set 32MHz internal clock (without PLL), disable external oscillator mode
// CONFIG2 register
#pragma config DEBUG = OFF, STVREN = OFF, PPS1WAY = OFF, ZCD = ON, BORV = HI, BOREN = ON, LPBOREN = OFF, PWRTE = ON, MCLRE = ON // Disable background debugger (it is automatically handled by the debug tool), disable reset on stack overflow or underflow, allow PPS register to be set multiple times, disable zero-cross detect circuit, set brown-out voltage level to high as recommended for Fosc > 16MHz, enable brown-out reset, disable low-power brown-out reset, enable power-up timer, configure MCLR pin as MCLR
// CONFIG3 register
#pragma config WDTCCS = LFINTOSC, WDTCWS = WDTCWS_0, WDTE = OFF, WDTCPS = WDTCPS_0 // Set watchdog timer reference clock to default value, set watchdog timer window to default value, disable watchdog timer, set watchdog period to default value
// CONFIG4 register
#pragma config LVP = OFF, SCANE = not_available, WRT = ON // Disable low-voltage programming, disable memory scanner module, enable program flash memory write protection
// CONFIG5 register
#pragma config CPD = OFF, CP = OFF // Disable data EEPROM code protection, disable program memory code protection

//-------------------------------------------------------------------------------------------------
// Entry point
//-------------------------------------------------------------------------------------------------
void main(void)
{
	unsigned char i = 15;

	// Initialize modules
	RelayInitialize();

	// TEST
	ANSELBbits.ANSB0 = 0;
	TRISBbits.TRISB0 = 0;

	while (1)
	{
		RelaySetState(i, 0);
		i++;
		if (i >= RELAYS_COUNT) i = 0;
		RelaySetState(i, 1);

		LATBbits.LATB0 = !LATBbits.LATB0;
		__delay_ms(1000);
	}
}
