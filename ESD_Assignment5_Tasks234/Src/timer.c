#include "main.h"

void TIM2_Init(void) {
    TIM2->PSC = (SystemCoreClock / 1000000UL) - 1;  // 1 µs tick      
    TIM2->ARR = 0xFFFF;
    TIM2->EGR = TIM_EGR_UG;
    TIM2->CR1 |= TIM_CR1_CEN;
}

void timer_delay_us(uint32_t us) {
    uint32_t start = TIM2->CNT;
    while ((TIM2->CNT - start) < us) {
        __asm volatile ("nop");
    }
}
