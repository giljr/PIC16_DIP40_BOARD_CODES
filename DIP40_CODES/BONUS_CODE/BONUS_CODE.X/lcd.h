#ifndef LCD_H
#define	LCD_H

#define rs RE0	
#define rw RE1
#define e  RE2

void init();                   
void LCD_init();               
void LCD_write(char x);            
void LCD_enable();             
void delay();                  
void LCD_line1();
void LCD_line2();
void LCD_clear();
//void LCD_writelcd(char *frase, int tam);



void init()
{
	ADCON1 = 0X07;               
    RA1=1;
	TRISE = 0X00;                
	TRISD = 0X00;                
}

void LCD_init()
{
    init();
	PORTD = 0X1;                 
	LCD_enable();
	PORTD = 0X38;                
	LCD_enable();
	PORTD = 0X0e;                
	LCD_enable();
	PORTD = 0X06;                
	LCD_enable();
	PORTD = 0X80;                
	LCD_enable();
}

void LCD_write(char x)
{
	PORTD = x;                   
	rs = 1;                      
	rw = 0;                      
	e = 0;                       
	delay();                   	 
	e = 1;                       
}

void LCD_clear(){
    PORTD = 0x01;
    rs = 0;
    rw = 0;
    e=0;
    delay();                   	 
	e = 1;
}

void LCD_line1(){
    PORTD = 0x02;
    rs = 0;
    rw = 0;
    e=0;
    delay();                   	 
	e = 1;
}
void LCD_line2(){
    PORTD = 0xC0;
    rs = 0;
    rw = 0;
    e=0;
    delay();                   	 
	e = 1;
}




void LCD_enable()
{
	rs = 0;                     
	rw = 0;                     
	e = 0;                      
	delay();                  	
	e = 1;                      
}

void delay()
{
	int i;
	for (i = 0;i < 5000;i++);
}




#endif	/* LCD_H */

