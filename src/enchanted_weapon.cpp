#include "headers/enchanted_weapon.h"


#define BOOSTER 2

int EnchantedWeapon::generate_damage(const std::shared_ptr<Enemy>& enemy) {
    type_feature type_enemy = enemy->get_feature();
    if ((type_enemy == type_feature::icy && type == characteristic::fiery) ||
        (type_enemy == type_feature::minotaur && type == characteristic::gigantic))
        return get_damage() * BOOSTER;
    return get_damage();   
}