/**
    * \file
    * \brief Header file with description of functions of class dungeon
*/

#ifndef DUNGEON_H
#define DUNGEON_H


#include <vector>
#include <memory>
#include "level.h"



/**
    * \class Dungeon
    * \brief Class Dungeon with its functions
    * 
    * Contains the player, vector of all enemies, current level, vector of all levels, lenght and width, constructors and functions
*/
class Dungeon {
    private:
        Player player;
        std::vector<std::shared_ptr<Enemy>> enemies;
        int level;
        std::vector<Level> levels;
        int length;
        int width;
    public:
        Dungeon() {
            level = 0;
        };
        Dungeon(const Player&, const std::vector<std::shared_ptr<Enemy>>&, int,
            const std::vector<Level>&, int, int);



        /**
            * \brief Setting lenght
            * \param lenght
        */
        void set_length(int);


        /**
            * \brief Setting width
            * \param width
        */
        void set_width(int);



        /**
            * \brief Setting all levels
            * \param vector of levels
        */
        void set_levels(const std::vector<Level>&);



        /**
            * \brief Increasing level
            * \param level
        */
        void increase_level();


        /**
            * \brief Setting enemies
            * \param vector of enemies
        */
        void set_enemies(const std::vector<std::shared_ptr<Enemy>>&);



        /**
            * \brief Setting player
            * \param player
        */
        void set_player(const Player&);



        /**
            * \brief Getting lenght
            * \return lenght
        */
        int get_length() const;



        /**
            * \brief Getting width
            * \return width
        */
        int get_width() const;



        /**
            * \brief Setting current level
            * \return level
        */
        int get_level() const;


        /**
            * \brief Getting all levels
            * \return levels
        */
        const std::vector<Level>& get_levels() const;


        /**
            * \brief Getting enemies
            * \return vector of enemies
        */
        const std::vector<std::shared_ptr<Enemy>>& get_enemies() const;

        /**
            * \brief Getting player
            * \return player
        */
        Player& get_player();

        void move_player(int, int);
        void disappear(Point);

        ~Dungeon() = default;
};

#endif