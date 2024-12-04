#ifndef DUNGEON_H
#define DUNGEON_H


#include <vector>
#include <memory>
#include "level.h"
//  #include "player.h"

class Dungeon {
    private:
        Player player;
        std::vector<std::shared_ptr<Enemy>> enemies;
        int level;
        std::vector<Level> levels;
        int length;
        int width;
    public:
        Dungeon() = default;
        Dungeon(Player, std::vector<std::shared_ptr<Enemy>>,
                int, std::vector<Level>, int, int);
        void set_length(int);
        void set_width(int);
        void set_levels(std::vector<Level>);
        void set_level(int);
        void set_enemies(std::vector<std::shared_ptr<Enemy>>);
        void set_player(Player);
        // void set_cell_type(Point, int, std::shared_ptr<Entity>);
        int get_length() const;
        int get_width() const;
        int get_level() const;
        std::vector<Level> get_levels() const;
        std::vector<std::shared_ptr<Enemy>> get_enemies() const;
        Player get_player() const;
        std::weak_ptr<Entity> get_cell_type(Point, int) const;


        void close_door(std::shared_ptr<Door>);
        void open_door(std::shared_ptr<Door>);
        ~Dungeon() = default;
};

#endif