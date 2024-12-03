#ifndef WEAPON_H
#define WEAPON_H

// #include "enemy.h"
#include <memory>
#include "object.h"

enum class type_value{ordinary, valuable};

class Enemy;

class Weapon: public Object {
    private:
        int damage;
        type_value value;
    public:
        Weapon() = default;
        Weapon(int _damage, type_value _value): Object(), damage(_damage), value(_value) {};
        void set_damage(int);
        void set_value(type_value);

        int get_damage() const;
        type_value get_type() const;
        virtual int generate_damage(std::shared_ptr<Enemy> = nullptr);
        ~Weapon() = default; 
};

#endif