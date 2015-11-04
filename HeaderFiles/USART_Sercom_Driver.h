
#include <stdint.h>
#include "samd10.h"

typedef enum
{
	USART_MSB_FIRST = 0,
	USART_LSB_FIRST,
	USART_DORD_OUT_OF_RANGE
} USART_DORD;

typedef enum
{
	RX_PAD0 = 0,
	RX_PAD1,
	RX_PAD2,
	RX_PAD3,
	RX_PAD_OUT_OF_RANGE
} USART_RXPO;

typedef enum
{
	TX_PAD0 = 0,
	TX_PAD2,
	TX_PAD0_ALT,
	RESERVED,
	TX_PAD_OUT_OF_RANGE
} USART_TXPO;

typedef enum
{
	USART_EXTCLK = 0,
	USART_INTCLK,
	USART_MODE_OUT_OF_RANGE
} USART_MODE;

typedef enum
{
	USART_EVEN_PARITY = 0,
	USART_ODD_PARITY,
	USART_PARITY_OUT_OF_RANGE
} USART_PMODE;

typedef enum
{
	USART_ONE_STOP = 0,
	USART_TWO_STOP,
	USART_STOP_OUT_OF_RANGE
} USART_SBMODE;

typedef enum
{
	USART_8BIT_DATA = 0,
	USART_9BIT_DATA,
	USART_5BIT_DATA = 0x5,
	USART_6BIT_DATA,
	USART_7BIT_DATA,
	USART_DATA_OUT_OF_RANGE
} USART_CHSIZE;


void USART_Enable( USART_RXPO	RXPad,
				   USART_TXPO	TXPad,
				   USART_MODE	ClockSelect,
				   USART_PMODE	ParityMode,
				   USART_SBMODE	StopBits,
				   USART_CHSIZE	DataWidth,
				   USART_DORD	DataOrder,
				   uint16_t		Sercom_BaudRegister );

void USART_Reset( void );
uint8_t	USART_BlockingReadByte( void );
void USART_BlockingWriteByte( uint8_t data );
