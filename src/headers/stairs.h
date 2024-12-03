#ifndef STAIRS_H
#define STAIRS_H

#include "construction.h"

enum class type_of_stairs{up, down};

class Stairs: public Construction {
    private:
        type_of_stairs type;
    public:
        Stairs() = default;
        Stairs(type_of_stairs _type): type(_type) {};
        void set_type(type_of_stairs);
        type_of_stairs get_type() const;

        ~Stairs() = default;
};

#endif