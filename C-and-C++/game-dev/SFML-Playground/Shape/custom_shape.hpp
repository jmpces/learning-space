#ifndef SFML_PLAYGROUND_MRDCVLSC_CUSTOM_SHAPE_TYPE_TUTORIAL
#define SFML_PLAYGROUND_MRDCVLSC_CUSTOM_SHAPE_TYPE_TUTORIAL

#include <SFML/Graphics.hpp>
#include <cmath>

/**

You can extend the set of shape classes with your own shape types. To do so, you must derive from sf::Shape and override
two functions:

getPointCount: return the number of points in the shape
getPoint: return a point of the shape

You must also call the update() protected function whenever any point in your shape changes, so that the base class is
informed and can update its internal geometry.

Here is a complete example of a custom shape class: EllipseShape.



*/

class EllipseShape : public sf::Shape {
    public:

    explicit EllipseShape(const sf::Vector2f &radius = sf::Vector2f(0.f, 0.f)) : m_radius(radius) {
        update();
    }

    void setRadius(const sf::Vector2f &radius) {
        m_radius = radius;
        update();
    }

    const sf::Vector2f &getRadius() const {
        return m_radius;
    }

    virtual std::size_t getPointCount() const {
        return 30; // fixed, but could be an attribute of the class if needed
    }

    virtual sf::Vector2f getPoint(std::size_t index) const {
        static const float pi = 3.141592654f;

        float angle = index * 2 * pi / getPointCount() - pi / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

    private:

    sf::Vector2f m_radius;
};

#endif