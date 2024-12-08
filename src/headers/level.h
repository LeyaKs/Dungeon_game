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

class Level {
    private:
        Matrix<Cell> map;
    public:
        Level() = default;
        Level(Matrix<Cell> _map): map(_map) {};

        void set_map(Matrix<Cell>);
        Matrix<Cell> get_map() const;
        ~Level() = default;
};

#endif