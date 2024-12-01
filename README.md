# <ins>Chip8-Emulator

## <ins>Overview

This project is an emulator for the CHIP-8, a simple interpreted programming language designed in the 1970s for creating games. The emulator aims to faithfully replicate the CHIP-8's behavior, enabling the execution of CHIP-8 programs (also known as ROMs).

## <ins>Features (Planned & Implemented)

Core Emulation:
[ ] CPU Emulation(opcodes)
[ ] Timers(delay and sound)
[ ] Memory Management

Graphics:
[ ] Display 64x32 Resolution

Input Handling:
[ ] Keyboard mapping for CHIP-8 keys

Audio:
[ ] Beep sound for sound timer expiration

Debugging Tools:
[ ] Instruction logging
[ ] Memory Visualization

## <ins>Installation
Clone the repository and navigate to the project directory:
```
   git clone https://github.com/yourusername/chip8-emulator.git  
   cd chip8-emulator
```
## <ins>Prerequisites
Make sure you have a compiler such as G++ or Clang and the SFML Libraries
```
    # Ubuntu/Debian
    sudo apt install libsfml-dev
    # Arch Linux
    pacman -S sfml
```
## <ins>Roadmap

Milestone 1: Implement a functional interpreter capable of running simple programs

Milestone 2: Add full support for all opcodes and sound

Milestone 3: Create a graphical debugger

## <ins>Acknowledgements:

Special thanks to the emulator development community for providing me the inspiration to commence with this project
A very special thanks to [Cowgod's Chip8 Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM) for providing me information on the Chip8 architecture
    
