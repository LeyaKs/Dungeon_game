#include "headers/dungeon.h"

Dungeon::Dungeon(const Player& _player, const std::vector<std::shared_ptr<Enemy>>& _enemies, int _level,
            const std::vector<Level>& _levels, int _length, int _width) {
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

void Dungeon::set_levels(const std::vector<Level>& _levels) {
    levels = _levels;
}

void Dungeon::set_player(const Player& _player) {
    player = _player;
}

void Dungeon::increase_level() {
    level++;
}

void Dungeon::set_enemies(const std::vector<std::shared_ptr<Enemy>>& _enemies) {
    enemies = _enemies;
}


int Dungeon::get_length() const {
    return length;
}

int Dungeon::get_width() const {
    return width;
}



Player& Dungeon::get_player(){
    return player;
}

int Dungeon::get_level() const {
    return level;
}

const std::vector<std::shared_ptr<Enemy>>& Dungeon::get_enemies() const {
    return enemies;
}

const std::vector<Level>& Dungeon::get_levels() const {
    return levels;
}

void Dungeon::move_player(int _x, int _y) {
    levels[level].map.matrix[player.get_point().x][player.get_point().y].set_entity(std::make_shared<Floor>());
    player.set_point(Point(_x, _y));
    levels[level].map.matrix[_x][_y].set_entity(std::make_shared<Player>(player)); 
}

void Dungeon::disappear(Point _point) {
    
    levels[level].map.matrix[_point.x][_point.y] = 
                Cell(_point, std::make_shared<Floor>());
}