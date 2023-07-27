/*
      Code 2: Light 2 LEDs together and turn them off via KEY1
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
                                   
#include <xc.h>                        // Compiler library
#include <pic16f877a.h>                // Library for the PIC16F877A

                                       // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS               // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF              // Watchdog Timer disabled
#pragma config PWRTE = OFF             // Power-up Timer disabled
#pragma config BOREN = ON              // Brown-out Reset enabled
#pragma config LVP = OFF               // Low voltage programming disabled (high Vpp)

#define _XTAL_FREQ 4000000             // Oscillator frequency (4 MHz)
#define TRUE 1

void main() {
     TRISD = 0B01111110;               // Configure PORTD pins RD0 and RD7 as output
     TRISB = 0B00000001;               // Configure PORTB pin RB0 as an input

                                       // Enable pull-up for RB0
     OPTION_REGbits.nRBPU = 0;

     PORTD = 0B11111111;               // Initialize PORTD with all LEDs off (inverted logic)

     while (TRUE) {
         if (PORTBbits.RB0 == 0) {     // Check if the KEY1 button was pressed (RB0 at low level - inverted logic)
             __delay_ms(50);           // Debounce - wait a short period to avoid noise
             if (PORTBbits.RB0 == 0) { // Check again if the KEY1 button is pressed (inverted logic)
                                       // Turn on the LEDs in the first and last bits of PORTD (inverted logic)
                 PORTDbits.RD0 = 0;    // Turn on the first LED (bit 0 of PORTD - inverted logic)
                 PORTDbits.RD7 = 0;    // Turn on the last LED (bit 7 of PORTD - inverted logic)
             }
         } else {
                                       // Turn off the LEDs in the first and last bits of PORTD (inverted logic)
             PORTDbits.RD0 = 1;        // Turn off the first LED (bit 0 of PORTD - inverted logic)
             PORTDbits.RD7 = 1;        // Turn off the last LED (bit 7 of PORTD - inverted logic)
         }
     }
}
