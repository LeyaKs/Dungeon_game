#ifndef ENCHANTED_WEAPON_H
#define ENCHANTED_WEAPON_H

#include "vector"
#include "weapon.h"

class EnchantedWeapon: public Weapon {
    public:
        EnchantedWeapon() = default;
        int generate_damage() override;
        ~EnchantedWeapon() = default;
};

#endif