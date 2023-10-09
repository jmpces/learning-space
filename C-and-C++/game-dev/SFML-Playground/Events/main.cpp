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
    window.create(sf::VideoMode(200, 200), "SFML works!");

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    auto window_dimension = window.getSize();

    sf::CircleShape shape((float) std::min(window_dimension.x, window_dimension.y) / 2.f);

    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition((float) window_dimension.x / 2.f, (float) window_dimension.y / 2.f);
    shape.setOrigin((float) window_dimension.x / 2.f, (float) window_dimension.y / 2.f);

    std::vector<std::string> words;
    std::string              word = "";

    bool is_typing = false;

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

            if (is_typing && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 3) {
                    std::cout << "ctrl+c - close\n";
                    window.close();
                } else if (event.text.unicode == 13) {
                    std::cout << "Entered\n";
                    words.push_back(word);
                    word = "";
                } else if (event.text.unicode < 128) {
                    std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode)
                              << " | code : " << event.text.unicode << std::endl;
                    word += static_cast<char>(event.text.unicode);
                }
            }

            if (!is_typing && event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::Escape) {
                    std::cout << "\nthe escape key was pressed" << std::endl;
                    std::cout << "scancode: " << event.key.scancode << std::endl;
                    std::cout << "code: " << event.key.code << std::endl;
                    std::cout << "control: " << event.key.control << std::endl;
                    std::cout << "alt: " << event.key.alt << std::endl;
                    std::cout << "shift: " << event.key.shift << std::endl;
                    std::cout << "system: " << event.key.system << std::endl;
                    std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString()
                              << std::endl;
                    std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
                    std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;
                }
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

        window.clear();
        window.draw(shape);
        window.display();
    }

    std::cout << "\n\n----------------------------\n\n";

    for (auto w: words) {
        std::cout << w << ' ';
    }

    std::cout << '\n';

    return 0;
}

// clang++ main.cpp -o sfml-app.out -lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window
// -lsfml-system