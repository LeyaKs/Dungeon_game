#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "headers/game.h"

TEST_CASE("Dungeon generation") {
    Game game;
    Dungeon dungeon = game.generate_dungeon();
    game.set_dungeon(dungeon);
    Dungeon dungeon1 = Dungeon(dungeon.get_player(), dungeon.get_enemies(), 
            dungeon.get_level(), dungeon.get_levels(), dungeon.get_length(),
            dungeon.get_width());
    REQUIRE(dungeon.get_enemies().size()>0);
    REQUIRE(dungeon.get_levels().size()>0);
    REQUIRE(dungeon.get_level() == 0);
    REQUIRE(dungeon.get_enemies().size()>0);
    REQUIRE(dungeon.get_player().get_point().x == 0);
    REQUIRE(dungeon.get_player().get_point().y == 0);
    REQUIRE(dungeon.get_length() > 0);
    REQUIRE(dungeon.get_width() > 0);
    REQUIRE(game.get_dungeon().get_levels()[0].map.matrix[0][0].get_entity().get());
    dungeon.increase_level();
    dungeon.move_player(0, 0);

}

TEST_CASE("Weapon") {
    Weapon weapon;
    weapon.set_damage(5);
    weapon.set_value(type_value::ordinary);
    REQUIRE(weapon.get_damage() == 5);
    REQUIRE(weapon.get_type() == type_value::ordinary);
    REQUIRE(weapon.generate_damage() == 5);

}

TEST_CASE("Stairs") {
    Stairs stairs;
    stairs.set_type(type_of_stairs::up);
    REQUIRE(stairs.get_type() == type_of_stairs::up);
}



TEST_CASE("Object") {
    Object object;
    object.set_name("Q");
    REQUIRE(object.get_name() == "Q");
}

TEST_CASE("LockPicks") {
    LockPicks lockpicks;
    lockpicks.change_count(5);
    REQUIRE(lockpicks.get_count() == 5);
}

TEST_CASE("Player") {
    Game game;
    Dungeon dungeon = game.generate_dungeon();
    game.set_dungeon(dungeon);
    Characteristics characteristics;
    characteristics.add_characteristic(type_of_characteristic::agility, 5);
    Weapon weapon;
    weapon.set_damage(5);
    std::vector<std::shared_ptr<Armor>> armor;
    std::vector<std::shared_ptr<Potion>> potions;
    Player player = dungeon.get_player();
    Player player1 = Player(Point(0, 0), 5, characteristics, std::make_shared<Weapon>(weapon), armor,
               potions, 5, 5);
    player.set_armor(armor);
    player.set_potions(potions);
    REQUIRE(player1.get_experience() == 5);
    REQUIRE(player1.get_armor().size() == 0);
    REQUIRE(player1.get_potions().size() == 0);
    REQUIRE(player1.get_max_potions() == 0);
    REQUIRE(player1.get_count_lock_picks() == 5);
    REQUIRE(player1.get_weapon());
    player1.change_experience(5);
    player1.change_count_lock_picks(5);
    LockPicks lockpicks;
    lockpicks.set_name("P");
    player.take_object(std::dynamic_pointer_cast<Object>(std::make_shared<LockPicks>(lockpicks)));
    player.take_object(std::dynamic_pointer_cast<Object>(std::make_shared<Weapon>(weapon)));
    Armor armor1;
    armor1.set_type(type_of_armor::breastplate);
    armor1.set_protection(5);
    player.take_object(std::dynamic_pointer_cast<Object>(std::make_shared<Armor>(armor1)));
    player.generate_damage();
    player1.take_damage(4);
    Chest chest;
    chest.set_level_padlock(5);
}


TEST_CASE("Armor") {
    Armor armor;
    armor.set_type(type_of_armor::breastplate);
    armor.set_protection(5);
    REQUIRE(armor.get_type() == type_of_armor::breastplate);
    REQUIRE(armor.get_protection() == 5);
}

TEST_CASE("Characteristics") {
    Characteristic char1;
    char1.set_type(type_of_characteristic::agility);
    std::vector<std::shared_ptr<Characteristic>> characteristics;
    characteristics.push_back(std::make_shared<Characteristic>(char1));
    Characteristics chars1 = Characteristics(characteristics);
    Game game;
    Dungeon dungeon = game.generate_dungeon();
    game.set_dungeon(dungeon);
    REQUIRE(dungeon.get_player().get_characteristics().get_count() == 5);
    REQUIRE(chars1.get_characteristics().size() > 0);
    
}

TEST_CASE("Chest") {
    Chest chest;
    chest.set_level_padlock(5);
    LockPicks lockpicks;
    chest.set_object(std::make_shared<LockPicks>(lockpicks));
    REQUIRE(chest.try_open(0) == nullptr);
    REQUIRE(chest.try_open(6) != nullptr);
    REQUIRE(chest.get_level_padlock() == 5);
}

TEST_CASE("Door") {
    Door door;
    door.set_type(type_of_door::closed);
    REQUIRE(door.get_level_padlock() == 0);
    REQUIRE(door.get_type() == type_of_door::closed);
}

TEST_CASE("Enchanted weapon") {
    EnchantedWeapon weapon = EnchantedWeapon("q", 5, type_value::ordinary, characteristic::gigantic);
    Enemy enemy;
    enemy.set_feature(type_feature::earth);
    int damage = weapon.generate_damage(std::make_shared<Enemy>(enemy));
    REQUIRE(damage == 5);
    enemy.set_feature(type_feature::minotaur);
    damage = weapon.generate_damage(std::make_shared<Enemy>(enemy));
    REQUIRE(damage == 10);
}

TEST_CASE("Enemy") {
    Enemy enemy;
    enemy.set_name("Boo");
    enemy.set_max_health(5);
    enemy.set_damage(5);
    enemy.set_hit(5);
    enemy.set_experience(5);
    enemy.set_feature(type_feature::earth);
    Armor armor;
    enemy.set_armor(std::make_shared<Armor>(armor));
    enemy.decrease_curr_health(0);
    REQUIRE(enemy.get_name() == "Boo");
    REQUIRE(enemy.get_max_health() == 5);
    REQUIRE(enemy.get_curr_health() == 0);
    REQUIRE(enemy.get_damage() == 5);
    REQUIRE(enemy.get_hit() == 5);
    REQUIRE(enemy.get_experience() == 5);
    REQUIRE(enemy.get_feature() == type_feature::earth);
    enemy.take_damage(3);
    Game game;
    Dungeon dungeon = game.generate_dungeon();
    game.set_dungeon(dungeon);
    enemy.do_damage(dungeon.get_player(), 1);
    enemy.drop_armor();
}


TEST_CASE("Cell") {
    Cell cell;
    Door door;
    cell.set_point(Point(0, 0));
    cell.set_entity(std::make_shared<Door>(door));
    REQUIRE(cell.get_point().x == 0);
    REQUIRE(cell.get_entity());
}