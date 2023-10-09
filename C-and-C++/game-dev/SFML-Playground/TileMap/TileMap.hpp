#ifndef MRDCVLSC_LEARNING_SPACE_COSTUM_SFML_ENTITY_HPP
#define MRDCVLSC_LEARNING_SPACE_COSTUM_SFML_ENTITY_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
    public:

    /// @param tileset path of the tileset texture.
    /// @param tileSize size of a single tile texture.
    /// @param width number of column of the tile map.
    /// @param height number of row of the tile map.
    [[nodiscard]] bool load1(
      const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height
    ) {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset)) {
            return false;
        }

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Triangles);
        m_vertices.resize(width * height * 6);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                // get the current tile number
                int tileNumber = tiles[y * width + x];

                // find its position in the tileset texture for the current tile map index
                int texture_x = tileNumber * tileSize.x;
                int texture_y = 0 * tileSize.y; // zero because the tile map only has 1 row of tiles.

                // get a pointer to the triangles' vertices of the current tile
                sf::Vertex *triangles = &m_vertices[(y * width + x) * 6];

                // define the 6 corners of the two triangles
                triangles[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
                triangles[1].position = sf::Vector2f(x * tileSize.x, y * tileSize.y + tileSize.y);
                triangles[2].position = sf::Vector2f(x * tileSize.x + tileSize.x, y * tileSize.y + tileSize.y);

                triangles[3].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
                triangles[4].position = sf::Vector2f(x * tileSize.x + tileSize.x, y * tileSize.y);
                triangles[5].position = sf::Vector2f(x * tileSize.x + tileSize.x, y * tileSize.y + tileSize.y);

                // define the 6 matching texture coordinates
                triangles[0].texCoords = sf::Vector2f(texture_x, texture_y);
                triangles[1].texCoords = sf::Vector2f(texture_x, texture_y + tileSize.y);
                triangles[2].texCoords = sf::Vector2f(texture_x + tileSize.x, texture_y + tileSize.y);

                triangles[3].texCoords = sf::Vector2f(texture_x, texture_y);
                triangles[4].texCoords = sf::Vector2f(texture_x + tileSize.x, texture_y);
                triangles[5].texCoords = sf::Vector2f(texture_x + tileSize.x, texture_y + tileSize.y);
            }
        }

        return true;
    }

    /// @param tileset path of the tileset texture.
    /// @param tileSize size of a single tile texture.
    /// @param width number of column of the tile map.
    /// @param height number of row of the tile map.
    [[nodiscard]] bool load2(
      const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height
    ) {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset)) {
            return false;
        }

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Triangles);
        m_vertices.resize(width * height * 6);

        // populate the vertex array, with two triangles per tile
        for (unsigned int i = 0; i < width; ++i) {
            for (unsigned int j = 0; j < height; ++j) {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the triangles' vertices of the current tile
                sf::Vertex *triangles = &m_vertices[(i + j * width) * 6];

                // define the 6 corners of the two triangles
                triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

                // define the 6 matching texture coordinates
                triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            }
        }

        return true;
    }

    private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
};

#endif