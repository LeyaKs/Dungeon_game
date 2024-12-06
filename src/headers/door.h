#ifndef DOOR_H
#define DOOR_H


#include "construction.h"

enum class type_of_door{opened, closed};

class Door: public Construction {
    private:
        int level_padlock;
        type_of_door type;
    public:
        Door(): type(type_of_door::closed) {};
        Door (type_of_door _type, int _lvl): type(_type), level_padlock(_lvl) {};
        void set_type(type_of_door);
        // void set_level_padlock(int);
        type_of_door get_type() const;
        int get_level_padlock() const;
        ~Door() = default;
};

#endif