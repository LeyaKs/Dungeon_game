#include "headers/object.h"

void Object::set_name(std::string _name) {
    name = _name;
}

std::string Object::get_name() const {
    return name;
}
