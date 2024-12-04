#ifndef STAIRS_H
#define STAIRS_H

#include "construction.h"

enum class type_of_stairs{up, down};

class Stairs: public Construction {
    private:
        type_of_stairs type;
    public:
        Stairs() = default;
        Stairs(Point _point, type_of_stairs _type): Construction(_point), type(_type) {};
        void set_type(type_of_stairs);
        type_of_stairs get_type() const;

        ~Stairs() = default;
};

#endif