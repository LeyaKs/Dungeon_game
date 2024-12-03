#ifndef ENCHANTED_WEAPON_H
#define ENCHANTED_WEAPON_H

#include <memory>
#include "vector"
#include "weapon.h"
#include "enemy.h"

enum class characteristic{psychological, slipper, snares, illuminated, prayerful, fiery, gigantic};

class EnchantedWeapon: public Weapon {
    private:
        characteristic type;
    public:
        EnchantedWeapon() = default;
        EnchantedWeapon(characteristic _type): Weapon(), type(_type){};
        int generate_damage(std::shared_ptr<Enemy>) override;
        ~EnchantedWeapon() = default;
};

#endif