#ifndef CELL_H
#define CELL_H

#include "entity.h"
#include <memory>


class Cell {
    private:
        Point point;
        std::weak_ptr<Entity> entity;
    public:
        Cell() = default;
        Cell(Point _point, std::weak_ptr<Entity> _entity):
            point(_point), entity(_entity) {};

        void set_point(Point);
        void set_entity(std::weak_ptr<Entity>);
        Point get_point() const;
        std::weak_ptr<Entity> get_entity() const;
        ~Cell() = default;
};

#endif