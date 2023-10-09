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
    //                                     SHAPE CREATION
    // =============================================================================================

    sf::CircleShape circle(25.f);

    // =============================================================================================
    //                                      SHAPE COLOR
    // =============================================================================================

    // set the shape color to green
    circle.setFillColor(sf::Color(100, 250, 50));

    // =============================================================================================
    //                            SHAPE OUTLINE/BORDER MODIFICATION
    // =============================================================================================

    // set a 10-pixel wide orange outline
    circle.setOutlineThickness(5.f);
    circle.setOutlineColor(sf::Color(250, 150, 100));

    // By default, the outline is extruded outwards from the shape (e.g. if you have a circle with a radius of 10 and an
    // outline thickness of 5, the total radius of the circle will be 15). You can make it extrude towards the center of
    // the shape instead, by setting a negative thickness.

    // To disable the outline, set its thickness to 0. If you only want the outline, you can set the fill color to
    // sf::Color::Transparent.

    // =============================================================================================
    //                                 ADDING TEXTURE TO SHAPE
    // =============================================================================================

    sf::Texture texture_fur;
    if (!texture_fur.loadFromFile("../assets/fur.jpg")) {
        std::cerr << "Error loading fur texture\n";
        return 1;
    }

    circle.setTexture(&texture_fur); // texture is a sf::Texture
    circle.setTextureRect(sf::IntRect(10, 10, 100, 100));

    // =============================================================================================
    //                                       RECTANGLES
    // =============================================================================================
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));

    // change the size to 100x100
    rectangle.setSize(sf::Vector2f(100.f, rectangle.getSize().x));

    // =============================================================================================
    //                                        CIRCLES
    // =============================================================================================

    // define a circle with radius = 200
    sf::CircleShape circle2(50.f);

    // change the radius to 40
    circle2.setRadius(100.f);

    // change the number of sides (points) to 100
    circle2.setPointCount(100);

    // =============================================================================================
    //                                         POLYGONS
    // =============================================================================================

    // define a triangle
    sf::CircleShape triangle(25.f, 3);

    // define a square
    sf::CircleShape square(25.f, 4);

    // define an octagon
    sf::CircleShape octagon(25.f, 8);

    // =============================================================================================
    //                                 Convex shapes
    // =============================================================================================

    // The sf::ConvexShape class is the ultimate shape class: It allows you to define any convex shape. SFML is unable
    // to draw concave shapes. If you need to draw a concave shape, you'll have to split it into multiple convex
    // polygons.

    // To construct a convex shape, you must first set the number of points it should have and then define the points.

    // create an empty shape
    sf::ConvexShape convex;

    // resize it to 5 points
    convex.setPointCount(5);

    // define the points
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));

    // The order in which you define the points is very important. They must all be defined either in clockwise or
    // counter-clockwise order. If you define them in an inconsistent order, the shape will be constructed incorrectly.

    // =============================================================================================
    //                                    LINES
    // =============================================================================================

    // There's no shape class for lines. The reason is simple: If your line has a thickness, it is a rectangle. If it
    // doesn't, it can be drawn with a line primitive.

    // Line with thickness USING RECTANGLES

    sf::RectangleShape line1(sf::Vector2f(150.f, 5.f));
    line1.rotate(45.f);
    line1.setPosition({50 * 5, 50 * 5});

    // Line without thickness USING VERTEX ARRAY

    // sf::Vertex line2[] = {
    //   sf::Vertex(sf::Vector2f(50.f * 15.f + 25.f, 25.f)),
    //   sf::Vertex(sf::Vector2f(50.f * 11.f + 25.f, 50.f * 8 + 25.f)),
    // };

    // short hand
    sf::Vertex line2[] = {
      {{50.f * 15.f + 25.f, 25.f}},
      {{50.f * 11.f + 25.f, 50.f * 8 + 25.f}},
    };

    // =============================================================================================
    //                                  CUSTOM SHAPES
    // =============================================================================================

    Particle ellipse(sf::Vector2f(100.f, 50.f));
    // =============================================================================================

    rectangle.setFillColor(sf::Color::Yellow);
    circle2.setFillColor(sf::Color::Blue);
    triangle.setFillColor(sf::Color::Cyan);
    square.setFillColor(sf::Color::Magenta);
    octagon.setFillColor(sf::Color::Red);
    convex.setFillColor(sf::Color(0xff, 0xc0, 0xcb, 0xff));
    ellipse.setFillColor(sf::Color::White);

    // =============================================================================================

    circle.setPosition(50, 50);
    rectangle.setPosition(200, 150);

    circle2.move(0, 200);
    triangle.move(50 * 5, 50);
    square.move(50 * 7, 50);
    octagon.move(50 * 9, 50);

    convex.setPosition(50 * 8, 50 * 6);

    ellipse.setPosition(50 * 8, 50 * 9);

    // =============================================================================================
    //                                    ANTIALIASED SHAPES
    // =============================================================================================

    // There's no option to anti-alias a single shape. To get anti-aliased shapes (i.e. shapes with smoothed edges), you
    // have to enable anti-aliasing globally when you create the window, with the corresponding attribute of the
    // sf::ContextSettings structure.

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
      sf::VideoMode(800, 600), "Shapes", sf::Style::Default,
      settings // use antialiasing level 8
    );

    // Remember that anti-aliasing availability depends on the graphics card: It might not support it, or have it forced
    // to disabled in the driver settings.

    // =============================================================================================

    sf::Texture texture_grid;
    sf::Sprite  grid;

    makeGrid(texture_grid, window);
    grid.setTexture(texture_grid);

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
        window.draw(grid);
        window.draw(circle);
        window.draw(circle2);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(square);
        window.draw(octagon);
        window.draw(convex);

        window.draw(line1);
        window.draw(line2, 2, sf::Lines);

        window.draw(ellipse);

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