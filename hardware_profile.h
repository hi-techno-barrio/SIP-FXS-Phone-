#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#include "driver/gpio.h"
#include "driver/spi_master.h"

// SPI Bus Configurations
#define SPI_HOST HSPI_HOST
#define PIN_NUM_MISO GPIO_NUM_19
#define PIN_NUM_MOSI GPIO_NUM_23
#define PIN_NUM_CLK  GPIO_NUM_18
#define PIN_NUM_CS   GPIO_NUM_5

// ProSLIC Control Pins
#define PIN_NUM_RESET GPIO_NUM_17

// SPI Device Handle for ProSLIC
extern spi_device_handle_t spi_handle;

// Function to initialize SPI for ProSLIC
void initialize_spi_for_proslic(void);

#endif // HARDWARE_PROFILE_H
