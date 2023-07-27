/*
     Code 5: Write "Hello World" on the LCD
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
#include <xc.h>                     // libraries for compiler
#include "lcd.h"                    // Include library for LCD
#include <pic16f877a.h>             // Include the library for PIC16F877A

                                    // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS            // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF           // Watchdog Timer disabled
#pragma config PWRTE = OFF          // Power-up Timer disabled
#pragma config BOREN = ON           // Brown-out Reset enabled
#pragma config LVP = OFF            // Low voltage programming disabled (high Vpp)
#pragma config CP = OFF

#define _XTAL_FREQ 4000000           // Oscillator frequency (4 MHz)

void main() {
                                     // LCD initialization
     LCD_init();
     LCD_clear();
     LCD_line1();
                                     // Write the phrase "HELLO WORLD" character by character on the first line of the display
     LCD_write('H');
     LCD_write('E');
     LCD_write('L');
     LCD_write('L');
     LCD_write('O');
     LCD_write(' ');
     LCD_write('W');
     LCD_write('O');
     LCD_write('L');
     LCD_write('R');
     LCD_write('D');
     LCD_write('!');

     while (1) {
                                     // Other operations or program logic can be added here
     }
}
