#include "headers/cell.h"

void Cell::set_point(Point _point) {
    point = _point;
}

void Cell::set_entity(std::weak_ptr<Entity> _entity) {
    entity = _entity;
}



Point Cell::get_point() const {
    return point;
}

std::weak_ptr<Entity> Cell::get_entity() const {
    return entity;
}
