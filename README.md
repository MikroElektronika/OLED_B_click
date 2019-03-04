![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# OLED_B Click

- **CIC Prefix**  : OLEDB
- **Author**      : Dusan Poluga
- **Verison**     : 1.0.0
- **Date**        : mar 2018.

---

### Software Support

We provide a library for the OLED_B Click on our [LibStock](https://libstock.mikroe.com/projects/view/1111/oled-b-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library contains all the necessary functions for full control of the OLED B display.

Key functions :

- ``` void oledb_displayPicture(const uint8_t *pic) ``` - Display picture for page addressing mode.
- ``` void oledb_init() ``` - This function initializes the click board for communication.
- ``` void oledb_sendCommand(uint8_t wData) ``` - his function is used for sending commands to the OLED display.

**Examples Description**

The application is composed of three sections :

- System Initialization -  Initializes GPIO and I2C structures.
- Application Initialization - Configures the micro controller for communication
  and initializes the click board.
- Application Task - This section contains the main program that is executed
  showing a practiacal example on how to use the implemented functions.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1111/oled-b-click) page.

Other mikroE Libraries used in the example:

- I2C library 
- SPI Library

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
