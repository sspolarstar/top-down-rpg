#pragma once

#include "global.hpp"

class Animation{
    public:
        Animation(){};
        Animation(sf::Texture &texture, sf::Vector2u &imageCount, float switchTime);
    public:
        void update(Position pos, float deltaTime);
        void draw(sf::RenderWindow& window);
        void setFacesRight(bool facesRight) { this->facesRight = facesRight; };
        void setRow(Position pos);
    private:
        //Timing variables
        float switchTime;
        float totalTime;
        //direction variables
        bool facesRight = true;
        //texture variables
        unsigned short currentImage;
	    unsigned short imageWidth;
        unsigned short imageHeight;
        short          row = 0;
        sf::Vector2u imageCount;
        //sprite variables
        sf::Sprite   sprite;
        sf::IntRect  spriteLocator;

        
};