#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

/* VIEWS - In games, it is not uncommon to have levels which are much bigger than the window itself. You only see is a
small part of them. This is typically the case in RPGs, platform games, and many other genres. What developers might
tend to forget is that they define entities in a 2D world, not directly in the window. The window is just a view, it
shows a specific area of the whole world. It is perfectly fine to draw several views of the same world in parallel, or
draw the world to a texture rather than to a window. The world itself remains unchanged, what changes is just the way it
is seen.

Since what is seen in the window is just a small part of the entire 2D world, you need a way to specify which part of
the world is shown in the window. Additionally, you may also want to define where/how this area will be shown within the
window. These are the two main features of SFML views.

To summarize, views are what you need if you want to scroll, rotate or zoom your world. They are also the key to
creating split screens and mini-maps.
*/

int main() {

    sf::Texture wood;
    if (!wood.loadFromFile("../assets/wood.jpg", sf::IntRect(10, 10, 50, 50))) {
        std::cerr << "error loading wood texture image\n";
        return 1;
    }

    sf::Sprite sprite_wood;
    sprite_wood.setTexture(wood);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(120);

    // ======================================================================================================
    //                               Defining what the `view` views
    // ======================================================================================================

    // create a view with the rectangular area of the 2D world to show
    sf::View view1(sf::FloatRect(200.f, 200.f, 300.f, 200.f));

    // create a view with its center and size
    sf::View view2(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 200.f));

    // These two definitions are equivalent: Both views will show the same area of the 2D world, a 300x200 rectangle
    // centered on the point (350, 300).

    // If you don't want to define the view upon construction or want to modify it later, you can use the equivalent
    // setters:

    view1.reset(sf::FloatRect(200.f, 200.f, 300.f, 200.f));

    view2.setCenter(sf::Vector2f(350.f, 300.f));
    view2.setSize(sf::Vector2f(200.f, 200.f));

    // ======================================================================================================
    //                                 Moving (scrolling) the view
    // ======================================================================================================

    // Unlike drawable entities, such as sprites or shapes whose positions are defined by their top-left corner (and can
    // be changed to any other point), views are always manipulated by their center -- this is simply more convenient.
    // That's why the function to change the position of a view is named setCenter, and not setPosition.

    sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));

    // move the view at point (200, 200)
    view.setCenter(200.f, 200.f);

    // move the view by an offset of (100, 100) (so its final position is (300, 300))
    view.move(100.f, 100.f);

    // ======================================================================================================
    //                                      Rotating the view
    // ======================================================================================================

    // To rotate a view, use the setRotation function.

    // rotate the view at 20 degrees
    view.setRotation(20.f);

    // rotate the view by 5 degrees relatively to its current orientation (so its final orientation is 25 degrees)
    view.rotate(5.f);

    // ======================================================================================================
    //                                   Zooming (scaling) the view
    // ======================================================================================================

    // Zooming in (or out) a view is done through to resizing it, so the function to use is setSize.

    // resize the view to show a 1200x800 area (we see a bigger area, so this is a zoom out)
    view.setSize(1200.f, 800.f);

    // zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
    view.zoom(0.5f);

    // ======================================================================================================
    //                                   Defining how the view is viewed
    // ======================================================================================================

    // Now that you've defined which part of the 2D world is seen in the window, let's define where it is shown. By
    // default, the viewed contents occupy the full window. If the view has the same size as the window, everything is
    // rendered 1:1. If the view is smaller or larger than the window, everything is scaled to fit in the window.

    // This default behavior is suitable for most situations, but it might need to be changed sometimes. For example, to
    // split the screen in a multiplayer game, you may want to use two views which each only occupy half of the window.
    // You can also implement a minimap by drawing your entire world to a view which is rendered in a small area in a
    // corner of the window. The area in which the contents of the view is shown is called the viewport.

    // To set the viewport of a view, you can use the setViewport function.

    // define a centered viewport, with half the size of the window
    view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));

    // You might have noticed something very important: The viewport is not defined in pixels, but instead as a ratio of
    // the window size. This is more convenient: It allows you to not have to track resize events in order to update the
    // size of the viewport every time the size of the window changes. It is also more intuitive: You would probably
    // define your viewport as a fraction of the entire window area anyway, not as a fixed-size rectangle.

    // ======================================================================================================
    //                                          Split-Screen
    // ======================================================================================================

    // Using a viewport, it is straightforward to split the screen for multiplayer games:

    sf::View player1View(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
    sf::View player2View(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));

    // player 1 (left side of the screen)
    player1View.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));

    // player 2 (right side of the screen)
    player2View.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));

    // ======================================================================================================
    //                                            Minimap
    // ======================================================================================================

    sf::View gameView(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
    sf::View minimapView(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));

    // the game view (full window)
    gameView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

    // mini-map (upper-right corner)
    minimapView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

    // ======================================================================================================
    //                                          Using a view
    // ======================================================================================================

    // To draw something using a view, you must draw it after calling the setView function of the target to which you
    // are drawing (sf::RenderWindow or sf::RenderTexture).

    // activate it
    window.setView(view);

    // draw something to that view
    window.draw(sprite_wood);

    // want to do visibility checks? retrieve the view
    sf::View currentView = window.getView();

    // The view remains active until you set another one. This means that there is always a view which defines what
    // appears in the target, and where it is drawn.

    // If you don't explicitly set any view, the render-target uses its own default view, which matches its size 1:1.

    // You can get the default view of a render-target with the `getDefaultView` function. This can be useful if you
    // want to define your own view based on it, or restore it to draw fixed entities (like a GUI) on top of your scene.

    sf::View oldView = window.getDefaultView();
    oldView.zoom(0.5f);
    window.setView(oldView);

    // restore the default view
    window.setView(window.getDefaultView());

    // NOTE!: When you call setView, the render-target makes a copy of the view, and doesn't store a pointer to the one
    // that is passed. This means that whenever you update your view, you need to call setView again to apply the
    // modifications. Don't be afraid to copy views or create them on the fly, they aren't expensive objects (they just
    // hold a few floats).

    // ======================================================================================================
    //                                       Coordinates conversions
    // ======================================================================================================

    // When you use a custom view, or when you resize the window without using the code above, pixels displayed on the
    // target no longer match units in the 2D world. For example, clicking on pixel (10, 50) may hit the point (26.5,
    // -84) of your world. You end up having to use a conversion function to map your pixel coordinates to world
    // coordinates: `mapPixelToCoords`.

    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

    // By default, `mapPixelToCoords` uses the current view. If you want to convert the coordinates using view which is
    // not the active one, you can pass it as an additional argument to the function.

    // The opposite, converting world coordinates to pixel coordinates, is also possible with the `mapCoordsToPixel`
    // function.

    // ======================================================================================================

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // ======================================================================================================
            //                                Showing more when the window is resized
            // ======================================================================================================

            // Since the default view never changes after the window is created, the viewed contents are always the
            // same. So when the window is resized, everything is squeezed/stretched to the new size.

            // If, instead of this default behavior, you'd like to show more/less stuff depending on the new size of the
            // window, all you have to do is update the size of the view with the size of the window.

            // catch the resize events

            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            // ======================================================================================================
        }

        window.clear(sf::Color::Black);

        window.draw(sprite_wood);

        window.display();
    }

    return 0;
}