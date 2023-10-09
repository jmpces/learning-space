# **Template Programming**

## **Compile Time Polymorphism : Heap or Stack Allocations**

In this examples we will try to create a class that can allocate an array attribute/member on stack or in heap without using runtime-polymorphism.

- **Example 1 :**

  Here we achieve compile time polymorphism using the following C++ features.

  - templates
  - [inheritance](https://en.cppreference.com/book/intro/inheritance)
  - [template-template parameter](https://en.cppreference.com/w/cpp/language/template_parameters#Template_template_parameter)

  ```c++
  #include <iostream>

  template <typename T, size_t Rows, size_t Cols>
  struct stack_allocator {
    T arr[Rows * Cols];

    stack_allocator() : arr() {}
  };

  template <typename T, size_t, size_t>
  struct heap_allocator {
    T *arr;
    size_t rows;
    size_t cols;

    heap_allocator(size_t rows, size_t cols) : arr(new T[rows * cols]), rows(rows), cols(cols) {}

    ~heap_allocator() { delete [] arr; }
  };

  template <typename T, size_t Rows, size_t Cols, template <typename _T, size_t _Rows, size_t _Cols> typename Allocator>
  struct Matrix : public Allocator<T, Rows, Cols> {
    Matrix() : Allocator<T, Rows, Cols>() {}
    Matrix(size_t rows, size_t cols) : Allocator<T, Rows, Cols>(rows, cols) {}
  };

  int main() {
    Matrix<char, 5, 5, stack_allocator> a;
    Matrix<char, 0, 0, heap_allocator> b(5, 5);

    std::cout << "sizeof(a) = " << sizeof(a) << "\n";

    // 16 byte for the two size_t members
    // and another 8 byte (4 byte for x86) for the pointer.
    std::cout << "sizeof(b) = " << sizeof(b) << "\n";
  }
  ```

- **Example 2 :**

  Here we achieve compile time polymorphism using the following C++ features.

  - templates
  - [inheritance](https://en.cppreference.com/book/intro/inheritance)
  - [partial template specialization](https://en.cppreference.com/w/cpp/language/partial_specialization)

  ```c++
  #include <iostream>

  template <size_t Rows, size_t Cols, class T>
  struct stack_allocator {
    T data[Rows * Cols];

    stack_allocator() : data() {
    }
  };

  template <class T>
  struct heap_allocator {
    T *data;
    size_t rows;
    size_t cols;

    heap_allocator(size_t rows, size_t cols) : data(new T[rows * cols]), rows(rows), cols(cols) {
    }
    ~heap_allocator() {
      delete[] data;
    }
  };

  template <class T, size_t Rows = 0, size_t Cols = 0>
  struct Matrix : public stack_allocator<Rows, Cols, T> {
    Matrix() : stack_allocator<Rows, Cols, T>() {
    }
  };

  // Partial specialization for heap_allocator
  template <class T>
  struct Matrix<T, 0, 0> : public heap_allocator<T> {
    Matrix(size_t rows, size_t cols) : heap_allocator<T>(rows, cols) {
    }
  };

  int main() {
    Matrix<char, 5, 5> a; // Uses stack_allocator
    Matrix<char> b(5, 5); // Uses heap_allocator

    std::cout << "sizeof(a) = " << sizeof(a) << "\n";

    // 16 byte for the two size_t members
    // and another 8 byte (4 byte for x86) for the pointer.
    std::cout << "sizeof(b) = " << sizeof(b) << "\n";
  }

  ```

- **Example 3:**

  In my opinion this is a much cleaner way.

  ```c++
  template <size_t Rows, size_t Cols>
  struct stack_allocator {
    static constexpr size_t rows = Rows;
    static constexpr size_t cols = Cols;

    template <typename _T, size_t _Rows, size_t _Cols>
    struct allocate {
      static constexpr size_t rows = _Rows;
      static constexpr size_t cols = _Cols;
      _T matrix[_Rows * _Cols];
      allocate() : matrix() {}
    };
  };

  template <size_t Rows = 0, size_t Cols = 0>
  struct _heap_allocator {
    static constexpr size_t rows = Rows;
    static constexpr size_t cols = Cols;

    template <typename _T, size_t _Rows, size_t _Cols>
    struct allocate {
      _T *matrix;
      size_t rows = _Rows;
      size_t cols = _Cols;
      allocate(size_t rows, size_t cols) : matrix(new _T[rows * cols]), rows(rows), cols(cols) { }
      ~allocate() { delete [] matrix; }
    };
  };

  typedef _heap_allocator<> heap_allocator;

  template <typename T, typename dim>
  struct Matrix : dim::template allocate<T, dim::rows, dim::cols>  {
    Matrix() : dim::template allocate<T, dim::rows, dim::cols>() {}
    Matrix(size_t rows, size_t cols) : dim::template allocate<T, dim::rows, dim::cols>(rows, cols) {}
  };

  int main() {
    Matrix<char, stack_allocator<5, 5>> a; // Uses stack_allocator
    Matrix<char, heap_allocator> b(5, 5); // Uses heap_allocator
  }
  ```