#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>

void LCD_init(void);
void LCD_command(uint8_t cmd);
void LCD_char(char data);
void LCD_string(const char *str);
void LCD_clear(void);
void LCD_gotoxy(uint8_t x, uint8_t y);

#endif
