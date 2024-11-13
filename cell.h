#ifndef CELL_H
#define CELL_H

#include "entity.h"



class Cell {
    private:
        Point point;
        Entity *entity;
    public:
        Cell() = default;
        void set_point(Point);
        void set_entity(Entity);
        Point get_point() const;
        Entity get_entity() const;
        ~Cell() = default;
};

#endif