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

#include "CustomSFMLEntity.hpp"

int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 350), "My window");
    window.setFramerateLimit(120);

    // =============================================================================================
    //                               CREATING A VERTEX - Manual Method
    // =============================================================================================

    // create a new vertex
    sf::Vertex vertex1;

    // set its position
    vertex1.position = sf::Vector2f(10.f, 10.f);

    // set its color
    vertex1.color = sf::Color::Red;

    // set its texture coordinates
    vertex1.texCoords = sf::Vector2f(100.f, 100.f);

    // =============================================================================================
    //                               CREATING A VERTEX - Constructor Method
    // =============================================================================================

    sf::Vertex vertex2(sf::Vector2f(100.f, 10.f), sf::Color::Blue, sf::Vector2f(100.f, 100.f));

    // =============================================================================================
    //                               CREATING A VERTEX - Constructor Method (shorthand)
    // =============================================================================================

    sf::Vertex vertex3 = {
      {100.f, 100.f},
      sf::Color::Green,
      {100.f, 100.f},
    };

    // =============================================================================================
    //                          CREATING A VERTEX ARRAY USING SFML sf::VertexArray
    // =============================================================================================

    // creating a vertex array
    sf::VertexArray triangle1(sf::Lines, 3);

    triangle1[0] = vertex1;
    triangle1[1] = vertex2;
    triangle1[2] = vertex3;

    // =============================================================================================
    //                          CREATING A VERTEX ARRAY USING std::vector
    // =============================================================================================

    float tri_start_x = 100.f;
    float tri_start_y = 100.f;

    std::vector<sf::Vertex> triangle2{
      {{vertex1.position.x + tri_start_x, vertex1.position.y + tri_start_y}, sf::Color::Red},
      {{vertex2.position.x + tri_start_x, vertex2.position.y + tri_start_y}, sf::Color::Magenta},
    };

    triangle2.push_back({{vertex3.position.x + tri_start_x, vertex3.position.y + tri_start_y}, sf::Color::Green});

    // =============================================================================================
    //                          CREATING A VERTEX ARRAY USING C arrays
    // =============================================================================================

    sf::Vertex triangle3[] = {
      sf::Vertex(sf::Vector2f(vertex1.position.x + 300.f, vertex1.position.y + 50.f), sf::Color(0, 0, 0xff, 0xff)),
      sf::Vertex(sf::Vector2f(vertex2.position.x + 300.f, vertex2.position.y + 50.f), sf::Color(0xff, 0, 0, 0xff)),
      sf::Vertex(sf::Vector2f(vertex3.position.x + 300.f, vertex3.position.y + 50.f), sf::Color(0, 0xff, 0, 0xff)),
    };

    // =============================================================================================
    //                          TEXTURING VERTEX ARRAYS
    // =============================================================================================

    sf::Texture stone;
    stone.loadFromFile("../assets/stone.jpg");

    // create a triangle strip
    sf::VertexArray triangleStrip(sf::TriangleStrip, 4);

    float tri_strip_start_x = 200.f;
    float tri_strip_start_y = 200.f;

    // define it as a rectangle, located at (10, 10) and with size 100x100
    triangleStrip[0].position = sf::Vector2f(tri_strip_start_x + 10.f, tri_strip_start_y + 10.f);
    triangleStrip[1].position = sf::Vector2f(tri_strip_start_x + 10.f, tri_strip_start_y + 110.f);
    triangleStrip[2].position = sf::Vector2f(tri_strip_start_x + 110.f, tri_strip_start_y + 10.f);
    triangleStrip[3].position = sf::Vector2f(tri_strip_start_x + 110.f, tri_strip_start_y + 110.f);

    // define its texture area to be a 25x50 rectangle starting at (0, 0)
    triangleStrip[0].texCoords = sf::Vector2f(tri_strip_start_x + 0.f, tri_strip_start_y + 0.f);
    triangleStrip[1].texCoords = sf::Vector2f(tri_strip_start_x + 0.f, tri_strip_start_y + 50.f);
    triangleStrip[2].texCoords = sf::Vector2f(tri_strip_start_x + 50.f, tri_strip_start_y + 0.f);
    triangleStrip[3].texCoords = sf::Vector2f(tri_strip_start_x + 50.f, tri_strip_start_y + 50.f);

    // =============================================================================================
    //                          TRANSFORMING VERTEX ARRAYS
    // =============================================================================================

    float            rotation_angle = 0.f;
    sf::RenderStates rotation_state;
    rotation_state.transform.rotate(0.5f);

    // =============================================================================================
    //                          CUSTOM SFML ENTITY
    // =============================================================================================

    MyEntity myShape(100, sf::Color::Red);

    myShape.setPosition(300, 200);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            rotation_state.transform.rotate(0.2f);
            triangle1.setPrimitiveType(sf::Triangles);
            myShape.rotate(-1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            // rotation_angle = std::fmod(rotation_angle - 0.1f, 360.f);
            rotation_state.transform.rotate(-0.2f);
            triangle1.setPrimitiveType(sf::Lines);
            myShape.rotate(1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
            triangle1.setPrimitiveType(sf::LineStrip);
            myShape.scale(1.01f, 1.01f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
            triangle1.setPrimitiveType(sf::TriangleStrip);
            myShape.scale(0.98f, 0.98f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Q)) {
            triangle1.setPrimitiveType(sf::TriangleFan);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            myShape.move(0.f, -1.75f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            myShape.move(0.f, 1.75f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            myShape.move(-1.75f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            myShape.move(1.75f, 0.f);
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(map);

        // =============================================================================================
        //                                DRAWING VERTEX ARRAYS
        // =============================================================================================

        // As you can see the vertices here uses a sf::PrimitiveType, this type is the one who is responsible on how
        // SFML renders the vertices, it answers the question of should it be filled? should it be just a line? should
        // the fill connect? for more information about this type you can follow this link
        // https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php#primitive-types

        window.draw(triangle1);
        window.draw(&triangle2[0], triangle2.size(), sf::Triangles, rotation_state);

        window.draw(&triangle3[0], triangle2.size(), sf::Triangles, &stone);

        // The line above is the short version for drawing vertex arrays with textures, if you need to pass other render
        // states (like a blend mode or a transform), you can use the explicit version which takes a sf::RenderStates
        // object:

        sf::RenderStates states;
        states.texture = &stone;

        window.draw(triangleStrip, states);

        window.draw(myShape);

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