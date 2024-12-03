#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H


#include "characteristic.h"
#include <vector>
#include <algorithm>
#include <memory>

class Characteristics {
    private:
        std::vector<std::shared_ptr<Characteristic>> characteristics;
    public:
        Characteristics() = default;
        Characteristics(std::vector<std::shared_ptr<Characteristic>>);
        void set_characteristic(type_of_characteristic, int);

        int find_characteristic(type_of_characteristic) const;
        int get_count();

        std::vector<std::shared_ptr<Characteristic>> get_characteristics() const;
        int get_characteristic(type_of_characteristic) const;
        
        ~Characteristics() = default;
};

#endif