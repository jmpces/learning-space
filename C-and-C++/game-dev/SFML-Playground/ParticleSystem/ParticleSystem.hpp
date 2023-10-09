#ifndef MRDCVLSC_LEARNING_SPACE_COSTUM_SFML_ENTITY_PARTICLE_SYSTEM_HPP
#define MRDCVLSC_LEARNING_SPACE_COSTUM_SFML_ENTITY_PARTICLE_SYSTEM_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include <chrono>
#include <iostream>
#include <random>

#include <cmath>

class ParticleSystem : public sf::Drawable, public sf::Transformable {
    public:

    ParticleSystem(unsigned int count)
        : m_particles(count), m_vertices(sf::Points, count), m_lifetime(sf::seconds(3.f)), m_emitter(0.f, 0.f) {
    }

    void setEmitter(sf::Vector2f position) {
        m_emitter = position;
    }

    void update(sf::Time elapsed) {
        for (std::size_t i = 0; i < m_particles.size(); ++i) {
            // update the particle lifetime
            Particle &p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero) {
                resetParticle(i);
            }

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

    private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    private:

    /// contains a velocity and lifetime.
    struct Particle {
        sf::Vector2f velocity;
        sf::Time     lifetime;
    };

    void resetParticle(std::size_t index) {
        // get a random angle which is converted to radians by multiplying it to (3.14f / 180.f)
        float angle = (std::rand() % 360) * 3.14f / 180.f;

        // get a random speed from 50 to 100
        float speed = (std::rand() % 50) + 50.f;

        // get the unit vector from the random angle
        sf::Vector2f unit_vector(std::cos(angle), std::sin(angle));

        // scale the random angled unit vector with the random speed
        m_particles[index].velocity = unit_vector * speed;

        // set the random lifetime of the particle ranging from 1000 to 3000 milliseconds
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

        // reset the position of the corresponding particle (vertex)
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray       m_vertices;
    sf::Time              m_lifetime;
    sf::Vector2f          m_emitter;
};

#endif