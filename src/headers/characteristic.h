#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

enum class type_of_characteristic{strength, agility, endurance,
                                    max_health, curr_health};

class Characteristic {
    private:
        type_of_characteristic type;
        int value;
    public:
        Characteristic() = default;
        void set_type(type_of_characteristic);
        void change_value(int);
        type_of_characteristic get_type() const;
        int get_value() const;
        ~Characteristic() = default;
};

#endif