#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

void SPI_init_master(void);
void SPI_init_slave(void);
uint8_t SPI_transfer(uint8_t data);

#endif
