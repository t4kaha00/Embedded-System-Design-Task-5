#include "main.h"

void IRQ_Init(void) {
    GPIOA->MODER &= ~(0x3 << (PIN0 * 2)); // Input

    SYSCFG_EXTICR1 &= ~(0xF << (PIN0 * 4));
    EXTI->IMR  |= (1 << PIN0);
    EXTI->RTSR |= (1 << PIN0);

    NVIC_ISER0 |= (1 << 6);
}

void EXTI0_IRQHandler(void) {
    static uint32_t last_press = 0;
    if ((tick - last_press) > DEBOUNCE_MS) {
        button_pressed = 1;
        last_press = tick;
    }
}
