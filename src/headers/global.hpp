#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
constexpr unsigned char CELL_SIZE     = 16;
constexpr unsigned char WINDOW_HEIGHT = 45;
constexpr unsigned char WINDOW_WIDTH  = 80;

constexpr unsigned char LEFT  = 0;
constexpr unsigned char RIGHT = 1;
constexpr unsigned char UP    = 2;
constexpr unsigned char DOWN  = 3;






struct Position{
    float x, y;
    Position(){
        y = x = 0.0;
    };
    Position(float x, float y){
        this->x = x; this->y = y;
    }
    void setPosition(Position pos){
        this->x = pos.x; this->y = pos.y;
    }
    void setPosition(float x, float y){
        setPosition({x,y});
    }
    bool operator==(Position target){
        return (this->x==target.x && this->y==target.y);        
    }
    Position operator+(Position target){
        this->x += target.x;
        this->y += target.y;
        Position pos(this->x, this->y);
        return (pos);
    }
};