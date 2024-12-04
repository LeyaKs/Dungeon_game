#include "headers/level.h"


void Level::set_map(Matrix _map) {
    map = _map;
}

Matrix Level::get_map() const {
    return map;
}