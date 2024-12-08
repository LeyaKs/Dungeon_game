#include "headers/level.h"


void Level::set_map(Matrix<Cell> _map) {
    map = _map;
}

Matrix<Cell> Level::get_map() const {
    return map;
}