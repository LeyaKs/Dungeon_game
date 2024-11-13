#ifndef DUNGEON_H
#define DUNGEON_H


#include <vector>
#include "matrix.h"
#include "enemy.h"
#include "player.h"
#include "entity.h"
#include "chest.h"
#include "construction.h"

class Dungeon {
    private:
        Player player;
        std::vector<Enemy *> enemies;
        int level;
        Matrix<Cell> levels;
        int length;
        int width;
    public:
        Dungeon() = default;
        void set_length(int);
        void set_width(int);
        void set_cell_type(int, int);
        int get_length() const;
        int get_width() const;
        Entity *get_cell_type(int, int) const;
        void close_door(int, int);
        void open_door(int, int);
        ~Dungeon() = default;
};

#endif