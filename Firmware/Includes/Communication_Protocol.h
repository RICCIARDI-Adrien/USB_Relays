/** @file Communication_Protocol.h
 * Receive a command, decode it, execute it and send the appropriate answer.
 * @author Adrien RICCIARDI
 */
#ifndef H_COMMUNICATION_PROTOCOL_H
#define H_COMMUNICATION_PROTOCOL_H

//-------------------------------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------------------------------
/** Wait for a fully valid command, process it and send the answer.
 * @note This function must be called repeatedly to process all incoming commands.
 * @note This function never returns and keeps processing all incoming commands infinitely.
 */ 
void CommunicationProtocolProcessCommands(void);

#endif
