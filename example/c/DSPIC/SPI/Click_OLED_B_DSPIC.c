/*
Example for OLED B Click

    Date          : mar 2018.
    Author        : Dusan Poluga

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.0.1.0

---
Description :

The application is composed of three sections :

- System Initialization -  Initializes GPIO and I2C structures.
- Application Initialization - Configures the micro controller for communication
  and initializes the click board.
- Application Task - This section contains the main program that is executed
  showing a practiacal example on how to use the implemented functions.

*/

#include "Click_OLED_B_types.h"
#include "Click_OLED_B_config.h"

#include "resources.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_OLEDB_SPI_CFG[0] );
    Delay_ms( 100 );
}
void applicationInit()
{
    oledb_spiDriverInit( (T_OLEDB_P)&_MIKROBUS1_GPIO, (T_OLEDB_P)&_MIKROBUS1_SPI );
    oledb_init();
    Delay_ms(100);
}

void applicationTask()
{
    uint8_t i=0x00;
    oledb_displayPicture(&oledb[0]);
    Delay_ms(500);
    oledb_sendCommand(OLED_B_INVERTDISPLAY);
    Delay_ms(500);
    oledb_sendCommand(OLED_B_NORMALDISPLAY);
    Delay_ms(500);

    for(i=0xAF; i>0x00; i--){
        oledb_setContrast(i);
        Delay_ms(10);
    }
    for(i=0x00; i<0xAF; i++){
        oledb_setContrast(i);
        Delay_ms(10);
    }
    oledb_scrollRight(0x00, 0x05);
    Delay_ms(1000);
    oledb_stopScroll();
    oledb_displayPicture(&oledb[0]);

    oledb_scrollLeft(0x00, 0x05);
    Delay_ms(1000);
    oledb_stopScroll();
    oledb_displayPicture(&oledb[0]);

    oledb_scrollDiagright(0x00, 0x05);
    Delay_ms(1000);
    oledb_stopScroll();
    oledb_displayPicture(&oledb[0]);

    oledb_scrollDiagleft(0x00, 0x05);
    Delay_ms(1000);
    oledb_stopScroll();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
