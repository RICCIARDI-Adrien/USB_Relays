/** @file UART.h
 * Simple blocking UART driver.
 * @author Adrien RICCIARDI
 */
#ifndef H_UART_H
#define H_UART_H

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------
/** Assign UART pin and configure it for operation. */
void UARTInitialize(void);

/** Wait for a byte to be received on the UART.
 * @return The received byte.
 */
unsigned char UARTReadByte(void);

/** Transmit a byte through the UART.
 * @param Data The byte to send.
 */
void UARTWriteByte(unsigned char Data);

#endif
