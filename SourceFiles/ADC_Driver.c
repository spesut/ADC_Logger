
#include "../HeaderFiles/ADC_Driver.h"


void ADC_Enable( ADC_REFSEL ReferenceSelect,
				 ADC_SAMPLENUM NumSamples,
				 ADC_RESSEL ResolutionSelect,
				 ADC_MUXNEG NegativeInputSelect,
				 ADC_MUXPOS PositiveInputSelect )
{
	// Setup the ADC with the requested settings
	ADC->REFCTRL.bit.REFSEL = ReferenceSelect;
	ADC->AVGCTRL.bit.SAMPLENUM = NumSamples;
	ADC->CTRLB.bit.RESSEL = ResolutionSelect;
	ADC->INPUTCTRL.bit.MUXNEG = NegativeInputSelect;
	ADC->INPUTCTRL.bit.MUXPOS = PositiveInputSelect;

	// Enable the ADC
	ADC->CTRLA.bit.ENABLE = 1;

	// Need to wait for the enable operation to sync before moving on
	while ( ADC->STATUS.bit.SYNCBUSY == 1 );

}

uint16_t ADC_BlockingRead( void )
{
	// Initiate a conversion
	ADC->SWTRIG.bit.START = 1;

	// START bit is cleared when the conversion starts
	// Wait for the conversion to start
	while ( ADC->SWTRIG.bit.START );

	// Wait for the result to be ready
	while ( ADC->INTFLAG.bit.RESRDY != 1 );

	// Return the conversion result (also clears RESRDY flag)
	return ADC->RESULT.reg;

}

void ADC_Reset( void )
{
	// Initiate the software reset
	ADC->CTRLA.bit.SWRST = 1;

	// Wait for the reset to complete
	while ( ADC->CTRLA.bit.SWRST == 1 );

}
