#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(600, 400), "My window");

    // a grid sprite - my own experimental implementation
    sf::Texture texture_grid;
    texture_grid.create(window.getSize().x, window.getSize().y);
    size_t     grid_linear_size = texture_grid.getSize().x * texture_grid.getSize().y * 4;
    size_t     cell_size = 50;
    sf::Uint8 *grid_values = new sf::Uint8[grid_linear_size];
    for (size_t i = 0; i < window.getSize().y; ++i) {
        for (size_t j = 0; j < window.getSize().x * 4; j += 4) {
            if (i % cell_size == 0 || (j / 4) % cell_size == 0) {
                grid_values[i * (window.getSize().x * 4) + j] = 0;
                grid_values[i * (window.getSize().x * 4) + j + 1] = 0xff;
                grid_values[i * (window.getSize().x * 4) + j + 2] = 0;
                grid_values[i * (window.getSize().x * 4) + j + 3] = 0xff;
            }
        }
    }
    texture_grid.update(grid_values);
    delete[] grid_values;

    sf::Sprite grid;
    grid.setTexture(texture_grid);

    // =================================================================================================================
    //                                          LOADING TEXTURES
    // =================================================================================================================

    sf::Texture wood;
    if (!wood.loadFromFile("../assets/wood.jpg", sf::IntRect(10, 10, 50, 50))) {
        // the second argument is optional, it loads a 50x50 rectangle that starts at (10, 10)
        std::cerr << "error loading wood texture image\n";
        return 1;

        // You can also load an image file from memory (loadFromMemory), from a custom input stream (loadFromStream), or
        // from an image that has already been loaded (loadFromImage). The latter loads the texture from an sf::Image,
        // which is a utility class that helps store and manipulate image data (modify pixels, create transparency
        // channel, etc.). The pixels of an sf::Image stay in system memory, which ensures that operations on them will
        // be as fast as possible, in contrast to the pixels of a texture which reside in video memory and are therefore
        // slow to retrieve or update but very fast to draw.
    }

    sf::Image img_stone;
    if (!img_stone.loadFromFile("../assets/stone.jpg")) {
        std::cerr << "error loading stone texture image\n";
        return 1;
    }

    // =================================================================================================================
    //                                       CREATING YOUR OWN TEXTURES
    // =================================================================================================================

    // create an empty 200x200 texture
    sf::Texture my_texture;
    if (!my_texture.create(200, 200)) {
        std::cerr << "error creating my texture image\n";
        return 1;
    }

    // =================================================================================================================
    //                                       UPDATING/MODIFYING TEXTURES
    // =================================================================================================================

    // update a texture from an array of pixels
    // '* 4' because pixels have 4 components (RGBA)
    sf::Uint8 *pixels = new sf::Uint8[my_texture.getSize().x * my_texture.getSize().y * 4];
    my_texture.update(pixels);

    // update a texture from a sf::Image
    sf::Texture stone;
    stone.create(img_stone.getSize().x, img_stone.getSize().y);
    stone.update(img_stone);

    // update the texture from the current contents of the window
    sf::Texture window_ctx_texture;
    window_ctx_texture.create(window.getSize().x, window.getSize().y);
    window_ctx_texture.update(window);

    // =================================================================================================================
    //                                       CREATING SPRITES
    // =================================================================================================================
    sf::Sprite sprite_wood;
    sprite_wood.setTexture(wood);

    // If you don't want your sprite to use the entire texture, you can set its texture rectangle.
    sf::Sprite sprite_stone;
    sprite_stone.setTexture(stone);
    sprite_stone.setTextureRect(sf::IntRect(10, 10, 20, 20));

    // You can also change the color of a sprite. The color that you set is modulated (multiplied) with the texture of
    // the sprite. This can also be used to change the global transparency (alpha) of the sprite.

    sprite_wood.setColor(sf::Color(0, 255, 0));           // green
    sprite_stone.setColor(sf::Color(255, 255, 255, 128)); // half transparent

    // =================================================================================================================
    //                                       TRANSFORMING SPRITES
    // =================================================================================================================

    // Sprites can also be transformed: They have a position, an orientation and a scale.

    // position

    // the difference in `setPosition` and `move` is that if you consecutively called the `setPosition` 3x times,
    // the position of the object will not change since it uses an absolute position.
    // `move` on the other hand will move the object 3x times if you call the `move` 3 consecutive times.

    sprite_wood.setPosition(sf::Vector2f(50.f, 50.f)); // absolute position
    sprite_wood.move(sf::Vector2f(50.f, 50.f));        // offset relative to the current position

    // // rotation
    sprite_wood.setRotation(15.f); // absolute angle
    sprite_wood.rotate(15.f);      // offset relative to the current angle

    // // scale
    sprite_wood.setScale(sf::Vector2f(1.5f, 1.5f)); // absolute scale factor
    sprite_wood.scale(sf::Vector2f(1.5f, 1.5f));    // factor relative to the current scale

    // you see that there is an 'absolute' version and a 'relative' version for each methods.

    // By default, the origin for these three transformations is the top-left corner of the sprite. If you want to set
    // the origin to a different point (for example the center of the sprite, or another corner), you can use the
    // setOrigin function.
    sprite_stone.setOrigin(sf::Vector2f(25.f, 25.f));

    // =================================================================================================================
    //                                       MAIN TAKENOTE
    // =================================================================================================================

    // Using as few textures as possible is a good strategy, and the reason is simple: Changing the current texture
    // is an expensive operation for the graphics card. Drawing many sprites that use the same texture will yield
    // the best performance.

    // Additionally, using a single texture allows you to group static geometry into a single entity (you can only use
    // one texture per draw call), which will be much faster to draw than a set of many entities. Batching static
    // geometry involves other classes and is therefore beyond the scope of this tutorial, for further details see the
    // vertex array tutorial.

    // Try to keep this in mind when you create your animation sheets or your tilesets: Use as little textures as
    // possible.

    // =================================================================================================================
    //                                       MAIN GAME LOOP
    // =================================================================================================================

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
        window.draw(sprite_wood);
        window.draw(sprite_stone);

        // end the current frame
        window.display();
    }

    delete[] pixels;

    return 0;
}