#pragma once
#include <SFML/Graphics.hpp>
#include "global.hpp"
#include "player.hpp"
class MapManager{
    public:
        MapManager(){};
        MapManager(Player&);
    public:
        unsigned short getCurrentLevel(){ return this->currentLevel; }
        void setCurrentLevel(unsigned short level) { currentLevel = level;}
        Map getMap(){return this->map;}
        void setMap(Map newMap);
        void convertSketch(sf::Image &mapRef, Player& player);
        void drawMap(sf::RenderWindow&, Position);
    private:
        unsigned short currentLevel = 0;
        Map map;
        

};
