#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode(480, 320), "SFML works!");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // set the mouse position, if the 2nd argument is not specified,
    // it use the position of the mouse pointer relative to the desktop.
    sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);

    while (window.isOpen()) {
        // mouse examples

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "mouse left button is pressed\n";
        }

        // get the mouse position, if the 1st argument is not specified,
        // it use the position of the mouse pointer relative to the desktop.
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        // keyboard examples
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            std::cout << "character moved to left\n";
            sf::Mouse::setPosition(
              sf::Vector2i((window.getSize().x + (localPosition.x - 3)) % window.getSize().x, localPosition.y), window
            );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            std::cout << "character moved to right\n";
            sf::Mouse::setPosition(sf::Vector2i((localPosition.x + 3) % window.getSize().x, localPosition.y), window);
        }

        // joystick - joystick number 0 is connected
        if (sf::Joystick::isConnected(0)) {

            // check how many buttons joystick number 0 has
            unsigned int buttonCount = sf::Joystick::getButtonCount(0);

            // check if joystick number 0 has a Z axis
            bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

            // you would want to move the previous joystick checks and setups above outside
            // of the game loop in a real game implementation to avoid performance issues

            if (sf::Joystick::isButtonPressed(0, 1)) {
                // yes: shoot!
                std::cout << "fire button\n";
            }

            // what's the current position of the X and Y axes of joystick number 0?
            float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
            float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

            std::cout << "move (x, y) = " << '(' << x << ", " << y << ")\n";
        }

        window.clear();
        window.display();
    }

    return 0;
}

// clang++ main.cpp -o sfml-app.out -lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window
// -lsfml-system