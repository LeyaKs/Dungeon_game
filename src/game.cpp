#include "headers/game.h"
#include <random>
#include <thread>
#include <mutex> 
#include <algorithm> 
#include <future>
#include <vector>
#include <memory>


#define MIN_COUNT_LEVEL 1
#define MAX_COUNT_LEVEL 10
#define MIN_LENGHT_LEVEL 2
#define MAX_LENGHT_LEVEL 10
#define MIN_WIDTH_LEVEL 3
#define MAX_WIDTH_LEVEL 10


#define PERCENTAGE_CHESTS 0.015
#define PERCENTAGE_ENEMIES 0.02


#define MIN_HEALTH_ENEMY 200
#define MAX_HEALTH_ENEMY 400
#define MIN_DAMAGE_ENEMY 5
#define MAX_DAMAGE_ENEMY 20
#define MIN_HIT_ENEMY 50
#define MAX_HIT_ENEMY 95
#define MIN_EXPERIENCE_ENEMY 5
#define MAX_EXPERIENCE_ENEMY 100

#define LEVEL_DOOR_PADLOCK 10
#define EXPERIENCE 10

std::mutex game_mutex;



void Game::start() {
    Dungeon dungeon = generate_dungeon();
}

result Game::process_enemy_battle(std::shared_ptr<Enemy> enemy,
                    Player& player, Dungeon& dungeon,
                    int x_to_move, int y_to_move) {
            result res;
            int damage = player.generate_damage();
            std::cout << "Generated damage by hero = " << damage << std::endl;
            std::cout << "Generated damage by enemy = " << enemy->get_damage() << std::endl;
             {
                std::lock_guard<std::mutex> lock(game_mutex);
                enemy->take_damage(damage);
            }
            std::cout << "Enemy: health = " << enemy->get_curr_health() << std::endl;
            if (enemy->get_curr_health() > 0) {
               {
                    std::lock_guard<std::mutex> lock(game_mutex);
                    enemy->do_damage(player, enemy->get_damage());
                    res.player_damage_taken = enemy->get_damage();
                }
                
            }
            else {
                {
                    std::lock_guard<std::mutex> lock(game_mutex);
                    player.change_experience(EXPERIENCE);
                    player.take_object(enemy->drop_armor());
                    dungeon.disappear(enemy->get_point());
                }
                res.enemy_defeated = true;
            }
            std::cout << "Player: health = " << player.get_characteristics().get_characteristic(type_of_characteristic::curr_health)
                << std::endl;
            return res;
}

void Game::step(sf::Keyboard::Key key) {
    Player& player = dungeon.get_player();
    // std::cout << "Player characteristics:\n\tagility "
    //             << player.get_characteristics().get_characteristic(type_of_characteristic::agility)
    //             << "\n\tcurr_health " << player.get_characteristics().get_characteristic(type_of_characteristic::curr_health)
    //             << std::endl 
    //             << "\tmax_health " << player.get_characteristics().get_characteristic(type_of_characteristic::max_health)
    //             << std::endl
    //             << "\tstrength " << player.get_characteristics().get_characteristic(type_of_characteristic::strength)
    //             << std::endl
    //             << "\texperience " << player.get_experience()
    //             << std::endl
    //             << "\tcount_lock_picks " << player.get_count_lock_picks()
    //             << std::endl;
    std::cout << "Player coords :" << player.get_point().x << " " << player.get_point().y << std::endl;
    bool game_over = false;
    int width = dungeon.get_width();
    int lenght = dungeon.get_length();
    int x_to_move = player.get_point().x;
    int y_to_move = player.get_point().y;
    bool flag;
    switch (key) {
        case sf::Keyboard::Up: //вверх    
            x_to_move--; 
            break;
        case sf::Keyboard::Down: // вниз
            x_to_move++;
            break;
        case sf::Keyboard::Right: // вправо
            y_to_move++;
            break;
        case sf::Keyboard::Left: // влево
            y_to_move--;
            break;
    }

    if (player.get_characteristics().get_characteristic(
                                        type_of_characteristic::curr_health) <= 0) {
            game_over = true;
    }
    flag = player.move(x_to_move, y_to_move, width, lenght); 
    if (flag) {
        auto entity = dungeon.get_levels()[dungeon.get_level()].map.matrix[x_to_move][y_to_move].get_entity();
        if (std::dynamic_pointer_cast<Chest>(entity)) {
            std::shared_ptr<Chest> chest = std::dynamic_pointer_cast<Chest>(entity);
            std::cout << "Chest level padlock = " << chest->get_level_padlock() << std::endl;
            std::shared_ptr<Object> object = player.open_chest(chest);
            if (object) {
                dungeon.disappear(chest->get_point());
                std::cout << "Success" << std::endl;
                player.take_object(object);
            }
        } else if (std::dynamic_pointer_cast<Enemy>(entity)) {
            std::future<result> future = std::async(std::launch::async,
                    std::bind(&Game::process_enemy_battle, this,
                    std::dynamic_pointer_cast<Enemy>(entity), std::ref(player), std::ref(dungeon), x_to_move, y_to_move));
            result res = future.get();
            if (res.enemy_defeated) {
                      std::cout << "Enemy defeated!\n";
                    } else {
                         std::cout << "Player win\n";
                    }
            
        } else if (std::dynamic_pointer_cast<Door>(entity)) {
            Door door = (*std::dynamic_pointer_cast<Door>(entity));
            if (player.open_door(door)) {
                std::dynamic_pointer_cast<Door>(entity)->set_type(type_of_door::opened);
            }
        } else if (std::dynamic_pointer_cast<Stairs>(entity)) {
            Stairs stairs = (*std::dynamic_pointer_cast<Stairs>(entity));
            auto door = dungeon.get_levels()[dungeon.get_level()].map.matrix[x_to_move][y_to_move - 1].get_entity();
            if (std::dynamic_pointer_cast<Door>(door)->get_type() == 
                type_of_door::opened && stairs.get_type() == type_of_stairs::down) {
                if (dungeon.get_level() < dungeon.get_levels().size()) {
                    dungeon.increase_level();
                    dungeon.disappear(player.get_point());
                    player.set_point(Point(0, 1));
                } else {
                    game_over = true;
                }
            }
        } else {
            dungeon.move_player(x_to_move, y_to_move);
        }
    }
    return;
}

Dungeon Game::generate_dungeon() {
    int level_count = random_value(MIN_COUNT_LEVEL, MAX_COUNT_LEVEL);
    int lenght = 10;//random_value(MIN_LENGHT_LEVEL, MAX_LENGHT_LEVEL);
    int width = 8;//random_value(MIN_WIDTH_LEVEL, MAX_WIDTH_LEVEL);
    Dungeon dungeon;
    Player player = generate_player(Point(0, 0));
    
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<Level> levels;
    dungeon.set_length(lenght);
    dungeon.set_width(width);
    // dungeon.set_level(0);
    
    for (int i = 0; i < level_count; ++i) {
        levels.push_back(std::move(generate_level(lenght, width, i, enemies)));
    }
    levels[0].map.matrix[0][0] = Cell(Point(0, 0), std::make_shared<Player>(player));
    dungeon.set_enemies(enemies);
    dungeon.set_levels(levels);
    // dungeon.set_level(0);
    dungeon.set_player(player);

    return dungeon;
}

Level Game::generate_level(int lenght, int width, int lvl, std::vector<std::shared_ptr<Enemy>>& enemies) {
    Matrix<Cell> matrix = Matrix<Cell>(width, lenght);
    // Player player = generate_player(Point(0, 0));
    

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < lenght; ++y) {
            
            if (x == 0 && y == 0 && lvl != 0) {
                Cell cell = Cell(Point(x, y), 
                                                std::make_shared<Stairs>(Point(x,y), 
                                                type_of_stairs::up));
                matrix[x][y] = cell;

            } else if (x == 0 && y == 1 && lvl != 0) {
                // Cell cell = Cell(Point(x, y), std::make_shared<Player>(player));
                // matrix[x][y] = cell;
            } else if (x == width - 1 && y == lenght - 1) {
                Cell cell = Cell(Point(x, y),
                                                std::make_shared<Stairs>(Point(x, y),
                                                type_of_stairs::down));
                matrix[x][y] = cell;
            } else if (x == width - 1 && y == lenght - 2) {
                Cell cell = Cell(Point(x, y),
                                                std::make_shared<Door>(Point(x, y),
                                                type_of_door::closed, LEVEL_DOOR_PADLOCK));
                matrix[x][y] = cell;
            } else if (x != 0 || y != 0) {
                Cell cell = Cell(Point(x, y), std::make_shared<Floor>());
                matrix[x][y] = cell;
                
            }
        }
    }
  
    Level level(matrix);


    int chest_count = lenght * width * PERCENTAGE_CHESTS;
    int enemy_count = random_value(lenght * width * PERCENTAGE_ENEMIES + 1, lenght * width * PERCENTAGE_ENEMIES + 3);
    Point point = find_free_point(level, width, lenght);
    level.map.matrix[point.x][point.y] = Cell(point, std::make_shared<Chest>(generate_chest(point)));
    std::dynamic_pointer_cast<Chest>(level.map.matrix[point.x][point.y].get_entity()).get()[0].
        set_object(std::make_shared<Object>(generate_lock_picks()));
    
    point = find_free_point(level, width, lenght);
    level.map.matrix[point.x][point.y] = Cell(point, std::make_shared<Chest>(generate_chest(point)));
    std::dynamic_pointer_cast<Chest>(level.map.matrix[point.x][point.y].get_entity()).get()[0].
        set_object(std::make_shared<Object>(generate_lock_picks()));

    Enemy enemy;
    point = find_free_point(level, width, lenght);
    for (int i = 0; i < chest_count; ++i) {
        point = find_free_point(level, width, lenght);
        level.map.matrix[point.x][point.y] = Cell(point, std::make_shared<Chest>(generate_chest(point)));
    }
    for (int i = 0; i < enemy_count; ++i) {
        point = find_free_point(level, width, lenght);
        enemy = generate_enemy(point);
        level.map.matrix[point.x][point.y] = Cell(point, std::make_shared<Enemy>(enemy)); 
        enemies.push_back(std::make_shared<Enemy>(enemy));
    }
    return level;
}



Enemy Game::generate_enemy(Point _point) {

    std::vector<std::string> names = {"Wook", "Mori"}; 
    std::string randomName = names[random_value(0, names.size() - 1)];
    int random_max_health = random_value(MIN_HEALTH_ENEMY, MAX_HEALTH_ENEMY);
    int random_damage = random_value(MIN_DAMAGE_ENEMY, MAX_DAMAGE_ENEMY);
    int random_hit = random_value(MIN_HIT_ENEMY, MAX_HIT_ENEMY);
    int random_experience = random_value(MIN_EXPERIENCE_ENEMY, MAX_EXPERIENCE_ENEMY);
    type_feature random_feature = static_cast<type_feature>(random_value(0,
                                            static_cast<int>(type_feature::minotaur)));

    
    std::shared_ptr<Armor> random_armor = std::make_shared<Armor>(generate_armor());

    return Enemy(_point, randomName, std::max(1, random_max_health), std::max(1, random_max_health), 
        std::max(0, random_damage), random_hit, random_experience, random_armor, random_feature);
}


Armor Game::generate_armor() {
  std::vector<std::string> names = { "Iron", "Steel", "Mithril", "Adamant", "Dragon", "Obsidian", "Shadow", "Frost", "Sun", "Storm", "Ancient", "Royal", "Elven", "Dwarven" };

  type_of_armor armor_type = static_cast<type_of_armor>(random_value(0, static_cast<int>(type_of_armor::sabaton)));
  int protection_value = random_value(10, 100);

  std::string name = names[random_value(0, names.size() - 1)];



  return Armor(name, armor_type, protection_value);
}


Chest Game::generate_chest(Point _point) {
    int level_padlock = random_value(1, 10);
    int object_type = random_value(0, 3);
    Object object;
    switch (object_type) {
        case 0:
            object = generate_potion();
            break;
        case 1:
            object = generate_armor();
            break;
        case 2: 
            object = generate_lock_picks();
            break;
        case 3:
            object = generate_weapon();
            break;
    }
    return Chest(_point, level_padlock, std::make_shared<Object>(object));
}

Potion Game::generate_potion() {
    int count_characteristics = random_value(1, 4);
    Potion potion;
    potion.set_characteristics(generate_characteristics(count_characteristics, 3, 10));
    return potion;
}


Characteristics Game::generate_characteristics(int count_characteristics, int min, int max) {
    int type_characteristic = random_value(0, static_cast<int>(type_of_characteristic::curr_health));
    int value = random_value(min, max);
    Characteristics characteristics;
    for (int i = 0; i < count_characteristics; ++i) {
        value = random_value(min, max);
        while(characteristics.find_characteristic(static_cast<type_of_characteristic>
                (type_characteristic))!=-1) {
                    type_characteristic = random_value(0, static_cast<int>(type_of_characteristic::curr_health));
        }
        characteristics.add_characteristic(static_cast<type_of_characteristic>(type_characteristic), value);
    }
    return characteristics;
}


LockPicks Game::generate_lock_picks() {
    int count = random_value(1, 3);
    std::string name = "Lock_picks";
    return LockPicks(name, count);
}


Weapon Game::generate_weapon() {
    std::vector<std::string> names = {"Sword", "Axe", "Dagger", "Staff", "Bow",
        "Crossbow", "Mace", "Spear"};
    bool is_enchanted = random_value(0, 1);
    int damage = random_value(1, 100);
    type_value value = (random_value(0, 1) == 0) ? type_value::ordinary : type_value::valuable;
    std::string name = names[random_value(0, names.size() - 1)];


    if (is_enchanted) {
        characteristic type = static_cast<characteristic>(random_value(0,
            static_cast<int>(characteristic::gigantic)));
        return EnchantedWeapon(name, damage, value, type);
    }
    return Weapon(name, damage, value); 
}



Player Game::generate_player(Point _point) {
    Player player;
    player.set_characteristics(generate_characteristics(static_cast<int>(type_of_characteristic::curr_health) + 1,
            50, 100));
    int diff = player.get_characteristics().get_characteristic(type_of_characteristic::max_health) - player.get_characteristics().get_characteristic(type_of_characteristic::curr_health);
    player.change_characteristic(type_of_characteristic::max_health, -diff);
    player.set_point(Point(0, 0));
    player.set_max_poitions(random_value(2, 5));
    player.set_weapon(std::make_shared<Weapon>(Weapon("Stick", 5, type_value::ordinary)));
    return player;
}




Point Game::find_free_point(Level& level, int width, int length) {
    int x = random_value(0, width - 1);
    int y = random_value(0, length - 1);
    std::shared_ptr<Entity> entity = level.map.matrix[x][y].get_entity();
    while(!std::dynamic_pointer_cast<Floor>(entity)) {
            x = random_value(0, width - 1);
            y = random_value(0, length - 1);
            entity = level.map.matrix[x][y].get_entity();
    }
    return Point(x, y);
}

int Game::random_value(int min, int max) {
    std::mt19937 eng {std::random_device{}()};
    std::uniform_int_distribution distr{min, max};
    return distr(eng);
}

Dungeon& Game::get_dungeon() {
    return dungeon;
}

