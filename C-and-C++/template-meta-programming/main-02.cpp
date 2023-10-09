#include <iostream>
#include <tuple>
#include <utility>

void println() {
    std::cout << '\n';
}

template<typename last_t>
void println(last_t arg) {
    std::cout << arg << '\n';
}

template<typename T0, typename ... TRest>
void println(T0 arg, TRest... args) {
    std::cout << arg << ", ";
    println(args...);
}

// `std::index_sequence<indices...>` - even though the parameter is not
// used, the reason why its here is for the compiler knows which overload
// to pick, this principle of taking a parameter just for the type and
// not for its data is called "Tag Dispatch"

template<typename tuple_t, size_t ... indices>
void print_tuple_impl(tuple_t tuple_arg, std::index_sequence<indices...>) { 
    println(std::get<indices>(tuple_arg)...);
    // expands the `indices` to
    // println(std::get<0>(tuple_arg),
    // println(std::get<1>(tuple_arg),
    // ...
    // println(std::get<N>(tuple_arg),
}

template <typename tuple_t>
void print_tuple(tuple_t tuple_arg) {
    // used tag dispatch
    print_tuple_impl(
        tuple_arg,
        // creates a `std::integer_sequence`
        std::make_index_sequence<
            // returns the size of the tuple type
            std::tuple_size<tuple_t>::value
        > {}
    );
}

int main() {
    println(9, "hello", true, 5.7f);
    println();
    println(7.8);

    // Creates a tuple object, deducing the target type from the types of
    // arguments (see move semantics, perfect forwarding for more info).
    auto myTuple = std::make_tuple("hello", "there", 99, true);

    print_tuple(myTuple);
}