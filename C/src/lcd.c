#include "lcd.h"
#include "gpio.h"

#define LCD_DDR  DDRD
#define LCD_PORT PORTD
#define RS PD0
#define EN PD1

void LCD_command(uint8_t cmd) {
    LCD_PORT = (cmd & 0xF0);
    GPIO_write(&LCD_PORT, RS, GPIO_LOW);
    GPIO_write(&LCD_PORT, EN, GPIO_HIGH);
    _delay_us(1);
    GPIO_write(&LCD_PORT, EN, GPIO_LOW);

    LCD_PORT = (cmd << 4);
    GPIO_write(&LCD_PORT, EN, GPIO_HIGH);
    _delay_us(1);
    GPIO_write(&LCD_PORT, EN, GPIO_LOW);
    _delay_ms(2);
}

void LCD_char(char data) {
    LCD_PORT = (data & 0xF0);
    GPIO_write(&LCD_PORT, RS, GPIO_HIGH);
    GPIO_write(&LCD_PORT, EN, GPIO_HIGH);
    _delay_us(1);
    GPIO_write(&LCD_PORT, EN, GPIO_LOW);

    LCD_PORT = (data << 4);
    GPIO_write(&LCD_PORT, EN, GPIO_HIGH);
    _delay_us(1);
    GPIO_write(&LCD_PORT, EN, GPIO_LOW);
    _delay_ms(2);
}

void LCD_init(void) {
    LCD_DDR = 0xFF;
    _delay_ms(20);
    LCD_command(0x02);
    LCD_command(0x28);
    LCD_command(0x0C);
    LCD_command(0x06);
    LCD_command(0x01);
    _delay_ms(2);
}

void LCD_string(const char *str) {
    while (*str) LCD_char(*str++);
}

void LCD_clear(void) {
    LCD_command(0x01);
    _delay_ms(2);
}

void LCD_gotoxy(uint8_t x, uint8_t y) {
    uint8_t addr = (y == 0) ? (0x80 + x) : (0xC0 + x);
    LCD_command(addr);
}
