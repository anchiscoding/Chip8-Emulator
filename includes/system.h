#pragma once

#include "shared.h"
#include <string>
#include "display.h"

class System {
    public:
        System();
        void load_game(std::string game_path);
        void start_execution();
    private:
        uint8_t m_sys_mem[4 * KB]; 
        struct {
            uint8_t m_V[0xF];
            uint8_t SP;
            uint16_t I;
            uint16_t PC;
            uint8_t  DT;
            uint8_t  ST;
        } m_registers;
        uint16_t m_stack[0xF];
        bool is_running;
        Display m_display;
};

// Work In Progress