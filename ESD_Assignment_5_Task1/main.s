//nrf5340
.syntax unified
.cpu cortex-m4
.thumb

.section .isr_vector, "a", %progbits
.word 0x20020000                     // Initial stack pointer
.word main                           // Reset vector

.section .text
.global main
.type main, %function
@ nrf5340
main:
    LDR r0, =0x40023830             // RCC base address 0x40023800 + offset 0x30
    LDR r1, [r0]
    ORR r1, r1, #(1 << 3)           // enable the clock at bit 3, BIC was clearing the bit values so nothing was enabled.
    STR r1, [r0]

    LDR r0, =0x40020C00             // GPIOD base address 0x40020C00
    LDR r1, [r0]                    // This line was missing so r1 was not being reset
    BIC r1, r1, #(0b11 << 24)
    ORR r1, r1, #(0b01 << 24)
    STR r1, [r0]

loop:
    LDR r0, =0x40020C14             // base address 0x40020C00 + offset 0x14
    LDR r1, [r0]
    EOR r1, r1, #(1 << 12)          // Green LED (LD4) is connected to PD12 so toggle bit 12 after every iteration
    STR r1, [r0]

    MOV r2, #0x80000
delay_loop:
    SUBS r2, r2, #1
    BNE delay_loop

    B loop
    