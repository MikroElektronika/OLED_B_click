/*
    __oledb_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __oledb_driver.h
@brief    OLED_B Driver
@mainpage OLED_B Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   OLEDB
@brief      OLED_B Click Driver
@{

| Global Library Prefix | **OLEDB** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **mar 2018.**      |
| Developer             | **Dusan Poluga**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _OLEDB_H_
#define _OLEDB_H_

/** 
 * @macro T_OLEDB_P
 * @brief Driver Abstract type 
 */
#define T_OLEDB_P    const uint8_t*

/** @defgroup OLEDB_COMPILE Compilation Config */              /** @{ */

   #define   __OLEDB_DRV_SPI__                            /**<     @macro __OLEDB_DRV_SPI__  @brief SPI driver selector */
   #define   __OLEDB_DRV_I2C__                            /**<     @macro __OLEDB_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __OLEDB_DRV_UART__                           /**<     @macro __OLEDB_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup OLEDB_VAR Variables */                           /** @{ */
extern uint8_t OLED_B_LCDWIDTH;
extern uint8_t OLED_B_LCDHEIGHT;
extern uint8_t OLED_B_DISPLAYOFF;
extern uint8_t OLED_B_SETDISPLAYCLOCKDIV;
extern uint8_t OLED_B_SETMULTIPLEX;
extern uint8_t OLED_B_SETDISPLAYOFFSET;
extern uint8_t OLED_B_SETSTARTLINE;
extern uint8_t OLED_B_CHARGEPUMP;
extern uint8_t OLED_B_SETSEGMENTREMAP;
extern uint8_t OLED_B_SEGREMAP;
extern uint8_t OLED_B_COMSCANDEC;
extern uint8_t OLED_B_SETCOMPINS;
extern uint8_t OLED_B_SETCONTRAST;
extern uint8_t OLED_B_SETPRECHARGE;
extern uint8_t OLED_B_SETVCOMDETECT;
extern uint8_t OLED_B_DISPLAYALLON_RESUME;
extern uint8_t OLED_B_NORMALDISPLAY;
extern uint8_t OLED_B_DISPLAYON;
extern uint8_t OLED_B_DISPLAYALLON;
extern uint8_t OLED_B_INVERTDISPLAY;
extern uint8_t OLED_B_SETLOWCOLUMN;
extern uint8_t OLED_B_SETHIGHCOLUMN;
extern uint8_t OLED_B_MEMORYMODE;
extern uint8_t OLED_B_COLUMNADDR;
extern uint8_t OLED_B_PAGEADDR;
extern uint8_t OLED_B_COMSCANINC;
extern uint8_t OLED_B_EXTERNALVCC;
extern uint8_t OLED_B_SWITCHCAPVCC;
extern uint8_t OLED_B_ACTIVATE_SCROLL;
extern uint8_t OLED_B_DEACTIVATE_SCROLL;
extern uint8_t OLED_B_SET_VERTICAL_SCROLL_AREA;
extern uint8_t OLED_B_RIGHT_HORIZONTAL_SCROLL;
extern uint8_t OLED_B_LEFT_HORIZONTAL_SCROLL;
extern uint8_t OLED_B_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL;
extern uint8_t OLED_B_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL;
extern uint8_t OLED_B_ADDR_COMMAND;
extern uint8_t OLED_B_ADDR_DATA;

/*extern uint8_t OLEDB_SPI_PROTO;
extern uint8_t OLEDB_I2C_PROTO;*/

                                                                       /** @} */
/** @defgroup OLEDB_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OLEDB_INIT Driver Initialization */              /** @{ */

#ifdef   __OLEDB_DRV_SPI__
void oledb_spiDriverInit(T_OLEDB_P gpioObj, T_OLEDB_P spiObj);
#endif
#ifdef   __OLEDB_DRV_I2C__
void oledb_i2cDriverInit(T_OLEDB_P gpioObj, T_OLEDB_P i2cObj, uint8_t slave);
#endif
#ifdef   __OLEDB_DRV_UART__
void oledb_uartDriverInit(T_OLEDB_P gpioObj, T_OLEDB_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void oledb_gpioDriverInit(T_OLEDB_P gpioObj);
                                                                       /** @} */
/** @defgroup OLEDB_FUNC Driver Functions */                   /** @{ */
void oledb_init(); /**< This function initializes the click board for communication. */
void oledb_sendCommand(uint8_t wData); /**< This function is used for sending commands to the OLED display. */
void oledb_sendData(uint8_t wData); /**< This function is used for sending data to the display. */
void oledb_setPage(uint8_t addr); /**< Set page adress for page addressing mode. */
void oledb_setColumn(uint8_t addr); /**< Set column adress for page addressing mode. */
void oledb_displayPicture(const uint8_t *pic); /**< Display picture for page addressing mode. */
void oledb_setContrast(uint8_t temp); /**< Set the display contrast level ( 0 to 255 ). */
void oledb_scrollRight(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display to the right. */
void oledb_scrollLeft(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display to the left. */
void oledb_scrollDiagright(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display diagonally to the right. */
void oledb_scrollDiagleft(uint8_t startPageAddress, uint8_t endPageAddress); /**< Scroll the display diagonally to the right. */
void oledb_stopScroll(); /**< Stop the scrolling motion */
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_OLED_B_STM.c
    @example Click_OLED_B_TIVA.c
    @example Click_OLED_B_CEC.c
    @example Click_OLED_B_KINETIS.c
    @example Click_OLED_B_MSP.c
    @example Click_OLED_B_PIC.c
    @example Click_OLED_B_PIC32.c
    @example Click_OLED_B_DSPIC.c
    @example Click_OLED_B_AVR.c
    @example Click_OLED_B_FT90x.c
    @example Click_OLED_B_STM.mbas
    @example Click_OLED_B_TIVA.mbas
    @example Click_OLED_B_CEC.mbas
    @example Click_OLED_B_KINETIS.mbas
    @example Click_OLED_B_MSP.mbas
    @example Click_OLED_B_PIC.mbas
    @example Click_OLED_B_PIC32.mbas
    @example Click_OLED_B_DSPIC.mbas
    @example Click_OLED_B_AVR.mbas
    @example Click_OLED_B_FT90x.mbas
    @example Click_OLED_B_STM.mpas
    @example Click_OLED_B_TIVA.mpas
    @example Click_OLED_B_CEC.mpas
    @example Click_OLED_B_KINETIS.mpas
    @example Click_OLED_B_MSP.mpas
    @example Click_OLED_B_PIC.mpas
    @example Click_OLED_B_PIC32.mpas
    @example Click_OLED_B_DSPIC.mpas
    @example Click_OLED_B_AVR.mpas
    @example Click_OLED_B_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __oledb_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */
