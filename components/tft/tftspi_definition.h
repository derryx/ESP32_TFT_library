//
// Created by Pedro Furlanetto on 1/27/20.
//


#include "tftspi.h"

#ifndef PICKS1_TFTSPI_DEFINITION_H
#define PICKS1_TFTSPI_DEFINITION_H

#define TOUCH_TYPE_NONE		0
#define TOUCH_TYPE_XPT2046	1
#define TOUCH_TYPE_STMPE610	2

#define TP_CALX_XPT2046		7472920
#define TP_CALY_XPT2046		122224794

#define TP_CALX_STMPE610	21368532
#define TP_CALY_STMPE610	11800144

// === Screen orientation constants ===
#define PORTRAIT	0
#define LANDSCAPE	1
#define PORTRAIT_FLIP	2
#define LANDSCAPE_FLIP	3

#define DISP_TYPE_ILI9341	0
#define DISP_TYPE_ILI9488	1
#define DISP_TYPE_ST7789V	2
#define DISP_TYPE_ST7735	3
#define DISP_TYPE_ST7735R	4
#define DISP_TYPE_ST7735B	5
#define DISP_TYPE_MAX		6

#if CONFIG_EXAMPLE_DISPLAY_TYPE == 1

// ** Set the correct configuration for ESP32-WROVER-KIT v3
// --------------------------------------------------------
//#define DEFAULT_DISP_TYPE           DISP_TYPE_ST7789V
#define DEFAULT_DISP_TYPE           DISP_TYPE_ILI9341
#define DEFAULT_TFT_DISPLAY_WIDTH   240
#define DEFAULT_TFT_DISPLAY_HEIGHT  320
#define DISP_COLOR_BITS_24          0x66
#define DEFAULT_GAMMA_CURVE         0
#define DEFAULT_SPI_CLOCK           26000000
#define TFT_INVERT_ROTATION         0
//#define TFT_INVERT_ROTATION1        1
#define TFT_INVERT_ROTATION1        0
#define TFT_RGB_BGR                 0x00

#define USE_TOUCH	TOUCH_TYPE_NONE

#define PIN_NUM_MISO 25		// SPI MISO
#define PIN_NUM_MOSI 23		// SPI MOSI
#define PIN_NUM_CLK  19		// SPI CLOCK pin
#define PIN_NUM_CS   22		// Display CS pin
//#define PIN_NUM_DC   21		// Display command/data pin
#define PIN_NUM_DC   33   // Display command/data pin
#define PIN_NUM_TCS   0		// Touch screen CS pin

#define PIN_NUM_RST  18  	// GPIO used for RESET control
#define PIN_NUM_BCKL  5     // GPIO used for backlight control
#define PIN_BCKL_ON   0     // GPIO value for backlight ON
#define PIN_BCKL_OFF  1     // GPIO value for backlight OFF
// --------------------------------------------------------

#elif CONFIG_EXAMPLE_DISPLAY_TYPE == 2

// ** Set the correct configuration for Adafruit TFT Feather
// ---------------------------------------------------------
#define DEFAULT_DISP_TYPE   DISP_TYPE_ILI9341
#define DEFAULT_TFT_DISPLAY_WIDTH   240
#define DEFAULT_TFT_DISPLAY_HEIGHT  320
#define DISP_COLOR_BITS_24          0x66
#define DEFAULT_GAMMA_CURVE         0
#define DEFAULT_SPI_CLOCK           26000000
#define TFT_INVERT_ROTATION         0
#define TFT_INVERT_ROTATION1        0
#define TFT_RGB_BGR                 0x08

#define USE_TOUCH                   TOUCH_TYPE_STMPE610

#define PIN_NUM_MISO 19		// SPI MISO
#define PIN_NUM_MOSI 18		// SPI MOSI
#define PIN_NUM_CLK  5		// SPI CLOCK pin
#define PIN_NUM_CS   15		// Display CS pin
#define PIN_NUM_DC   33		// Display command/data pin
#define PIN_NUM_TCS  32		// Touch screen CS pin (NOT used if USE_TOUCH=0)

#define PIN_NUM_RST  0  	// GPIO used for RESET control (#16)
#define PIN_NUM_BCKL 0  	// GPIO used for backlight control
#define PIN_BCKL_ON  0  	// GPIO value for backlight ON
#define PIN_BCKL_OFF 1  	// GPIO value for backlight OFF
// ---------------------------------------------------------

#elif CONFIG_EXAMPLE_DISPLAY_TYPE == 3

// ** Set the correct configuration for M5Stack TFT
// ---------------------------------------------------------
#define DEFAULT_DISP_TYPE   DISP_TYPE_ILI9341
#define DEFAULT_TFT_DISPLAY_WIDTH   320
#define DEFAULT_TFT_DISPLAY_HEIGHT  240
#define DISP_COLOR_BITS_24          0x66
#define DEFAULT_GAMMA_CURVE         0
#define DEFAULT_SPI_CLOCK           26000000
#define TFT_INVERT_ROTATION         0
#define TFT_INVERT_ROTATION1        0
#define TFT_INVERT_ROTATION2        1   // Adapte M5Stack TFT
#define TFT_RGB_BGR                 0x08

#define USE_TOUCH                   TOUCH_TYPE_NONE

#define PIN_NUM_MISO 19		// SPI MISO
#define PIN_NUM_MOSI 23		// SPI MOSI
#define PIN_NUM_CLK  18		// SPI CLOCK pin
#define PIN_NUM_CS   14		// Display CS pin
#define PIN_NUM_DC   27		// Display command/data pin
#define PIN_NUM_TCS  0		// Touch screen CS pin (NOT used if USE_TOUCH=0)

#define PIN_NUM_RST  33  	// GPIO used for RESET control (#16)
#define PIN_NUM_BCKL 32  	// GPIO used for backlight control
#define PIN_BCKL_ON  1  	// GPIO value for backlight ON
#define PIN_BCKL_OFF 0  	// GPIO value for backlight OFF
// ---------------------------------------------------------

#else

// Configuration for other boards, set the correct values for the display used
//----------------------------------------------------------------------------
#define DISP_COLOR_BITS_24	0x66
//#define DISP_COLOR_BITS_16	0x55  // Do not use!

// #############################################
// ### Set to 1 for some displays,           ###
//     for example the one on ESP-WROWER-KIT ###
// #############################################
#define TFT_INVERT_ROTATION 0
#define TFT_INVERT_ROTATION1 0

// ################################################
// ### SET TO 0X00 FOR DISPLAYS WITH RGB MATRIX ###
// ### SET TO 0X08 FOR DISPLAYS WITH BGR MATRIX ###
// ### For ESP-WROWER-KIT set to 0x00           ###
// ################################################
#define TFT_RGB_BGR 0x08

// ##############################################################
// ### Define ESP32 SPI pins to which the display is attached ###
// ##############################################################

// The pins configured here are the native spi pins for HSPI interface
// Any other valid pin combination can be used
#define PIN_NUM_MISO 19		// SPI MISO
#define PIN_NUM_MOSI 23		// SPI MOSI
#define PIN_NUM_CLK  18		// SPI CLOCK pin
#define PIN_NUM_CS   5		// Display CS pin
#define PIN_NUM_DC   26		// Display command/data pin
#define PIN_NUM_TCS  25		// Touch screen CS pin (NOT used if USE_TOUCH=0)

// --------------------------------------------------------------
// ** Set Reset and Backlight pins to 0 if not used !
// ** If you want to use them, set them to some valid GPIO number
#define PIN_NUM_RST  0  	// GPIO used for RESET control

#define PIN_NUM_BCKL 0  	// GPIO used for backlight control
#define PIN_BCKL_ON  0  	// GPIO value for backlight ON
#define PIN_BCKL_OFF 1  	// GPIO value for backlight OFF
// --------------------------------------------------------------

// #######################################################
// Set this to 1 if you want to use touch screen functions
// #######################################################
#define USE_TOUCH	TOUCH_TYPE_NONE
// #######################################################

// #######################################################################
// Default display width (smaller dimension) and height (larger dimension)
// #######################################################################
#define DEFAULT_TFT_DISPLAY_WIDTH  240
#define DEFAULT_TFT_DISPLAY_HEIGHT 320
// #######################################################################

#define DEFAULT_GAMMA_CURVE 0
#define DEFAULT_SPI_CLOCK   26000000
#define DEFAULT_DISP_TYPE   DISP_TYPE_ILI9341
//----------------------------------------------------------------------------

#endif  // CONFIG_EXAMPLE_ESP_WROVER_KIT

#endif //PICKS1_TFTSPI_DEFINITION_H
