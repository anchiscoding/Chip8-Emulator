# <ins>Chip8-Emulator

## <ins>Overview

This project is an emulator for the CHIP-8, a simple interpreted programming language designed in the 1970s for creating games. The emulator aims to faithfully replicate the CHIP-8's behavior, enabling the execution of CHIP-8 programs (also known as ROMs).

## <ins>Features (Planned & Implemented)

Core Emulation:
[ ] CPU Emulation(opcodes) <br/>
[ ] Timers(delay and sound) <br/>
[ ] Memory Management <br/>

Graphics:
[ ] Display 64x32 Resolution <br/>

Input Handling:
[ ] Keyboard mapping for Chip8 keys <br/>

Audio:
[ ] Beep sound for sound timer expiration <br/>

Debugging Tools:
[ ] Instruction logging <br/>
[ ] Memory Visualization <br/>

## <ins>Installation
Clone the repository and navigate to the project directory: <br/>
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

Milestone 1: Implement a functional interpreter capable of running simple programs<br/>

Milestone 2: Add full support for all opcodes and sound<br/>

Milestone 3: Create a graphical debugger<br/>

## <ins>Acknowledgements:

Special thanks to the emulator development community for providing me the inspiration to commence with this project
A very special thanks to [Cowgod's Chip8 Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM) for providing me information on the Chip8 architecture
    
