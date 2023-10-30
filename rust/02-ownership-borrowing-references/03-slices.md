# Slices

Slices let you reference **a part** of a contiguous sequence of elements in a collection rather than the whole collection. A slice is **a kind of reference**, so it **does not have ownership**.

All rules of ownership and borrowing also applies to slices.

```rust
let a = [1, 2, 3, 4, 5];
let slice = &a[1..3];
assert_eq!(slice, &[2, 3]);
```

We create slices using a range within brackets by specifying `[starting_index..ending_index]`, where:

- `starting_index` is the first position in the slice
- `ending_index` is one more than the last position in the slice.

We can drop the **`starting_index` number** if we want to automatically start at the front most index of our slice, e.g: `&a[..3]`.

We can also drop the **`ending_index` number** if want to slice up until to the last most index automatically, e.g: `&a[1..]`.

We can **even drop both `starting_index`** and **`ending_index`** values in the slice range to get a whole slice, e.g: `&a[..]`.

> [!Note]  
> String slice range indices must occur at valid UTF-8 character boundaries.
>
> If you attempt to create a string slice in the middle of a multibyte character, your program will exit with an error.
>
> For the purposes of introducing string slices, we are assuming ASCII only in this section; a more thorough discussion of UTF-8 handling is in the “Storing UTF-8 Encoded Text with Strings” section of Chapter 8.

# Slice Types

This slice has the type `&[i32]`

```rust
let slice = &a[1..3];
```

This kind of slice is common for different types of collections, the format of the type of the slice is, It works the same way as string slices do, by **storing a reference** to the **first element** and a **length**.

```rust
&[type]
```

# Functions and Slices

**`iter()`** is a method that returns each element in a collection.

**`enumerate()`** wraps the result of `iter()` and returns each element as part of a `tuple` instead, The first element of the `tuple` returned from `enumerate()` is the **index**, and the second element is a **reference to the element**. This is a bit more convenient than calculating the index ourselves.

Because the `enumerate()` method returns a `tuple`, we can use patterns to **destructure** that `tuple` .

We’ll be discussing patterns more in Chapter 6. In the `for` loop, we specify a pattern that has `i` for the **index** in the `tuple` and `&item` for the **single byte** in the `tuple`. Because we get a **reference to the element** from `.iter().enumerate()`, we use `&` in the pattern.

```rust
fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    // returns the whole word
    &s[..]
}
```

# String Literals as Slices

**The type of `s` here is `&str`** a string slice, it is a `slice` pointing to that specific point of the binary. This is also why **string literals are immutable**; `&str` is an immutable reference.

```rust
let s = "Hello, world!";
```

# String Slices as Parameters and Return Types

```rust
fn first_word(s: &String) -> &str {
```

A more experienced Rustacean would write the signature shown below instead of the version above because it allows us to use the same function on both `&String` values and `&str` values.

```rust
fn first_word(s: &str) -> &str {
```

This flexibility takes advantage of deref coercions, a feature we will cover in **“Implicit Deref Coercions with Functions and Methods”** section of **Chapter 15**.

--------------------------------------------------------

The concepts of ownership, borrowing, and slices ensure memory safety in Rust programs at compile time. The Rust language gives you control over your memory usage in the same way as other systems programming languages, but having the owner of data automatically clean up that data when the owner goes out of scope means you don’t have to write and debug extra code to get this control.