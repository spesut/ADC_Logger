
#include "../HeaderFiles/GCLK_Driver.h"


void GCLK_Enable( GCLK_SRC GenClkSrc,
				  GCLK_CLKCTRL_ID GenClkId,
				  GCLK_SELECT IDVal )
{

	// Select the GCLK to be used
	GCLK->GENCTRL.bit.ID = IDVal;
	GCLK->CLKCTRL.bit.GEN = IDVal;

	// Select the generic clock to configure
	GCLK->CLKCTRL.bit.ID = GenClkId;

	// Select the GCLK source clock
	GCLK->GENCTRL.bit.SRC = GenClkSrc;

	// Enable the generic clock generator
	GCLK->GENCTRL.bit.GENEN = 1;

	// Write the enable bit and wait for it to be set
	GCLK->CLKCTRL.bit.CLKEN = 1;
	while ( GCLK->CLKCTRL.bit.CLKEN == 0 );

}


void GCLK_Reset( void )
{
	// Initiate the GCLK reset
	GCLK->CTRL.bit.SWRST = 1;

	// Wait for the reset operation to complete
	while ( GCLK->CTRL.bit.SWRST );
}
