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
        Weapon(std::string _name, int _damage, type_value _value): Object(_name),
            damage(_damage), value(_value) {};
        void set_damage(int);
        void set_value(type_value);

        int get_damage() const;
        type_value get_type() const;
        virtual int generate_damage(const std::shared_ptr<Enemy>& = nullptr);
        virtual ~Weapon() = default; 
};

#endif