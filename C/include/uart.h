#ifndef UART_H
#define UART_H

#include <avr/io.h>

void UART_init(uint32_t baud);
void UART_send_char(char data);
void UART_send_string(const char *str);
char UART_receive_char(void);

#endif
