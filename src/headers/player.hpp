#pragma once

#include "global.hpp"
#include "animation.hpp"

class Player{
    public:
    //contructors
        Player(sf::Texture& texture, sf::Text &text, sf::Vector2f size, sf::Vector2u imageCount);
    public:
        void setPosition(Position pos);
        void update(float deltaTime, Map map);
        Position getPosition(){return this->position;};
		void draw(sf::RenderWindow &window);

    private:
        Animation animation;
        sf::RectangleShape body;
        Position position;
        sf::Text text;
        float speed = 100.0;
    
    public:
        bool Change_Map = false;
};