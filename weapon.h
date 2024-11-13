#ifndef WEAPON_H
#define WEAPON_H

#include "object.h"

enum class type_value{ordinary, valuable};

class Weapon: public Object {
    private:
        int damage;
        type_value value;
    public:
        Weapon() = default;
        void set_damage(int);
        void set_value(type_value);

        int get_damage() const;
        type_value get_type() const;
        virtual int generate_damage();
        
        ~Weapon() = default; 
};

#endif