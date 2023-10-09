#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <functional>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <vector>

#include <chrono>

#include "TileMap.hpp"

int main() {
    // create a view with the rectangular area of the 2D world to show
    sf::View game_view(sf::FloatRect(150.f, 150.f, 512.f, 350.f));
    float    view_move_distance = 5.f, view_rotation_angle = 2.f;

    sf::CircleShape player(20.f);
    player.setFillColor(sf::Color::Red);
    player.setOrigin(20.f, 20.f);
    player.setPosition(game_view.getCenter());

    sf::RenderWindow window(sf::VideoMode(512, 350), "My window");
    window.setFramerateLimit(120);

    // if you used an `sf::View` with a `rectWidth` x `rectHeight` that is not equivalent to the `sf::Window`
    // `rectWidth` x `rectHeight`, the displayed View will wrap to fit the window size
    window.setView(game_view);

    const int level[] = {
      1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 3, 3, 3, 3, 3, 3,
      0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
      0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2,
      0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0,
      0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3,
      1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0,
      1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0,
      0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0,
      0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3,
      3, 3, 3, 3, 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0,
      3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 1, 0, 0, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 0, 3, 3, 3, 3, 3, 3,
    };

    TileMap map;
    if (!map.load1("../assets/tileset.png", sf::Vector2u(32, 32), level, 38, 15)) {
        std::cerr << "Error loading tileset\n";
        return -1;
    }

    std::vector<sf::CircleShape> clicked_areas;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::Q) {
                    window.close();
                }

                // move the view center relative to it's position
                if (event.key.scancode == sf::Keyboard::Scan::Up) {
                    game_view.move(0.f, -view_move_distance);
                }

                // move the view center a certain position
                if (event.key.scancode == sf::Keyboard::Scan::Down) {
                    game_view.setCenter(game_view.getCenter().x, game_view.getCenter().y + view_move_distance);
                }

                // move the view center a certain position
                if (event.key.scancode == sf::Keyboard::Scan::Left) {
                    game_view.setCenter(game_view.getCenter().x - view_move_distance, game_view.getCenter().y);
                }

                // move the view center relative to it's position
                if (event.key.scancode == sf::Keyboard::Scan::Right) {
                    game_view.move(view_move_distance, 0.f);
                }

                // zoom in the view
                if (event.key.scancode == sf::Keyboard::Scan::Equal) {
                    game_view.zoom(0.95f);
                }

                // zoom out the view
                if (event.key.scancode == sf::Keyboard::Scan::Hyphen) {
                    game_view.zoom(1.05f);
                }

                // rotate the view on a certain angle
                if (event.key.scancode == sf::Keyboard::Scan::Num9) {
                    auto rotation = game_view.getRotation();
                    game_view.rotate(-view_rotation_angle);
                }

                // relatively rotate the view
                if (event.key.scancode == sf::Keyboard::Scan::Num0) {
                    auto rotation = game_view.getRotation();
                    game_view.setRotation(std::fmod(rotation + view_rotation_angle, 360.f));
                }

                if (event.key.scancode == sf::Keyboard::Scan::Escape) {
                    window.setView(window.getDefaultView());
                }

                window.setView(game_view);
            }

            // converting window position to 2D world position
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::CircleShape clicked_area(5.f);
                    clicked_area.setFillColor(sf::Color::Yellow);
                    clicked_area.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                    clicked_areas.push_back(clicked_area);
                }
            }
        }

        player.setPosition(game_view.getCenter());

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(map);
        window.draw(player);
        for (auto &clicked_area: clicked_areas) {
            window.draw(clicked_area);
        }

        window.display();
    }

    return 0;
}