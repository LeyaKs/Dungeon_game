/**
    * \file
    * \brief Header file with description of functions of class enchanted_weapon
*/

#ifndef ENCHANTED_WEAPON_H
#define ENCHANTED_WEAPON_H

#include <memory>
#include "vector"
#include "weapon.h"
#include "enemy.h"


/**
    * \enum characteristic
    * \brief Enum class characteristic with available variant of characteristic
*/
enum class characteristic{psychological, slipper, snares,
                         illuminated, prayerful, fiery, gigantic};


/**
    * \class EnchantedWeapon
    * \brief Child class EnchantedWeapon from class Weapon
    * 
    * Contains characteristic type, constructors and functions
*/
class EnchantedWeapon: public Weapon {
    private:
        characteristic type;
    public:
        EnchantedWeapon() = default;
        EnchantedWeapon(std::string _name, int _damage, type_value _value, 
            characteristic _type): Weapon(_name, _damage, _value), type(_type){};


        /**
            * \brief Generating damage
            * \param enemy
            * \return damage
        */        
        int generate_damage(const std::shared_ptr<Enemy>& enemy) override;
        ~EnchantedWeapon() = default;
};

#endif