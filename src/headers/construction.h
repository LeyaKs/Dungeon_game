#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <string>
#include "entity.h"

class Construction: public Entity {
    public:
        Construction() = default;
        Construction(Point _entity): Entity(_entity) {};
        virtual ~Construction() = default;
};

#endif