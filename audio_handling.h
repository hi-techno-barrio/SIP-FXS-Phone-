#ifndef AUDIO_HANDLING_H
#define AUDIO_HANDLING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the audio hardware and any necessary libraries.
 * This function sets up the ProSLIC module and any required audio processing
 * initializations needed for the ESP32 to handle PCM audio streams.
 * 
 * @return int Returns 0 on success, or a negative error code on failure.
 */
int audio_init(void);

/**
 * @brief Start audio processing and transmission.
 * This function starts the processing of audio data, which might involve starting
 * DMA transfers, enabling interrupts, or activating the ProSLIC module's PCM interface.
 * 
 * @return int Returns 0 on success, or a negative error code on failure.
 */
int audio_start(void);

/**
 * @brief Stop audio processing and transmission.
 * This function stops the audio processing, effectively disabling DMA transfers,
 * interrupt handling, and possibly powering down the ProSLIC module or parts of it.
 * 
 * @return int Returns 0 on success, or a negative error code on failure.
 */
int audio_stop(void);

/**
 * @brief Deinitialize the audio hardware.
 * This function deinitializes and releases any resources allocated by audio_init().
 * This typically involves resetting hardware states and deallocating memory if applicable.
 * 
 * @return int Returns 0 on success, or a negative error code on failure.
 */
int audio_deinit(void);

/**
 * @brief Handle reading audio data from the ProSLIC or similar hardware.
 * 
 * @param data Pointer to the buffer where the audio data should be stored.
 * @param length Length of the data buffer in bytes.
 * @return int Number of bytes actually read, or a negative error code on failure.
 */
int audio_read_data(uint8_t* data, int length);

/**
 * @brief Handle writing audio data to the ProSLIC or similar hardware.
 * 
 * @param data Pointer to the buffer containing the audio data to write.
 * @param length Length of the data buffer in bytes.
 * @return int Number of bytes actually written, or a negative error code on failure.
 */
int audio_write_data(uint8_t* data, int length);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_HANDLING_H
