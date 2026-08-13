#include <stdint.h>
#include<stdio.h>
#include"macros.h"

#define TX    10U
#define RX    6U
#define UPORT B


              /***  FUNCTIONS ***/

// UART INITIALISATION
void uart_init();

// UART TRANSMISSION
void uart_transmit(unsigned char);

// BIT DURATION
void bit_duration(void);

// TIMER CLOCK CONFIG
void baud_rate(uint32_t);