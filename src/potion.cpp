#include "headers/potion.h"

void Potion::set_characteristics(const Characteristics& _characteristics) {
    characteristics = _characteristics;
}

void Potion::set_values(const std::vector<int>& _values) {
    values =_values;
}

void Potion::set_name(std::string _name) {
    this->set_name(_name);
}

Characteristics Potion::get_characteristics() const {
    return characteristics;
}

std::vector<int> Potion::get_values() const {
    return values;
}

std::string Potion::get_name() const {
    return this->get_name();
}
