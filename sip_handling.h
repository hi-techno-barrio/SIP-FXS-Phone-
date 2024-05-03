#ifndef SIP_HANDLING_H
#define SIP_HANDLING_H

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t sip_client_init(const char *server_uri, const char *user, const char *password);
esp_err_t sip_client_start(void);
esp_err_t sip_client_stop(void);
esp_err_t sip_client_call(const char *number);
esp_err_t sip_client_hangup(void);
esp_err_t sip_client_accept_call(void);

#ifdef __cplusplus
}
#endif

#endif // SIP_HANDLING_H

