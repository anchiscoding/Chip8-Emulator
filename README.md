# <ins>Chip8-Emulator
## [WORK IN PROGRESS]
## <ins>Overview

This project is an emulator for the CHIP-8, a simple interpreted programming language designed in the 1970s for creating games. The emulator aims to faithfully replicate the CHIP-8's behavior, enabling the execution of CHIP-8 programs (also known as ROMs).

## <ins>Planned Features

### Core Emulation: <br/>
[ ] CPU Emulation(opcodes) <br/>
[ ] Timers(delay and sound) <br/>
[ ] Memory Management <br/>

### Graphics: <br/>
[ ] Display 64x32 Resolution <br/>

### Input Handling: <br/>
[ ] Keyboard mapping for Chip8 keys <br/>

### Audio: <br/>
[ ] Beep sound for sound timer expiration <br/>

### Debugging Tools: <br/>
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
    sudo apt install g++ libsfml-dev
    # Arch Linux
    pacman -S gcc sfml   
```
## <ins>Roadmap

Milestone 1: Implement a functional interpreter capable of running simple programs<br/>

Milestone 2: Add full support for all opcodes and sound<br/>

Milestone 3: Create a graphical debugger<br/>

## <ins>Acknowledgements:

Special thanks to the emulator development community for providing me the inspiration to commence with this project. <br/>
Another special thanks to [Cowgod's Chip8 Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM) for providing me information on the Chip8 architecture
    
