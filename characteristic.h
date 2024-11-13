#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

class Characteristic {
    private:
        std::string name;
        int value;
    public:
        Characteristic() = default;
        void set_name(std::string);
        void set_value(int);
        std::string get_name() const;
        int get_value() const;
        ~Characteristic() = default;
};

#endif