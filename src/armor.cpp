#include "headers/armor.h"

void Armor::set_type(type_of_armor _type) {
    type = _type;
}

void Armor::set_protection(int _protection) {
    protection = _protection;
}

type_of_armor Armor::get_type() const {
    return type;
}

int Armor::get_protection() const {
    return protection;
}
