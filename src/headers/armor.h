#ifndef ARMOR_H
#define ARMOR_H

#include "object.h"

enum class type_of_armor{helmet, breastplate, gauntlet, pauldron, greaves, sabaton};

class Armor: public Object {
    private:
        type_of_armor type;
        int protection;
    public:
        Armor() = default;
        Armor(type_of_armor _type, int _protection): Object(), type(_type), protection(_protection) {};
        void set_type(type_of_armor);
        void set_protection(int);
        type_of_armor get_type() const;
        int get_protection() const;
        ~Armor() = default;
};

#endif