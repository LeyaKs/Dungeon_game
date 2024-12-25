#include "headers/enemy.h"


Enemy::Enemy(Point _entity, string _name, int _max_health, int _curr_health,
             int _damage, int _hit, int _experience, const std::shared_ptr<Armor>& _armor, type_feature _feature)
     : Entity(_entity),
       name(_name), 
       max_health(_max_health), 
       curr_health(_curr_health),
       damage(_damage),
       hit(_hit),
       experience(_experience),
       armor(_armor),
       feature(_feature)
{}



void Enemy::set_name(string _name) {
    name = _name;
}

void Enemy::set_max_health(int _max_health) {
    max_health = _max_health;
}

void Enemy::set_damage(int _damage) {
    damage = _damage;
}

void Enemy::set_hit(int _hit) {
    hit = _hit;
}

void Enemy::set_experience(int _experience) {
    experience = _experience;
}

void Enemy::set_armor(std::shared_ptr<Armor> _armor) {
    armor = std::move(_armor);
}

void Enemy::set_feature(type_feature _feature) {
    feature = _feature;
}

void Enemy::decrease_curr_health(int damage) {
    curr_health -= damage;
}

string Enemy::get_name() const {
    return name;
}

int Enemy::get_max_health() const {
    return max_health;
}

int Enemy::get_curr_health() const {
    return curr_health;
}

int Enemy::get_damage() const {
    return damage;
}

int Enemy::get_hit() const {
    return hit;
}

int Enemy::get_experience() const {
    return experience;
}


type_feature Enemy::get_feature() const {
    return feature;
}



void Enemy::take_damage(int _damage) {
    decrease_curr_health(_damage);
}

void Enemy::do_damage(Player& player, int _damage) {
    player.change_characteristic(type_of_characteristic::curr_health, -_damage);
}

std::shared_ptr<Armor> Enemy::drop_armor() {
    return armor;
}