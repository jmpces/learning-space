#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <string>
#include <exception>

/// supports: C++11 and above only
namespace randomize
{
    std::uint16_t random_this() {
        auto seed_data = std::array<int, std::mt19937::state_size>();
        auto random_device = std::random_device();
        std::generate_n(std::data(seed_data), std::size(seed_data), std::ref(random_device));
        auto sequence = std::seed_seq(std::begin(seed_data), std::end(seed_data));
        auto rng = std::mt19937(sequence);
        return std::uniform_int_distribution(0, std::numeric_limits<std::uint16_t>::max())(rng);
    }

    template<typename T, typename E>
    T integer()
    {
        T machine_min = T(std::numeric_limits<T>::min());
        T machine_max = T(std::numeric_limits<T>::max());
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        E rand_engine(seed);
        std::uniform_int_distribution<T> random_number(machine_min,machine_max);
        return random_number(rand_engine);
    }

    template<typename T, typename E>
    T integer(T min, T max)
    {
        T machine_min = T(std::numeric_limits<T>::min());
        T machine_max = T(std::numeric_limits<T>::max());

        if(min>max)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::integer(min,max)\n\tthe min("+std::to_string(min)+") given is greater than the given max("+std::to_string(max)+")\n"
            );
        }
        else if(max<min)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::integer(min,max)\n\tthe max("+std::to_string(max)+") given is less than the given min("+std::to_string(min)+")\n"
            );
        }
        else if(min<machine_min)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::integer(min,max)\n\tthe min("+std::to_string(min)+") overflow - limit:"+std::to_string(machine_min)+"\n"
            );
        }
        else if(max>machine_max)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::integer(min,max)\n\tthe max("+std::to_string(max)+") overflow - limit:"+std::to_string(machine_max)+"\n"
            );
        }

        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        E rand_engine(seed);
        std::uniform_int_distribution<T> random_number(min,max);
        return random_number(rand_engine);
    }

    template<typename T, typename E>
    T real()
    {
        T machine_min = T(std::numeric_limits<T>::min());
        T machine_max = T(std::numeric_limits<T>::max());
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        E rand_engine(seed);
        std::uniform_real_distribution<T> random_number(machine_min,machine_max);
        return random_number(rand_engine);
    }

    template<typename T, typename E>
    T real(T min, T max)
    {
        // T machine_min = T(std::numeric_limits<T>::min());
        // T machine_max = T(std::numeric_limits<T>::max());

        if(min>max)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::real(min,max)\n\tthe min("+std::to_string(min)+") given is greater than the given max("+std::to_string(max)+")\n"
            );
        }
        else if(max<min)
        {
            throw std::range_error
            (
                "\n\nERROR: randomize::real(min,max)\n\tthe max("+std::to_string(max)+") given is less than the given min("+std::to_string(min)+")\n"
            );
        }

        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        E rand_engine(seed);
        std::uniform_real_distribution<T> random_number(min,max);
        return random_number(rand_engine);
    }
}

#endif
