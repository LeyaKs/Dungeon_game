#include "headers/weapon.h"

#define WEAPON_BOOSTER 1

void Weapon::set_damage(int _damage) {
    damage = _damage;
}

void Weapon::set_value(type_value _value) {
    value = _value;
}

int Weapon::get_damage() const {
    return damage;
}

type_value Weapon::get_type() const {
    return value;
}



int Weapon::generate_damage(const std::shared_ptr<Enemy>&) {
    return damage * WEAPON_BOOSTER;
}
