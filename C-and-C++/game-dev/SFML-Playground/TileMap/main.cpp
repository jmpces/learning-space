#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
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

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 350), "My window");
    window.setFramerateLimit(120);

    // =============================================================================================
    //                                TILE MAP CUSTOM ENTITY
    // =============================================================================================

    // define the level with an array of tile indices
    const int level[] = {
      0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
      1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
      0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
      2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    TileMap map;
    if (!map.load1("../assets/tileset.png", sf::Vector2u(32, 32), level, 16, 8)) {
        std::cerr << "Error loading tileset\n";
        return -1;
    }

    // =============================================================================================

    // run the program as long as the window is open
    while (window.isOpen()) {
        auto start = std::chrono::high_resolution_clock::now();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(map);

        // =============================================================================================
        // end the current frame

        window.display();

        // show fps

        auto   end = std::chrono::high_resolution_clock::now();
        auto   dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        double fps = 1.0 / (double) dur.count();
        std::cout << "fps : " << fps * 1000.f << "\n";
    }

    return 0;
}