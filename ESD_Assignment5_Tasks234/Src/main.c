/*******************************************************************************
 * Assignment 5 – Tasks 2, 3, and 4
 *
 * - The provided code compiles with NO warnings or errors. 
 * - A clean build does NOT guarantee correctness → you must debug each task.
 * - Do not rewrite from scratch; find and fix bugs in the given code.
 *
 * Workflow:
 *   1. Start with Task 2 (uncomment, test, debug).
 *   2. Then Task 3 (you can leave Task 2 active).
 *   3. Then Task 4 (you can leave Tasks 2+3 active).
 *
 * After each working task:
 *   - Show your result to the TA/teacher.
 *   - Commit & push your changes to Git.
 *
 * See Assignment 5 document for details.
 ******************************************************************************/



#include "main.h"
#include <stdio.h>

volatile uint32_t tick = 0;
volatile uint8_t button_pressed = 0;

uint8_t lstate = 0;

void SysTick_Init(uint32_t sysclk) {
    SYST_RVR = ((sysclk / 1000) - 1) & 0xFFFFFF; // 1 ms tick
    SYST_CVR = 0;
    SYST_CSR = (1 << 0) | (1 << 1) | (1 << 2); // Enable | TickInt | CLKSOURCE
}
void SysTick_Handler(void) {
    tick++;
}

int main(void) {
    uint32_t baud = 9600;

    while (1) {
        /* ============ Task 2 ============ */
        // Also send 0x55 and 0x96 and take a screenshot of PulseView
        uart_send_char('A', baud);   // Debug: check with logic analyzer
        timer_delay_us(1000);

    /* =================== Task 3 ===================
     *  
     *  Uncomment for Task 3
     */
        if (button_pressed) {
//            button_pressed = 0;
//            printf("Button Pressed!\n");
//            fflush(stdout);
    /* =================== Task 4 ===================
     *  
     *  Uncomment when Task 3 is working and DEBUGGED
     */
            /* ============ Task 4 ============ */
//            lstate = (lstate + 1) % NUM_STATES;
//            SetState(lstate);
        }
    }
}
