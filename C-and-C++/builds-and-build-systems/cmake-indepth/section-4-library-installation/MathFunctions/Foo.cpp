#include <Foo.hpp>
#include <iostream>

void Bar() {
    std::cout << "Hello from Foo header function Bar\n";
    #ifdef USE_MYMATH
    std::cout << "Using use my math\n";
    #endif
}