
#include "USART_Sercom_Driver.h"

void USART_Enable( USART_RXPO	RXPad,
				   USART_TXPO	TXPad,
				   USART_MODE	ClockSelect,
				   USART_PMODE	ParityMode,
				   USART_SBMODE	StopBits,
				   USART_CHSIZE	DataWidth,
				   USART_DORD	DataOrder,
				   uint16_t		Sercom_BaudRegister )
{
	// Setup SERCOM1 with the desired settings
	SERCOM1->USART.CTRLA.bit.RXPO = RXPad;
	SERCOM1->USART.CTRLA.bit.TXPO = TXPad;
	SERCOM1->USART.CTRLA.bit.MODE = ClockSelect;
	SERCOM1->USART.CTRLB.bit.PMODE = ParityMode;
	SERCOM1->USART.CTRLB.bit.SBMODE = StopBits;
	SERCOM1->USART.CTRLB.bit.CHSIZE = DataWidth;
	SERCOM1->USART.CTRLA.bit.DORD = DataOrder;
	SERCOM1->USART.BAUD.bit.BAUD = Sercom_BaudRegister;

	// Enable the transmitter and receiver
	SERCOM1->USART.CTRLB.bit.RXEN = 1;
	SERCOM1->USART.CTRLB.bit.TXEN = 1;

	// Enable the USART
	SERCOM1->USART.CTRLA.bit.ENABLE = 1;
	// Block until the USART enable has completed
	while ( SERCOM1->USART.SYNCBUSY.bit.ENABLE );
}

void USART_Reset( void )
{
	// Initiate the reset
	SERCOM1->USART.CTRLA.bit.SWRST = 1;

	// Wait for the reset to complete
	while ( SERCOM1->USART.SYNCBUSY.bit.SWRST &&
			SERCOM1->USART.CTRLA.bit.SWRST );

}

uint8_t	USART_BlockingReadByte( void )
{
	// Wait for the receive bit to be set
	while ( !SERCOM1->USART.INTFLAG.bit.RXC );

	// Return the data received
	return SERCOM1->USART.DATA.bit.DATA;
}

void USART_BlockingWriteByte( uint8_t data )
{

	// Wait for the data register to empty
	while ( !SERCOM1->USART.INTFLAG.bit.DRE );

	// Load the data register
	SERCOM1->USART.DATA.bit.DATA = data;

	// Wait for transmission to complete
	while ( !SERCOM1->USART.INTFLAG.bit.TXC );


}
