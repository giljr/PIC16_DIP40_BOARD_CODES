/*
      Code 3: Turn on LEDs in sequence
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
                               
#include <xc.h>                 // Compiler library
#include <pic16f877a.h>         // Include the library for PIC16F877A

                                // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS        // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = OFF      // Power-up Timer disabled
#pragma config BOREN = ON       // Brown-out Reset enabled
#pragma config LVP = OFF        // Low voltage programming disabled (high Vpp)

#define _XTAL_FREQ 4000000      // Oscillator frequency (4 MHz)

void main() {
     TRISD = 0x00;              // Set all PORTD pins as output
     PORTD = 0xFF;              // Initialize PORTD with all LEDs off (inverted logic)

                                // Set Timer 0 to generate a 1 second delay
     OPTION_REG = 0b11000111;   // Prescaler 1:256, timer mode, rising edge on internal clock

     while (1) {
                                // Sequence of turning the LEDs on and off
         for (int i = 0; i < 8; i++) {
                                // Turn on the current LED (bit i) and turn off the previous LED (bit i-1)
             PORTD = ~(1 << i);
             __delay_ms(1000);  // 1 second delay

                                // Turn off all LEDs
             PORTD = 0xFF;
             __delay_ms(1000);  // 1 second delay
         }
     }
}
