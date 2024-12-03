#include "headers/chest.h"

void Chest::set_level_padlock(int _level_padlock) {
    level_padlock = _level_padlock;
}

void Chest::set_object(std::shared_ptr<Object> _object) {
    object = std::move(_object);
}

int Chest::get_level_padlock() const {
    return level_padlock;
}




std::shared_ptr<Object> Chest::try_open(int agility) {
    if (agility - level_padlock <= 0) {
        std::shared_ptr<Object> object_temp = std::move(object);
        return object_temp;
    }
    return nullptr;
}
