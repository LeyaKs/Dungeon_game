/**
    * \file
    * \brief Header file with description of functions of class enemy
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "player.h"
#include "entity.h"
#include "armor.h"

using std::string;

/**
    * \enum type_feature
    * \brief Enum class type_festure with available enemy type
*/
enum class type_feature{icy, earth, minotaur};



/**
    * \class Enemy
    * \brief Child class Enemy from class Entity
    * 
    * Contains name, health, damage, hit, experince, armor and type of feature
*/
class Enemy: public Entity{
    private:
        string name;
        int max_health;
        int curr_health;
        int damage;
        int hit;
        int experience;
        std::shared_ptr<Armor> armor;
        type_feature feature;
    public:
        Enemy() = default;
        Enemy(Point, string, int, int, int, int, int, const std::shared_ptr<Armor>&, type_feature);
                


        /**
            * \brief Setting name
            * \param name
        */
        void set_name(string);


        /**
            * \brief Setting max health
            * \param max health
        */
        void set_max_health(int);


        /**
            * \brief Setting damage
            * \param damage
        */
        void set_damage(int);



        /**
            * \brief Setting hit
            * \param hit
        */
        void set_hit(int);



        /**
            * \brief Setting experience
            * \param experience
        */
        void set_experience(int);


        /**
            * \brief Setting armor
            * \param armor
        */
        void set_armor(std::shared_ptr<Armor>);



        /**
            * \brief Setting feature
            * \param type of feature
        */
        void set_feature(type_feature);




        /**
            * \brief Getting name
            * \return name
        */
        string get_name() const;


        /**
            * \brief Getting max health
            * \return max_health
        */
        int get_max_health() const;


        /**
            * \brief Getting current health
            * \return current health
        */
        int get_curr_health() const;


        /**
            * \brief Getting damage
            * \return damage
        */
        int get_damage() const;


        /**
            * \brief Getting hit
            * \return hit
        */
        int get_hit() const;


        /**
            * \brief Getting experience
            * \return experience
        */
        int get_experience() const;


        /**
            * \brief Getting feature
            * \return type of feature
        */
        type_feature get_feature() const;


        /**
            * \brief Decreasing health
            * \param damage
        */
        void decrease_curr_health(int);


        /**
            * \brief Taking damage
            * \param damage
        */    
        void take_damage(int _damage);


        /**
            * \brief Doing damage
            * \param player, damage
        */
        void do_damage(Player& player, int _damage);


        /**
            * \brief Dropping armor after death
            * \return pointer to armor
        */
        std::shared_ptr<Armor> drop_armor();

        ~Enemy() = default;
};

#endif