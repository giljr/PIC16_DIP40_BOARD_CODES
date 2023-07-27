/*
      Code 4: Light 4 LEDs two by two (and turn them off) via KEY1 and KEY2
      MCU: PIC16F877A
      Dev.Board: PIC-DIP40 - UNINTER - VERSION 2
      Oscillator: 4M
      Ext. Modules: PIC KIT 3 - MICROCHIP
      Date: AUG/2023
  */
                                       
#include <xc.h>                         // Libraries for the compiler
#include <pic16f877a.h>                 // Include the library for PIC16F877A

                                        // Configuration of the PIC16F877A configuration bits
#pragma config FOSC = HS                // External oscillator in HS mode (High Speed)
#pragma config WDTE = OFF               // Watchdog Timer disabled
#pragma config PWRTE = OFF              // Power-up Timer disabled
#pragma config BOREN = ON               // Brown-out Reset enabled
#pragma config LVP = OFF                // Low voltage programming disabled (high Vpp)

#define _XTAL_FREQ 4000000              // Oscillator frequency (4 MHz)
#define TRUE 1


void main() {
     TRISD = 0B00111010;                // Configure PORTD pins RD0 and RD7 as output
     TRISB = 0B00000011;                // Configure PORTB pin RB0 as an input

                                        // Enable pull-up for RB0
     OPTION_REGbits.nRBPU = 0;
     unsigned char flag = 0;            // Button 2 control variable

     PORTD = 0B11111111;                // Initialize PORTD with all LEDs off (inverted logic)

     while (TRUE) {
         if (PORTBbits.RB0 == 0) {      // Check if the KEY1 button was pressed (RB0 at low level - inverted logic)
             __delay_ms(50);            // Debounce - wait a short period to avoid noise
             if (PORTBbits.RB0 == 0) {  // Check again if the KEY1 button is pressed (inverted logic)
                                        // Turn on the LEDs in the first and last bits of PORTD (inverted logic)
                 PORTDbits.RD0 = 0;     // Turn on the first LED (bit 0 of PORTD - inverted logic)
                 PORTDbits.RD7 = 0;     // Turn on the last LED (bit 7 of PORTD - inverted logic)
             }
              else {
                                        // Turn off the LEDs in the first and last bits of PORTD (inverted logic)
                 PORTDbits.RD0 = 1;     // Turn off the first LED (bit 0 of PORTD - inverted logic)
                 PORTDbits.RD7 = 1;     // Turn off the last LED (bit 7 of PORTD - inverted logic)
              }
         }
         if (PORTBbits.RB1 == 0 & flag == 0) {
                                        // Checks if the KEY2 button was pressed (RB1 at low level - inverted logic) and flag lowered
             __delay_ms(50);            // Debounce - wait a short period to avoid noise
             if (PORTBbits.RB1 == 0 & flag == 0) { // Check again
                 PORTDbits.RD6 = 0;     // Turn on LED2 (RD6 - inverted logic)
                 PORTDbits.RD2 = 0;     // Turn on LED6 (RD2 - inverted logic)
                 __delay_ms(1000);      // Ignore the finger remaining on the button
                 flag = 1;              // Raise the flag
             }
         }
         if (PORTBbits.RB1 == 0 & flag == 1) {
             __delay_ms(50);            // Debounce - wait a short period to avoid noise
             if (PORTBbits.RB1 == 0 & flag == 1) {
                                        // Checks again if the KEY2 button is pressed (inverted logic) and flag raised
                 PORTDbits.RD6 = 1;     // Turn off LED2 (RD6 - inverted logic)
                 PORTDbits.RD2 = 1;     // Turn off LED6 (RD2 - inverted logic)
                 __delay_ms(1000);      // Ignore the finger remaining on the button
                 flag = 0;              // Lower the flag
             }
         }

     }
}

