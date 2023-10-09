# Metaprogramming

- **Program** - Something that inputs a data, transforms/process that said data to a process output data or information.

- **Metaprogram** - Something that transforms programs or code instead of data.
    - If it looks at it's own structure it is a **reflection**, C++ meta prgramming with templates is a reflection.

# Template Specialization

- **Basic Template Declaration**

    ```c++
    template<typename KEY, typname DATA>
    struct Qmap {
        Qmap() { std::cout << "Qmap\n"; }
    };
    ```

- **Partial Specialization** - not all template parameters are filled in but only some, it will works for all cases of the template where the first parameter is deduced to be an `int`.

    ```c++
    template<typname DATA>
    struct Qmap<int, DATA> {
        Qmap() { std::cout << "Qmap<int, DATA>\n"; }
    };
    ```

- **Full Specialization** - all template parameters are filled in.

    ```c++
    template<>
    struct Qmap<int, int> {
        Qmap() { std::cout << "Qmap<int, int>\n"; }
    };
    ```

The compiler will check all of the different specialization, as well as the main template definition, and see which ones will work with these template parameters, the compiler will then choose which of the **candidate set** is more specific.

# Initializing with Template Classes - Template Argument Deduction

- **Aggregate Initialization** - providing values inside `{}` that matches the member variables values and types of the class.

- **Constructor Initialization** - construction of objects with `{}` is also possible by creatinh a constructor that will match the values and types inside the `{}` initialization values.

```c++
int main() {
    // chooses the main template definition
    auto A = Qmap<float, bool>();

    // the main and partial definition are a match, but the compiler
    // will choose the partial template specialization because it is
    // more specific.
    auto B = Qmap<int, bool>();

    // will choose the full partial Specialization of the double
    // in template parameter since it is the most specific.
    auto C = Qmap<int, int>();
}
```

# Type Traits

C++ provides predefined meta functions built in to the standard library.

# Checking if Type is Pointer/Reference

To know more about template meta programming let us implement the `std::is_pointer<T>::value` of the standard library that checks if the given template parameter `T` type is a pointer type `T*` or not.

```c++
// for all possible cases except the Specializations, this struct will
// return false
template<typename T>
struct is_pointer {
    static constexpr bool value = false;
}

// specializes if the given type is a pointer it will return true.
template<typename T>
struct is_pointer<*T> {
    static constexpr bool value = true;
}
```

# Manipulating Types: Striping Pointer Types

Here is another example of how to get only the type `T` of a pointer `T*` using template specialization.

```c++
// returns the type itself if the type is not a pointer.
template<typename T>
struct strip_pointer {
    using type = T;
}

// returns only the type of a given pointer type.
template <typename T>
struct strip_pointer<T*> {
    using type = T;
}
```