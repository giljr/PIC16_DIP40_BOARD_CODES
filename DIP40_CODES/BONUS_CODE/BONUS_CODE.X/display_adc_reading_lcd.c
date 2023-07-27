#include <xc.h>
#include <stdio.h>
#include "lcd.h"
#include <pic16f877a.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000

void writeWord(char *word) {
    while (*word != '\0') {
        LCD_write(*word);
        word++;
    }
}

void ADC_init() {
    ADCON0 = 0x81;
    ADCON1 = 0x80;
}

unsigned int ADC_read(unsigned int channel) {
    unsigned int reading;
    ADCON0 &= 0xC5;                           // 11000101, clear channels' bits
    ADCON0 |= (channel << 3);                 // Set channel now
    GO_nDONE = 1;
    while (GO_nDONE);
                                             // Retrieve the converted digital value
    reading = ((ADRESH << 8) + (int)ADRESL); // Combine ADRESH and ADRESL for a 10-bit result
    return reading;
}

void main() {
    unsigned int reading;
    char buffer[8];                         // Buffer to hold the formatted ADC reading

    ADC_init();
    LCD_init();
                                            // Clear the LCD before each new reading
    LCD_clear();
    LCD_line1();
    writeWord("--ADC Reading--");

    while (1) {

        
        reading = ADC_read(0);
        LCD_line2();
                                            // Format the ADC reading as a two-digit number
                                            //sprintf(buffer, "%u.%03u", reading / 1000, reading % 1000);
        sprintf(buffer, "%02u", reading);
                                            // Write the formatted string to the LCD
        writeWord(buffer);
        writeWord("      ");                // Clear line2 before each new reading
    }
}
