#include "../includes/display.h"
#include <SFML/Window.hpp>
#include <cstdint>


Display::Display() {
    sf::Vector2u resolution(64,32);
    sf::VideoMode mode(resolution);
    m_window.create(mode, "Chip 8 emulator");
}

sf::RenderWindow& Display::getWindow() {
    
    return m_window;
}
void Display::clear_display()
{
    int i;
    for(i =0 ; i < 64; i++)
    {
        for(int j=0;j < 32; j++)
        {
            m_pixels[i][j]=0;
        }
    }
    update_sfml_window();
}

void Display::dxyn(uint8_t x, uint8_t y, uint8_t num_bytes, uint8_t (&sys_mem)[4*KB], uint16_t I, uint8_t& VF){ // Implementation of Cowgod's reference for the DXYN Draw instruction for Chip8
    int horizontal_index_start = x;                                                                      //     http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#Dxyn
    int vertical_index_start = y;

    for(int offset = 0; offset < num_bytes; offset++){
        uint8_t sprite = sys_mem[I + offset];
        for(int bit_index = 0; bit_index < 8; bit_index++) {
            uint8_t most_sig_bit = sprite & 0x80;

            if(most_sig_bit) {
                // Check collision
                if(m_pixels[horizontal_index_start][vertical_index_start] == 1  && most_sig_bit == 1) {
                    VF = 1;
                    m_pixels[horizontal_index_start][vertical_index_start] = 0;
                } else {
                    m_pixels[horizontal_index_start][vertical_index_start] = 1;
                }
            }

            horizontal_index_start++;

            if(horizontal_index_start > 63) {
                horizontal_index_start %= 64;
            }

            sprite = sprite << 1;
        }
    }

    update_sfml_window();
}

void Display::update_sfml_window()
{

}
// Work In Progress
