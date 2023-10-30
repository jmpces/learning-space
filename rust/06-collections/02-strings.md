# Strings

# Storing UTF-8 Encoded Text with Strings

- Core language **String Slice - `str`**

    References to some UTF-8 encoded string data stored elsewhere. **String literals**, for example, are stored in the program’s binary and are therefore string slices.

- **`String` type**

    Provided by Rust's standard library rather than coded into the core language, this type is a growable UTF-8 encoded string type.

# Creating New String


```rust
let mut s = String::new();
```

Many of the same operations available with `Vec<T>` are available with `String` as well, because `String` is actually implemented as a wrapper around a vector of bytes with some extra  guarantees, restrictions, and capabilities.

# Create String from types with `Display` trait.

Any types that **implements** the `Display` trait will always have an available `to_string()` method, **string literals** also implements that trait hence:

```rust
let s = "initial contents".to_string();
```

# Create String using the `from` function.

We can also use the function `String::from` to create a `String` from a string literal.

```rust
let s = String::from("initial contents");
```

# UTF-8 valid string values

```rust
let hello = String::from("السلام عليكم");
let hello = String::from("Dobrý den");
let hello = String::from("Hello");
let hello = String::from("שָׁלוֹם");
let hello = String::from("नमस्ते");
let hello = String::from("こんにちは");
let hello = String::from("안녕하세요");
let hello = String::from("你好");
let hello = String::from("Olá");
let hello = String::from("Здравствуйте");
let hello = String::from("Hola");
```

# Append a whole string literal/string slice.

```rust
let mut s = String::from("foo");
s.push_str("bar"); // s = foobar
```

# Append a character

```rust
s.push('l');
```

# Concatenation with `+` operator

```rust
let s1 = String::from("Hello, ");
let s2 = String::from("world!");

// note s1 has been moved here and can no longer be used
// operator `+` is an 's1' method that returns itself (moved) to s3
let s3 = s1 + &s2;
```

The `+` operator uses the `add` method, whose signature looks something like this:

```rust
fn add(self, s: &str) -> String {
```

But wait—the type of `&s2` is `&String`, not `&str`, as specified in the second parameter to `add`. So why does it compiles?

The reason we’re able to use `&s2` in the call to `add` is that the compiler can coerce the `&String` argument into a `&str`. When we call the `add` method, **Rust uses a deref coercion**, which here turns `&s2` into `&s2[..]`. 

Because `add` does not take ownership of the `s` parameter, `s2` will still be a valid `String` after this operation.

Second, we can see in the signature that `add` takes ownership of `self`, because `self` does not have an `&`. This means `s1` will be moved into the `add` call and will no longer be valid after that.

So although `let s3 = s1 + &s2;` looks like it will copy both strings and create a new one, this statement actually **takes ownership of `s1`**, **appends a copy of the contents of `s2`**, and then returns ownership of the result.

# Concatenation with Format Macro

The `format!` macro uses references so that this call doesn’t take ownership of any of its parameters, the string `s1`, `s2` and `s3` will still be a valid string after the macro call.

```rust
let s1 = String::from("tic");
let s2 = String::from("tac");
let s3 = String::from("toe");

let s = format!("{s1}-{s2}-{s3}");
//  s = "tic-tac-toe"
```

# Indexing Into Strings

It is not allowed to index `String` in rust, this is because unlike other languages like C and C++, rust uses `UTF-8` encoding (this encoding could use up to 1-4 bytes of data) instead of the `ASCII` (fixed one byte for characters) which can cause confusion to developers so rust doesn't allow it.


# Bytes and Scalar Values and Grapheme Clusters! Oh My!

**Indexing into a string is often a bad idea because it’s not clear what the return type of the string-indexing operation should be: a byte value, a character, a grapheme cluster, or a string slice.**

If we look at the Hindi word “नमस्ते” written in the **Devanagari script**, it is stored **as a vector of `u8` values** that looks like this:

```rust
[224, 164, 168, 224, 164, 174, 224, 164, 184, 224, 165, 141, 224, 164, 164, 224, 165, 135]
```

If we look at them **as Unicode scalar values**, which are what **Rust’s `char` type** is, those bytes look like this:

```rust
['न', 'म', 'स', '्', 'त', 'े']
```

There are six char values here, but the fourth and sixth are not letters: they’re diacritics that don’t make sense on their own.

Finally, if we look at them **as grapheme clusters**, we’d get what a person would call the four letters that make up the Hindi word:

```rust
["न", "म", "स्", "ते"]
```

It isn’t also possible to guarantee O(1) performance with a `String` indexing, because Rust would have to walk through the contents from the beginning to the index to determine how many valid characters there were.


# Slicing Strings

Rather than indexing using `[]` with a single number, you can **use `[]` with a range to create a string slice** containing particular bytes:

```rust
let hello = "Здравствуйте";
let s = &hello[0..4];
```

If we were to try to slice only part of a character’s bytes with something like `&hello[0..1]`, Rust would panic at runtime in the same way as if an invalid index were accessed in a vector.

> [!WARNING]  
> You should use ranges to create string slices with caution, because doing so can crash your program, and you will still get the behaviour given above when indexing a `UTF-8` string.

# Methods for Iterating Over Strings : Char

For individual Unicode scalar values, use the `chars` method. Calling chars on `“Зд”` separates out and returns two values of type `char`:

```rust
for c in "Зд".chars() {
    println!("{c}");
}
```

This code will print the following:


```bash
З
д
```

# Methods for Iterating Over Strings : Bytes

Alternatively, the `bytes` method returns each raw byte, which might be appropriate for your domain:

```rust
for b in "Зд".bytes() {
    println!("{b}");
}
```

This code will print the four bytes that make up this string:

```bash
208
151
208
180
```

# Methods for Iterating Over Strings : Grapheme Cluster

Getting grapheme clusters from strings as with the Devanagari script is complex, so this functionality is not provided by the standard library. Crates are available on crates.io if this is the functionality you need.

