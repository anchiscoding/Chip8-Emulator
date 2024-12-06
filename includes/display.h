#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdint>
#include "shared.h"

class Display {
    public:
        Display();
        sf::RenderWindow& getWindow();
        void dxyn(uint8_t x, uint8_t y, uint8_t num_bytes, uint8_t (&sys_mem)[4*KB], uint16_t I, uint8_t& VF);
        void draw();
        void clear_display();
    private:
        sf::RenderWindow m_window;
        uint8_t m_pixels[64][32];
        void update_sfml_window();

};

// Work In Progress