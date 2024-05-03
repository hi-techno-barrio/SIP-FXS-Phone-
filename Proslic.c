
#include "proslic.h"
#include "hardware_profile.h"
#include "esp_log.h"

static const char *TAG = "ProSLIC";
static spi_device_handle_t spi_handle;

static void proslic_spi_init(void) {
    spi_bus_config_t buscfg = {
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 128
    };
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1 * 1000 * 1000,  // 1 MHz
        .mode = 0,  // SPI mode 0
        .spics_io_num = PIN_NUM_CS,
        .queue_size = 7
    };
    ESP_ERROR_CHECK(spi_bus_initialize(SPI_HOST, &buscfg, SPI_DMA_CH_AUTO));
    ESP_ERROR_CHECK(spi_bus_add_device(SPI_HOST, &devcfg, &spi_handle));
}

void proslic_init(void) {
    gpio_set_direction(PIN_NUM_RESET, GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_NUM_RESET, 0);
    vTaskDelay(pdMS_TO_TICKS(10));
    gpio_set_level(PIN_NUM_RESET, 1);
    
    proslic_spi_init();
    ESP_LOGI(TAG, "ProSLIC initialized");
}

uint8_t proslic_spi_read(uint8_t reg) {
    uint8_t tx_data[2] = {reg & 0x7F, 0xFF};
    uint8_t rx_data[2];
    spi_transaction_t t = {
        .length = 16,  // Transaction length is 16 bits
        .tx_buffer = tx_data,
        .rx_buffer = rx_data
    };
    spi_device_transmit(spi_handle, &t);
    return rx_data[1];  // Data is in the second byte
}

void proslic_spi_write(uint8_t reg, uint8_t value) {
    uint8_t tx_data[2] = {reg | 0x80, value};  // Write operation
    spi_transaction_t t = {
        .length = 16,  // Transaction length is 16 bits
        .tx_buffer = tx_data
    };
    spi_device_transmit(spi_handle, &t);
}

void proslic_set_linefeed(int state) {
    ESP_LOGI(TAG, "Setting line feed to %d", state);
    proslic_spi_write(64, state);  // Example register address
}

void proslic_ring_start(void) {
    ESP_LOGI(TAG, "Starting ring");
    proslic_spi_write(66, 0xFF);  // Example register address
}

void proslic_ring_stop(void) {
    ESP_LOGI(TAG, "Stopping ring");
    proslic_spi_write(66, 0x00);  // Example register address
}
