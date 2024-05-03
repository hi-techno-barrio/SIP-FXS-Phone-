#include "audio_handling.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"
#include "esp_log.h"

static const char* TAG = "AudioHandling";

// Configuration for the I2S driver setup
static const i2s_config_t i2s_config = {
    .mode = I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX,
    .sample_rate = 8000,  // Sample rate of 8 kHz
    .bits_per_sample = 16,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,  // stereo channel
    .communication_format = I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0, // Default interrupt priority
    .dma_buf_count = 6,
    .dma_buf_len = 60,
    .use_apll = false,
    .tx_desc_auto_clear = true, // Auto clear tx descriptor on underflow
    .fixed_mclk = 0
};

// Configuration for the I2S pin layout
static const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_PIN_NO_CHANGE,
    .ws_io_num = I2S_PIN_NO_CHANGE,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_PIN_NO_CHANGE
};

void audio_handling_init() {
    // Install and start i2s driver
    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);

    ESP_LOGI(TAG, "I2S driver installed and configured.");
}

void audio_handling_start() {
    // Start audio handling task
    ESP_LOGI(TAG, "Starting audio handling...");
}

void audio_handling_stop() {
    // Stop the I2S driver
    i2s_driver_uninstall(I2S_NUM_0);
    ESP_LOGI(TAG, "Stopped audio handling and uninstalled I2S driver.");
}
