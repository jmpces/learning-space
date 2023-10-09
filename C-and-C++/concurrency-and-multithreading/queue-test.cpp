#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

class thread_pool {
    public:

    size_t cores;
    std::mutex lock;
    std::condition_variable run_condition;
    std::atomic<size_t> running_threads;
    std::vector<std::thread> threads;

    thread_pool() {
        cores = std::thread::hardware_concurrency();
        running_threads = 0;
    }

    void start() {
        while (running_threads < cores) {
            run_condition.notify_one();
            running_threads++;
        }
    }

    void join_all() {
        for (size_t i = 0; i < threads.size(); ++i) {
            threads[i].join();
        }
    }

    void push(size_t id, size_t second_wait) {

        auto fn = [this](size_t id, size_t second_wait) {
            std::unique_lock<std::mutex> ulock(lock);

            if (running_threads < cores) {
                ulock.unlock();
            } else {
                run_condition.wait(ulock);
            }

            running_threads++;

            for (size_t i = 0; i <= second_wait; ++i) {
                std::cout << "total running threads(" << running_threads << ") : The thread " << id << " remaining time " << second_wait - i << " seconds\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            running_threads--;
            run_condition.notify_one();
        };

        threads.push_back(std::thread(
            fn, id, second_wait
        ));
    }
};

int main() {

    thread_pool myThreadPool;

    std::cout << myThreadPool.cores << "\n";

    myThreadPool.push(111, 4);
    myThreadPool.push(222, 4);
    myThreadPool.push(333, 4);
    myThreadPool.push(444, 2);
    myThreadPool.push(555, 6);
    myThreadPool.push(666, 3);
    myThreadPool.push(777, 4);
    myThreadPool.push(888, 1);

    myThreadPool.join_all();

    return 0;
}