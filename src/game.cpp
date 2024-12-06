#include "headers/game.h"
#include <random>


#define MIN_COUNT_LEVEL 1
#define MAX_COUNT_LEVEL 10
#define MIN_LENGHT_LEVEL 2
#define MAX_LENGHT_LEVEL 10
#define MIN_WIDTH_LEVEL 3
#define MAX_WIDTH_LEVEL 10


#define PERCENTAGE_CHESTS 0.05
#define PERCENTAGE_ENEMIES 0.1


#define MIN_HEALTH_ENEMY 10
#define MAX_HEALTH_ENEMY 100
#define MIN_DAMAGE_ENEMY 1
#define MAX_DAMAGE_ENEMY 20
#define MIN_HIT_ENEMY 50
#define MAX_HIT_ENEMY 95
#define MIN_EXPERIENCE_ENEMY 5
#define MAX_EXPERIENCE_ENEMY 100


void Game::start() {
    Dungeon dungeon = generate_dungeon();
    Player player = dungeon.get_player();
    bool game_over = false;
    int width = dungeon.get_width();
    int lenght = dungeon.get_length();
    int x_to_move = player.get_point().x;
    int y_to_move = player.get_point().y;
    bool flag;


    while (!game_over) {
        // Соединить с графикой, если нажал на клавишу
        int key;
        switch (key) {
            case 0: //вверх    
                x_to_move--; 
                break;
            case 1: // вниз
                x_to_move++;
                break;
            case 2: // вправо
                y_to_move++;
                break;
            case 3: // влево
                y_to_move--;
                break;
        }

        flag = player.move(x_to_move, y_to_move, width, lenght); 
        if (flag) {
            auto entity = dungeon.get_levels()[dungeon.get_level()].get_map().get_matrix()[x_to_move][y_to_move].get_entity();
            if (std::dynamic_pointer_cast<Chest>(entity.lock())) {
                std::shared_ptr<Chest> chest = std::dynamic_pointer_cast<Chest>(entity.lock());
                std::shared_ptr<Object> object = player.open_chest(chest);
                if (object) {
                    player.take_object(object);
                }
            } else if (std::dynamic_pointer_cast<Enemy>(entity.lock())) {
                 std::shared_ptr<Enemy> enemy = (std::dynamic_pointer_cast<Enemy>(entity.lock()));
                //если нажал кнопку удара
                int damage = player.generate_damage();
                enemy->take_damage(damage);
                if (enemy->get_curr_health() > 0)
                    enemy->do_damage(player, enemy->get_damage());
            } else if (std::dynamic_pointer_cast<Door>(entity.lock())) {
                Door door = (*std::dynamic_pointer_cast<Door>(entity.lock()));
                player.open_door(door);
            } else if (std::dynamic_pointer_cast<Stairs>(entity.lock())) {
                Stairs stairs = (*std::dynamic_pointer_cast<Stairs>(entity.lock()));
                auto door = dungeon.get_levels()[dungeon.get_level()].get_map().get_matrix()[x_to_move][y_to_move - 1].get_entity();
                if (std::dynamic_pointer_cast<Door>(entity.lock())->get_type() == 
                    type_of_door::opened && stairs.get_type() == type_of_stairs::down) {
                    if (dungeon.get_level() < dungeon.get_levels().size()) {
                        dungeon.set_level(dungeon.get_level() + 1);
                    } else {
                        game_over = true;
                    }
                }
            }
        }
        
        //если нажал кнопку выпить зелье
        int number = 0; //какое зелье
        player.drink_potion(number);

        if (player.get_characteristics().get_characteristic(
                                            type_of_characteristic::curr_health) <= 0) {
             game_over = true;
        }
    }

}

Dungeon Game::generate_dungeon() {
    int level_count = random_value(MIN_COUNT_LEVEL, MAX_COUNT_LEVEL);
    int length = random_value(MIN_LENGHT_LEVEL, MAX_LENGHT_LEVEL);
    int width = random_value(MIN_WIDTH_LEVEL, MAX_WIDTH_LEVEL);
    Dungeon dungeon;
    Player player = generate_player(Point(0, 0));
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<Level> levels;

    dungeon.set_length(length);
    dungeon.set_width(width);
    dungeon.set_level(0);

    for (int i = 0; i < level_count; ++i) {
        levels.push_back(generate_level(length, width, i, enemies));
    }
    dungeon.set_player(player);
    dungeon.set_enemies(enemies);
    levels[0].get_map().get_matrix()[0][0] = Cell(Point(0, 0), std::make_shared<Player>(player));
    return dungeon;
}

Level Game::generate_level(int length, int width, int lvl, std::vector<std::shared_ptr<Enemy>>& enemies) {
    std::vector<std::vector<Cell>> _matrix(width, std::vector<Cell>(length));
    Matrix matrix;
    matrix.set_matrix(_matrix);
    Level level(matrix);
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < length; ++y) {
            if (x == 0 && y == 0) {
                level.get_map().get_matrix()[x][y] = Cell(Point(x, y), 
                                                std::make_shared<Stairs>(Point(x,y), 
                                                type_of_stairs::up));
            };
            if (x == width - 1 && y == length -1) {
                level.get_map().get_matrix()[x][y] = Cell(Point(x, y),
                                                std::make_shared<Stairs>(Point(x,y),
                                                type_of_stairs::down));
            } else {
                level.get_map().get_matrix()[x][y] = Cell(Point(x, y), std::make_shared<Floor>());
                
            }
        }
    }


    int chest_count = length * width * PERCENTAGE_CHESTS;
    int enemy_count = random_value(length * width * PERCENTAGE_ENEMIES - 1, length * width * PERCENTAGE_ENEMIES + 2);
    Point point = find_free_point(level, width, length);
    LockPicks lock_picks = generate_lock_picks();
    Chest chest = generate_chest(point);
    chest.set_object(std::make_shared<Object>(lock_picks));
    level.get_map().get_matrix()[point.x][point.y] = Cell(point, std::make_shared<Chest>(chest));
    point = find_free_point(level, width, length);
    lock_picks = generate_lock_picks();
    chest = generate_chest(point);
    chest.set_object(std::make_shared<Object>(lock_picks));
    level.get_map().get_matrix()[point.x][point.y] = Cell(point, std::make_shared<Chest>(chest));
    Enemy enemy;
    point = find_free_point(level, width, length);
    for (int i = 0; i < chest_count; ++i) {
        point = find_free_point(level, width, length);
        level.get_map().get_matrix()[point.x][point.y] = Cell(point, std::make_shared<Chest>());
    }
    for (int i = 0; i < enemy_count; ++i) {
        point = find_free_point(level, width, length);
        enemy = generate_enemy(point);
        level.get_map().get_matrix()[point.x][point.y] = Cell(point, std::make_shared<Enemy>(enemy)); 
        enemies.push_back(std::make_shared<Enemy>(enemy));
    }
    return Level();
}



Enemy Game::generate_enemy(Point _point) {

    std::vector<std::string> names = {"Goblin", "Orc", "Skeleton", "Spider", "Ice Golem", "Dwarf Warrior"}; 
    std::string randomName = names[random_value(0, names.size() - 1)];
    int random_max_health = random_value(MIN_HEALTH_ENEMY, MAX_HEALTH_ENEMY);
    int random_damage = random_value(MIN_DAMAGE_ENEMY, MAX_DAMAGE_ENEMY);
    int random_hit = random_value(MIN_HIT_ENEMY, MAX_HIT_ENEMY);
    int random_experience = random_value(MIN_EXPERIENCE_ENEMY, MAX_EXPERIENCE_ENEMY);
    type_feature random_feature = static_cast<type_feature>(random_value(0,
                                            static_cast<int>(type_feature::dwarf)));

    
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
        while(characteristics.find_characteristic(static_cast<type_of_characteristic>
                (type_characteristic))!=-1) {
                    type_characteristic = random_value(0, static_cast<int>(type_of_characteristic::curr_health));
        }
        characteristics.change_value_characteristic(static_cast<type_of_characteristic>(type_characteristic), value);
        value = random_value(min, max);
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
    player.set_characteristics(generate_characteristics(static_cast<int>(type_of_characteristic::curr_health),
            50, 100));
    player.set_max_poitions(random_value(2, 5));
    player.set_weapon(std::make_shared<Weapon>(Weapon("Stick", 5, type_value::ordinary)));
    return player;
}




Point Game::find_free_point(const Level& level, int width, int length) {
    int x = random_value(0, width);
    int y = random_value(0, length);
    std::shared_ptr<Entity> entity = level.get_map().get_matrix()[x][y].get_entity().lock();
    while(!std::dynamic_pointer_cast<Floor>(entity)) {
            x = random_value(0, width);
            y = random_value(0, length);
    }
    return Point(x, y);
}

int Game::random_value(int min, int max) {
    std::mt19937 eng {std::random_device{}()};
    std::uniform_int_distribution distr{min, max};
    return distr(eng);
}