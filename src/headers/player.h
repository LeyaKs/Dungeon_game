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

class Player: public Entity{
    private:
        int experience;
        Characteristics characteristics;
        std::shared_ptr<Weapon> weapon;
        std::vector<std::shared_ptr<Armor>> armor;
        std::vector<std::shared_ptr<Potion>> potions;
        int max_potions;
        int count_lock_picks;
    public:
        Player() = default;
        Player(Point, int, Characteristics, std::shared_ptr<Weapon>,
            std::vector<std::shared_ptr<Armor>>, 
            std::vector<std::shared_ptr<Potion>>,
            int, int);
        void set_experience(int);
        void set_characteristics(Characteristics);
        void set_weapon(std::shared_ptr<Weapon>);
        void set_armor(std::vector<std::shared_ptr<Armor>>);
        void set_potions(std::vector<std::shared_ptr<Potion>>);
        void set_max_poitions(int);
        void set_count_lock_picks(int);

        int get_experience() const;
        Characteristics get_characteristics() const;
        std::vector<std::shared_ptr<Armor>> get_armor() const;
        std::vector<std::shared_ptr<Potion>> get_potions() const;
        int get_max_poitions() const;
        int get_count_lock_picks() const;
        std::shared_ptr<Weapon> get_weapon() const;

        void take_object(std::shared_ptr<Object>);
        void drink_potion(int);
        int generate_damage();
        bool take_damage(int);
        std::shared_ptr<Object> open_chest(std::shared_ptr<Chest>);
        void improve_characteristic(std::shared_ptr<Characteristic>, int);
        bool move(int, int, int, int);
        bool open_door(Door);
        ~Player() = default;
};

#endif