#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

#include "custom_shape.hpp"

void makeGrid(sf::Texture &output_texture, sf::RenderWindow const &window);

int main() {
    // =============================================================================================
    //                                        CIRCLES
    // =============================================================================================

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes", sf::Style::Default);

    window.setFramerateLimit(120);

    // define a circle with radius = 200
    Particle atom(3.f);
    atom.setFillColor(sf::Color::Red);
    atom.setPosition(400, 300);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        atom.calculate_window_bounce(window);
        atom.apply(2.f);

        window.draw(atom);

        // end the current frame
        window.display();
    }

    return 0;
}

void makeGrid(sf::Texture &output_texture, sf::RenderWindow const &window) {
    auto dimension = window.getSize();
    output_texture.create(dimension.x, dimension.y);
    size_t     grid_linear_size = output_texture.getSize().x * output_texture.getSize().y * 4;
    size_t     cell_size = 50;
    sf::Uint8 *pixels = new sf::Uint8[grid_linear_size];
    for (size_t i = 0; i < window.getSize().y; ++i) {
        for (size_t j = 0; j < window.getSize().x * 4; j += 4) {
            if (i % cell_size == 0 || (j / 4) % cell_size == 0) {
                pixels[i * (window.getSize().x * 4) + j] = 0;
                pixels[i * (window.getSize().x * 4) + j + 1] = 0xff;
                pixels[i * (window.getSize().x * 4) + j + 2] = 0;
                pixels[i * (window.getSize().x * 4) + j + 3] = 0xff;
            }
        }
    }
    output_texture.update(pixels);
    delete[] pixels;
}