/** @file Communication_Protocol.c
 * See Communication_Protocol.h for description.
 * @author Adrien RICCIARDI
 */
#include <Communication_Protocol.h>
#include <Configuration.h>
#include <ctype.h>
#include <Relay.h>
#include <string.h>
#include <UART.h>

//-------------------------------------------------------------------------------------------------
// Private constants
//-------------------------------------------------------------------------------------------------
/** The magic number prefixing all commands. */
#define COMMUNICATION_PROTOCOL_MAGIC_NUMBER '#'

/** This character allows to immediately clear the reception buffer. */
#define COMMUNICATION_PROTOCOL_ABORT_CHARACTER '!'

//-------------------------------------------------------------------------------------------------
// Private types
//-------------------------------------------------------------------------------------------------
/** All command reception and execution state machine states. */
typedef enum
{
	COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER,
	COMMUNICATION_PROTOCOL_STATE_RECEIVE_COMMAND_CODE,
	COMMUNICATION_PROTOCOL_STATE_RECEIVE_PAYLOAD,
	COMMUNICATION_PROTOCOL_STATE_RECEIVE_CARRIAGE_RETURN,
	COMMUNICATION_PROTOCOL_STATE_RECEIVE_LINE_FEED
} TCommunicationProtocolState;

//-------------------------------------------------------------------------------------------------
// Private variables
//-------------------------------------------------------------------------------------------------
/** Each command code is a single uppercase letter. This lookup table tells the payload size for all available commands. */
static unsigned char Command_Payload_Sizes[] =
{
	// 'A'
	0,
	// 'B'
	0,
	// 'C'
	0,
	// 'D'
	0,
	// 'E'
	0,
	// 'F'
	0,
	// 'G'
	0,
	// 'H'
	0,
	// 'I'
	0,
	// 'J'
	0,
	// 'K'
	0,
	// 'L'
	0,
	// 'M'
	0,
	// 'N'
	0,
	// 'O'
	0,
	// 'P'
	0,
	// 'Q'
	0,
	// 'R'
	0,
	// 'S'
	0,
	// 'T'
	0,
	// 'U'
	0,
	// 'V'
	0,
	// 'W'
	0,
	// 'X'
	0,
	// 'Y'
	0,
	// 'Z'
	0
};

//-------------------------------------------------------------------------------------------------
// Private functions
//-------------------------------------------------------------------------------------------------
/** Check command payload, execute the command then send the answer.
 * @param Command_Code The command to execute.
 * @param Pointer_String_Payload This string contains data only for commands that need a payload. The string is guaranteed to be zero-terminated.
 */ 
static void CommunicationProtocolExecuteCommand(unsigned char Command_Code, unsigned char *Pointer_String_Payload)
{
	unsigned char String_Answer[8];

	switch (Command_Code)
	{
		// Get firmware version
		case 'V':
			strcpy(String_Answer, CONFIGURATION_FIRMWARE_VERSION_STRING);
			break;

		// Unknown command
		default:
			strcpy(String_Answer, "KO");
			break;
	}

	// Send the answer
	strcat(String_Answer, "\r\n"); // Always add the answer suffix
	UARTWriteString(String_Answer);
}

//-------------------------------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------------------------------
void CommunicationProtocolProcessCommands(void)
{
	unsigned char Character, Command_Code, Payload_Size, String_Payload[4];
	TCommunicationProtocolState State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER;

	while (1)
	{
		// Wait for next character
		Character = UARTReadByte();

		switch (State)
		{
			case COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER:
				if (Character == COMMUNICATION_PROTOCOL_MAGIC_NUMBER) State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_COMMAND_CODE;
				break;

			case COMMUNICATION_PROTOCOL_STATE_RECEIVE_COMMAND_CODE:
				// Should the command be aborted ?
				if (Character == COMMUNICATION_PROTOCOL_ABORT_CHARACTER)
				{
					State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER;
					break;
				}
				// Make sure the command code is an upper case character
				if (!isupper(Character))
				{
					State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER;
					break;
				}
				// Determine the payload size
				Command_Code = Character;
				Payload_Size = Command_Payload_Sizes[Command_Code - 'A']; // Look-up table starts from 0
				// Is there any payload to be received ?
				if (Payload_Size > 0) State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_PAYLOAD; // TODO
				else State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_CARRIAGE_RETURN;
				break;

			case COMMUNICATION_PROTOCOL_STATE_RECEIVE_CARRIAGE_RETURN:
				if (Character != '\r') State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER; // This check also works for detecting the abort character
				else State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_LINE_FEED;
				break;

			case COMMUNICATION_PROTOCOL_STATE_RECEIVE_LINE_FEED:
				if (Character == '\n') CommunicationProtocolExecuteCommand(Command_Code, String_Payload);
				State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER;
				break;

			// This state should never be reached
			default:
				State = COMMUNICATION_PROTOCOL_STATE_RECEIVE_MAGIC_NUMBER;
				break;
		}
	}
}
