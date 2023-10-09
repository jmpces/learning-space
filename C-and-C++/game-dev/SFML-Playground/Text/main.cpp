#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // It may seem obvious, but you also have to make sure that the font that you use contains the characters that you
    // want to draw. Indeed, fonts don't contain glyphs for all possible characters (there are more than 100000 in the
    // Unicode standard!), and an Arabic font won't be able to display Japanese text, for example.

    sf::Font font;
    if (!font.loadFromFile("../assets/ubuntu.ttf")) {
        std::cerr << "Error loading font\n";
    }

    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world");

    // Handling non-ASCII characters (such as accented European, Arabic, or Chinese characters) correctly can be tricky.
    // It requires a good understanding of the various encodings involved in the process of interpreting and drawing
    // your text. To avoid having to bother with these encodings, there's a simple solution: Use wide literal strings.
    // text.setString(L"יטאח");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    // create the window
    sf::RenderWindow window(sf::VideoMode(400, 300), "Text");

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
        window.clear(sf::Color::White);

        // draw everything here...
        window.draw(text);

        // end the current frame
        window.display();
    }

    return 0;
}