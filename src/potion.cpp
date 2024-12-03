#include "headers/potion.h"

void Potion::set_characteristics(Characteristics _characteristics) {
    characteristics = _characteristics;
}

void Potion::set_values(std::vector<int> _values) {
    values =_values;
}

void Potion::set_name(std::string _name) {
    name = _name;
}

Characteristics Potion::get_characteristics() const {
    return characteristics;
}

std::vector<int> Potion::get_values() const {
    return values;
}

std::string Potion::get_name() const {
    return name;
}
