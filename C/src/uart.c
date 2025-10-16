#include "uart.h"

void UART_init(uint32_t baud) {
    uint16_t ubrr = F_CPU/16/baud - 1;
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_send_char(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void UART_send_string(const char *str) {
    while (*str) {
        UART_send_char(*str++);
    }
}

char UART_receive_char(void) {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}
