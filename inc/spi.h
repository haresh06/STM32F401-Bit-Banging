#include "macros.h"


#define SPI_MOSI 0U
#define SPI_CLK  1U
#define SPI_CS   2U
#define SPORT    B


#include <stdint.h>
//TODO
void spi_init(void);

// TODO
void spi_duration(void);

// TODO
void spi_transmit(uint8_t);

void spi_transmit_mode0(uint8_t dat);
void spi_transmit_mode1(uint8_t dat);
void spi_transmit_mode2(uint8_t dat);
void spi_transmit_mode3(uint8_t dat);