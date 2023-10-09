#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    constexpr float PI = 3.14159265359f;
    constexpr float SINE_HALF_CYCLE = PI;

    sf::RenderWindow window;
    window.create(sf::VideoMode(200, 200), "SFML works!");
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::CircleShape shape((float) std::min(window.getSize().x, window.getSize().y) / 2.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition((float) window.getSize().x / 2.f, (float) window.getSize().y / 2.f);
    shape.setOrigin((float) window.getSize().x / 2.f, (float) window.getSize().y / 2.f);

    float sine_input = 0.f;
    float circle_scale = 0.f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // if (event.type == sf::Event::KeyPressed) {
            //     window.setPosition(sf::Mouse::getPosition());
            // }

            if (event.type == sf::Event::MouseButtonPressed) {
                window.setSize(sf::Vector2u(window.getSize().x + 10, window.getSize().y + 10));
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sine_input = std::fmod(sine_input + 0.02f, SINE_HALF_CYCLE);
        circle_scale = std::sin(sine_input);

        shape.setScale(circle_scale, circle_scale);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

// clang++ main.cpp -o sfml-app.out -lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window
// -lsfml-system