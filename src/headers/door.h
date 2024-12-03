#ifndef DOOR_H
#define DOOR_H


#include "construction.h"

enum class type_of_door{opened, closed};

class Door: public Construction {
    private:
        type_of_door type;
    public:
        Door(): type(type_of_door::closed) {};
        Door (type_of_door _type): type(_type) {};
        void set_type(type_of_door);
        // type_of_door get_type() const;
        ~Door() = default;
};

#endif