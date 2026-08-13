#include "spi.h"

void spi_init(void)
{

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<0);

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<1);

	// PROVIDING CLOCK
	RCC_AHB1ENR |= (1<<2);

	// SETTING IDLE STATE
	GPIO_ODR(SPORT) |= ( (1<<SPI_MOSI) | (1<<SPI_CS) );
	GPIO_ODR(SPORT) &= ~(1<<SPI_CLK);

	// PB0 AS MOSI
	GPIO_MODER(SPORT) |= (1<<(SPI_MOSI*2));
	GPIO_MODER(SPORT) &= ~(1<<((SPI_MOSI*2)+1));

	// PB1 AS CLK
	GPIO_MODER(SPORT) |= (1<<(SPI_CLK*2));
	GPIO_MODER(SPORT) &= ~(1<<((SPI_CLK*2)+1));

	// PB2 AS CS
	GPIO_MODER(SPORT) |= (1<<(SPI_CS*2));
	GPIO_MODER(SPORT) &= ~(1<<((SPI_CS*2)+1));

	//  ==== TIMER10 CONFIG ====  //

	// CLOCK PROVIDER
	RCC_APB2ENR |=(1<<17);

	// DISABLING THE COUNTER
	TIM10_CR1 &= ~(1<<0);

	// PRESCALE VALUE
	TIM10_PSC =16U;

	// ARR VALUE FOR THE PARTICULAR BAUD RATE
	TIM10_ARR = 4U;

	// COUNTER VALUE
	TIM10_CNT = 0U;

	// UPDATE GENERATION
	TIM10_EGR |= (1<<0);

	// CLEARNIG THE UIF
	TIM10_SR &= ~(1<<0);

}

void spi_duration()
{
	// RESETTING THE COUNTER
	TIM10_CNT = 0;

	// ENABLING THE COUNTER
	TIM10_CR1 |= (1<<0);

	// WAITING FOR THE
	while(!(TIM10_SR & (1<<0)));

	// CLEARNIG UIF MANUALLY AS IT SHOULD BE
	TIM10_SR &= ~(1<<0);

	// DISABLING THE COUNTER
	TIM10_CR1 &= ~(1<<0);
}

void spi_transmit_mode0(uint8_t dat)
{

	// CS LOW
	GPIO_ODR(SPORT) &= ~(1<<SPI_CS);

	// DATA TRANSMISSION
	for (int8_t i=7;i>=0;i--)
	{
		if (dat & (1 << i))
		{
			// MOSI
			GPIO_ODR(SPORT) |= (1<<SPI_MOSI);
		}

		else
		{
			// MOSI
			GPIO_ODR(SPORT) &= ~(1<<SPI_MOSI);
		}

		// CLK LEADING EDGE
		GPIO_ODR(SPORT) |= (1<<SPI_CLK);

		// DELAY
		spi_duration();

		// CLK TRAILING EDGE
		GPIO_ODR(SPORT) &= ~(1<<SPI_CLK);

		// DELAY
		spi_duration();

	}

	// CS HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_CS);

	// MOSI HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_MOSI);

}

void spi_transmit_mode1(uint8_t dat)
{

	// CS LOW
	GPIO_ODR(SPORT) &= ~(1<<SPI_CS);

	// DATA TRANSMISSION
	for (int8_t i=7;i>=0;i--)
	{
		if (dat & (1 << i))
		{
			// MOSI
			GPIO_ODR(SPORT) |= (1<<SPI_MOSI);
		}

		else
		{
			// MOSI
			GPIO_ODR(SPORT) &= ~(1<<SPI_MOSI);
		}

		// CLK LEADING EDGE
		GPIO_ODR(SPORT) |= (1<<SPI_CLK);

		// DELAY
		spi_duration();

		// CLK TRAILING EDGE
		GPIO_ODR(SPORT) &= ~(1<<SPI_CLK);

		// DELAY
		spi_duration();

	}

	// CS HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_CS);

	// MOSI HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_MOSI);

}

void spi_transmit_mode2(uint8_t dat)
{

	// CS LOW
	GPIO_ODR(SPORT) &= ~(1<<SPI_CS);

	// DATA TRANSMISSION
	for (int8_t i=7;i>=0;i--)
	{
		if (dat & (1 << i))
		{
			// MOSI
			GPIO_ODR(SPORT) |= (1<<SPI_MOSI);
		}

		else
		{
			// MOSI
			GPIO_ODR(SPORT) &= ~(1<<SPI_MOSI);
		}

		// CLK TRAILING EDGE
		GPIO_ODR(SPORT) &= ~(1<<SPI_CLK);

		// DELAY
		spi_duration();

		// CLK LEADING EDGE
		GPIO_ODR(SPORT) |= (1<<SPI_CLK);

		// DELAY
		spi_duration();


	}

	// CS HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_CS);

	// MOSI HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_MOSI);

}

void spi_transmit_mode3(uint8_t dat)
{

	// CS LOW
	GPIO_ODR(SPORT) &= ~(1<<SPI_CS);

	// DATA TRANSMISSION
	for (int8_t i=7;i>=0;i--)
	{
		if (dat & (1 << i))
		{
			// MOSI
			GPIO_ODR(SPORT) |= (1<<SPI_MOSI);
		}

		else
		{
			// MOSI
			GPIO_ODR(SPORT) &= ~(1<<SPI_MOSI);
		}

		// CLK TRAILING EDGE
		GPIO_ODR(SPORT) &= ~(1<<SPI_CLK);

		// DELAY
		spi_duration();

		// CLK LEADING EDGE
		GPIO_ODR(SPORT) |= (1<<SPI_CLK);

		// DELAY
		spi_duration();


	}

	// CS HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_CS);

	// MOSI HIGH
	GPIO_ODR(SPORT) |= (1<<SPI_MOSI);

}