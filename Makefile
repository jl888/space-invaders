# File: Makefile
# Author: GitHub @ jl888
# Date: 03/10/2016
# Descr: Makefile for game.c

# Definitions
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers -I../../drivers/avr -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target
all: game.out


# Compile: Create object files from C source files
game.o: game.c ../../utils/task.h ../../drivers/avr/system.h ../../drivers/navswitch.h ../../drivers/display.h ../../drivers/led.h ../../drivers/ledmat.h ../../fonts/font5x7_1.h ../../utils/tinygl.h display_aliens_task.h navswitch_task.h user_fire_task.h alien_fire_task.h check_task.h
	$(CC) -c $(CFLAGS) $< -o $@

task.o: ../../utils/task.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: ../../drivers/led.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/led.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

display_aliens_task.o: display_aliens_task.c ../../drivers/avr/system.h ../../drivers/display.h display_aliens_task.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch_task.o: navswitch_task.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/navswitch.h check_task.h navswitch_task.h
	$(CC) -c $(CFLAGS) $< -o $@

user_fire_task.o: user_fire_task.c ../../drivers/avr/system.h navswitch_task.h display_aliens_task.h user_fire_task.h
	$(CC) -c $(CFLAGS) $< -o $@

alien_fire_task.o: alien_fire_task.c ../../drivers/avr/system.h display_aliens_task.h alien_fire_task.h
	$(CC) -c $(CFLAGS) $< -o $@

check_task.o: check_task.c ../../drivers/avr/system.h ../../drivers/led.h ../../utils/tinygl.h ../../fonts/font5x7_1.h navswitch_task.h display_aliens_task.h alien_fire_task.h user_fire_task.h check_task.h
	$(CC) -c $(CFLAGS) $< -o $@




# Link: Create output file (executable) from object files
game.out: game.o task.o system.o timer.o navswitch.o display.o ledmat.o led.o tinygl.o font.o display_aliens_task.o navswitch_task.o user_fire_task.o alien_fire_task.o check_task.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Create hex file for programming from executable file
game.hex: game.out
	$(OBJCOPY) -O ihex game.out game.hex


# Target: Clean project
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: Program project
.PHONY: program
program: game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start