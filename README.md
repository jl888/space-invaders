# Space Invaders Game
Written in <code>C</code> for an ATmega CMOS 8-bit microcontroller based on the AVR enhanced RISC architecture. To run this game, your board must consist of:
- At least 2 buttons.
- At least 2 LEDs.
- A navigation switch.
- An LED matrix (7 x 5).

## Before Starting
Requires <code>AVR</code> programming tools to be installed, including <code>avr-gcc</code> and <code>avr-lib</code>. Other major tools required are USB drivers and <code>dfu-programmer</code>.

## Running the game
<code>cd</code> to the directory
```
make
make program
```

## Notes
- <code>game.c</code> is the main file.
- <code>game.c</code> requires all the modules within this folder.
- The <code>Makefile</code> should compile this game.
- The program was designed to be simple due to limited memory available i.e. RAM or EEPROM.