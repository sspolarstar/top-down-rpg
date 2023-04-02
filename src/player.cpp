#include "headers/player.hpp"
#include <iostream>
Player::Player(sf::Texture& texture, sf::Text &text, sf::Vector2f size, sf::Vector2u imageCount):
animation(texture, imageCount, 0.2f){
    this->text = text;
    this->body.setSize(size);
    this->body.setPosition({0.0,0.0});
}

void Player::update(float deltaTime){

    //movements
    Position movements;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movements.x -= deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movements.x += deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movements.y -= deltaTime * speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movements.y += deltaTime * speed;
    }
    std::cout <<" movements.x " << movements.x << "mov.y " << movements.y << std::endl;
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