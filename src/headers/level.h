/**
    * \file
    * \brief Header file with description of functions of class level
*/

#ifndef LEVEL_H
#define LEVEL_H


#include <vector>
#include "matrix.h"
#include "chest.h"
#include "construction.h"
#include "floor.h"
#include "stairs.h"
#include "door.h"
#include "enemy.h"
#include "player.h"


/**
    * \class Level
    * \brief Class Level
    * 
    * Contains matrix, constructors and functions
*/
class Level {
    public:
        Matrix<Cell> map;

        Level() = default;
        Level(Matrix<Cell>& _map): map(_map) {};
        Level operator =(const Level &other) {map = other.map; return *this;}
        ~Level() {};
};

#endif