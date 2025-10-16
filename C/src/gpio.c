#include "gpio.h"

void GPIO_init(volatile uint8_t *ddr, uint8_t pin, gpio_direction_t direction) {
    if (direction == GPIO_OUTPUT)
        *ddr |= (1 << pin);
    else
        *ddr &= ~(1 << pin);
}

void GPIO_write(volatile uint8_t *port, uint8_t pin, gpio_state_t state) {
    if (state == GPIO_HIGH)
        *port |= (1 << pin);
    else
        *port &= ~(1 << pin);
}

gpio_state_t GPIO_read(volatile uint8_t *pin_reg, uint8_t pin) {
    return ((*pin_reg & (1 << pin)) ? GPIO_HIGH : GPIO_LOW);
}

void GPIO_toggle(volatile uint8_t *port, uint8_t pin) {
    *port ^= (1 << pin);
}
