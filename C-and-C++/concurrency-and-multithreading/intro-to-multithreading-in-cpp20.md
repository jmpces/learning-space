# **An Introduction to Multi-Threading in C++ 20**

## **Multithreading for Scalability**

Amdahl's Law

$$
S = \dfrac{1}{1 - p + \dfrac{p}{n}}
$$

- $S$ = Maximum speed-up multiplier.
- $p$ = Fraction/percentage that can be parallelized.
- $n$ = Number of processor cores.

## **Built-in parallel algorithms** 

Some standard C++ algorithm have built-in parallel version,
use them if there is one for that specific algorithm.

ex:

```c++
std::vector<MyData> data = { ... };
std::sort(
    std::execution::par,
    data.begin(), data.end(),
    MyComparator{}
);
```

Only use this on appropriate times, like in the example above
if we have a trillion `MyData` elements then it's better to
use the parallel version of `std::sort`.