#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT
} gpio_direction_t;

typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} gpio_state_t;

void GPIO_init(volatile uint8_t *ddr, uint8_t pin, gpio_direction_t direction);
void GPIO_write(volatile uint8_t *port, uint8_t pin, gpio_state_t state);
gpio_state_t GPIO_read(volatile uint8_t *pin_reg, uint8_t pin);
void GPIO_toggle(volatile uint8_t *port, uint8_t pin);

#endif
