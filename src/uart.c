#include "uart.h"

uint8_t port_global;
uint8_t txg;
uint8_t rxg;

// UART INITIALISATION DEFINITION
void uart_init(void)
{

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<0);

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<1);

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<2);

	// CONFIGURING TX PIN AS GP OUTPUT MODE
	GPIO_MODER(UPORT) |= (1<<(TX*2));
	GPIO_MODER(UPORT) &= ~(1<<((TX*2)+1));

//	GPIO_MODER(port)

	// CONFIGURING RX PIN AS INPUT MODE
	GPIO_MODER(UPORT) &= ~(1<<(RX*2));
	GPIO_MODER(UPORT) &= ~(1<<((RX*2)+1));

	// SHARING TO GLOBAL
	port_global = UPORT;
	txg = TX;
	rxg = RX;
}

// TIMER CLOCK CONFIG FOR BAUD RATE
void baud_rate(uint32_t baud)
{

	// CLOCK PROVIDER
	RCC_APB2ENR |=(1<<16);

	// DISABLING THE COUNTER
	TIM9_CR1 &= ~(1<<0);

	// PRESCALE VALUE
	TIM9_PSC = 0U;

	// ARR VALUE FOR THE PARTICULAR BAUD RATE
	TIM9_ARR = (APB2_CLK/(baud))-1;

	// TODO
	TIM9_CNT = 0U;

	// UPDATE GENERATION
	TIM9_EGR |= (1<<0);

	// CLEARNIG THE UIF
	TIM9_SR &= ~(1<<0);

	// ENABLING THE COUNTER
	TIM9_CR1 |= (1<<0);

}


// BIT DURATION FOR PARTICULAR BAUD RATE
void bit_duration(void)
{

	// WAITING FOR THE ARR TO MATCH
	while(!(TIM9_SR & (1<<0)));

	// CLEARNIG UIF MANUALLY AS IT SHOULD BE
	TIM9_SR &= ~(1<<0);

}

void uart_transmit(unsigned char dat)
{

	// TODO
	// RESETTING THE COUNTER
	TIM9_CNT = 0;

	// CLEARNIG UIF MANUALLY AS IT SHOULD BE
	TIM9_SR &= ~(1<<0);

	// START BIT
	GPIO_ODR(UPORT) &= ~(1<<TX);

	// TODO
	bit_duration();

	//
	for (uint8_t i=0;i<8;i++)
	{
		if ((dat & (1<<0))==1)
		{
			GPIO_ODR(UPORT) |= (1<<TX);

		}

		else
		{
			GPIO_ODR(UPORT) &= ~(1<<TX);
		}

		bit_duration();

		dat = (dat>>1);
	}

	// STOP BIT
	GPIO_ODR(UPORT) |= (1<<TX);
	bit_duration();
}

void uart_transmit_string(char string[])
{
	for (uint8_t c=0;string[c]!='\0';c++)
	  {
	    uart_transmit(string[c]);
	    for(volatile uint32_t ii=0;ii<10000;ii++);
	  }
}