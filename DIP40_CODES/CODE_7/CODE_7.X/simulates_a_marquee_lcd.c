/*
      Code 7: Simulates a Marquee on the LCD (to the right)
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
        
#include <xc.h>
#include "lcd.h"                  // Include library for LCD
#include <pic16f877a.h>           // Include the library for PIC16F877A

                                  // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS          // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF         // Watchdog Timer disabled
#pragma config PWRTE = OFF        // Power-up Timer disabled
#pragma config BOREN = ON         // Brown-out Reset enabled
#pragma config LVP = OFF          // Low voltage programming disabled (high Vpp)

#define _XTAL_FREQ 4000000        // Oscillator frequency (4 MHz)

                                  // function prototype
void writeWord(char *word);
int stringLength(char *str);
void LCD_shift_right(char *word);

void writeWord(char *word) {      // Function to write a word on the LCD
     while (*word != '\0') {
         LCD_write(*word);
         word++;
     }
}

                                  // Custom function to calculate string length
int stringLength(char *str) {
     int len = 0;
     while (*str != '\0') {
         len++;
         str++;
     }
     return len;
}
                                  // Function to animate the letters to the right in the display
void LCD_shift_right(char *word) {
     int len = stringLength(word); // Calculate the word length
     int i, j;
                                  // Loop to shift characters
     for (i = 0; i < len + 16; i++) {
         LCD_line1();             // Position the cursor on the first line, first column
         for (j = 0; j < 16; j++) {
                                  // Shift characters to the right
             LCD_write(i + j < len ? word[i + j] : ' '); // Show word character or white space
         }
         __delay_ms(1);           // Delay to control animation speed
     }
}

void main() {
                                  // LCD initialization
     LCD_init();
                                  // First line: "Your Name and Id: 1234567"
     LCD_line1();                 // Position the cursor on the first line, first column
     LCD_shift_right("Your Name");

     while (1) {
                                   // Other operations or program logic can be added here
     }
}
