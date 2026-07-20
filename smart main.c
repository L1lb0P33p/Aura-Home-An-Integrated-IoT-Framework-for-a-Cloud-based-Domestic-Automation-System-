#include "LCDHeadersmart.h"

/* Add this function here */
void LCD_SCROLL_TITLE(void)
{
    unsigned int i, j;
    char title[] = "An Integrated IoT Framework for a Cloud-Based Domestic Automation System";
    char buf[21];

    for(i = 0; i < sizeof(title) - 20; i++)
    {
        LCD_COMMAND(0x01);
        LCD_COMMAND(0x80);

        for(j = 0; j < 20; j++)
        {
            buf[j] = title[i + j];
        }
        buf[20] = '\0';

        LCD_STR(buf);
        delay_milliseconds(100);
    }

    LCD_COMMAND(0x01);

    LCD_COMMAND(0x80);
    LCD_STR("choose which");

    LCD_COMMAND(0xC0);
    LCD_STR("BULB do you");

    LCD_COMMAND(0x94);
    LCD_STR("want to turn");

    LCD_COMMAND(0xD4);
    LCD_STR("ON / OFF");

    delay_milliseconds(500);
}
void LCD_BULB(void)
{
    LCD_COMMAND(0x01);
    LCD_COMMAND(0x80);
    LCD_STR("BULB 1 :");
    LCD_COMMAND(0xC0);
    LCD_STR("BULB 2 :");
    LCD_COMMAND(0x94);
    LCD_STR("BULB 3 :");
    LCD_COMMAND(0xD4);
    LCD_STR("BULB 4 :");
}

int main()
{
    unsigned char rxbyte;
	PINSEL0 |=0;
	PINSEL1 |=0;
    IODIR0 |= BULB1 | BULB2 | BULB3 | BULB4;
    IOSET0 = BULB1 | BULB2 | BULB3 | BULB4;
    LCD_INIT();
	LCD_CREATE_BULB();
    /*Bulb Status Screen */
	LCD_SCROLL_TITLE();
    LCD_BULB();

    UART_CONFIG();

while(1)
{
    rxbyte = UART_RX();

    /* BULB 1 */
    if(rxbyte == 'A')
    {
        IOCLR0 = BULB1;
        LCD_COMMAND(0x89);
        LCD_STR("ON ");

        LCD_COMMAND(0x8F);      // Last column of Line 1
        LCD_DATA(0);            // Bulb icon
    }
    else if(rxbyte == 'a')
    {
        IOSET0 = BULB1;
        LCD_COMMAND(0x89);
        LCD_STR("OFF");

        LCD_COMMAND(0x8F);
        LCD_DATA(' ');          // Remove icon
    }

    /* BULB 2 */
    else if(rxbyte == 'B')
    {
        IOCLR0 = BULB2;
        LCD_COMMAND(0xC9);
        LCD_STR("ON ");

        LCD_COMMAND(0xCF);      // Last column of Line 2
        LCD_DATA(0);
    }
    else if(rxbyte == 'b')
    {
        IOSET0 = BULB2;
        LCD_COMMAND(0xC9);
        LCD_STR("OFF");

        LCD_COMMAND(0xCF);
        LCD_DATA(' ');
    }

    /* BULB 3 */
    else if(rxbyte == 'C')
    {
        IOCLR0 = BULB3;
        LCD_COMMAND(0x9D);      // Status position
        LCD_STR("ON ");

        LCD_COMMAND(0xA3);      // Last column of Line 3
        LCD_DATA(0);
    }
    else if(rxbyte == 'c')
    {
        IOSET0 = BULB3;
        LCD_COMMAND(0x9D);
        LCD_STR("OFF");

        LCD_COMMAND(0xA3);
        LCD_DATA(' ');
    }

    /* BULB 4 */
    else if(rxbyte == 'D')
    {
        IOCLR0 = BULB4;
        LCD_COMMAND(0xDD);      // Status position
        LCD_STR("ON ");

        LCD_COMMAND(0xE3);      // Last column of Line 4
        LCD_DATA(0);
    }
    else if(rxbyte == 'd')
    {
        IOSET0 = BULB4;
        LCD_COMMAND(0xDD);
        LCD_STR("OFF");

        LCD_COMMAND(0xE3);
        LCD_DATA(' ');
    }

    else
    {
        IOSET0 = BULB1 | BULB2 | BULB3 | BULB4;
    }
}
}
