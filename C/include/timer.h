#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

void TIMER0_init_normal(void);
void TIMER0_delay_ms(uint16_t ms);
void TIMER1_init_fast_pwm(void);
void TIMER1_set_duty(uint16_t duty);

#endif
