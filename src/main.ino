#include <Arduino.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include "lib/lcdbutton.h"
#include <util/delay.h>

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char s[10];
char b;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Hallo Welt");
    lcd.setCursor(0,1);
    lcd.print("Wie geht es?");
    _delay_ms(1000);
}

void loop() {
    lcd.home();
    b = get_button();
    switch(b) {
        case button_up   : lcd.print("up   "); break;
        case button_down : lcd.print("down "); break;
        case button_left : lcd.print("left "); break;
        case button_right: lcd.print("right"); break;
        case button_ok   : lcd.print("ok   "); break;
        default          : lcd.print("Hallo"); break;
    }
    //sprintf(s,"%d   ",get_button());
    //lcd_puts(s);
}