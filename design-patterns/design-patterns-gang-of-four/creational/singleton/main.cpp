#include <iostream>
#include <chrono>

class Singleton {
    public:
        static Singleton& instance() {
            static Singleton* singleton = new Singleton();
            return *singleton;
        }

        void set_data(int value) { data = value; }
        int get_data() { return data; }
    private:
        Singleton() : data(0) {}
        ~Singleton() {}
        int data;    
};

class Singleton {
    public:
        static Singleton& instance() {
            static Singleton* singleton;
            
            if (singleton == nullptr) {
                singleton = new Singleton();
            }

            return *singleton;
        }

        void set_data(int value) { data = value; }
        int get_data() { return data; }
    private:
        Singleton() : data(0) {}
        ~Singleton() { delete this; }
        int data;    
};

int main() {
    std::cout << "Singleton data = " << Singleton::instance().get_data() << '\n';

    Singleton::instance().set_data(678);

    std::cout << "Singleton data = " << Singleton::instance().get_data() << '\n';

    std::cout << "allocation start\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 138'000'000; ++i) {
        Singleton::instance().set_data(
            Singleton::instance().get_data() + i
        );
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "deallocation? end\n";
    std::cout << "total time = " << dur.count() << " nanoseconds\n";
    std::cin.get();

    return 0;
}

/*
#include <iostream>

class Singleton {
    public:
        static Singleton& instance() {
            static Singleton* singleton;
            
            if (singleton == nullptr) {
                singleton = new Singleton();
            }

            return *singleton;
        }

        void set_data(int value) { data = value; }
        int get_data() { return data; }
    private:
        Singleton() : data(0) {}
        ~Singleton() { delete this; }
        int data;    
};

int main() {
    std::cout << "Singleton data = " << Singleton::instance().get_data() << '\n';

    Singleton::instance().set_data(5);

    std::cout << "Singleton data = " << Singleton::instance().get_data() << '\n';

    Singleton::instance().set_data(678);

    std::cout << "Singleton data = " << Singleton::instance().get_data() << '\n';

    return 0;
}
*/