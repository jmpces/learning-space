#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

void Update(CircleShape &circle, RenderWindow &window);
void Draw(RenderWindow &window, CircleShape &circle);

int main() {

    int keyTime = 8;

    RenderWindow window(VideoMode(600, 480), "Simple square");
    window.setFramerateLimit(60);
    RectangleShape square(Vector2f(100.f, 100.f));

    sf::CircleShape circle1;
    circle1.setRadius(50);
    circle1.setOutlineColor(sf::Color::Black);
    circle1.setOutlineThickness(5);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        Update(circle1, window);

        Draw(window, circle1);
    }

    return 0;
}

void Update(CircleShape &circle, RenderWindow &window) {
    sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
    circle.setPosition(window.mapPixelToCoords(globalPosition));
}
void Draw(RenderWindow &window, CircleShape &circle) {

    window.clear(Color::White);

    window.draw(circle);

    window.display();
}