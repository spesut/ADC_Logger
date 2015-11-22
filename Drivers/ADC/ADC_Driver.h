#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H


#include <stdint.h>
#include "samd10.h"

typedef enum
{
	INT1V = 0,
	INTVCC0,
	INTVCC1,
	VREFA,
	VREFB,
	MAX_ADC_REF,
	ADC_OUT_OF_RANGE_REFSEL
} ADC_REFSEL;


typedef enum
{
	ADC_1_SAMPLE = 0,
	ADC_2_SAMPLES,
	ADC_4_SAMPLES,
	ADC_8_SAMPLES,
	ADC_16_SAMPLES,
	ADC_32_SAMPLES,
	ADC_64_SAMPLES,
	ADC_128_SAMPLES,
	ADC_256_SAMPLES,
	ADC_512_SAMPLES,
	ADC_1024_SAMPLES,
	ADC_OUT_OF_RANGE_SAMPLENUM
} ADC_SAMPLENUM;

typedef enum
{
	ADC_12BIT_RES = 0,
	ADC_16BIT_RES,
	ADC_10BIT_RES,
	ADC_8BIT_RES,
	ADC_OUT_OF_RANGE_RESSEL
} ADC_RESSEL;


typedef enum
{
	ADC_MUXNEG_PIN0 = 0,
	ADC_MUXNEG_PIN1,
	ADC_MUXNEG_GND,
	ADC_MUXNEG_IOGND,
	ADC_OUT_OF_RANGE_MUXNEG
} ADC_MUXNEG;


typedef enum
{
	ADC_MUXPOS_PIN0 = 0,
	ADC_MUXPOS_PIN1,
	ADC_MUXPOS_PIN2,
	ADC_MUXPOS_PIN3,
	ADC_MUXPOS_PIN4,
	ADC_MUXPOS_PIN5,
	ADC_MUXPOS_PIN6,
	ADC_MUXPOS_PIN7,
	ADC_MUXPOS_PIN8,
	ADC_MUXPOS_PIN9,
	ADC_MUXPOS_TEMP = 0x18,
	ADC_MUXPOS_BANDGAP,
	ADC_MUXPOS_SCALEDCOREVCC,
	ADC_MUXPOS_SCALEDIOVCC,
	ADC_MUXPOS_DAC,
	ADC_OUT_OF_RANGE_MUXPOS
} ADC_MUXPOS;



void ADC_Enable( ADC_REFSEL ReferenceSelect,
				 ADC_SAMPLENUM NumSamples,
				 ADC_RESSEL ResolutionSelect,
				 ADC_MUXNEG NegativeInputSelect,
				 ADC_MUXPOS PositiveInputSelect );

uint16_t ADC_BlockingRead( void );

void ADC_Reset( void );

#endif //ADC_DRIVER_H
