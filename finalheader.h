#include <LPC21xx.h>

/* Relay Output Pins */
#define BULB1   (1<<14)
#define BULB2   (1<<15)
#define BULB3   (1<<16)
#define BULB4   (1<<17)

/* LCD Pins */
#define LCD     (0x0F<<4)
#define RS      (1<<8)
#define E       (1<<9)

/* UART Configuration */
void UART_CONFIG(void)
{
    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 97;
    U0DLM = 0;
    U0LCR = 0x03;
}

/* UART Transmit */
void UART_TX(unsigned char tx)
{
    U0THR = tx;
    while(((U0LSR >> 5)&1)==0);
}

/* UART Receive */
unsigned char UART_RX(void)
{
    while((U0LSR&1)==0);
    return U0RBR;
}

/* UART String */
void UART_STRING(unsigned char *s)
{
    while(*s)
    {
        UART_TX(*s++);
    }
}

/* Delay Function */
void delay_milliseconds(unsigned int ms)
{
    T0PR = 15000 - 1;
    T0TCR = 0x01;
    while(T0TC < ms);
    T0TCR = 0x03;
    T0TCR = 0x00;
}

/* LCD Command */
void LCD_COMMAND(unsigned char cmd)
{
    IOCLR0 = LCD;
    IOSET0 = (cmd&0xF0)<<0;

    IOCLR0 = RS;
    IOSET0 = E;
    delay_milliseconds(2);
    IOCLR0 = E;

    IOCLR0 = LCD;
    IOSET0 = (cmd&0x0F)<<4;

    IOCLR0 = RS;
    IOSET0 = E;
    delay_milliseconds(2);
    IOCLR0 = E;
}

/* LCD Data */
void LCD_DATA(unsigned char d)
{
    IOCLR0 = LCD;
    IOSET0 = (d&0xF0)<<0;

    IOSET0 = RS;
    IOSET0 = E;
    delay_milliseconds(2);
    IOCLR0 = E;

    IOCLR0 = LCD;
    IOSET0 = (d&0x0F)<<4;

    IOSET0 = RS;
    IOSET0 = E;
    delay_milliseconds(2);
    IOCLR0 = E;
}

/* LCD Initialization */
void LCD_INIT(void)
{
    IODIR0 |= LCD | RS | E;

    LCD_COMMAND(0x01);
    LCD_COMMAND(0x02);
    LCD_COMMAND(0x28);
    LCD_COMMAND(0x0C);
    LCD_COMMAND(0x80);
}

/* LCD String */
void LCD_STR(unsigned char *s)
{
    while(*s)
    {
        LCD_DATA(*s++);
    }
}
unsigned char BULB_SYMBOL[8]=
{
    0x0E,
    0x11,		 
    0x11,
    0x11,
    0x0E,
    0x0E,
    0x0E,
    0x04
};

void LCD_CREATE_BULB(void)
{
    unsigned char i;

    LCD_COMMAND(0x40);      // CGRAM Address

    for(i=0;i<8;i++)
        LCD_DATA(BULB_SYMBOL[i]);

    LCD_COMMAND(0x80);      // DDRAM Address
}
