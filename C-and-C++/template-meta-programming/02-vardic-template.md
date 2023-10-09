# Parameter Pack

A template parameter pack is a template parameter that accepts zero or more template arguments (non-types, types, or templates). A function parameter pack is a function parameter that accepts zero or more function arguments.

```c++
template<typename ... TRest>
void print(TRest... args) {
    // C++17 pack fold expression
    ((std::cout << args << ' '), ...);
}
```

A template with at least one parameter pack is called a variadic template.

# Pack Expansion

A pattern followed by an ellipsis, in which the name of at least one parameter pack appears at least once, is expanded into zero or more comma-separated instantiations of the pattern, where the name of the parameter pack is replaced by each of the elements from the pack, in order.

# Pack Fold Expansion - C++17

```c++
template<typename T, typename ... TRest>
T sum(T arg, TRest... args) {
    T total = arg;
    ((total += args), ...); // pack fold expansion syntax
    return total;
}
```

# Vardic Templates - Arbitrary Template & Function Parameter

Since we don't have for loops with variadic templates, we use recursion when iterating it.

```c++
// handle empty arguments
void println() {
    std::cout << '\n';
}

// handle base case when the type that is left is only one
template<typename last_t>
void println(last_t arg) {
    std::cout << arg << '\n';
}

// handles multiple arguments with different types
template<typename T0, typename ... TRest>
void println(T0 arg, TRest... args) {
    std::cout << arg << ", ";

    // when the `TRest` only contains one type, it will
    // not use itself, instead it will use the one argument
    // `println` template function.
    println(args...);
}
```

- `typename ... TRest` - indicates that there could be an arbitrary numbers of type names.

- `TRest.. args`       - "parameter pack" expands the given arbitrary types.

- `println(args...);`  - expand the `args` "parameter pack" values when passed to the `println` function recursively.

```c++
int main() {
    println(9, "hello", true, 5.7f);
    println();
    println(7.8);
}
```

# Printing `tuple` types using our `println`  function

**Tag Dispatch** - Here even though the function parameter **`std::index_sequence<indices...>`** is not named and used, the only reason why its here is for the compiler to know which overload to pick.

The principle of taking a parameter just for the type and not for its data is called "Tag Dispatch"

```c++
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
```

Then we can print our tuple using the new template function.

> [!IMPORTANT]  
> For this implementation, we are using pass-by-value so there would be a lot of copies being used, look for the next section to know how we can pass-by-reference with our `print_tuple` function with **perfect forwarding**.

```c++
int main() {
    // Creates a tuple object, deducing the target type from
    // the types of arguments (see move semantics perfect
    // forwarding for more info).
    auto myTuple = std::make_tuple("hello", "there", 99, true);

    print_tuple(myTuple);
}
```
continue:
9:56 - E3 - Variadic Templates - Template Metaprogramming in C++.mp4