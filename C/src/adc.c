#include "adc.h"

void ADC_init(void) {
    ADMUX = (1 << REFS0);                // AVcc as reference
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC, prescaler 64
}

uint16_t ADC_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    ADCSRA |= (1 << ADSC);               // Start conversion
    while (ADCSRA & (1 << ADSC));        // Wait for conversion
    return ADC;
}
