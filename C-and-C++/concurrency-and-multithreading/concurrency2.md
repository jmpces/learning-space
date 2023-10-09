# **Concurrency 2**

## **Threads**

One process can have many threads.

- static variables are initialize even in different threads.
- Each thread shares the same code, data, and kernel
context.
    - run-time heap
    - read/write data
    - read-only code/data
    - shared libraries
- A thread has its own thread ID (TID).
- A thread has its own logical control flow.
- A thread has its own stack for local variables.

## **Passing values on a thread**

- If the `function` or lambda has a **pass-by-value** parameter.

    ```c++
    std::thread new_t(function, n);
    ```

- If the `function` or lambda has a **pass-by-reference** parameter.

    ```c++
    std::thread new_t(function, std::ref(n));
    ```

- Passing a `method` of a specific object (instance of a class).

    ```c++
    std::thread new_t(&class_name::method, &instance);
    ```

- Moving a thread.

    ```c++
    std::thread new_t(std::move(old_thread));
    ```

## **Executing multiple threads**

```c++
std::vector<std::thread> threads;

auto lambda = [](size_t x) {
    std::cout << "lambda.thread.get_id(" << x << ") : " << std::this_thread::get_id() << "\n";
};

for (size_t i = 0; i < 10; ++i) {
    threads.push_back(std::thread(lambda, i));
}

for (size_t i = 0; i < threads.size(); ++i) {
    threads[i].join();
}
```
## **C++20 jthreads**

In C++20 `std::jthread` is introduced where it automatically
calls `.join()` when the destructor is called, this happens
if the running threads went out of scope.

```c++
std::vector<std::jthread> threads;

auto lambda = [](size_t x) {
    std::cout << "lambda.thread.get_id(" << x << ") : " << std::this_thread::get_id() << "\n";
};

for (size_t i = 0; i < 10; ++i) {
    threads.push_back(std::jthread(lambda, i));
}

// in this case we don't need to create a loop that
// will call the .join() method for each thread
```

## **Condition Variables**

A way to signal an event between 2 or more threads.

Condition variables allow us to in a sense take one thread 
of the queue, until it is notified that it should start 
working.

```c++
// 42:49 - Back to Basics - Mike Shah
```

## **Barriers**

Allow a fixed number of threads to enter a critical section.
- `std::counting_semaphore`
- `std::latch`
- `std::barrier`

## **Multiple threads using Asynchronous Programming**

Asynchronous programming does not mean multi-threading in general
but in C++ we can also create multiple threads with it.

We can start running a function simultaneously using `std::async`.

```c++
auto foo = std::async(&function, arg1, arg2, ..., argN);
```

And like `std::thread` we need to call `.get()` to synchronize the program.

```c++
auto foo1 = std::async(&function, arg1, arg2, ..., argN);
auto foo2 = std::async(&function, arg1, arg2, ..., argN);

auto foo1_result = foo1.get();
auto foo2_result = foo2.get();
```
Passing `std::launch::async` as the first argument when constructing
`std::async` will force the program to create a new thread for that
function, if you omit this the decision of whether to create a thread
or not will depend on the underlying implementation.

```c++
auto foo = std::async(std::launch::async, &function, arg1, arg2, ..., argN);
```

One advantage of `std::async` is that by calling `.get()` 
method we can get the return value of the function, this
is not the case for `std::thread`'s `.join()` method.