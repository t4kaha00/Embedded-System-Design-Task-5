#include "main.h"

void UART_Set_Pin(void) {

    GPIOE_MODER &= ~(0x3 << (TX_PIN * 2));
    GPIOE_MODER |=  (0x1 << (TX_PIN * 2));

    // Idle = High
    GPIOE_ODR |= (1 << TX_PIN);
}

void uart_send_char(char c, uint32_t baud) {
    uint32_t bit_time_us = 1000UL / baud;

    // Start bit
    GPIOE_ODR &= ~(1 << TX_PIN);
    timer_delay_us(bit_time_us);

    // Data bits (LSB first)
    for (int i = 0; i < 8; i++) {
        if (c & (1 << i))
            GPIOE_ODR |= (1 << TX_PIN);
        else
            GPIOE_ODR &= ~(1 << TX_PIN);
        timer_delay_us(bit_time_us);
    }

    // Stop bit
    GPIOE_ODR |= (1 << TX_PIN);
    timer_delay_us(bit_time_us);
}
