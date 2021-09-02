/** @file Main.c
 * Entry point and main loop.
 * @author Adrien RICCIARDI
 */
#include <Communication_Protocol.h>
#include <Led.h>
#include <Relay.h>
#include <UART.h>
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
// Private functions
//-------------------------------------------------------------------------------------------------
/** Called everytime an enabled interrupt fires. */
static void __interrupt MainInterruptHandler(void)
{
	if (LED_IS_INTERRUPT_PENDING()) LedInterruptHandler();
}

//-------------------------------------------------------------------------------------------------
// Entry point
//-------------------------------------------------------------------------------------------------
void main(void)
{
	unsigned char Is_Led_Lighted = 0;

	// Initialize modules
	RelayInitialize();
	UARTInitialize();
	LedInitialize();

	// Enable interrupts
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;

	// Turn led on to tell user that everything is up and running
	LedSetState(LED_STATE_ON);

	// Process each received command, this function does not return
	CommunicationProtocolProcessCommands();

	// Do not execute random code in case something went wrong, instead make the led blinks with an unusual frequency to tell user
	while (1)
	{
		LedSetState(Is_Led_Lighted);
		Is_Led_Lighted = !Is_Led_Lighted;
		__delay_ms(150);
	}
}
