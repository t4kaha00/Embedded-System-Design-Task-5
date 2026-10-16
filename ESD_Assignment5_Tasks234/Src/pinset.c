#include "main.h"

void GDPIN_Init(void) {
    for (int i = 12; i <= 15; ++i) {
        GPIOD->MODER  &= ~(0x3 << (i));
        GPIOD->MODER  |=  (0x1 << (i));
        GPIOD->OTYPER |= (0x1 << i);
        GPIOD->PUPDR  |= (0x1 << i * 2);
    }
}

void SetState(uint8_t state) {

    GPIOD->BSRR = ((0xF << 12) << 16);

    if (state < 4) {
        GPIOD->BSRR = (1 << (BASE_PIN + state));
    }
}
