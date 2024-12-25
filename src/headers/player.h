/**
    * \file
    * \brief Header file with description of functions of class player
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "characteristics.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"
#include "point.h"
#include "lock_picks.h"
#include "entity.h"
#include "chest.h"
#include "door.h"


/**
    * \class Player
    * \brief Child class Player from class Entity
    * 
    * Contains characteristics, experince, set of armor, weapon, potions and lock picks
*/
class Player: public Entity{
    private:
        int experience = 0;
        Characteristics characteristics;
        std::shared_ptr<Weapon> weapon;
        std::vector<std::shared_ptr<Armor>> armor;
        std::vector<std::shared_ptr<Potion>> potions;
        int max_potions = 0;
        int count_lock_picks = 0;
    public:
        Player() = default;
        Player(Point, int, const Characteristics&, const std::shared_ptr<Weapon>&,
            const std::vector<std::shared_ptr<Armor>>&, 
            const std::vector<std::shared_ptr<Potion>>&,
            int, int);

        /**
            * \brief Setting characteristics
            * \param characteristics
        */
        void set_characteristics(const Characteristics&);

        /**
            * \brief Setting weapon
            * \param weapon
        */
        void set_weapon(const std::shared_ptr<Weapon>&);


        /**
            * \brief Setting set of armor
            * \param set of armor
        */
        void set_armor(const std::vector<std::shared_ptr<Armor>>&);

        /**
            * \brief Setting potions
            * \param apotions
        */
        void set_potions(const std::vector<std::shared_ptr<Potion>>&);

        /**
            * \brief Setting max count of potions
            * \param count
        */
        void set_max_poitions(int);



        /**
            * \brief Getting experience
            * \return experience
        */
        int get_experience() const;




        /**
            * \brief Getting characteristics
            * \return characteristics
        */
        Characteristics get_characteristics() const;


        /**
            * \brief Getting set of armor
            * \return set of armor
        */
        std::vector<std::shared_ptr<Armor>> get_armor() const;


        /**
            * \brief Getting set of potions
            * \return set of potions
        */
        std::vector<std::shared_ptr<Potion>> get_potions() const;

        /**
            * \brief Getting max count of potions
            * \return count
        */
        int get_max_potions() const;


       /**
            * \brief Getting count of lock picks
            * \param count
        */
        int get_count_lock_picks() const;

          /**
            * \brief Getting weapon
            * \return weapon
        */     
        std::shared_ptr<Weapon> get_weapon() const;


        void change_characteristic(type_of_characteristic, int);

        /**
            * \brief Changing experience
            * \param value
        */
        void change_experience(int);


 
        /**
            * \brief Changing count of lock picks
            * \param value
        */      
        void change_count_lock_picks(int);



        /**
            * \brief Taking object
            * \param object
        */
        void take_object(std::shared_ptr<Object>);



        /**
            * \brief Drinking potion
            * \param number
        */
        void drink_potion(int);



        /**
            * \brief Generating damage
            * \return damage
        */
        int generate_damage();


        /**
            * \brief Taking damage
            * \param damage
        */       
        bool take_damage(int);


        /**
            * \brief Opening chest
            * \return pointer to object or nullptr
        */
        std::shared_ptr<Object> open_chest(std::shared_ptr<Chest>&);

        /**
            * \brief Improving characteristic
            * \param characteristic, value
        */
        void improve_characteristic(std::shared_ptr<Characteristic>&, int);

        /**
            * \brief moving
            * \param x, y, width, lenght
            * \return bool value, success of operation
        */
        bool move(int, int, int, int);

        /**
            * \brief Opening door
            * \param door
        */
        bool open_door(Door&);
        ~Player() = default;
};

#endif