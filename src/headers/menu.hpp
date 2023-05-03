#pragma once

#include "global.hpp"

class Menu{
    public:
        Menu(sf::Text& text);
    
    public:
        void presentMenu(sf::RenderWindow& window);
        void loadingScreen(sf::RenderWindow& window);
    private:
        sf::Text text;
        bool menuActive = true;
        sf::RectangleShape background, button, textbox;
};