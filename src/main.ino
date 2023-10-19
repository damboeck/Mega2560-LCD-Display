#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
//#include <avr/pgmspace.h>
#include <lcdarduino.h>
#include <util/delay.h>

char s[10];
char b;

void setup() {
    lcd_init(LCD_DISP_ON);
    lcd_clrscr();
    lcd_puts("Hallo Welt\n");
    lcd_puts("Wie geht's?");

    _delay_ms(1000);
}

void loop() {
    lcd_home();
    b = get_button();
    switch(b) {
        case button_up   : lcd_puts("up   "); break;
        case button_down : lcd_puts("down "); break;
        case button_left : lcd_puts("left "); break;
        case button_right: lcd_puts("right"); break;
        case button_ok   : lcd_puts("ok   "); break;
        default          : lcd_puts("Hallo"); break;
    }
    //sprintf(s,"%d   ",get_button());
    //lcd_puts(s);
}