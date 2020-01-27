/*
 * 
 * HIGH SPEED LOW LEVEL DISPLAY FUNCTIONS USING DIRECT TRANSFER MODE
 *
*/

#ifndef _TFTSPI_H_
#define _TFTSPI_H_

#include "tftspi.h"
#include "spi_master_lobo.h"
#include "sdkconfig.h"
#include "stmpe610.h"

#include "tftspi_definition.h"
#include "tftspi_initialization.h"

// ##############################################################
// #### Global variables                                     ####
// ##############################################################

// ==== Converts colors to grayscale if 1 =======================
extern uint8_t gray_scale;

// ==== Spi clock for reading data from display memory in Hz ====
extern uint32_t max_rdclock;

// ==== Display dimensions in pixels ============================
extern int _width;
extern int _height;

// ==== Display type, DISP_TYPE_ILI9488 or DISP_TYPE_ILI9341 ====
extern uint8_t tft_disp_type;

// ==== Spi device handles for display and touch screen =========
extern spi_lobo_device_handle_t disp_spi;
extern spi_lobo_device_handle_t ts_spi;

// ##############################################################

// 24-bit color type structure
typedef struct __attribute__((__packed__)) {
//typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color_t ;

// ==== Public functions =========================================================

// == Low level functions; usually not used directly ==
esp_err_t wait_trans_finish(uint8_t free_line);
void disp_spi_transfer_cmd(int8_t cmd);
void disp_spi_transfer_cmd_data(int8_t cmd, uint8_t *data, uint32_t len);
void drawPixel(int16_t x, int16_t y, color_t color, uint8_t sel);
void send_data(int x1, int y1, int x2, int y2, uint32_t len, color_t *buf);
void TFT_pushColorRep(int x1, int y1, int x2, int y2, color_t data, uint32_t len);
int read_data(int x1, int y1, int x2, int y2, int len, uint8_t *buf, uint8_t set_sp);
color_t readPixel(int16_t x, int16_t y);
int touch_get_data(uint8_t type);

// Deactivate display's CS line
//========================
esp_err_t disp_deselect();

// Activate display's CS line and configure SPI interface if necessary
//======================
esp_err_t disp_select();

// Find maximum spi clock for successful read from display RAM
// ** Must be used AFTER the display is initialized **
//======================
uint32_t find_rd_speed();

// Change the screen rotation.
// Input: m new rotation value (0 to 3)
//=================================
void _tft_setRotation(uint8_t rot);

// Initialize all pins used by display driver
// ** MUST be executed before SPI interface initialization
//=================
void TFT_PinsInit();

// Perform display initialization sequence
// Sets orientation to landscape; clears the screen
// * All pins must be configured
// * SPI interface must already be setup
// * 'tft_disp_type', 'COLOR_BITS', '_width', '_height' variables must be set
//======================
void TFT_display_init();

//===================
void stmpe610_Init();

//============================================================
int stmpe610_get_touch(uint16_t *x, uint16_t *y, uint16_t *z);

//========================
uint32_t stmpe610_getID();

// ===============================================================================

#endif