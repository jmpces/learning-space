#include <iostream>

class Foo{
    public:
        void bar(){
            std::cout << "Hello" << std::endl;
        }
};

extern "C" {
    Foo* Foo_new()
    {
        std::cout << "constructor called\n";
        return new Foo();
    }

    void Foo_bar(Foo* foo){
        foo->bar();
    }

    void Foo_del(Foo* instance)
    {
        std::cout << "destructor called\n";
        delete [] instance;
    }
}

// compile and run
// g++ -c -fPIC foo.cpp -o foo.o
// g++ -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.o
// python3 test.py