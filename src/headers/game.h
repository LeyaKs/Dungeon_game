#ifndef GAME_H
#define GAME_H

#include "dungeon.h"
#include "enchanted_weapon.h"


class Game {
    private:
        Dungeon dungeon;
    public:
        Game() = default;
        Game(Dungeon _dungeon): dungeon(_dungeon) {};

        void start();
        Level generate_level(int, int, int, std::vector<std::shared_ptr<Enemy>>);
        Enemy generate_enemy(Point);
        Armor generate_armor();
        Chest generate_chest(Point);
        Potion generate_potion();
        LockPicks generate_lock_picks();
        Weapon generate_weapon();
        Player generate_player(Point);
        Characteristics generate_characteristics(int, int, int);
        Dungeon generate_dungeon();

        Point find_free_point(Level, int, int);
        int random_value(int, int);
        ~Game() = default;
};

#endif