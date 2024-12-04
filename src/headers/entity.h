#ifndef ENTITY_H
#define ENTITY_H

#include "point.h"

class Entity {
    private:
        Point point;
    public:
        Entity() = default;
        Entity(Point coords) : point(coords) {};
        void set_point(Point);
        Point get_point() const;
        virtual ~Entity() = default;
};

#endif