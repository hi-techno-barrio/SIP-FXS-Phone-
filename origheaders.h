#ifndef ORIGHEADERS_H
#define ORIGHEADERS_H

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "audio_element.h"
#include "audio_pipeline.h"
#include "audio_event_iface.h"
#include "audio_common.h"
#include "i2s_stream.h"
#include "esp_peripherals.h"
#include "periph_wifi.h"
#include "board.h"
#include "input_key_service.h"

#include "driver/gpio.h"
#include "lvgl/lvgl.h"
#include "esp_freertos_hooks.h"
#include "downmix.h"
#include "audio_mem.h"
#include "raw_stream.h"
#include "filter_resample.h"
#include "esp_sip.h"
#include "esp_sip/include/esp_sip.h"
#include "esp_sip/include/g711.h"
#include "mp3_decoder.h"
#include "drv/stmpe610.h"
#include "drv/ili9341.h"
#include "drv/disp_spi.h"

#include "sipgui/gui.h"

#endif // ORIGHEADERS_H
