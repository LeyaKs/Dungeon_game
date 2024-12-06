#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "player.h"
#include "entity.h"
#include "armor.h"

using std::string;

enum class type_feature{humanoid, insect, animal, undead, demon, icy, dwarf};


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
                
        void set_name(string);
        void set_max_health(int);
        void set_damage(int);
        void set_hit(int);
        void set_experience(int);
        void set_armor(std::shared_ptr<Armor>);
        void set_feature(type_feature);

        string get_name() const;
        int get_max_health() const;
        int get_curr_health() const;
        int get_damage() const;
        int get_hit() const;
        int get_experience() const;
        type_feature get_feature() const;


        void decrease_curr_health(int);
        void take_damage(int _damage);
        void do_damage(Player& player, int _damage);
        std::shared_ptr<Armor> drop_armor();

        ~Enemy() = default;
};

#endif