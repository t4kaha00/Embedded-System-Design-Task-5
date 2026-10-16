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
    LDR r0, =0x40016000    //SWI SWI2 Software interrupt 2
    LDR r1, [r0]
    BIC r1, r1, #(0 << 3)   
    STR r1, [r0]
    
    LDR r0, =0x40006000    //GPIOTE GPIO tasks and events, atomic op 
    BIC r1, r1, #(0b11 << 24)
    ORR r1, r1, #(0b01 << 24)
    STR r1, [r0]

loop:
    LDR r0, =0x40020C14    
    LDR r1, [r0]
    EOR r1, r1, #(1 << 12) 
    STR r1, [r0]

    MOV r2, #0x80000
delay_loop:
    SUBS r2, r2, #1
    BNE delay_loop

    B loop
    