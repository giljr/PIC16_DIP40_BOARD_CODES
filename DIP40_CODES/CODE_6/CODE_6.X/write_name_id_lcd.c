/*
      Code 6: Write Name AND ID on the LCD
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
        
#include <xc.h>                // Compiler library
#include "lcd.h"               // Include library for LCD
#include <pic16f877a.h>        // Include the library for PIC16F877A

                               // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS       // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF      // Watchdog Timer disabled
#pragma config PWRTE = OFF     // Power-up Timer disabled
#pragma config BOREN = ON      // Brown-out Reset enabled
#pragma config LVP = OFF       // Low voltage programming disabled (high Vpp)

#define _XTAL_FREQ 4000000     // Oscillator frequency (4 MHz)

void writeWord();              // function prototype
                               
void writeWord(char *word) {   // Function to write a word on the LCD
     while (*word != '\0') {
         LCD_write(*word);
         word++;
     }
}

void main() {
                               // LCD initialization
     LCD_init();

                               // Write "Your Name" on the first line
     LCD_line1();              // Position the cursor on the first line, first column
     writeWord("Your Name Goes Here!");

                               // Write "ID: 1234567" on the second line
     LCD_line2();              // Position the cursor on the second line, first column
     writeWord("ID: 1234567");

     while (1) {
                               // Other operations or program logic can be added here
     }
}
