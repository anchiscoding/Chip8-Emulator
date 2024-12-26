#include "../includes/system.h"
#include <cstdint>
#include <sys/types.h>

System::System() {
    m_registers.PC = static_cast<uint16_t>(0x200);
}

void System::start_execution() {
    is_running = true;
    while(is_running) {
        // Get opcode
        uint8_t opcode =  m_sys_mem[m_registers.PC];
        switch((opcode & 0xF000) >> 12) {
            case 0x0:
                if(opcode == 0x00E0) // Instruction 00E0 clears the display
                {
                    m_display.clear_display();
                }
                if(opcode == 0x00EE) // Instruction 00EE (RET) returns from a subroutine
                {
                    m_registers.PC=m_stack[m_registers.SP];
                    m_registers.SP-=1;
                }
                break;
            case 0x1: // Instruction 1nnn jumps to location nnn 
                m_registers.PC = static_cast<uint16_t>(opcode & 0x0FFF);
                break;
            case 0x2: // Instruction 2nnn calls subroutine at nnn
                m_registers.SP +=1;
                m_stack[m_registers.SP]=m_registers.PC;
                m_registers.PC = static_cast<uint16_t>(opcode & 0x0FFF);
                break;
            case 0x3: // Instruction 3xkk skips next instruction if Vx = kk
                if( m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] == static_cast<uint8_t>(opcode & 0x00FF))
                m_registers.PC+=2;
                break;
            case 0x4: // Instruction 4xkk skips next instruction if Vx != kk
                if( m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] != static_cast<uint8_t>(opcode & 0x00FF))
                m_registers.PC+=2;
                break;
            case 0x5: // Instruction 5xy0 skips next instruction if Vx = Vy
                if( m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] == m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)])
                m_registers.PC+=2;
                break;
            case 0x6: // Instruction 6xkk Sets Vx = kk 
                m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = static_cast<uint8_t>(opcode & 0x00FF);
                break;
            case 0x7: // Instruction 7xkk Sets Vx = Vx + kk 
                m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)]= m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] + static_cast<uint8_t>(opcode & 0x00FF);
                break;
            case 0x8: // Instructions 8xy(1 to E)
                switch (opcode & 0x000F) {
                    case 0x0: // 8xy0 -> Set Vx = Vy
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00)>> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        break;
                    case 0x1: // 8xy1 -> Set Vx = Vx OR Vy
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] | m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        break;
                    case 0x2: // 8xy2 -> Set Vx = Vx AND Vy
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00)>> 8)] & m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        break;
                    case 0x3: // 8xy3 -> Set Vx = Vx XOR Vy
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00)>> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] ^ m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        break;
                    case 0x4: // 8xy4 -> Set Vx = Vx + Vy, set VF = carry
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] + m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        if(m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] > static_cast<uint8_t>(0xFF))
                        {
                            m_registers.m_V[0xE] = 1;
                        }
                        else {
                        {
                            m_registers.m_V[0xE] = 0;
                        }
                        }
                        break;
                    case 0x5: // 8xy5 -> Vx = Vx - Vy, set VF = NOT borrow
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] - m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)];
                        break;
                    case 0x6: // 8xy6 -> Vx = Vx SHR 1
                        if((m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] & 0x0001) == 1)
                        {
                            m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = 1;
                        }
                        else {
                            m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = 0;
                        }
                        m_registers.m_V[static_cast<uint8_t>(opcode & 0x0F00 >> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8) ] /  2;
                        break;
                    case 0x7: // 8xy7 -> Vx = Vy -Vx, set VF = NOT borrow
                        if(m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)] > m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)])
                        {
                            m_registers.m_V[0xE] = 1;
                        }
                        else {
                            m_registers.m_V[0xE] = 0;
                        }
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x00F0) >> 4)] - m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)];
                        break;
                    case 0xE: // 8xyE -> Vx = Vx SHL 1
                        if((m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] & 0x0001) == 1)
                        {
                            m_registers.m_V[0xE] = 1;
                        }
                        else {
                            m_registers.m_V[0xE] = 0;
                        }
                        m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00)>> 8)] = m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] * 2;
                        break;
                }
                break;
            case 0x9:
                if( m_registers.m_V[static_cast<uint8_t>(opcode & 0x0F00) >> 8] != m_registers.m_V[static_cast<uint8_t>(opcode & 0x00F0) >> 4])
                {
                   m_registers.PC =  m_registers.PC + 2;
                } 
                break;
            case 0xA:
                m_registers.I = static_cast<uint16_t>(opcode & 0x0FFF);
                break;
            case 0xB:
                m_registers.I = (static_cast<uint16_t>(opcode & 0x0FFF) + m_registers.m_V[0]);
                break;
            case 0xC:
            {
                uint8_t randomno = rand() % 256;
                m_registers.m_V[static_cast<uint8_t>((opcode & 0x0F00) >> 8)] = randomno & (static_cast<uint8_t>(opcode & 0x00FF));
                break;
            }
            case 0xD:
                m_display.dxyn(static_cast<uint8_t>((opcode & 0x0F00) >> 8), static_cast<uint8_t>((opcode & 0x00F0) >> 4 ), static_cast<uint8_t>(opcode & 0x000F), m_sys_mem, m_registers.I, m_registers.m_V[0xE]);  
                break;
            case 0xE:
                break;
            case 0xF:
                break;
        }

                

                
    }
}


// Work In Progress