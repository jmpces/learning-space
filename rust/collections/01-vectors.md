# Vectors

# Initializing Empty Vectors

```rust
let v: Vec<i32> = Vec::new();
```

Note that we added a type annotation here. Because we aren’t inserting any values into this vector, Rust doesn’t know what kind of elements we intend to store. Vectors are implemented using generics.

# Initializing Vectors with Values

Rust conveniently provides the `vec!` macro, which will create a new vector that holds the values you give it. 

Rust can infer that the type of `v` is `Vec<i32>` just by looking at the given values, and the type annotation isn’t necessary. 

```rust
let v = vec![1, 2, 3];
```

# Updating Vectors

As with any variable, if we want to be able to change its value, we need to make it mutable using the `mut` keyword.

```rust
let mut v = Vec::new();

v.push(5);
v.push(6);
```

# Reading Elements of Vectors

There are **two ways** to **reference a value** stored in a vector: via **indexing** or using the **`get/get_mut` methods**.

**Instantiate a vector**

```rust
let v = vec![1, 2, 3, 4, 5];
```

**Access elements using indexing operator**

This method of accessing elements of a vector will panic if the given index is out of bounds.

```rust
let third: &i32 = &v[2];
println!("The third element is {third}");
```

**Access elements using `get` method**

When we pass an index that is outside the size range of the vector in `get` method, it will return a  `None` Option enum variant without panicking. 

The get method returns a `Option<&T>` enum if the given index is in range of the vector size.

```rust
let third: Option<&i32> = v.get(2);
match third {
    Some(third) => println!("The third element is {third}"),
    None => println!("There is no third element."),
}
```

# Iterating over the Values in a Vector

To change the value that the mutable reference refers to, we have to use the `*` dereference operator to get to the value in i before we can use the `+=` operator.

```rust
let mut v = vec![100, 32, 57];

for i in &mut v {
    *i += 50;
}

for i in &v {
    println!("{i}");
}
```

Iterating over a vector, whether immutably or mutably, is safe because of the borrow checker's rules. If we attempted to insert or remove items in the `for` loop bodies, we would get a compiler error. The **reference to the vector** that the `for` loop holds **prevents simultaneous modification of the whole vector**.

# Using an Enum to Store Multiple Types

Vectors can only store values that are the same type. This can be inconvenient; there are definitely use cases for needing to store a list of items of different types. Fortunately, the variants of an enum are defined under the same enum type, so when we need one type to represent elements of different types, we can define and use an enum!

```rust
enum SpreadsheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

let row = vec![
    SpreadsheetCell::Int(3),
    SpreadsheetCell::Text(String::from("blue")),
    SpreadsheetCell::Float(10.12),
];
```