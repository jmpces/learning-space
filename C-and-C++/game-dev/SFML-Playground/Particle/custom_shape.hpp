#ifndef SFML_PLAYGROUND_MRDCVLSC_CUSTOM_SHAPE_TYPE_TUTORIAL
#define SFML_PLAYGROUND_MRDCVLSC_CUSTOM_SHAPE_TYPE_TUTORIAL

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <cmath>
#include <limits>
#include <random>

/**

You can extend the set of shape classes with your own shape types. To do so, you must derive from sf::Shape and override
two functions:

getPointCount: return the number of points in the shape
getPoint: return a point of the shape

You must also call the update() protected function whenever any point in your shape changes, so that the base class is
informed and can update its internal geometry.

Here is a complete example of a custom shape class: EllipseShape.



*/

class Particle : public sf::CircleShape {
    public:

    explicit Particle(float radius, sf::Vector2f const &vec = sf::Vector2f(1.f, 1.f))
        : sf::CircleShape(radius), unit_vector(vec) {
        std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());

        constexpr float PI = 3.141592654f;
        constexpr float MAX_RADIAN = 2.f * PI;

        std::uniform_real_distribution<float> rng(0.f, MAX_RADIAN);

        randomize_direction(rng(engine));

        update();
    }

    void apply(float force = 0.f) {
        move(unit_vector * force);
    }

    void calculate_window_bounce(sf::RenderTarget &target) {
        auto bounds = static_cast<sf::Vector2f>(target.getSize());
        auto position = getPosition();

        if ((position.x < 0.f) ^ (position.x > bounds.x)) {
            unit_vector.x = -unit_vector.x;
        }

        if ((position.y < 0.f) ^ (position.y > bounds.y)) {
            unit_vector.y = -unit_vector.y;
        }
    }

    void randomize_direction(float angle) {
        float x = std::cos(angle);
        float y = std::sin(angle);

        unit_vector.x = x;
        unit_vector.y = y;
    }

    private:

    sf::Vector2f unit_vector;
};

#endif