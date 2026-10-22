#ifndef MAIN_H
#define MAIN_H

#include "system.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

/* ================= Global Defines ================= */
#define BASE_PIN     12
#define PIN0        0
#define NUM_STATES        5
#define DEBOUNCE_MS     200
#define TX_PIN           9
#define SystemCoreClock 16000000UL   // if HSI 16 MHz

/* ================= Global Variables ================= */
extern volatile uint32_t tick;
extern volatile uint8_t button_pressed;

/* ================= Function Prototypes ================= */
void CLK_Init(void);
void TIM2_Init(void);
void timer_delay_us(uint32_t us);

void SWO_Init(void);
void SysTick_Init(uint32_t sysclk);

void uart_send_char(char c, uint32_t baud);
void UART_Set_Pin(void);

void GDPIN_Init(void);
void SetState(uint8_t state);

void IRQ_Init(void);
void EXTI0_IRQHandler(void);

#endif
