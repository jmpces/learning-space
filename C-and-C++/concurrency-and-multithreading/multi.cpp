// `std::jthread` is a C++20 feature

#include <iostream>
#include <vector>
#include <thread>
#include <functional>

void contain(size_t maxJobs, size_t totalJobs) {
    auto lambda = [](size_t x) {
        std::cout << "lambda.thread.get_id(" << x << ") : " << std::this_thread::get_id() << "\n";
    };

    size_t total_jobs = totalJobs;

    while (total_jobs > maxJobs) {
        std::cout << "job set\n";
        std::vector<std::jthread> threads;
        for (size_t i = 0; i < maxJobs; ++i) {
            threads.push_back(std::jthread(lambda, total_jobs - i));
        }
        total_jobs -= maxJobs;
    }

    std::cout << "last job set\n";
    std::vector<std::jthread> remaining_threads;
    for (size_t i = 0; i < total_jobs; ++i) {
        remaining_threads.push_back(std::jthread(lambda, total_jobs - i));
    }
}

int main() {
    contain(4, 10);
    std::cout << "this is the last call\n";
    return 0;
}