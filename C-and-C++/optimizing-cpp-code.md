## **Techniques to Optimize C++ Programs**

In general, all of these techniques can be combined to optimize C++ code.

### **Let the Compiler See Ahead**

The compiler can easily optimize code when it can anticipate the code's behavior. By using `constexpr`, macros, template arguments, or a combination of the three, we can calculate things that are possible to compute at compile time. Since these calculations are performed at compile time, the compiler can better analyze the code and optimize it more effectively.

Here are some examples:

1. Use `constexpr`, macro definitions, template integral arguments, or literals for integral types inside loop iteration conditions, if possible.
2. Utilize `constexpr` on variables that can be calculated at compile time (which can be used in #1).
3. Utilize template arguments when initializing classes (which can be used in #2 and #1).
4. Use `if constexpr` when necessary.
5. Use STL type traits to check for types at compile time, then perform casting or other operations accordingly.
6. Use macros, `constexpr`, and/or template arguments to initialize arrays on the stack (this can be done globally, locally, and inside classes/structs).

In general, try to implement compile-time preprocessing setup techniques as much as possible.

### **Put Objects on the Stack to Reduce Memory Allocations and Deallocations**

Since the stack is faster to access than the heap, consider placing objects on the stack whenever possible.

For small to medium-sized arrays, prefer placing them on the stack, especially if they are fixed-size arrays.

You can also use a fixed-size array to simulate a dynamic array as long as the maximum dynamic size does not exceed the fixed array size.

If you find yourself performing constant allocation and deallocation inside a loop or recursive call, this can slow down your program. Aim to minimize these operations to improve performance.

### **Utilize Larger Data Types or SIMD Vector Registers**

Using SIMD vector registers through inline assembly or C/C++ intrinsic functions can optimize your code.

Additionally, casting to larger types (e.g., casting a 64-byte `unsigned char` to a double element `unsigned int` array) can sometimes improve code performance. Taking advantage of wider register instruction operations when using larger data types, similar to SIMD vector registers but with limitations, can also be beneficial.

However, keep in mind that in most cases, the compiler can handle these optimizations automatically. It's still recommended to check the assembly output frequently using tools like Godbolt to verify the compiler's optimizations.

You can also combine STL std type checking with casting to larger types.

### **Minimize CPU Cache Misses**

While I have personally had limited success with this technique (only when implementing matrix multiplication), it can significantly speed up your program, sometimes by a surprising factor (e.g., 4x4 block matrix multiplication can be greatly optimized).

Memory alignment is related to this concept, but I haven't fully grasped it yet.

### **Implement Simplified Code [NOT ALWAYS THE CASE]**

In most scenarios, simpler code tends to perform faster. Reducing complexity leads to less work, resulting in improved performance. This principle holds true for C++ code as well.

1. Use algorithms with lower time complexity. However, keep in mind that memory allocation and deallocation can also impact program speed. For example, quicksort is often faster than mergesort, even if they have the same time complexity.

2. If possible, simplify or take shortcuts in the code. Constant expressions can be useful in such cases. Sometimes, we can take a shortcut, but the preprocessing setup required to do so may be performance-expensive. In such situations, consider performing the computation at compile time.
