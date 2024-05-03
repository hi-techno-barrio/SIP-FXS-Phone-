#ifndef PROSLIC_H
#define PROSLIC_H

#include "driver/spi_master.h"

void proslic_init(void);
void proslic_set_linefeed(int state);
void proslic_ring_start(void);
void proslic_ring_stop(void);
uint8_t proslic_spi_read(uint8_t reg);
void proslic_spi_write(uint8_t reg, uint8_t value);

#endif // PROSLIC_H

