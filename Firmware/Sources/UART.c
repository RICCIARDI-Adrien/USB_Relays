/** @file UART.c
 * See UART.h for description.
 * @author Adrien RICCIARDI
 */
#include <UART.h>
#include <xc.h>

//-------------------------------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------------------------------
void UARTInitialize(void)
{
	// Remap UART pins through PPS module
	RC4PPS = 0x10; // Assign UART TX to RC4 as output pin
	RXPPS = 0x15; // Assign UART RX to RC5 as input pin

	// Configure UART pins as digital I/O
	ANSELC &= 0xCF;

	// Configure pins direction
	TRISCbits.TRISC4 = 0; // Set TX as output, even if this pin direction is automatically handled by the UART module
	TRISCbits.TRISC5 = 1; // Set RX pin as input

	// Set a 115200 bit/s baud rate
	BAUD1CON = 0x08; // Idle state for transmit is a high level (default value), use 16-bit baud rate generator, disable wake-up function, disable auto-baud detection
	SPBRG = 68; // Results in 0.64% deviation

	// Configure UART module
	TX1STA = 0x24; // Select 8-bit transmission, enable transmission, select asynchronous mode, select high baud rate
	RC1STA = 0x90; // Enable serial port, select 8-bit reception, enable continuous reception
}

unsigned char UARTReadByte(void)
{
	// TODO overrun and framing errors

	// Wait for a byte to be received
	while (!PIR3bits.RCIF);

	// Reading the byte also automatically clears RCIF bit
	return RC1REG;
}

void UARTWriteByte(unsigned char Data)
{
	// Wait for the bus to be idle
	while (!PIR3bits.TXIF);

	// Transmit the byte
	TX1REG = Data;
}

void UARTWriteString(const unsigned char *Pointer_String)
{
	while (*Pointer_String)
	{
		UARTWriteByte(*Pointer_String);
		Pointer_String++;
	}
}
