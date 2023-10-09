#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// shader - small program that is executed on the graphics card
//          used to create effects that would be too complicated,
//          if not impossible, to describe with regular OpenGL
//          functions: Per-pixel lighting, shadows, etc

// newer versions of OpenGL are already entirely shader-based, and the fixed set of states and functions (which is
// called the "fixed pipeline") that you might know of has been deprecated and will likely be removed in the future.

// Shaders are written in GLSL (OpenGL Shading Language), which is very similar to the C programming language.

// There are two types of shaders: vertex shaders and fragment (or pixel) shaders. Vertex shaders are run for each
// vertex, while fragment shaders are run for every generated fragment (pixel). Depending on what kind of effect you
// want to achieve, you can provide a vertex shader, a fragment shader, or both.

int main() {
    sf::Texture wood;
    if (!wood.loadFromFile("../assets/wood.jpg", sf::IntRect(30, 30, 32, 32))) {
        std::cerr << "Error loading wood sprite\n";
        return 1;
    }

    sf::Sprite wood_sprite;
    wood_sprite.setTexture(wood);

    // =================================================================================
    //                           CHECK GPU SUPPORTS SHADERS
    // ---------------------------------------------------------------------------------

    // check if shader is available, Any attempt to use the sf::Shader class will fail if sf::Shader::isAvailable()
    // returns false.

    if (sf::Shader::isAvailable()) {
        std::cerr << "Shader is available\n";
    } else {
        std::cerr << "Shader is NOT-available\n";
    }

    // =================================================================================
    //                             LOAD SHADERS FROM FILE
    // ---------------------------------------------------------------------------------

    sf::Shader shader;

    // load only the vertex shader
    if (!shader.loadFromFile("vertex_shader.vert", sf::Shader::Vertex)) {
        // error...
    }

    // load only the fragment shader
    if (!shader.loadFromFile("fragment_shader.frag", sf::Shader::Fragment)) {
        // error...
    }

    // load both shaders
    if (!shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag")) {
        // error...
    }

    // Shader source is contained in simple text files (like your C++ code). Their extension doesn't really matter, it
    // can be anything you want, you can even omit it. ".vert" and ".frag" are just examples of possible extensions.

    // =================================================================================
    //                            LOAD SHADERS FROM STRINGS
    // ---------------------------------------------------------------------------------

    const std::string vertexShader =
      "void main()"
      "{"
      "    ..."
      "}";

    const std::string fragmentShader =
      "void main()"
      "{"
      "    ..."
      "}";

    // load only the vertex shader
    if (!shader.loadFromMemory(vertexShader, sf::Shader::Vertex)) {
        // error...
    }

    // load only the fragment shader
    if (!shader.loadFromMemory(fragmentShader, sf::Shader::Fragment)) {
        // error...
    }

    // load both shaders
    if (!shader.loadFromMemory(vertexShader, fragmentShader)) {
        // error...
    }

    // And finally, like all other SFML resources, shaders can also be loaded from a custom input stream with the
    // loadFromStream function.

    // If loading fails, don't forget to check the standard error output (the console) to see a detailed report from the
    // GLSL compiler.

    // =================================================================================
    //                           PASSING VARIABLES TO SHADERS
    // ---------------------------------------------------------------------------------

    // Like any other program, a shader can take parameters so that it is able to behave differently from one draw to
    // another. These parameters are declared as global variables known as uniforms in the shader.

    /*shader file program:

        ```shader
        uniform float myvar;

        void main()
        {
            // use myvar...
        }
        ```
    */

    shader.setUniform("myvar", 5.f);

    /* setUniform's overloads support all the types provided by SFML:

        float         == (GLSL type float)
        sf::Vector2f  == (GLSL type vec2)
        sf::Vector3f  == (GLSL type vec3)
        4 floats      == (GLSL type vec4)
        sf::Color     == (GLSL type vec4)
        sf::Transform == (GLSL type mat4)
        sf::Texture   == (GLSL type sampler2D)
    */

    // The GLSL compiler optimizes out unused variables (here, "unused" means "not involved in the calculation of the
    // final vertex/pixel"). So don't be surprised if you get error messages such as Failed to find variable "xxx" in
    // shader when you call setUniform during your tests.

    // =================================================================================

    // =================================================================================
    // =================================================================================
    // =================================================================================

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(120);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // =================================================================================
        //                              USING SHADERS
        // ---------------------------------------------------------------------------------

        window.draw(wood_sprite, &shader);

        // =================================================================================
        // =================================================================================
        // =================================================================================
        // =================================================================================
        // =================================================================================

        window.display();
    }

    return 0;
}