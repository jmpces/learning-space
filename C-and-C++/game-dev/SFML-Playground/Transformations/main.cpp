#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main() {
    sf::Texture wood;
    if (!wood.loadFromFile("../assets/wood.jpg", sf::IntRect(30, 30, 32, 32))) {
        std::cerr << "Error loading wood sprite\n";
        return 1;
    }

    sf::Sprite wood_sprite;
    wood_sprite.setTexture(wood);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(120);

    // =================================================================================
    // sets the origin is the center point of all the three transformation
    // by default this it the top left (0, 0) point of an entity, but we can change it using the code below.

    // Note that changing the origin also changes where the entity is drawn on screen, even though its position property
    // hasn't changed. If you don't understand why, read this tutorial one more time!

    auto wood_sprite_dim = wood_sprite.getGlobalBounds(); // the square where all vertices of an entity lies

    wood_sprite.setOrigin(wood_sprite_dim.width / 2.f, wood_sprite_dim.height / 2.f);

    // =================================================================================
    // sets the absolute position of the entity.
    wood_sprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // =================================================================================
    // sets the absolute rotation of an entity.
    wood_sprite.setRotation(10.f);

    // =================================================================================
    // sets the absolute scale of an entity
    wood_sprite.setScale(1.3f, 1.3f);

    // =================================================================================
    // custom transform

    sf::Transform t1 = sf::Transform::Identity;

    // a rotation transform
    sf::Transform t2;
    t2.rotate(10.f);

    // a custom matrix - an identity matrix - same thing as t1
    sf::Transform t3(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);

    // a combined transform
    sf::Transform t4 = t1 * t2 * t3;
    // =================================================================================

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // =================================================================================
        // relative moves

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            // set the new position relative to the current position.
            wood_sprite.move(-1.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            // set the new position relative to the current position.
            wood_sprite.move(1.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
            // set the new position relative to the current position.
            wood_sprite.move(0.f, -1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
            // set the new position relative to the current position.
            wood_sprite.move(0.f, 1.f);
        }

        // =================================================================================
        // relative rotations

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            // set the new rotation relative to the current rotation
            wood_sprite.rotate(-1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            // set the new rotation relative to the current rotation
            wood_sprite.rotate(1.f);
        }

        // =================================================================================
        // relative scale

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            // set the new scale value relative to the old scale value
            wood_sprite.scale(1.02f, 1.02f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            // set the new scale value relative to the old scale value
            wood_sprite.scale(0.98f, 0.98f);
        }

        // =================================================================================
        // calculate the bounding box

        auto               bounding_box = wood_sprite.getGlobalBounds();
        sf::RectangleShape bounding_box_border({bounding_box.width, bounding_box.height});

        bounding_box_border.setFillColor(sf::Color::Transparent);
        bounding_box_border.setOutlineColor(sf::Color::Red);
        bounding_box_border.setOutlineThickness(3.f);
        bounding_box_border.setPosition(bounding_box.getPosition());
        // =================================================================================

        window.clear(sf::Color::Black);

        window.draw(wood_sprite);
        window.draw(bounding_box_border);

        window.draw(wood_sprite, t4);
        window.draw(bounding_box_border, t4);

        window.display();

        // =================================================================================
        // get the transform values on an entity
        std::cerr << "\ncurrent position point : (" << wood_sprite.getPosition().x << ", "
                  << wood_sprite.getPosition().y << ")\n";
        std::cerr << "current rotation angle : " << wood_sprite.getRotation() << '\n';
        std::cerr << "current scale factor   : [" << wood_sprite.getScale().x << ", " << wood_sprite.getScale().y
                  << "]\n";
        // =================================================================================
    }

    return 0;
}