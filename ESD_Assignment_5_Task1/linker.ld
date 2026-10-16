ENTRY(main)  
/* @ - Any rectification to .type main, %function must start with _  */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

_stack_top = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  .text :
  {
    *(.text*)
    *(.rodata*)
  } > FLASH

  .data : AT(ADDR(.text) + SIZEOF(.text))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM
/* @ - For all address changes in main add a nope op right after it and a label with _ */
  .bss (NOLOAD) :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  .stack (NOLOAD) :
  {
    *(.stack)
  } > RAM

  _sidata = LOADADDR(.data);
}