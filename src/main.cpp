// #include <iostream>
// #include "headers/matrix.h"


// int main() {
//     Vector<int> a = {};
//     a.push_back(17);
//     a.push_back(127);
//     a.print_vector();
//     a.remove();
//     a.print_vector();
    
//     static_assert(std::random_access_iterator<VectorIter<int, false>>);
//     static_assert(std::random_access_iterator<VectorIter<int, true>>);
//     std::cout<<"hi"<<std::endl;
// }


#include <SFML/Graphics.hpp>
#include <vector>
#include "headers/game.h"

using namespace sf;



void draw_entities(Dungeon&, RenderWindow&, std::vector<RectangleShape>&, float);


int main() {
    Game game;
    Dungeon dungeon = game.generate_dungeon();
    game.set_dungeon(dungeon);

    std::vector<RectangleShape> shapes;
    RenderWindow window(sf::VideoMode(1280, 1024), "Dungeon");
    float tileSize = 128.f;


    Texture floor_texture;
    Texture player_texture;
    Texture chest_texture;
    Texture stairs_texture;
    Texture door_closed_texture;
    Texture door_opened_texture;
    Texture ice_golem_texture;
    Texture earth_golem_texture;
    Texture minotaur_texture;
    


    const int windowWidth = 1280;
    const int windowHeight = 1024;

    // Настройки сетки
    const int gridWidth = 9;
    const int gridHeight = 11;
    // float tileSize = std::min((float)windowWidth / gridWidth, (float)windowHeight / gridHeight);
    
    // Вектор для хранения линий
    std::vector<sf::VertexArray> lines;

    // Создаем вертикальные линии
    for (int x = 0; x <= gridWidth; ++x) {
        sf::VertexArray verticalLine(sf::Lines, 2);
        verticalLine[0].position = sf::Vector2f(x * tileSize, 0);
        verticalLine[1].position = sf::Vector2f(x * tileSize, windowHeight);
        verticalLine[0].color = sf::Color::Black;
        verticalLine[1].color = sf::Color::Black;
        lines.push_back(verticalLine);
    }

    // Создаем горизонтальные линии
    for (int y = 0; y <= gridHeight; ++y) {
      sf::VertexArray horizontalLine(sf::Lines, 2);
        horizontalLine[0].position = sf::Vector2f(0, y * tileSize);
        horizontalLine[1].position = sf::Vector2f(windowWidth, y * tileSize);
        horizontalLine[0].color = sf::Color::Black;
        horizontalLine[1].color = sf::Color::Black;
        lines.push_back(horizontalLine);
    }



    RectangleShape gaming_background(Vector2f(1280, 1024));
    RectangleShape player(Vector2f(1280 / game.get_dungeon().get_length() * 4 / 5, 1024 / game.get_dungeon().get_width() * 10 / 9 * 4 / 5));
    RectangleShape chest(Vector2f(1280 / game.get_dungeon().get_length() * 2 / 3, 1024 / game.get_dungeon().get_width() * 9 / 10 * 2 / 3));
    RectangleShape stairs(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));
    RectangleShape door_closed(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));
    RectangleShape door_opened(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));
    RectangleShape ice_golem(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));
    RectangleShape earth_golem(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));
    RectangleShape minotaur(Vector2f(1280 / game.get_dungeon().get_length(), 1024 / game.get_dungeon().get_width()));



    if (!floor_texture.loadFromFile("img/dungeon.jpg")) return 1;
    if (!player_texture.loadFromFile("img/hero.png")) return 1;
    if (!chest_texture.loadFromFile("img/chest.png")) return 1;
    if (!stairs_texture.loadFromFile("img/stairs.png")) return 1;
    if (!door_closed_texture.loadFromFile("img/door_closed.png")) return 1;
    if (!door_opened_texture.loadFromFile("img/door_opened.png")) return 1;
    if (!ice_golem_texture.loadFromFile("img/ice_golem.png")) return 1;
    if (!earth_golem_texture.loadFromFile("img/earth_golem.png")) return 1;
    if (!minotaur_texture.loadFromFile("img/minotaur.png")) return 1;


    gaming_background.setTexture(&floor_texture);
    player.setTexture(&player_texture);
    chest.setTexture(&chest_texture);
    stairs.setTexture(&stairs_texture);
    door_closed.setTexture(&door_closed_texture);
    door_opened.setTexture(&door_opened_texture);
    ice_golem.setTexture(&ice_golem_texture);
    earth_golem.setTexture(&earth_golem_texture);
    minotaur.setTexture(&minotaur_texture);


    


    shapes.push_back(player);
    shapes.push_back(chest);
    shapes.push_back(stairs);
    shapes.push_back(door_closed);
    shapes.push_back(door_opened);
    shapes.push_back(ice_golem);
    shapes.push_back(earth_golem);
    shapes.push_back(minotaur);



    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (game.get_dungeon().get_player().get_characteristics().get_characteristic(type_of_characteristic::curr_health) <= 0) {
                std::cout << "LOSE" << std::endl;
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {
                std::cout << "key pressed" << std::endl;
                game.step(event.key.code);
                std::cout<< "LEVEL   " << game.get_dungeon().get_level() << std::endl;
            }
        }

        window.clear();

    
        window.draw(gaming_background);
        for(auto& line : lines) {
             window.draw(line);
        }
        

        draw_entities(game.get_dungeon(), window, shapes, tileSize);
        
        window.display();
    }

    return 0;
}

void draw_entities(Dungeon& dungeon, RenderWindow& window, std::vector<RectangleShape>& shapes,
                     float tileSize) {
    for (int x = 0; x < dungeon.get_width(); ++x) {
        for (int y = 0; y < dungeon.get_length(); ++y) {
            auto entity = dungeon.get_levels()[dungeon.get_level()].map.matrix[x][y].get_entity();
            if (std::dynamic_pointer_cast<Player>(entity)) {
                shapes[0].setPosition(static_cast<float>(y) *
                     tileSize, static_cast<float>(x) * tileSize);
                window.draw(shapes[0]);
            } else  if (std::dynamic_pointer_cast<Chest>(entity)) {
                shapes[1].setPosition(static_cast<float>(y) *
                     tileSize, static_cast<float>(x) * tileSize);
                window.draw(shapes[1]);
            } else  if (std::dynamic_pointer_cast<Stairs>(entity)) {
                shapes[2].setPosition(static_cast<float>(y) *
                    tileSize, static_cast<float>(x) * tileSize);
                    window.draw(shapes[2]);
            } else  if (std::dynamic_pointer_cast<Door>(entity)) {
                    if (std::dynamic_pointer_cast<Door>(entity).get()->get_type() == type_of_door::closed) {
                        shapes[3].setPosition(static_cast<float>(y) *
                            tileSize, static_cast<float>(x) * tileSize);
                        window.draw(shapes[3]);
                    } else {
                        shapes[4].setPosition(static_cast<float>(y) *
                            tileSize, static_cast<float>(x) * tileSize);
                        window.draw(shapes[4]);
                    }
            } else  if (std::dynamic_pointer_cast<Enemy>(entity)) {
                    if (std::dynamic_pointer_cast<Enemy>(entity).get()->get_feature() == type_feature::icy) {
                        shapes[5].setPosition(static_cast<float>(y) *
                            tileSize, static_cast<float>(x) * tileSize);
                        window.draw(shapes[5]);
                    } else if (std::dynamic_pointer_cast<Enemy>(entity).get()->get_feature() == type_feature::earth) {
                        shapes[6].setPosition(static_cast<float>(y) *
                            tileSize, static_cast<float>(x) * tileSize);
                        window.draw(shapes[6]);
                    } else if (std::dynamic_pointer_cast<Enemy>(entity).get()->get_feature() == type_feature::minotaur) {
                        shapes[7].setPosition(static_cast<float>(y) *
                            tileSize, static_cast<float>(x) * tileSize);
                        window.draw(shapes[7]);
                    }
            }
        }
    }
    return;
}
