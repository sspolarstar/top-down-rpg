#pragma once

#include "global.hpp"

    Collision getMapCollision(Position pos, float speed,  float deltaTime, Map map);
    Collision getIACollision(Position pos, unsigned char direction, Map map);

