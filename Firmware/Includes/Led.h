/** @file Led.h
 * Drive board blue led.
 * @author Adrien RICCIARDI
 */
#ifndef H_LED_H
#define H_LED_H

#include <xc.h>

//-------------------------------------------------------------------------------------------------
// Constants
//-------------------------------------------------------------------------------------------------
/** Tell whether the led interrupt has fired. */
#define LED_IS_INTERRUPT_PENDING() (PIE0bits.TMR0IE && PIR0bits.TMR0IF)

//-------------------------------------------------------------------------------------------------
// Types
//-------------------------------------------------------------------------------------------------
/** All led possible states. */
typedef enum
{
	LED_STATE_OFF,
	LED_STATE_ON,
	LED_STATE_BLINKING
} TLedState;

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------
/** Initialize led and turn it off. */
void LedInitialize(void);

/** Change led state.
 * @param State The new led state.
 */
void LedSetState(TLedState State);

/** This task must be called in interrupt context when the led interrupt has fired. */
void LedInterruptHandler(void);

#endif
