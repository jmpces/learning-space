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
    window.create(sf::VideoMode(400, 300), "SFML works!");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    auto window_dimension = window.getSize();

    sf::CircleShape shape(5.f, 5.f);

    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition((float) window_dimension.x / 2.f, (float) window_dimension.y / 2.f);
    shape.setOrigin((float) window_dimension.x / 2.f, (float) window_dimension.y / 2.f);

    sf::Mouse mouse;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }

            if (event.type == sf::Event::LostFocus) {
                std::cout << "window is inactive - game paused\n";
            }

            if (event.type == sf::Event::GainedFocus) {
                std::cout << "window is active - game resumed\n";
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    std::cout << "wheel type: vertical" << std::endl;
                } else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
                    std::cout << "wheel type: horizontal" << std::endl;
                } else {
                    std::cout << "wheel type: unknown" << std::endl;
                }
                std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
            }

            if (event.type == sf::Event::MouseMoved) {
                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl << std::endl;
            }

            if (event.type == sf::Event::MouseEntered) {
                std::cout << "the mouse cursor has entered the window" << std::endl;
            }

            if (event.type == sf::Event::MouseLeft) {
                std::cout << "the mouse cursor has left the window" << std::endl;
            }
        }

        shape.setPosition(mouse.getPosition().x, mouse.getPosition().y);

        window.clear();

        window.draw(shape);

        window.display();
    }

    return 0;
}

// clang++ main.cpp -o sfml-app.out -lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window
// -lsfml-system