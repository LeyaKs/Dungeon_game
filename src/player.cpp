#include "headers/player.h"
#include <memory>
#include <algorithm>

#define MIN_DAMAGE 5
#define AGILITY 10

Player::Player(int _experience, Characteristics _characteristics, std::shared_ptr<Weapon> _weapon, std::vector<std::shared_ptr<Armor>> _armor, std::vector<std::shared_ptr<Potion>> _potions, int _max_potions, int _count_lock_picks) {
    experience = _experience;
    characteristics = _characteristics;
    weapon = std::move(_weapon);
    armor = std::move(_armor);
    potions = std::move(_potions);
    count_lock_picks = _count_lock_picks;
}

void Player::set_experience(int _experience) {
    experience = _experience;
}

void Player::set_characteristics(Characteristics _characteristics) {
    characteristics = _characteristics;
}

void Player::set_armor(std::vector<std::shared_ptr<Armor>> _armor) {
    armor = std::move(_armor);
}

void Player::set_potions(std::vector<std::shared_ptr<Potion>> _potions) {
    potions = std::move(_potions);
}

void Player::set_weapon(std::shared_ptr<Weapon> _weapon) {
    weapon = std::move(_weapon);
}

void Player::set_max_poitions(int _max_potions) {
    max_potions = _max_potions;
}

void Player::set_count_lock_picks(int _count_lock_picks) {
    count_lock_picks = _count_lock_picks;
}

int Player::get_experience() const {
    return experience;
}

Characteristics Player::get_characteristics() const {
    return characteristics;
}

std::vector<std::shared_ptr<Armor>> Player::get_armor() const {
    return armor;
}

std::vector<std::shared_ptr<Potion>> Player::get_potions() const {
    return potions;
}

int Player::get_max_poitions() const {
    return max_potions;
}

int Player::get_count_lock_picks() const {
    return count_lock_picks;
}

void Player::take_object(std::shared_ptr<Object> object) {
    if (object) {
        if (auto _weapon = std::dynamic_pointer_cast<Weapon>(object)) {
            if (_weapon) set_weapon(_weapon);
        } else if (auto _armor = std::dynamic_pointer_cast<Armor>(object)) {
            if (_armor) {
                auto it = std::find_if(armor.begin(), armor.end(),
                                    [&](const std::shared_ptr<Armor>& a) {
                                        return a->get_type() == _armor->get_type();
                                    });
                if (it == armor.end()) {
                    armor.push_back(_armor);
                }
            }
        } else if (auto _potion = std::dynamic_pointer_cast<Potion>(object)) {
            if (_potion) {
                if (potions.size() < max_potions) {
                    potions.push_back(_potion);
                }
            }
        } else if (auto lockpicks = std::dynamic_pointer_cast<LockPicks>(object)) {
            if (lockpicks) count_lock_picks++;
        }
    }
}

void Player::drink_potion(std::shared_ptr<Potion> _potion) {
    for (int i = 0; i < _potion->get_characteristics().get_count(); ++i) {
        improve_characteristic(_potion->get_characteristics().get_characteristics()[i], _potion->get_values()[i]);
    }
}

int Player::generate_damage() {
    if (characteristics.get_characteristic(type_of_characteristic::agility) > AGILITY)
        return characteristics.get_characteristic(type_of_characteristic::strength);
    return MIN_DAMAGE;
}

bool Player::take_damage(int _damage) {
    characteristics.set_characteristic(type_of_characteristic::curr_health, characteristics.get_characteristic(type_of_characteristic::curr_health) - _damage);
    if (characteristics.get_characteristic(type_of_characteristic::curr_health) <= 0)
        return false;
    return true;
}

void Player::improve_characteristic(std::shared_ptr<Characteristic> _characteristic, int _value) {
    if (_characteristic) {
        int index = characteristics.find_characteristic(_characteristic->get_type());
        if (index >= 0) {
            characteristics.get_characteristics()[index]->set_value(characteristics.get_characteristics()[index]->get_value() + _value);
        }
    }
}
