/** @file Led.h
 * Drive board blue led.
 * @author Adrien RICCIARDI
 */
#ifndef H_LED_H
#define H_LED_H

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------
/** Initialize led and turn it off. */
void LedInitialize(void);

/** Turn led on or off.
 * @param Is_Lighted Set to 1 to turn led on, set to 0 to turn led off.
 */
void LedSetState(unsigned char Is_Lighted);

#endif
