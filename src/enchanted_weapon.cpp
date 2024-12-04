#include "headers/enchanted_weapon.h"


#define BOOSTER 2

int EnchantedWeapon::generate_damage(std::shared_ptr<Enemy> enemy) {
    type_feature type_enemy = (*enemy).get_feature();
    if ((type_enemy == type_feature::humanoid && 
        type == characteristic::psychological) ||
        (type_enemy == type_feature::insect && type == characteristic::slipper) ||
        (type_enemy == type_feature::animal && type == characteristic::snares) || 
        (type_enemy == type_feature::undead && type == characteristic::illuminated) ||
        (type_enemy == type_feature::demon && type == characteristic::prayerful) || 
        (type_enemy == type_feature::icy && type == characteristic::fiery) ||
        (type_enemy == type_feature::dwarf && type == characteristic::gigantic))
        return get_damage() * BOOSTER;
    return get_damage();   
}