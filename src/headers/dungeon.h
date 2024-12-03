#ifndef DUNGEON_H
#define DUNGEON_H


#include <vector>
#include <memory>
#include "level.h"
 #include "player.h"
#include "door.h"

class Dungeon {
    private:
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<Enemy>> enemies;
        int level;
        std::vector<Level> levels;
        int length;
        int width;
    public:
        Dungeon() = default;
        Dungeon(std::shared_ptr<Player>, std::vector<std::shared_ptr<Enemy>>, int, std::vector<Level>, int, int);
        void set_length(int);
        void set_width(int);
        void set_cell_type(Point, int, std::shared_ptr<Entity>);
        int get_length() const;
        int get_width() const;
        Entity *get_cell_type(Point, int) const;


        void close_door(std::shared_ptr<Door>);
        void open_door(std::shared_ptr<Door>);
        ~Dungeon() = default;
};

#endif