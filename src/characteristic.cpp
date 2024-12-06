#include "headers/characteristic.h"

void Characteristic::set_type(type_of_characteristic _type) {
    type = _type;
}

void Characteristic::change_value(int _value) {
    value += _value;
}




type_of_characteristic Characteristic::get_type() const {
    return type;
}

int Characteristic::get_value() const {
    return value;
}
