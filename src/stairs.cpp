#include "headers/stairs.h"

void Stairs::set_type(type_of_stairs _type) {
    type = _type;
}

type_of_stairs Stairs::get_type() const {
    return type;
}
