#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <string>
#include "entity.h"

class Construction: public Entity {
    private:
        std::string name;
    public:
        Construction() = default;
        void set_name(std::string);
        std::string get_name() const;
        ~Construction() = default;
};

#endif