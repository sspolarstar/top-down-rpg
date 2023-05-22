#include "headers/collider.hpp"
#include <iostream>


Collision getMapCollision(Position pos, float speed, float deltaTime, Map map){
    //player can occupy 4 cells, so we check the current position and use the speed/delta time to make sure that we can't get any closer.
    float maxDistance = speed*deltaTime;
    if(pos.x - maxDistance < 0 || ceil((pos.x + maxDistance)/CELL_SIZE) > MAP_WIDTH ||
        pos.y - maxDistance < 0 || ceil((pos.y + maxDistance)/CELL_SIZE) > MAP_HEIGHT
     ){
        maxDistance = 0;
    }

    Position checkCell;
    Collision collision;
    if(pos.x/CELL_SIZE > MAP_WIDTH || pos.x < 0 || pos.y/CELL_SIZE > MAP_HEIGHT || pos.y < 0){
        std::cout << std::endl << "not in range" << std::endl;
        return collision;
    }

    for(int a = 0; a < 4; a++){
        switch (a){
        case LEFT:
            //cell left of position is at floor(pos.x)/CELL_SIZE
            //reference collisions from the bottom layer
            checkCell = {floor((pos.x - maxDistance)/CELL_SIZE), ceil(pos.y/CELL_SIZE)};
            break;
        case RIGHT: 
            checkCell = {ceil((pos.x + maxDistance)/CELL_SIZE), ceil(pos.y/CELL_SIZE)};
        case UP:
            //Check from the center of the player
            checkCell = {(pos.x + CELL_SIZE/2)/CELL_SIZE, floor((pos.y - maxDistance)/CELL_SIZE)};
        case DOWN:
            checkCell = {(pos.x + CELL_SIZE/2)/CELL_SIZE, ceil((pos.y+ maxDistance)/CELL_SIZE)};
        default:
            break;
        }
    collision.wall[a] = (map[checkCell.x][checkCell.y] == Cell::wall);  

    }
    return collision;
}

Collision getIACollision(Position pos, unsigned char direction, Map map){
    Collision collision;

    return collision;
}