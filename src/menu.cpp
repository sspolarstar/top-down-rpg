#include "headers/menu.hpp"

Menu::Menu(){
    sf::Font font;
    font.loadFromFile("../assets/fonts/sansation.ttf");
    text.setFont(font);
    text.setCharacterSize(14);
    menuActive = true;
}

void Menu::presentMenu(sf::RenderWindow& window){
    while(menuActive){

    }
}