#include <SFML/Graphics.hpp>
#include <iostream>
#include "headers/global.hpp"
#include "headers/player.hpp"
#include "headers/mapManager.hpp"

int main(){
    //////////////////// start render Data
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH*CELL_SIZE, WINDOW_HEIGHT*CELL_SIZE), "placeholder");
        window.setFramerateLimit(30);  
        sf::View view({0,0,WINDOW_WIDTH*CELL_SIZE, WINDOW_HEIGHT*CELL_SIZE});
        sf::Clock clock;
        float deltaTime = 0.0;
        Position playerPos;
    //////////////////// end render Data

    //////////////////// start font constructor
        sf::Font font; font.loadFromFile("assets/fonts/sansation.ttf");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color(255,255,255,255));
    //////////////////// end font constructor

    //////////////////// start player constructor
        sf::Texture playerTexture;
        playerTexture.loadFromFile("assets/img/player.png");
        sf::Vector2u playerImageCount(4,3);   
        Player player(playerTexture, text, {CELL_SIZE, 2* CELL_SIZE}, playerImageCount);
    //////////////////// end player constructor
    
    /////////////////// start Map constructor
        sf::Image mapImage;
        mapImage.loadFromFile("assets/maps/start.png");
        MapManager mapManager;
        mapManager.convertSketch(mapImage, player);
    /////////////////// end Map constructor





//=================================== START LOOP =========================================
    while(window.isOpen()){
        /////////////////////TEST CLOSE/////////////
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    window.close();}}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        /////////////////////TEST CLOSE/////////////

        ////////////////////START UPDATE SPRITES//////////
            deltaTime = clock.restart().asSeconds();
            player.update(deltaTime);
        ////////////////////END UPDATE SPRITES//////////

        ////////////////////START MAP UPDATES//////////
            if(player.Change_Map){
                player.Change_Map = false;
                int level = mapManager.getCurrentLevel();
                mapImage.loadFromFile("assets/maps/level" + std::to_string(level) + ".png");
                mapManager.convertSketch( mapImage, player);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                player.Change_Map = true;
                sf::sleep(sf::milliseconds(100));
            }
        ////////////////////END MAP UPDATES////////////


        ////////////////////START SETTING POSITIONS//////////
            playerPos = player.getPosition();
            view.reset({playerPos.x - (WINDOW_WIDTH * CELL_SIZE)/2,
            playerPos.y - (WINDOW_HEIGHT * CELL_SIZE)/2,
            WINDOW_WIDTH * CELL_SIZE,
            WINDOW_HEIGHT * CELL_SIZE }); //left, top, width, height
            window.setView(view);
        ////////////////////END SETTING POSITIONS//////////

        ////////////////////START RENDER WINDOW//////////
            window.clear();
            mapManager.drawMap(window, playerPos);
            player.draw(window);
            window.display();
        ////////////////////END RENDER WINDOW//////////

    } //================ END LOOP===========================================
    return 0;
}// ==================== end main ==========================================