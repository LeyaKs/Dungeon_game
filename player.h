#ifndef PLQYER_H
#define PLAYER_H

#include <vector>
#include "characteristics.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"

class Player {
    private:
        int experience;
        Characteristics characteristics;
        Weapon weapon;
        std::vector<Armor *> armor;
        std::vector<Potion *> potions;
        int max_potions;
        int count_lock_picks;
    public:
        Player() = default;
        void set_experience(int);
        void set_characteristics(Characteristics);
        void set_armor(std::vector<Armor *>);
        void set_potions(std::vector<Potion *>);
        void set_max_poitions(int);
        void set_count_lock_picks(int);

        int get_experience() const;
        Characteristics get_characteristics() const;
        std::vector<Armor> get_armor() const;
        std::vector<Potion> get_potions() const;
        int get_max_poitions() const;
        int get_count_lock_picks() const;

        void take_object(Object *);
        void drink_potion(Potion *);
        int generate_damage();
        void take_damage(int);
        void improve_characteristic(Characteristic);
        ~Player() = default;
};

#endif