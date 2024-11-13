#ifndef DOOR_H
#define DOOR_H


#include "construction.h"

enum class type_of_door{opened, closed};

class Door: public Construction {
    private:
        type_of_door type;
    public:
        Door() = default;
        void set_type(type_of_door);
        type_of_door get_type() const;
        void close_door();
        void open_door();
        ~Door() = default;
};

#endif