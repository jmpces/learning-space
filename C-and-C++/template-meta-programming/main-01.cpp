#include <iostream>
#include <tuple>
#include <utility>

/// \returns the `Y` type if condition is true.
/// \returns the `N` type if condition is false.
template<bool condition, typename Y, typename N>
struct if_;

template<typename Y, typename N>
struct if_<true, Y, N> {
    using type = Y;
};

template<typename Y, typename N>
struct if_<false, Y, N> {
    using type = N;
};

template<typename find_t, typename TUPLE, size_t i = 0>
struct contains_type :
    if_<
        // is element's type on index 'i' equal to 'find_t' type?
        std::is_same<find_t, std::tuple_element_t<i, TUPLE>>::value,
        
        // yes: inherit 'std::true_type'
        std::true_type,

        // no: nest another 'if_'
        typename if_<
            // is index 'i' equal to the last index value of the tuple?
            i == std::tuple_size<TUPLE>::value - 1,

            // yes: inherit 'std::false_type'
            std::false_type,

            // no: check the next index by recursion
            contains_type<find_t, TUPLE, i + 1>
        >::type
    >::type
{};

/// specialize for empty tuple
template<typename find_t>
struct contains_type<find_t, std::tuple<>> : std::false_type {};

int main() {
    std::tuple<int, bool, float> tup;

    std::cout << std::boolalpha << contains_type<bool, decltype(tup)>::value << '\n'; // true

    std::cout << std::boolalpha << contains_type<double, decltype(tup)>::value << '\n'; // false

    std::cout << std::boolalpha << contains_type<bool, std::tuple<>>::value << '\n'; // false
}