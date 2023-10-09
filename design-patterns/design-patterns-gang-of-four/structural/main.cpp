#include <iostream>

class Component {
    public:
    // operations / methods
    // ...

    //
    virtual ~Component () = 0;

    virtual void add(Component* component) {}
    virtual void remove(Component* Component) {}
    virtual Component* get_child(size_t index) {}
};



int main() {
    return 0;
}