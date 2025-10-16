#include "timer.h"
#include <util/delay.h>

void TIMER0_init_normal(void) {
    TCCR0A = 0x00;
    TCCR0B = (1 << CS01) | (1 << CS00);  // Prescaler 64
}

void TIMER0_delay_ms(uint16_t ms) {
    while (ms--) _delay_ms(1);
}

void TIMER1_init_fast_pwm(void) {
    DDRB |= (1 << PB1);                  // OC1A pin as output
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
    ICR1 = 39999;                        // 50Hz (for servo control)
}

void TIMER1_set_duty(uint16_t duty) {
    OCR1A = duty;
}
