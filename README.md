
# Project  - DIP40 BOARD - All the Codes for Free! ☕

This project uses the [PIC-DIP40 Development Board](https://www.amazon.ca/Microchip-PIC16F877A-Microcontroller-Development-Interface/dp/B07WTB68FK)  and presents 7 projects using the PIC16F877A in C Language. All codes are functional!
## Installation

Run theses Examples by Install **MPLAB-X** on **WIN10**:

**Use**: [microchip_MPLABX](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)

**Use**: [MPLAB® XC8 Compiler](https://www.microchip.com/en-us/education/developer-help/learn-tools-software/mcu-mpu/compilers/xc8)
```
Version:
Product Version: MPLAB X IDE v6.10
Java: 1.8.0_345; OpenJDK 64-Bit Server VM 25.345-b01
Runtime: OpenJDK Runtime Environment 1.8.0_345-b01
System: Windows 10 version 10.0 running on amd64; Cp1252; pt_BR (mplab)
```
    
## Documentation
[PIC16F877A](https://www.microchip.com/en-us/product/pic16f877a)

[MPLAB XC8 Compiler](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8)


[PICkit™ 3](https://ww1.microchip.com/downloads/aemtest/OTH/ProductDocuments/UserGuides/52116A.pdf)


## Run Locally

Download the project

 [Zip File](https://github.com/giljr/Projeto_Sistemas_Microcontrolados/archive/refs/heads/main.zip)

Create a Directory named:

```bash
  MPLABXProjects
```

Inside expand the Directories:

```bash
   (PRAT_1, PRAT_2...)
```

Open App and Point to Open each Project:

```bash
  MPLABX app
```



## Usage/Examples

```c
/*
     Prática 1 (A):   Piscar 1 LED
     MCU:             PIC16F877A
     Dev.Board:       PIC-DIP40 - UNINTER - VERSAO 2
     Oscillator:      4M
     Ext. Modules:    PIC KIT 3 - MICROCHIP
     Date:            AGO/2023
 */


#include <xc.h>                // Biblioteca do compilador
#include <pic16f877a.h>        // Inclua a biblioteca para o PIC16F877A0

                               // Configuração dos bits de configuração do PIC16F877A
#pragma config FOSC = HS       // Oscilador externo em modo HS (High Speed)
#pragma config WDTE = OFF      // Watchdog Timer desativado
#pragma config PWRTE = OFF     // Power-up Timer desativado
#pragma config BOREN = ON      // Brown-out Reset habilitado
#pragma config LVP = OFF       // Programação em baixa tensão desabilitada (Vpp alto)


#define _XTAL_FREQ 4000000     // Frequência do oscilador (4 MHz)
# define TRUE 1 

void main(){
    TRISD = 0x00;
    
    while (TRUE){
        PORTD = 0x7f;          // Todos pinos PORTD off, exceto RD0
        __delay_ms(1000);      // Espera 1 sec.
        PORTD = 0xff;          // Todos pinos PORTD off
        __delay_ms(1000);      // Espera 1 sec.          
    }
}
```

#### For LEDS:
In the [PIC-DIP40 Development Board](https://www.amazon.ca/Microchip-PIC16F877A-Microcontroller-Development-Interface/dp/B07WTB68FK)  
```
> KEEP LED-EN jumper
```
#### For LCDs:
```
> REMOVE the LED-EN jumper
```
## Authors
[@linkedin](https://www.linkedin.com/in/giljrx/)

[@GitHub](https://github.com/giljr)



## Screenshots

![Micro chip Learning Board, Microcontroller Development Board with RS232 Interface,PIC16F877At](https://m.media-amazon.com/images/I/61EMuMuvLqL._AC_SL1001_.jpg)


## License

[MIT](https://choosealicense.com/licenses/mit/)
