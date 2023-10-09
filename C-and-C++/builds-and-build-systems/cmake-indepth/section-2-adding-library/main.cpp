#include <iostream>
#include <config.hpp>
#include <MathFunctions.hpp>
#include <Foo.hpp>

int main() {
    std::cout << "Project : ";
    std::cout << "Hello cmake adding library\n";
    std::cout << " Version : "
        << VERSION_MAJOR << '.'
        << VERSION_MINOR << '.'
        << VERSION_PATCH << '\n';
    std::cout << "squared(5)    = " << mysquared(5) << "\n";
    std::cout << "pow(2, 8) - 1 = " << mypow(2, 8) - 1 << "\n";
    Bar();
    
    return 0;
}