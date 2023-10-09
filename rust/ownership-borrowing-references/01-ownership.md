# Ownership

The main purpose of ownership is to manage heap data.

### Ownership Rules

1. Each value in rust has an owner
2. There can only be one owner at a time:
    - By default, when we **assign a variable to another variable**, the new variable becomes the owner of the value, rendering the old variable invalid and unusable (this is a **move**).
    - Similarly also by default, if we **pass a variable as a function argument**, the old variable also becomes invalid, and the function parameter now becomes the new owner (this is also another **move**).
3. When the owner goes out of scope, the value will be dropped.

_As you can see here **move** are the default behaviour of rust when assigning or passing variables_.

> [!Note]  
> In C++, this pattern of deallocating resources at the end of an item’s lifetime is called the **RAII** or **Resource Acquisition Is Initialization**.
>
> The `drop` function in Rust will be familiar to you if you’ve used RAII patterns, this is quiet similar to `destructors` of C++ classes where it is also automatically called when an object goes out of scope, **except that in rust the old variable becomes unusable** because of the default move.

### Stack Data Should Be Copied

Rust has a special annotation called the `Copy` **trait** that we can place on types that are stored on the stack.

If a **type implements** the **`Copy` trait**, variables that use it **do not move**, but rather are **trivially copied**, making them **still valid after assigning** to another variable.

Some rust built-in data types implements the `Copy` trait by default like scalar value and arrays on stack.

```rust
// variable on stack is copied
let x = 5;
let y = x;

// "x" is still accessible and usable
println!("x = {x}, y = {y}");

// array on stack is copied
let a = [32usize; 10];
let mut b = a;

b[0] = 555;

// "a" is still accessible and usable
for n in a { print!("{n} ") }
println!();

for n in b { print!("{n} ") }
println!();
```

Rust **won’t let us annotate** a type with `Copy` trait **if** the type, or any of its parts, has **implement**ed the **`Drop` trait**.

If the type needs something special to happen when the value goes out of scope and we add the Copy annotation to that type, we’ll get a compile-time error.

So, what types implement the Copy trait? You can check the documentation for the given type to be sure, but as a **general rule**, **any** group of simple scalar values can implement Copy, and **nothing that requires allocation** or is **some form of resource** can implement Copy.

Here are some of the types that implement Copy:

- All the integer types, such as `u32`.
- The Boolean type, `bool`, with values `true` and `false`.
- All the floating-point types, such as `f64`.
- The character type, `char`.
- Tuples, if they only contain types that also implement Copy. For example, (`i32`, `i32`) implements Copy, but (`i32`, String) does not.

### Heap Data are Move (In C++ Term) by Default

By following the rules that was previously stated above, it is impossible to directly copy heap-allocated data like the `String` type since it **does not implement** the **`Copy` trait** so it will always be a **move**.

_The `String` type might also implements the `Drop` trait somewhere inside its declaration be it indirectly or directly to clean-up heap-allocated resources_.

```rust
let s1 = String::from("hello");
let s2 = s1;

println!("{}, world!", s2);
// println!("{}, world!", s1); // compilation error
```

### Copying Heap Data

If we do want to **copy the heap data** of the String and other heap-allocated data types, not just the stack data, we can use a common method called `clone()`. 

_In my understanding the clone method should be implemented in a way that it allocates a new space in the heap, then it copies the values of the original data, after that using the default move semantic behaviour of rust mentioned in the very begining; the new heap-allocated copied data will be move to the variable where it was assigned or passed if it was a function_.

```rust
let s1 = String::from("hello");
let s2 = s1.clone();

// we can still use "s1" because it was not moved.
println!("s1 = {}, s2 = {}", s1, s2);
```

### Ownership and Functions

The mechanics of passing a value to a function are similar to those when assigning a value to a variable. Passing a variable to a function will move or copy, just as assignment does ([as stated above in no.3](#ownership-rules)).

When passing a variable in a paremeter as an argument that is not a reference, the value **ownership** will be move to the function parameter, leaving the old variable unusable.

```rust
fn main() {
    let s = String::from("hello");

    takes_ownership(s);     // s's value moves into the function.
    // println!("s = {s}"); // "s" is no longer valid here - compile error

    let x = 5;

    makes_copy(x); // "x" would move into the function,
                   // but i32 is Copy, so it's okay to still
                   // use x afterward
}

fn takes_ownership(some_string: String) {
    println!("{}", some_string);
    // When "some_string" goes out of scope after the function
    // was called/invoked the `drop` method is called freeing
    // the heap-allocated memory.
}


fn makes_copy(some_integer: i32) {
    println!("{}", some_integer);
    // Here, some_integer goes out of scope. Nothing special happens.
}
```

### Return Values and Scope

Returning values can also transfer ownership, this is one way to return the ownership of a variable after we pass it to a function.

```rust
fn main() {
    let mut s = String::from("hello");

    s = takes_ownership(s); // s's value moves into the function.

    // "s" is valid again because we return a new value for "s" to own.
    println!("s = {s}");
}

fn takes_ownership(some_string: String) -> String {
    println!("{}", some_string);
    
    // this is now a move, we returned the ownership
    // remember this is an implicit return in rust.
    some_string
}
```