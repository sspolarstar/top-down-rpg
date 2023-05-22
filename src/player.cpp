#include "headers/player.hpp"
#include "headers/collider.hpp"
#include <iostream>
Player::Player(sf::Texture& texture, sf::Text &text, sf::Vector2f size, sf::Vector2u imageCount):
animation(texture, imageCount, 0.2f){
    this->text = text;
    this->body.setSize(size);
    this->body.setPosition({0.0,0.0});
}

void Player::update(float deltaTime, Map map){
    //get collider
    Collision collision = getMapCollision(this->getPosition(), this->speed, deltaTime, map);
    //movements
    Position movements;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(!collision.wall[LEFT])
            movements.x -= deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(!collision.wall[RIGHT])
            movements.x += deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if(!collision.wall[UP])
            movements.y -= deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if(!collision.wall[DOWN])
            movements.y += deltaTime * speed;
    }

    
    animation.setRow(movements);
    this->setPosition(this->position+movements);
    animation.update(getPosition(), deltaTime);
}

void Player::setPosition(Position pos){
    this->position.setPosition(pos);
    this->body.setPosition({pos.x, pos.y});
}

void Player::draw(sf::RenderWindow &window){
    animation.draw(window);
}