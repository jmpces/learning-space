#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

int main() {

    std::mutex mtx;

    std::cout << "thread A lock call - before\n";
    mtx.lock();
    std::cout << "thread A lock call - after\n";

    std::thread threadB = std::thread([&](){
        std::cout << "thread B lock call - before\n";
        // mtx.lock();
        std::cout << "thread B lock call - after\n";
        
        std::cout << "thread B unlock call - before\n";
        // mtx.unlock();
        std::cout << "thread B nlock call - after\n";

        std::cout << "Hello from B\n";
    });

    std::cout << "Hello from A\n";

    std::cout << "thread A ulock call - before\n";
    mtx.unlock();
    std::cout << "thread A ulock call - after\n";

    threadB.join();
    
    std::cout << "Hello again from A\n";

    return 0;
}