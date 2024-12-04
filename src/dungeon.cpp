#include "headers/dungeon.h"

Dungeon::Dungeon(Player _player, std::vector<std::shared_ptr<Enemy>> _enemies, int _level, std::vector<Level> _levels, int _length, int _width) {
    player = _player;
    enemies = _enemies;
    level = _level;
    levels = _levels;
    length = _length;
    width = _width;
}

void Dungeon::set_length(int _length) {
    length = _length;
}

void Dungeon::set_width(int _width) {
    width = _width;
}

void Dungeon::set_levels(std::vector<Level> _levels) {
    levels = _levels;
}

void Dungeon::set_player(Player _player) {
    player = _player;
}

void Dungeon::set_level(int _level) {
    level = _level;
}

void Dungeon::set_enemies(std::vector<std::shared_ptr<Enemy>> _enemies) {
    enemies = _enemies;
}
// void Dungeon::set_cell_type(Point point, int level, Entity *entity) {
//     levels[level].get_map()[point.x][point.y].set_entity(entity);
// }

int Dungeon::get_length() const {
    return length;
}

int Dungeon::get_width() const {
    return width;
}

std::weak_ptr<Entity> Dungeon::get_cell_type(Point point, int level) const {
    return levels[level].get_map().get_matrix()[point.x][point.y].get_entity();
}

Player Dungeon::get_player() const{
    return player;
}

int Dungeon::get_level() const {
    return level;
}

std::vector<std::shared_ptr<Enemy>> Dungeon::get_enemies() const {
    return enemies;
}

std::vector<Level> Dungeon::get_levels() const {
    return levels;
}



void Dungeon::close_door(std::shared_ptr<Door> door) {
    door->set_type(type_of_door::closed);
}

void Dungeon::open_door(std::shared_ptr<Door> door) {
    door->set_type(type_of_door::opened);
}
