#ifndef CHRONO_MINI_BENCHMARK_HPP
#define CHRONO_MINI_BENCHMARK_HPP

#include <iostream>
#include <chrono>

#define BENCHMARK_NANOSECONDS(BLOCK_NAME,ITERATIONS,CODE_BLOCK) { \
    auto start = std::chrono::high_resolution_clock::now(); \
    for(size_t i=0; i<ITERATIONS; ++i) \
    { \
        CODE_BLOCK \
    } \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start); \
    std::cout << BLOCK_NAME << " took " << duration.count() << " nanosecond(s)\n"; \
}

#define BENCHMARK_MILLISECONDS(BLOCK_NAME,ITERATIONS,CODE_BLOCK) { \
    auto start = std::chrono::high_resolution_clock::now(); \
    for(size_t i=0; i<ITERATIONS; ++i) \
    { \
        CODE_BLOCK \
    } \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start); \
    std::cout << BLOCK_NAME << " took " << duration.count() << " millisecond(s)\n"; \
}

#define BENCHMARK_MICROSECONDS(BLOCK_NAME,ITERATIONS,CODE_BLOCK) { \
    auto start = std::chrono::high_resolution_clock::now(); \
    for(size_t i=0; i<ITERATIONS; ++i) \
    { \
        CODE_BLOCK \
    } \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start); \
    std::cout << BLOCK_NAME << " took " << duration.count() << " microsecond(s)\n"; \
}

#define BENCHMARK_SECONDS(BLOCK_NAME,ITERATIONS,CODE_BLOCK) { \
    auto start = std::chrono::high_resolution_clock::now(); \
    for(size_t i=0; i<ITERATIONS; ++i) \
    { \
        CODE_BLOCK \
    } \
    auto end = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end-start); \
    std::cout << BLOCK_NAME << " took " << duration.count() << " second(s)\n"; \
}

template<typename T>
void print4x4(T *mat, std::string name="")
{
    std::cout << name;
    for(size_t i=0; i<4; ++i)
    {
        for(size_t j=0; j<4; ++j)
            std::cout << mat[i*4+j] << ' ';
        std::cout << "\n";
    }
    std::cout << "\n";
}

#endif