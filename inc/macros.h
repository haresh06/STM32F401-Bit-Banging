//#define REG32(addr) ((volatile uint32_t*)(addr))

// Freq. FOR APB2
#define APB2_CLK (16000000U)

//==================================================
// GPIO BASE ADDRESSES
//==================================================

#define A  0x40020000
#define B  0x40020400
#define C  0x40020800
#define D  0x40020C00
#define E  0x40021000
#define H  0x40021C00


//==================================================
// GPIO REGISTER OFFSETS
//==================================================

#define  MODER_OFFSET        0x00
#define OTYPER_OFFSET     0x04
#define OSPEEDR_OFFSET    0x08
#define PUPDR_OFFSET      0x0C
#define IDR_OFFSET        0x10
#define ODR_OFFSET        0x14
#define BSRR_OFFSET       0x18
#define LCKR_OFFSET       0x1C
#define AFRL_OFFSET       0x20
#define AFRH_OFFSET       0x24


//==================================================
// GPIO REGISTER ACCESS MACRO
//==================================================

#define REG32(addr) (*(volatile uint32_t *)(addr))


//==================================================
// GPIO REGISTER ACCESS
//==================================================

#define GPIO_MODER(port)      REG32((port) + MODER_OFFSET)
#define GPIO_OTYPER(port)     REG32((port) + OTYPER_OFFSET)
#define GPIO_OSPEEDR(port)    REG32((port) + OSPEEDR_OFFSET)
#define GPIO_PUPDR(port)      REG32((port) + PUPDR_OFFSET)
#define GPIO_IDR(port)        REG32((port) + IDR_OFFSET)
#define GPIO_ODR(port)        REG32((port) + ODR_OFFSET)
#define GPIO_BSRR(port)       REG32((port) + BSRR_OFFSET)
#define GPIO_AFRL(port)       REG32((port) + AFRL_OFFSET)
#define GPIO_AFRH(port)       REG32((port) + AFRH_OFFSET)

//==================================================
// TIMER BASE ADDRESSES
//==================================================

#define TIM9_BASE   0x40014000
#define TIM10_BASE  0x40014400
#define TIM11_BASE  0x40014800


//==================================================
// TIMER REGISTER OFFSETS
//==================================================

#define CR1_OFFSET      0x00    // Control Register 1
#define CR2_OFFSET      0x04    // Control Register 2
#define SMCR_OFFSET     0x08    // Slave Mode Control Register
#define DIER_OFFSET     0x0C    // DMA/Interrupt Enable Register
#define SR_OFFSET       0x10    // Status Register
#define EGR_OFFSET      0x14    // Event Generation Register
#define CCMR1_OFFSET    0x18    // Capture Compare Mode Register 1
#define CCER_OFFSET     0x20    // Capture Compare Enable Register
#define CNT_OFFSET      0x24    // Counter Register
#define PSC_OFFSET      0x28    // Prescaler Register
#define ARR_OFFSET      0x2C    // Auto Reload Register
#define CCR1_OFFSET     0x34    // Capture Compare Register 1
#define CCR2_OFFSET     0x38    // Capture Compare Register 2 (TIM9 only)


//==================================================
// GENERIC 16-BIT REGISTER ACCESS
//==================================================

#define REG16(addr) (*(volatile uint16_t *)(addr))


//==================================================
// TIMER REGISTER ACCESS MACROS
//==================================================

#define TIM_CR1(timer)      REG16((timer) + CR1_OFFSET)
#define TIM_CR2(timer)      REG16((timer) + CR2_OFFSET)
#define TIM_SMCR(timer)     REG16((timer) + SMCR_OFFSET)
#define TIM_DIER(timer)     REG16((timer) + DIER_OFFSET)
#define TIM_SR(timer)       REG16((timer) + SR_OFFSET)
#define TIM_EGR(timer)      REG16((timer) + EGR_OFFSET)
#define TIM_CCMR1(timer)    REG16((timer) + CCMR1_OFFSET)
#define TIM_CCER(timer)     REG16((timer) + CCER_OFFSET)
#define TIM_CNT(timer)      REG16((timer) + CNT_OFFSET)
#define TIM_PSC(timer)      REG16((timer) + PSC_OFFSET)
#define TIM_ARR(timer)      REG16((timer) + ARR_OFFSET)
#define TIM_CCR1(timer)     REG16((timer) + CCR1_OFFSET)
#define TIM_CCR2(timer)     REG16((timer) + CCR2_OFFSET)

//===========GPIOA============

#define GPIOA_MODER   REG32(0x40020000)
#define GPIOA_OTYPER  REG32(0x40020004)
#define GPIOA_OSPEEDR REG32(0x40020008)
#define GPIOA_PUPDR   REG32(0x4002000C)
#define GPIOA_IDR     REG32(0x40020010)
#define GPIOA_ODR     REG32(0x40020014)
#define GPIOA_BSRR    REG32(0X40020018)
#define GPIOA_LCKR    REG32(0x4002001C)
#define GPIOA_AFRL    REG32(0X40020020)
#define GPIOA_AFRH    REG32(0X40020024)

//===========GPIOB============

#define GPIOB_MODER   REG32(0x40020400)
#define GPIOB_OTYPER  REG32(0x40020404)
#define GPIOB_OSPEEDR REG32(0x40020408)
#define GPIOB_PUPDR   REG32(0x4002040C)
#define GPIOB_IDR     REG32(0x40020410)
#define GPIOB_ODR     REG32(0x40020414)
#define GPIOB_BSRR    REG32(0x40020418)
#define GPIOB_LCKR    REG32(0x4002041C)
#define GPIOB_AFRL    REG32(0x40020420)
#define GPIOB_AFRH    REG32(0x40020424)

//===========GPIOC============

#define GPIOC_MODER   REG32(0x40020800)
#define GPIOC_OTYPER  REG32(0x40020804)
#define GPIOC_OSPEEDR REG32(0x40020808)
#define GPIOC_PUPDR   REG32(0x4002080C)
#define GPIOC_IDR     REG32(0x40020810)
#define GPIOC_ODR     REG32(0x40020814)
#define GPIOC_BSRR    REG32(0x40020818)
#define GPIOC_LCKR    REG32(0x4002081C)
#define GPIOC_AFRL    REG32(0x40020820)
#define GPIOC_AFRH    REG32(0x40020824)

//===========GPIOD============

#define GPIOD_MODER   REG32(0x40020C00)
#define GPIOD_OTYPER  REG32(0x40020C04)
#define GPIOD_OSPEEDR REG32(0x40020C08)
#define GPIOD_PUPDR   REG32(0x40020C0C)
#define GPIOD_IDR     REG32(0x40020C10)
#define GPIOD_ODR     REG32(0x40020C14)
#define GPIOD_BSRR    REG32(0x40020C18)
#define GPIOD_LCKR    REG32(0x40020C1C)
#define GPIOD_AFRL    REG32(0x40020C20)
#define GPIOD_AFRH    REG32(0x40020C24)

//===========GPIOE============

#define GPIOE_MODER   REG32(0x40021000)
#define GPIOE_OTYPER  REG32(0x40021004)
#define GPIOE_OSPEEDR REG32(0x40021008)
#define GPIOE_PUPDR   REG32(0x4002100C)
#define GPIOE_IDR     REG32(0x40021010)
#define GPIOE_ODR     REG32(0x40021014)
#define GPIOE_BSRR    REG32(0x40021018)
#define GPIOE_LCKR    REG32(0x4002101C)
#define GPIOE_AFRL    REG32(0x40021020)
#define GPIOE_AFRH    REG32(0x40021024)

//===========GPIOH============

#define GPIOH_MODER   REG32(0x40021C00)
#define GPIOH_OTYPER  REG32(0x40021C04)
#define GPIOH_OSPEEDR REG32(0x40021C08)
#define GPIOH_PUPDR   REG32(0x40021C0C)
#define GPIOH_IDR     REG32(0x40021C10)
#define GPIOH_ODR     REG32(0x40021C14)
#define GPIOH_BSRR    REG32(0x40021C18)
#define GPIOH_LCKR    REG32(0x40021C1C)
#define GPIOH_AFRL    REG32(0x40021C20)
#define GPIOH_AFRH    REG32(0x40021C24)

//===========TIMER9============

#define TIM9_CR1     REG32(0x40014000)
#define TIM9_SMCR    REG32(0x40014008)
#define TIM9_DIER    REG32(0X4001400C)
#define TIM9_SR      REG32(0x40014010)
#define TIM9_EGR     REG32(0x40014014)
#define TIM9_CCMR1   REG32(0x40014018)
#define TIM9_CCER    REG32(0x40014020)
#define TIM9_CNT     REG32(0x40014024)
#define TIM9_PSC     REG32(0x40014028)
#define TIM9_ARR     REG32(0x4001402C)
#define TIM9_CCR1    REG32(0x40014034)
#define TIM9_CCR2    REG32(0x40014038)

//===========TIMER10============

#define TIM10_CR1     REG32(0x40014400)
#define TIM10_SMCR    REG32(0x40014408)
#define TIM10_DIER    REG32(0x4001440C)
#define TIM10_SR      REG32(0x40014410)
#define TIM10_EGR     REG32(0x40014414)
#define TIM10_CCMR1   REG32(0x40014418)
#define TIM10_CCER    REG32(0x40014420)
#define TIM10_CNT     REG32(0x40014424)
#define TIM10_PSC     REG32(0x40014428)
#define TIM10_ARR     REG32(0x4001442C)
#define TIM10_CCR1    REG32(0x40014434)

//===========RCC CLOCK PROVIDERS============

#define RCC_APB2ENR  REG32(0x40023844)   // TIM9
#define RCC_APB2ENR  REG32(0x40023844)   // TIM10
#define RCC_AHB1ENR  REG32(0x40023830)   // GPIOA

//// FOR ARRAYS
//#define A 0U
//#define B 1U
//#define C 2U