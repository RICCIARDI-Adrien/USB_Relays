/** @file Relay.h
 * Control each relay separately.
 * @author Adrien RICCIARDI
 */
#ifndef H_RELAY_H
#define H_RELAY_H

//-------------------------------------------------------------------------------------------------
// Constants
//-------------------------------------------------------------------------------------------------
/** How many relays are available. */
#define RELAYS_COUNT 16

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------
/** Configure all relay GPIOs and turn off all relays. */
void RelayInitialize(void);

/** Turn a relay on or off.
 * @param Relay_ID The relay to set state (in range 0 to RELAYS_COUNT - 1). The function does nothing if an invalid relay ID is provided.
 * @param Is_Enabled Set to 1 to turn the relay on, set to 0 to turn the relay off.
 */
void RelaySetState(unsigned char Relay_ID, unsigned char Is_Enabled);

#endif
