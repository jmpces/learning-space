#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>
#include <atomic>
#include <mutex>

int main() {
    size_t iterations = 300'000'000;
    // size_t iterations = 1'000'000;
    size_t halfs = iterations / 2;

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_engine(seed);

    auto min = std::numeric_limits<unsigned char>::min();
    auto max = std::numeric_limits<unsigned char>::max();

    std::uniform_int_distribution<unsigned char> random_number(min, max);

    std::vector<size_t> random_numbers;
    size_t sum = 0;

    // ################## generate rng ################## 
    auto rng_start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) {
        size_t rng = random_number(rand_engine);
        random_numbers.push_back(rng);
        sum += rng;
    }
    auto rng_end = std::chrono::high_resolution_clock::now();
    auto rng_dur = std::chrono::duration_cast<std::chrono::milliseconds>(rng_end - rng_start);

    // ################## single thread sum ################## 
    size_t single_thread_sum = 0;
    auto single_t_start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) {
        single_thread_sum += random_numbers[i];
    }
    auto single_t_end = std::chrono::high_resolution_clock::now();
    auto single_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(single_t_end - single_t_start);

    // ################## data race thread sum ################## 
    
    // This will produce a wrong sum almost all of the
    // time because of the undefined behaviour caused
    // by the physical data race.
#ifndef _DISABLE_DATA_RACE
    size_t data_race_sum = 0;

    auto race_t_start = std::chrono::high_resolution_clock::now();
    std::thread data_race_thread = std::thread([&](){
        for (size_t i = 0; i < halfs; ++i) {
            data_race_sum += random_numbers[i];
        }
    });

    for (size_t i = halfs; i < iterations; ++i) {
        data_race_sum += random_numbers[i];
    }

    data_race_thread.join();
    auto race_t_end = std::chrono::high_resolution_clock::now();
    auto race_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(race_t_end - race_t_start);
#endif

    // ################## partition thread sum ################## 
    
    // currently because of the way this is setup this
    // will only work if the `iterations` is an even number.
    
    size_t partition_sum = 0, partition_sum1 = 0, parition_sum2 = 0;

    auto partition_t_start = std::chrono::high_resolution_clock::now();
    std::thread partition_thread = std::thread([&](){
        for (size_t i = 0; i < halfs; ++i) {
            partition_sum1 += random_numbers[i];
        }
    });

    for (size_t i = halfs; i < iterations; ++i) {
        parition_sum2 += random_numbers[i];
    }
    partition_thread.join();

    partition_sum = partition_sum1 + parition_sum2;

    auto partition_t_end = std::chrono::high_resolution_clock::now();
    auto partition_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(partition_t_end - partition_t_start);

    // ################## atomic thread sum ################## 
    std::atomic<size_t> atomic_sum(0);

    auto atomic_t_start = std::chrono::high_resolution_clock::now();
    std::thread atomic_thread = std::thread([&](){
        for (size_t i = 0; i < halfs; ++i) {
            atomic_sum += random_numbers[i];
        }
    });

    for (size_t i = halfs; i < iterations; ++i) {
        atomic_sum += random_numbers[i];
    }

    atomic_thread.join();
    auto atomic_t_end = std::chrono::high_resolution_clock::now();
    auto atomic_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(atomic_t_end - atomic_t_start);

    // ################## mutex thread sum ##################

    // Mutex'es can produce "dead locks" if we forgot to
    // call .unlock() and another case where the mutex goes
    // out of scope before calling the unlock, this can
    // happen in if-else block or try-catch blocks.
    
    // Mutex'es can also produce "thread starvation" where
    // the other threads cannot accquire resource or is
    // waiting for a very very long long time. A possible cause
    // of this case is when one thread that locks a mutex takes
    // an eternity before unlocking it back.

    size_t mutex_sum = 0;
    std::mutex main_mutex;

    auto mutex_t_start = std::chrono::high_resolution_clock::now();
    std::thread mutex_thread = std::thread([&](){
        for (size_t i = 0; i < halfs; ++i) {
            main_mutex.lock();
            mutex_sum += random_numbers[i];
            main_mutex.unlock();
        }
    });

    for (size_t i = halfs; i < iterations; ++i) {
        main_mutex.lock();
        mutex_sum += random_numbers[i];
        main_mutex.unlock();
    }

    mutex_thread.join();
    auto mutex_t_end = std::chrono::high_resolution_clock::now();
    auto mutex_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(mutex_t_end - mutex_t_start);

    // ################## mutex with lock_guard thread sum ##################

    size_t lockGuardedMutex_sum = 0;
    std::mutex lockGuardedMutex;

    auto lockGuardedMutex_t_start = std::chrono::high_resolution_clock::now();
    std::thread lockGuardedMutex_thread = std::thread([&](){
        for (size_t i = 0; i < halfs; ++i) {
            std::lock_guard<std::mutex> mtxLockGuard(lockGuardedMutex);
            lockGuardedMutex_sum += random_numbers[i];
        }
    });

    for (size_t i = halfs; i < iterations; ++i) {
        std::lock_guard<std::mutex> mtxLockGuard(lockGuardedMutex);
        lockGuardedMutex_sum += random_numbers[i];
    }

    lockGuardedMutex_thread.join();
    auto lockGuardedMutex_t_end = std::chrono::high_resolution_clock::now();
    auto lockGuardedMutex_t_dur = std::chrono::duration_cast<std::chrono::milliseconds>(lockGuardedMutex_t_end - lockGuardedMutex_t_start);

    // ################## results ##################
    std::cout << "original sum         = " << sum << "\n";
    std::cout << "single thread sum    = " << single_thread_sum << "\n";
#ifndef _DISABLE_DATA_RACE
    std::cout << "data race sum        = " << data_race_sum << "\n";
#endif
    std::cout << "partition sum        = " << partition_sum << "\n";
    std::cout << "atomic sum           = " << atomic_sum << "\n";
    std::cout << "mutex sum            = " << mutex_sum << "\n";
    std::cout << "mutex lock guard sum = " << lockGuardedMutex_sum << "\n";

    std::cout << "\n\noriginal sum         time = " << rng_dur.count() << " milliseconds\n";
    std::cout << "single thread sum    time = " << single_t_dur.count() << " milliseconds\n";
#ifndef _DISABLE_DATA_RACE
    std::cout << "data race sum        time = " << race_t_dur.count() << " milliseconds\n";
#endif
    std::cout << "partition sum        time = " << partition_t_dur.count() << " milliseconds\n";
    std::cout << "atomic sum           time = " << atomic_t_dur.count() << " milliseconds\n";
    std::cout << "mutex sum            time = " << mutex_t_dur.count() << " milliseconds\n";
    std::cout << "mutex lock guard sum time = " << lockGuardedMutex_t_dur.count() << " milliseconds\n";

#ifndef _DISABLE_DATA_RACE
    return sum + single_thread_sum * data_race_sum | atomic_sum ^ mutex_sum;
#else
    return sum + single_thread_sum | atomic_sum ^ mutex_sum;
#endif
}

/*

clang++ sum.cpp -o sum.out -O3

original sum      = 38248994573
single thread sum = 38248994573
data race sum     = 19147855676
partition sum     = 38248994573
atomic sum        = 38248994573
mutex sum         = 38248994573

original sum      time = 17884 milliseconds
single thread sum time = 632 milliseconds
data race sum     time = 540 milliseconds
partition sum     time = 467 milliseconds
atomic sum        time = 8876 milliseconds
mutex sum         time = 72955 milliseconds


as you can see the data race sum has wrong answer because
of the physical data race happening.

*/