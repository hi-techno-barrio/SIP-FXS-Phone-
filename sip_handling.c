#include "sip_handling.h"
#include "esp_log.h"
#include "esp_sip.h"

static const char *TAG = "SIP_HANDLING";
static sip_handle_t sip_handle = NULL;

static void sip_event_handler(sip_event_msg_t *event) {
    switch (event->type) {
        case SIP_EVENT_REGISTERED:
            ESP_LOGI(TAG, "Successfully registered with SIP server.");
            break;
        case SIP_EVENT_RINGING:
            ESP_LOGI(TAG, "Incoming call ringing.");
            break;
        case SIP_EVENT_INVITING:
            ESP_LOGI(TAG, "Outgoing call in progress.");
            break;
        case SIP_EVENT_HANGUP:
            ESP_LOGI(TAG, "Call hung up.");
            break;
        case SIP_EVENT_AUDIO_SESSION_BEGIN:
            ESP_LOGI(TAG, "Audio session has begun.");
            break;
        case SIP_EVENT_AUDIO_SESSION_END:
            ESP_LOGI(TAG, "Audio session has ended.");
            break;
        case SIP_EVENT_UNREGISTERED:
            ESP_LOGI(TAG, "Unregistered from SIP server.");
            break;
        default:
            ESP_LOGI(TAG, "Unhandled SIP Event: %d", event->type);
            break;
    }
}

esp_err_t sip_client_init(const char *server_uri, const char *user, const char *password) {
    if (sip_handle) {
        ESP_LOGE(TAG, "SIP client already initialized.");
        return ESP_FAIL;
    }

    sip_config_t sip_cfg = {
        .uri = server_uri,
        .event_handler = sip_event_handler,
        .username = user,
        .password = password
    };

    sip_handle = esp_sip_init(&sip_cfg);
    if (!sip_handle) {
        ESP_LOGE(TAG, "Failed to initialize SIP client.");
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t sip_client_start(void) {
    if (!sip_handle) {
        ESP_LOGE(TAG, "SIP client is not initialized.");
        return ESP_FAIL;
    }
    return esp_sip_start(sip_handle);
}

esp_err_t sip_client_stop(void) {
    if (!sip_handle) {
        ESP_LOGE(TAG, "SIP client is not initialized.");
        return ESP_FAIL;
    }
    return esp_sip_stop(sip_handle);
}

esp_err_t sip_client_call(const char *number) {
    if (!sip_handle) {
        ESP_LOGE(TAG, "SIP client is not initialized.");
        return ESP_FAIL;
    }
    return esp_sip_uac_invite(sip_handle, number);
}

esp_err_t sip_client_hangup(void) {
    if (!sip_handle) {
        ESP_LOGE(TAG, "SIP client is not initialized.");
        return ESP_FAIL;
    }
    return esp_sip_uac_bye(sip_handle);
}

esp_err_t sip_client_accept_call(void) {
    if (!sip_handle) {
        ESP_LOGE(TAG, "SIP client is not initialized.");
        return ESP_FAIL;
    }
    return esp_sip_uas_answer(sip_handle, true);
}
