#include "headers/characteristics.h"
#include <stdexcept>


// Characteristics::Characteristics() {
//     Characteristic char1, char2, char3, char4, char5;
//     char1.set_type(type_of_characteristic::strength);
//     char2.set_type(type_of_characteristic::agility);
//     char3.set_type(type_of_characteristic::endurance);
//     char4.set_type(type_of_characteristic::max_health);
//     char5.set_type(type_of_characteristic::curr_health);
//     characteristics.push_back(std::make_shared<Characteristic>(char1));
//     characteristics.push_back(std::make_shared<Characteristic>(char2));
//     characteristics.push_back(std::make_shared<Characteristic>(char3));
//     characteristics.push_back(std::make_shared<Characteristic>(char4));
//     characteristics.push_back(std::make_shared<Characteristic>(char5));

// }



Characteristics::Characteristics(const std::vector<std::shared_ptr<Characteristic>>& _characteristics) :
    characteristics(_characteristics) {}

void Characteristics::change_value_characteristic(type_of_characteristic _type, int _value) {
    int index = find_characteristic(_type);
    if (index == -1) { return;
    }
    characteristics[index]->change_value(_value);
}





int Characteristics::get_count() const{
    return characteristics.size();
}

std::vector<std::shared_ptr<Characteristic>> Characteristics::get_characteristics() const {
    return characteristics;
}

void Characteristics::add_characteristic(type_of_characteristic _type, int _value) {
    Characteristic temp;
    temp.set_type(_type);
    temp.change_value(_value);

    characteristics.push_back(std::make_shared<Characteristic>(temp));

}

int Characteristics::get_characteristic(type_of_characteristic _type) const {
    int index = find_characteristic(_type);
    if (index  == -1) {  return -1;
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