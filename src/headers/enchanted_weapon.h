#ifndef ENCHANTED_WEAPON_H
#define ENCHANTED_WEAPON_H

#include <memory>
#include "vector"
#include "weapon.h"
#include "enemy.h"

enum class characteristic{psychological, slipper, snares,
                         illuminated, prayerful, fiery, gigantic};

class EnchantedWeapon: public Weapon {
    private:
        characteristic type;
    public:
        EnchantedWeapon() = default;
        EnchantedWeapon(std::string _name, int _damage, type_value _value, 
            characteristic _type): Weapon(_name, _damage, _value), type(_type){};
        int generate_damage(const std::shared_ptr<Enemy>& enemy) override;
        ~EnchantedWeapon() = default;
};

#endif