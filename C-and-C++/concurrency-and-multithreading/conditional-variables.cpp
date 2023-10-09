#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main() {
    std::cout << "main() starts\n";

    int result = 0;

    std::thread reporter([&]() {
        std::cout << "reporter thread enters\n";
        std::unique_lock<std::mutex> lock(gLock);
        std::cout << "reporter thread after lock\n";

        gConditionVariable.wait(lock);

        std::cout << "\tReporter Result = " << result << "\n";
    });

    std::thread worker([&](){
        std::cout << "worker thread enters\n";
        std::unique_lock<std::mutex> lock(gLock);
        std::cout << "worker thread after lock\n";

        result = 42;
        
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "\tWork Complete\n";
        gConditionVariable.notify_one();
    });

    reporter.join();
    worker.join();

    std::cout << "main end\n";

    return 0;
}