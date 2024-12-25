/**
    * \file
    * \brief Header file with description of functions of class game
*/
#ifndef GAME_H
#define GAME_H

#include "dungeon.h"
#include "enchanted_weapon.h"
#include <SFML/Graphics.hpp>

struct result {
    bool enemy_defeated = false;
    int player_damage_taken = 0;
};

/**
    * \class Game
    * \brief Class Game
    * 
    * Contains dungeon as field and main logic in the game
*/
class Game {
    private:
        Dungeon dungeon;
    public:
        Game() = default;
        Game(Dungeon _dungeon): dungeon(_dungeon) {};


        /**
            * \brief Starting the game
        */      
        void start();

        /**
            * \brief Doing one step
        */      
        void step(sf::Keyboard::Key);


        /**
            * \brief Generating level
            * \param lenght, width, current number of level, vector of enemies
            * \return level
        */        
        Level generate_level(int, int, int, std::vector<std::shared_ptr<Enemy>>&);

        
        void set_dungeon(const Dungeon& d) { dungeon = d;}
        /**
            * \brief Generating enemy
            * \param point
            * \return enemy
        */              
        Enemy generate_enemy(Point);


        /**
            * \brief Generating armor
            * \return armor
        */        
        Armor generate_armor();


        /**
            * \brief Generating chest
            * \param point
            * \return chest
        */        
        Chest generate_chest(Point);


        /**
            * \brief Generating potion
            * \return potion
        */    
        Potion generate_potion();


        /**
            * \brief Generating lock picks
            * \return lock picks
        */    
        LockPicks generate_lock_picks();


        /**
            * \brief Generating weapon
            * \return weapon
        */    
        Weapon generate_weapon();



        /**
            * \brief Generating player
            * \param point
            * \return player
        */    
        Player generate_player(Point);


        /**
            * \brief Generating characteristics
            * \param count, range(min and max values)
            * \return characteristics
        */    
        Characteristics generate_characteristics(int, int, int);


        /**
            * \brief Generating dungeon
            * \return dungeon
        */   
        Dungeon generate_dungeon();



        /**
            * \brief Getting dungeon
            * \return dungeon
        */   
        Dungeon& get_dungeon();


        /**
            * \brief Finding free point
            * \param level, width, lenght
            * \return point
        */   
        Point find_free_point(Level&, int, int);

        /**
            * \brief Generating random value
            * \param range(min and max values)
            * \return value
        */   
        int random_value(int, int);


      

        result process_enemy_battle(std::shared_ptr<Enemy>,
                   Player&, Dungeon&, int, int);
        ~Game() = default;
};

#endif