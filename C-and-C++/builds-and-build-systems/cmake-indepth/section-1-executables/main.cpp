#include <iostream>
#include <config.hpp>

int main() {
    std::cout << "Project : ";
    std::cout << "Hello cmake\n";
    std::cout << " Version : "
        << VERSION_MAJOR << '.'
        << VERSION_MINOR << '.'
        << VERSION_PATCH << '\n';
    return 0;
}