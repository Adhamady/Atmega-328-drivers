#include "spi.h"

void SPI_init_master(void) {
    DDRB |= (1 << PB5) | (1 << PB3) | (1 << PB2);   // MOSI, SCK, SS
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);  // Enable SPI, master, f/16
}

void SPI_init_slave(void) {
    DDRB |= (1 << PB4);                              // MISO as output
    SPCR = (1 << SPE);                               // Enable SPI
}

uint8_t SPI_transfer(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}
