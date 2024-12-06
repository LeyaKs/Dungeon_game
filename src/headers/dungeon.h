#ifndef DUNGEON_H
#define DUNGEON_H


#include <vector>
#include <memory>
#include "level.h"

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
        Dungeon(const Player&, const std::vector<std::shared_ptr<Enemy>>&, int,
            const std::vector<Level>&, int, int);
        void set_length(int);
        void set_width(int);
        void set_levels(const std::vector<Level>&);
        void set_level(int);
        void set_enemies(const std::vector<std::shared_ptr<Enemy>>&);
        void set_player(const Player&);
        int get_length() const;
        int get_width() const;
        int get_level() const;
        std::vector<Level> get_levels() const;
        std::vector<std::shared_ptr<Enemy>> get_enemies() const;
        Player get_player() const;
        std::weak_ptr<Entity> get_cell_type(Point, int) const;


        ~Dungeon() = default;
};

#endif