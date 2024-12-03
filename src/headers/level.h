#ifndef LEVEL_H
#define LEVEL_H


#include <vector>
#include "matrix.h"
// #include "enemy.h"
#include "chest.h"
#include "construction.h"

class Level {
    private:
        Matrix<Cell> map;
    public:
        Level() = default;
        Level(Matrix<Cell> _map): map(_map) {};
        Matrix<Cell> get_map() const;
        ~Level() = default;
};

#endif