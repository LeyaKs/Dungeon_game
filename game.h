#ifndef GAME_H
#define GAME_H

#include "dungeon.h"

class Game {
    private:
        Dungeon dungeon;
    public:
        Game() = default;
        void make_step();
        ~Game() = default;
};

#endif