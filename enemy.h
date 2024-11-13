#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "entity.h"
#include "armor.h"

enum class type_feature{humanoid, insect, animal, undead, demon, icym, dwarf};

class Enemy: public Entity{
    private:
        std::string name;
        int max_health;
        int curr_health;
        int damage;
        int hit;
        int experience;
        Armor armor;
        type_feature feature;
    public:
        Enemy() = default;
        void set_name(std::string);
        void set_max_health(int);
        void set_curr_health(int);
        void set_damage(int);
        void set_hit(int);
        void set_experience(int);
        void set_armor(Armor);
        void set_feature(type_feature);

        std::string get_name() const;
        int get_max_health() const;
        int get_curr_health() const;
        int get_damage() const;
        int get_hit() const;
        int get_experience() const;
        Armor get_armor() const;
        type_feature get_feature() const;
};

#endif