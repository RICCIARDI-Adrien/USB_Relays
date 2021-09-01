/** @file Relay.c
 * See Relay.h for description.
 * @author Adrien RICCIARDI
 */
#include <Relay.h>
#include <xc.h>

//-------------------------------------------------------------------------------------------------
// Private types
//-------------------------------------------------------------------------------------------------
/** A relay information. */
typedef struct
{
	volatile unsigned char *Pointer_Port; //<! The GPIO port the relay is connected to.
	unsigned char Pin; //<! The pin in the port connected to the relay.
	unsigned char Is_Enabled; //<! Cache enabling state.
} TRelay;

//-------------------------------------------------------------------------------------------------
// Private variables
//-------------------------------------------------------------------------------------------------
/** All available relays. */
static TRelay Relays[] =
{
	// Relay 1
	{
		&LATA,
		0,
		0
	},
	// Relay 2
	{
		&LATA,
		1,
		0
	},
	// Relay 3
	{
		&LATA,
		2,
		0
	},
	// Relay 4
	{
		&LATA,
		3,
		0
	},
	// Relay 5
	{
		&LATA,
		4,
		0
	},
	// Relay 6
	{
		&LATA,
		5,
		0
	},
	// Relay 7
	{
		&LATA,
		7,
		0
	},
	// Relay 8
	{
		&LATA,
		6,
		0
	},
	// Relay 9
	{
		&LATC,
		3,
		0
	},
	// Relay 10
	{
		&LATC,
		2,
		0
	},
	// Relay 11
	{
		&LATC,
		1,
		0
	},
	// Relay 12
	{
		&LATC,
		0,
		0
	},
	// Relay 13
	{
		&LATC,
		6,
		0
	},
	// Relay 14
	{
		&LATC,
		7,
		0
	},
	// Relay 15
	{
		&LATB,
		4,
		0
	},
	// Relay 16
	{
		&LATB,
		5,
		0
	}
};

//-------------------------------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------------------------------
void RelayInitialize(void)
{
	// Set all relay pins to digital I/O
	ANSELA = 0;
	ANSELB &= 0xCF;
	ANSELC &= 0x30;

	// Make sure all relay pins are cleared
	LATA = 0;
	LATB &= 0xCF;
	LATC &= 0x30;

	// Set all relay pins direction to output
	TRISA = 0;
	TRISB &= 0xCF;
	TRISC &= 0x30;
}

unsigned char RelayGetState(unsigned char Relay_ID)
{
	// Make sure the provided relay ID is valid
	if (Relay_ID >= RELAYS_COUNT) return 0;

	return Relays[Relay_ID].Is_Enabled;
}

void RelaySetState(unsigned char Relay_ID, unsigned char Is_Enabled)
{
	TRelay *Pointer_Relay;

	// Make sure the provided relay ID is valid
	if (Relay_ID >= RELAYS_COUNT) return;

	// Cache relay access
	Pointer_Relay = &Relays[Relay_ID];

	if (Is_Enabled) *Pointer_Relay->Pointer_Port |= 1 << Pointer_Relay->Pin;
	else *Pointer_Relay->Pointer_Port &= ~(1 << Pointer_Relay->Pin);
	Pointer_Relay->Is_Enabled = Is_Enabled;
}
