/* 
    Code 1: Blink 1 LED
     
     MCU: PIC16F877A
     Dev.Board: PIC-DIP40 - VERSION 2
     Oscillator: 4M
     Ext. Modules: PIC KIT 3 - MICROCHIP
     Date: AUG/2023
 */


#include <xc.h>                // Compiler library
#include <pic16f877a.h>        // Include library for PIC16F877A0

                               // Setting the PIC16F877A configuration bits
#pragma config FOSC = HS       // External oscillator in HS (High Speed) mode
#pragma config WDTE = OFF      // Watchdog Timer desable
#pragma config PWRTE = OFF     // Power-up Timer desable
#pragma config BOREN = ON      // Brown-out Reset unable
#pragma config LVP = OFF       // Disabled low voltage programming (high Vpp)


#define _XTAL_FREQ 4000000     // Oscillator frequency (4 MHz)
# define TRUE 1 

void main(){
    TRISD = 0x00;
    
    while (TRUE){
        PORTD = 0x7f;          // All PORTD pins off except RD0
        __delay_ms(1000);      // Wait 1 sec.
        PORTD = 0xff;          // All PORTD pins off
        __delay_ms(1000);      // Wait 1 sec.          
    }
}
