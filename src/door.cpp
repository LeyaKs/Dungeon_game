#include "headers/door.h"

void Door::set_type(type_of_door _type) {
    type = _type;
}

type_of_door Door::get_type() const {
    return type;
}

int Door::get_level_padlock() const {
    return level_padlock;
}