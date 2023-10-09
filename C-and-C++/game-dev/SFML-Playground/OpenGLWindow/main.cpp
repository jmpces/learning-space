#include <GL/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

#include <SFML/OpenGL.hpp>

#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    constexpr float PI = 3.14159265359f;
    constexpr float SINE_HALF_CYCLE = PI;

    // set the settings of the underlying window context (optional).
    sf::ContextSettings window_setting;
    window_setting.depthBits = 24;
    window_setting.stencilBits = 8;
    window_setting.antialiasingLevel = 4;
    window_setting.majorVersion = 3;
    window_setting.minorVersion = 0;

    sf::RenderWindow window(
      sf::VideoMode(200, 200), "With OpenGL!",

      // a `style` argument is needed since we cannot leave this parameter empty if a `settings` argument is present.
      sf::Style::Default,

      window_setting
    );

    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(300);

    // Since SFML is based on OpenGL, its windows are ready for OpenGL calls without any extra effort.
    glEnable(GL_TEXTURE_2D);

    // activate OpenGL context in this window.
    window.setActive(true);

    // get settings of the underlying OpenGL context.
    sf::ContextSettings settings = window.getSettings();

    // display the current setting of the underlying OpenGL context.
    std::cout << "depth bits        :" << settings.depthBits << std::endl;
    std::cout << "stencil bits      :" << settings.stencilBits << std::endl;
    std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
    std::cout << "version           :" << settings.majorVersion << "." << settings.minorVersion << std::endl;

    sf::CircleShape shape((float) std::min(window.getSize().x, window.getSize().y) / 2.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition((float) window.getSize().x / 2.f, (float) window.getSize().y / 2.f);
    shape.setOrigin((float) window.getSize().x / 2.f, (float) window.getSize().y / 2.f);

    float sine_input = 0.f;
    float circle_scale = 0.f;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
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