#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H


#include "characteristic.h"

class Characteristics {
    private:
        Characteristic *specifications;
    public:
        Characteristics() = default;
        void set_characteristic(std::string);
        int get_characteristic() const;
        void change_characteristic(std::string);
        int get_count();
        ~Characteristics() = default;
};

#endif