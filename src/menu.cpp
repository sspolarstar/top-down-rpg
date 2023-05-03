#include "headers/menu.hpp"
#include <iostream>
Menu::Menu(sf::Text& text){
    // sf::Font font;
    // font.loadFromFile("../assets/fonts/sansation.ttf");
    // text.setFont(font);
    // text.setCharacterSize(14);
    this->text = text;
    menuActive = true;
    sf::RectangleShape background, button, textbox;
    background.setFillColor(sf::Color(31,31,31,175));
    background.setPosition(0.0f,0.0f);
    background.setSize({(WINDOW_WIDTH*CELL_SIZE), (WINDOW_HEIGHT*CELL_SIZE)});

    textbox.setFillColor(sf::Color::Blue);
    textbox.setSize({100,50});
    textbox.setPosition((WINDOW_WIDTH* CELL_SIZE)/2 - 50, (WINDOW_HEIGHT*CELL_SIZE)/2 - 25);

    this->button = button;
    this->textbox = textbox;
    this->background = background;
}

void Menu::presentMenu(sf::RenderWindow& window){
    //define the menu options
    
    while(menuActive){
        if(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    window.close();}}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i mousePos = sf::Mouse::getPosition() - window.getPosition();
                if(mousePos.x > WINDOW_WIDTH* CELL_SIZE/2 - 50 && mousePos.x < WINDOW_WIDTH*CELL_SIZE/2 + 50 &&
                   mousePos.y > (WINDOW_HEIGHT*CELL_SIZE)/2 - 25 && mousePos.y < (WINDOW_HEIGHT*CELL_SIZE)/2 + 25
                ){
                    this->menuActive = false;
                }
            }
            window.clear();
            window.draw(this->background);
            window.draw(this->textbox);
            window.display();
        }
        else{
            return;
        }
    }

}