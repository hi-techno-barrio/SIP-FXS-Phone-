#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#ifdef __cplusplus
extern "C" {
#endif

// GPIO pin assignments
#define GPIO_PIN_RESET       2   // ProSLIC Reset Pin
#define GPIO_PIN_CS          15  // ProSLIC Chip Select for SPI
#define GPIO_PIN_INT         4   // ProSLIC Interrupt Pin

// SPI Bus configuration
#define SPI_HOST             HSPI_HOST
#define SPI_DMA_CHAN         2
#define SPI_CLK_FREQ         1000000  // 1 MHz SPI clock frequency
#define SPI_MODE             0        // SPI mode 0

// PCM interface configuration
#define PCM_FS_PIN           5   // Frame Sync Pin
#define PCM_DIN_PIN          18  // PCM Data In Pin
#define PCM_DOUT_PIN         19  // PCM Data Out Pin
#define PCM_CLK_PIN          21  // PCM Clock Pin

// Power settings
#define PROSLIC_POWERDOWN    0   // Power down mode setting

// Initialization parameters
#define PROSLIC_COUNTRY_CODE 1   // Country code setting for region-specific parameters

/**
 * @brief Initialize GPIOs and SPI interface for ProSLIC communication.
 * 
 * This function configures the GPIO and SPI settings necessary for interacting
 * with the ProSLIC module. It ensures that all pins are properly set up for
 * both PCM and control interactions.
 */
void hardware_init(void);

/**
 * @brief Configure PCM interface for audio data transmission.
 * 
 * This function sets up the PCM interface pins and configuration to match
 * the expected format and frequency needed by the ProSLIC module to transmit
 * and receive audio data correctly.
 */
void pcm_interface_init(void);

#ifdef __cplusplus
}
#endif

#endif // HARDWARE_PROFILE_H

