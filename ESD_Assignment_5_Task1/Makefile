# Makefile
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
GDB = arm-none-eabi-gdb

CFLAGS = -mcpu=cortex-m4 -mthumb -g
LDFLAGS = -g

all: program.elf program.bin

program.o: main.s
	$(AS) $(CFLAGS) -o program.o main.s

program.elf: program.o linker.ld
	$(LD) $(LDFLAGS) -T linker.ld -o program.elf program.o

program.bin: program.elf
	$(OBJCOPY) -O binary program.elf program.bin

clean:
	rm -f *.o *.elf *.bin