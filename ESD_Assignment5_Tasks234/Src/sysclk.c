#include "main.h"

void CLK_Init(void) {
    /* --- Enable TIM2 --- */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN
	              | RCC_APB2ENR_TIM8EN
	              | RCC_APB2ENR_USART1EN
	              | RCC_APB2ENR_USART6EN
	              | RCC_APB2ENR_ADC1EN
	              | RCC_APB2ENR_ADC2EN
	              | RCC_APB2ENR_ADC3EN
	              | RCC_APB2ENR_SDIOEN
	              | RCC_APB2ENR_SPI1EN
	              | RCC_APB2ENR_SYSCFGEN
	              | RCC_APB2ENR_TIM9EN
	              | RCC_APB2ENR_TIM10EN
	              | RCC_APB2ENR_TIM11EN;
}
