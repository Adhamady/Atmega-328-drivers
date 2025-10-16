#ifndef I2C_H
#define I2C_H

#include <avr/io.h>

#define F_CPU 16000000UL
#define SCL_CLK 100000UL

void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(uint8_t data);
uint8_t I2C_read_ack(void);
uint8_t I2C_read_nack(void);

#endif
