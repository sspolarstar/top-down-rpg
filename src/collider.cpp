#include "headers/collider.hpp"
#include <iostream>


Collision getMapCollision(Position pos, float speed, float deltaTime, Map map){
    //player can occupy 4 cells, so we check the current position and use the speed/delta time to make sure that we can't get any closer.
    float maxDistance = abs(deltaTime*speed) -0.75f;
    if(pos.x - maxDistance < 0 || ceil((pos.x + maxDistance)/CELL_SIZE) > MAP_WIDTH ||
        pos.y - maxDistance < 0 || ceil((pos.y + maxDistance)/CELL_SIZE) > MAP_HEIGHT
     ){
        maxDistance = 0;
    }

    Position checkCell;
    Collision collision;
    if(pos.x/CELL_SIZE > MAP_WIDTH || pos.x < 0 || pos.y/CELL_SIZE > MAP_HEIGHT || pos.y < 0){
        return collision;
    }

    for(int a = 0; a < 4; a++){
        switch (a){
        case LEFT:
            //cell left of position is at floor(pos.x)/CELL_SIZE
            //reference collisions from the TOP layer
            checkCell = {static_cast<int>((pos.x - maxDistance) / CELL_SIZE),
                         static_cast<int>((pos.y) / CELL_SIZE)};
            break;
        case RIGHT: 
            checkCell = {static_cast<int>((pos.x + maxDistance + PLAYER_WIDTH) / CELL_SIZE),
                         static_cast<int>((pos.y) / CELL_SIZE)};
            break;
        case UP:
            //Check from the left of the player
            checkCell = {static_cast<int>((pos.x) / CELL_SIZE),
                         static_cast<int>((pos.y - maxDistance) / CELL_SIZE)};
            break;
        case DOWN:
            checkCell = {static_cast<int>((pos.x) / CELL_SIZE),
                         static_cast<int>((pos.y + (PLAYER_HEIGHT) + maxDistance) / CELL_SIZE)};
            break;
        default:
            break;
        }
        if(checkCell.x < 0 || checkCell.x > MAP_WIDTH || checkCell.y < 0 || checkCell.y > MAP_HEIGHT){
            return collision;
        }
        collision.wall[a] = (map[checkCell.x][checkCell.y] == Cell::wall);  

    }
    //check the other half!
     for(int a = 0; a < 4; a++){
        switch (a){
        case LEFT:
            //cell left of position is at ceiling (pos.x)/CELL_SIZE
            //reference collisions from the bottom layer
            checkCell = {static_cast<int>((pos.x - maxDistance) / CELL_SIZE),
                         static_cast<int>((pos.y + PLAYER_HEIGHT) / CELL_SIZE)};
            break;
        case RIGHT: 
            checkCell = {static_cast<int>((pos.x +  maxDistance + PLAYER_WIDTH) / CELL_SIZE),
                         static_cast<int>((pos.y + PLAYER_HEIGHT) / CELL_SIZE)};
            break;
            //check the right of the player
        case UP:
            checkCell = {static_cast<int>((pos.x + PLAYER_WIDTH) / CELL_SIZE),
                         static_cast<int>((pos.y - maxDistance) / CELL_SIZE)};
            break;
        case DOWN:
            checkCell = {static_cast<int>((pos.x + PLAYER_WIDTH) / CELL_SIZE),
                         static_cast<int>((pos.y + (PLAYER_HEIGHT) + maxDistance) / CELL_SIZE)};
            break;
        default:
            break;
        }
        if(checkCell.x < 0 || checkCell.x > MAP_WIDTH || checkCell.y < 0 || checkCell.y > MAP_HEIGHT){
            return collision;
        }
        collision.wall[a] |= (map[checkCell.x][checkCell.y] == Cell::wall);  
    }

    return collision;
}

Collision getIACollision(Position pos, unsigned char direction, Map map){
    Collision collision;

    return collision;
}
