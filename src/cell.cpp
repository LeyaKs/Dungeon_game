#include "headers/cell.h"

void Cell::set_point(Point _point) {
    point = _point;
}

void Cell::set_entity(const std::shared_ptr<Entity>& _entity) {
    entity = _entity;
}


Point Cell::get_point() const {
    return point;
}

std::shared_ptr<Entity> Cell::get_entity() const {
    return entity;
}
