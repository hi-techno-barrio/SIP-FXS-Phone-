#ifndef AUDIO_HANDLING_H
#define AUDIO_HANDLING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the audio hardware and any necessary libraries.
 * 
 * @return void
 */
void audio_init(void);

/**
 * @brief Start audio transmission.
 * 
 * @return void
 */
void audio_start(void);

/**
 * @brief Stop audio transmission.
 * 
 * @return void
 */
void audio_stop(void);

/**
 * @brief Deinitialize the audio hardware.
 * 
 * @return void
 */
void audio_deinit(void);

/**
 * @brief Handle audio stream read operations.
 * 
 * @param data Buffer to hold the audio data.
 * @param length Length of the data to read.
 * @return int Number of bytes read.
 */
int audio_read_data(uint8_t* data, int length);

/**
 * @brief Handle audio stream write operations.
 * 
 * @param data Buffer containing the audio data to write.
 * @param length Length of the data to write.
 * @return int Number of bytes written.
 */
int audio_write_data(uint8_t* data, int length);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_HANDLING_H

