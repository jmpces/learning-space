# **[Rust Lang](../Rustlang.md)**

# **Data Types**

In rust data types have two subsets;
- **scalar** types
- and **compound** types

# **Scalar Types**

A scalar type represents a single value. Rust has four primary scalar types: integers, floating-point numbers, Booleans, and characters. You may recognize these from other programming languages. Let’s jump into how they work in Rust.

In other languages they can be called as "built-in" or "primitive" types.

# **Integers** 

| Length   | Signed  | Unsigned |
| -------- | ------- | -------- |
| 8-bit    | `i8`    | `u8`     |
| 16-bit   | `i16`   | `u16`    |
| 32-bit   | `i32`   | `u32`    |
| 64-bit   | `i64`   | `u64`    |
| 128-bit  | `i128`  | `u128`   |
| arch-bit | `isize` | `usize`  |

### **Integer literal formats**

Like C, C++ and Python. Rust also supports writing integers in other
representation format.

This being on **Binary (`0b`)**, **Octal (`0o`)**, **Decimal** and
**Hex (`0x`)**. Rust also have a **Byte** e.g. : `b'A'`.

You can also separate a digit literal with the `_` (underscore) character
to make it easier to read, example:

```rust
let tenthousand = 10_000;
```

> [!NOTE]  
> The `_` (underscore) is just ignored, so the following
literal expression is valid:

```rust
let ten = 1____________0; // 10
let onehundred = 1_0_0;   // 100
let lucky = 7_77;         // 777
```

### **Rust Integer Overflows**

- **Debug Mode** - Rust includes checks for integer overflow that cause your program to panic at runtime if this behavior occurs. Rust uses the term panicking when a program exits with an error;

- **Release Mode** - Rust does not include checks for integer overflow that cause panics. Instead, if overflow occurs, Rust performs two’s complement wrapping.

Unlike C and C++, Rust considers wrapping behavior an error, to **explicitly** handle the possibility of overflow, the standard library provides families of methods for primitive numeric types like:

- `wrapping_*` methods ex: `wrapping_add`
- `checked_*`
- `overflowing_*`
- `saturating_*`

# **Floating-Points**

Represented by the usual **IEEE-754** standard.

| Length | Precision | type-keyword |
| ------ | --------- | ------------ |
| 32-bit | Single    | **`f32`**    |
| 64-bit | Double    | **`f64`**    |

# **Boolean Types**

Unlike C and C++ where a boolean is just an integers, Rust has a distinguished difference between **integer** types and **boolean** types.

In rust a **boolean** has the same size as a **byte**, and a boolean can only contain the value **`true`** and **`false`**.

# **Character types**

Another difference unlike C and C++ where `int8` are just `char` (characters), rust also separates the two, in rust the type for characters is **`char`** and this is different from **`i8`** type.

Rust’s `char` type is **four bytes** in size and represents a Unicode Scalar Value.

# **Compound Types**

Compound types can **group multiple values into one type**. Rust has two 
primitive compound types: tuples and arrays, both of these types allocate
elements **on stack**, so by default their size cannot grow.

# **Tuples**

A tuple is a general **way of grouping** together a number of **values** with a **variety of types** into **one** compound type.

Tuples have a **fixed length**: once declared, they cannot grow or shrink in size.


**Initializing** a tuple with **type annotation**, the type **count** and the argument **count** should be the same, _type annotation format_ : `(types, ...)`.

```rust
let tup: (i32, f64, u8) = (500, 6.4, 1);
```

**Initializing** without annotations, just literals with different types achieved through their post-fix type indicators.

```rust
let tup = (300u32, 32.43f64, 255u64);
```

**Initializing** without type annotation and other specifiers, this will just promt the tuple to take the default type of the literals `500` as `i32`, `64.4` as double and `1` as `i32` (for x86-64 bit systems).
```rust
let tup = (500, 6.4, 1);
```

**Destructuring** a tuple is also possible in rust.

```rust
let (x, y, z) : (u32, f64, u64) = (300, 32.43, 255);
// or
let (x, y, z) = (300u32, 32.43f64, 255u64);
// or
let tup : (u32, f64, u64) = (300, 32.43, 255);
let (x, y, z) = tup;
```
**Indexing** a tuple.
```rust
let x = tup.0;
let y = tup.1;
let z = tup.2;

println!("{x}, {y}, {z}"); // variables

// accessing a tuple index is an expression so we cannot
// put them inside the placeholder {}
println!("{}, {}, {}", tup.0, tup.1, tup.2,);
```

# **Arrays**

Unlike a tuple, every element of an array must have the **same type**. Unlike arrays in some other languages, arrays in Rust have a **fixed length**.

Arrays are useful when you want your data allocated on the stack rather than the heap.

**Initializing** arrays **without type annotations** automatically detects the types and the size, the values should all be of the same type.

```rust
let arr = [1.0f32, 2f32, 3.3f32, 4f32, 5f32];
```

**Initializing with type annotations**, _type annotation format_ : `[type, size]`

```rust
let arr : [u32; 5] = [1, 2, 3, 4, 5];
```

**Initializing all index with one value**, _type annotation format_ : `[value, size]`

```rust
let arr = [-9i64; 7];
```

Arrays are useful when representing collections of small and known sizes, like for example the name of the months:

```rust
let months = [
    "Jan" , "Feb" , "March", "April",
    "May" , "June", "July" , "Aug"  ,
    "Sept", "Oct" , "Nov"  , "Dec"
];
```

### **Accessing Element**

Like many programming languages, **rust** also have array indexing with the `[]` square bracket (indexing) operator.

Though by default, we can only pass a type `usize` into it, unlike other programming languages where we can pass any integer types.

### **Bounds Checking**

**In C/C++** we use the flag `-fsanitize=address` as a **dynamic analysis** tool in out unit tests or CI, to check if there is a stack or heap buffer overflow that occurred when indexing through  arrays.

We can also implement an array type container/class that has its own internal bound checking functionality, this could be achieved by overloading the `operator[](size_t) {}`.

On the other hand, **In Rust** this bound checking is already built in, **Rust** checks the given index if it is greater than the length of an array and stops the program when an overflow occurs, no need to use a compiler flag, and/or no need to implement your own bound checking.