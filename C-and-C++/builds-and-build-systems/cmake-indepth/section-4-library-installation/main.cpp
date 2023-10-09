#include <iostream>
#include <config.hpp>

#ifdef USE_MYMATH
#include <MathFunctions.hpp>
#endif

#include <Foo.hpp>

int main() {
    std::cout << "Project : ";
    std::cout << "Hello cmake adding library\n";
    
    std::cout << " Version : "
        << VERSION_MAJOR << '.'
        << VERSION_MINOR << '.'
        << VERSION_PATCH << '\n';

    #ifdef USE_MYMATH
    std::cout << "squared(5)    = " << mysquared(5) << "\n";
    std::cout << "pow(2, 8) - 1 = " << mypow(2, 8) - 1 << "\n";
    #endif
    
    Bar();
    
    return 0;
}