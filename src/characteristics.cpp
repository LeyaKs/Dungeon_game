#include "headers/characteristics.h"
#include <stdexcept>




Characteristics::Characteristics(std::vector<std::shared_ptr<Characteristic>> _characteristics) {
    characteristics = _characteristics;
} 

void Characteristics::set_characteristic(type_of_characteristic _type, int _value) {
    int index = 0;
    if (index = find_characteristic(_type) == -1) {
        throw std::out_of_range("Not found");
    }
    characteristics[index]->set_value(_value);
}


int Characteristics::get_count()
{
    return characteristics.size();
}

std::vector<std::shared_ptr<Characteristic>> Characteristics::get_characteristics() const {
    return characteristics;
}

int Characteristics::get_characteristic(type_of_characteristic _type) const
{
    int index = 0;
    if (index = find_characteristic(_type) == -1) {
        throw std::out_of_range("Not found");
    }
    return characteristics[index]->get_value();
}

int Characteristics::find_characteristic(type_of_characteristic _type) const {
    auto result = std::find_if(begin(characteristics), end(characteristics), [_type](const std::shared_ptr<Characteristic> characteristic) {
        return characteristic->get_type() == _type;
    });
    if (result != end(characteristics)) {
        return std::distance(characteristics.begin(), result);
    }
    return -1;
}