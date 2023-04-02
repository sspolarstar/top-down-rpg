#include "headers/animation.hpp"
#include <iostream>
Animation::Animation(sf::Texture &texture, sf::Vector2u &imageCount, float switchTime){
    this->sprite.setTexture(texture);
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->currentImage = 0;
    this->imageWidth = texture.getSize().x/imageCount.x;
    this->imageHeight = (texture.getSize().y)/imageCount.y;
    this->spriteLocator= {0,0,imageWidth, imageHeight};
}


void Animation::setRow(Position pos){
    if(pos.x > 0){
        row = 1;
        facesRight = true;
    } 
    if (pos.x < 0) {
        row = 1;
        facesRight = false;
    }
    if(pos.y > 0){
        row = 0;
        facesRight = false;
    }
    if(pos.y < 0){
        row = 2;
        facesRight = false;
    }
    if( pos == Position(0,0)){
        row = -1;
    }
}

void Animation::update(Position pos, float deltaTime){
    this->sprite.setPosition({pos.x, pos.y});
    this->totalTime += deltaTime;

    if(totalTime >= switchTime){
        totalTime -= switchTime;
        if(row == -1){
            currentImage = 1;
            if(!facesRight)
                this->spriteLocator.left = imageWidth;
            else
                this->spriteLocator.left = (2*imageWidth);
        }
        else{
            if(!facesRight)
                this->spriteLocator = sf::IntRect(currentImage * imageWidth, this->row * imageHeight, imageWidth, imageHeight);
            else 
                this->spriteLocator = sf::IntRect((currentImage + 1) * imageWidth, this->row * imageHeight, -imageWidth, imageHeight );
            currentImage = (currentImage + 1) % imageCount.x;
            
        }
            this->sprite.setTextureRect(spriteLocator);
    }
}

void Animation::draw(sf::RenderWindow& window){
    window.draw(this->sprite);
}