#include "headers/mapManager.hpp"
#include <iostream>
MapManager::MapManager(Player& player){

}

void MapManager::convertSketch(sf::Image& mapRef, Player& player){
    this->map.clear();
    this->map.resize((int)mapRef.getSize().x);
    // std::cout << mapRef.getSize().y << std::endl;
    // std::cout << mapRef.getSize().x << std::endl;
    
    for(int x = 0; x < mapRef.getSize().x; x++){
        this->map[x].resize((int)mapRef.getSize().y);
        for(int y = 0; y < mapRef.getSize().y; y++){
            sf::Color pixel = mapRef.getPixel(x,y);
            if(pixel == sf::Color(255,255,255)){
                this->map[x][y] = Cell::path;     
            }
            else if(pixel == sf::Color( 0, 0, 0, 0 )){
                this->map[x][y] = Cell::empty;
            }
            else if(pixel == sf::Color(25, 88, 13,255)){
                player.setPosition({(float)x * CELL_SIZE, (float)y * CELL_SIZE});
            }
            else{
                this->map[x][y] = Cell::wall;
                std::cout << std::endl << "weird color with RGBA = " << (float)pixel.r << ", " << (float)pixel.g <<", " <<(float)pixel.b <<", "<<(float)pixel.a <<"."<< std::endl;
            }

        }
    }
}

void MapManager::drawMap(sf::RenderWindow &window, Position pos){
    sf::RectangleShape cell;
    cell.setSize({CELL_SIZE, CELL_SIZE});
    cell.setFillColor(sf::Color(0,0,0));
    cell.setOutlineColor(sf::Color::White);
    cell.setOutlineThickness(1);

    int xStart = 0;
        if((pos.x/CELL_SIZE - (WINDOW_WIDTH/2) ) < 0)
            xStart = 0;
        else
            xStart = pos.x/CELL_SIZE - (WINDOW_WIDTH/2);
    
    int xFinish;
        if((pos.x/CELL_SIZE + (WINDOW_WIDTH/2)) > this->map.size()){
            xFinish = this->map.size();
        } else
            xFinish = pos.x/CELL_SIZE + (WINDOW_WIDTH/2);

    int yStart = 0;
        if( (pos.y/CELL_SIZE - (WINDOW_HEIGHT/2)) < 0){
            yStart = 0;
        } else
            yStart = pos.y/CELL_SIZE - (WINDOW_HEIGHT/2);

    int yFinish = this->map[0].size();
        if((pos.y/CELL_SIZE + (WINDOW_HEIGHT/2)) < this->map[0].size()){
            yFinish = pos.y/CELL_SIZE + (WINDOW_HEIGHT/2);
        } else 
            yFinish = this->map[0].size();

    for(int x = xStart; x < xFinish - 1; x++){
        for(int y = yStart; y < yFinish -1; y++){  
            if(map[x][y] == Cell::path){
                cell.setOutlineColor(sf::Color::White); 
                cell.setFillColor(sf::Color(0,0,0));
                cell.setPosition((float)x * CELL_SIZE , (float)y * CELL_SIZE);
            }
            if(map[x][y] == Cell::wall){
                cell.setOutlineColor(sf::Color::White); 
                cell.setFillColor(sf::Color(255,255,255));
                cell.setPosition((float)x * CELL_SIZE , (float)y * CELL_SIZE);
            }
            window.draw(cell);
        }
    }
}

void MapManager::setMap(Map newMap){
}