#ifndef POTION_H
#define POTION_H

#include <vector>
#include "object.h"
#include "characteristics.h"

class Potion: public Object {
    private:
        Characteristics characteristics;
        std::vector<int> values;
    public:
        Potion() = default;
        void set_characteristics(Characteristics);
        void set_values(std::vector<int>);

        Characteristics get_characteristics() const;
        std::vector<int> get_values() const;
        ~Potion() = default;
};

#endif