# Generic Data Types

This an example code that finds the largest value in an array of `i32` and `char` by using duplicated code.

```rust
fn largest_i32(list: &[i32]) -> &i32 {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn largest_char(list: &[char]) -> &char {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}
```

# In Function Definitions

To define the generic largest function, place type name declarations inside angle brackets, `<>`, between the name of the function and the parameter list, like this:

```rust
fn largest<T>(list: &[T]) -> &T {
```

Now this is the generic code equivalent to the code example in the section above. Here we use `T` as a placeholder for the types that will be used in the function.

```rust
fn largest<T>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}
```

> [!IMPORTANT]  
> This code will **fail to compile**, the line `if item > largest` uses the greater than operator, but what if we pass a type `T` that does not implement the **greater than operator** (or a certain trait or operator?) rust would detect this error at compile time.

# Adding Traits as Type Constraints

The code below fixes the problem above:

```rust
fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}
```

The `std::cmp::PartialOrd` is a restriction for the type `T`, imagine it like **`C++ Concepts or the older SFINAE`** to restrict types. In C++, if we only give `T` without the restriction we might get missing symbol or reference errors in the future, to prevent this problem with templates in C++20 we can use **concepts** to add restrictions to the types that we are passing to our template parameters.

Similarly in the rust code above, adding the trait `: std::cmp::PartialOrd` will restrict the types valid for `T` to only those that implement the said trait, this would tell the compiler that it should only accept types that can be ordered or have the greater than operator.

The standard library implements `PartialOrd` on both `i32` and `char` hence the new code will now compile.

# In Struct Definitions

We can also define structs to use a generic type parameter in one or more fields using the `<>` syntax.

```rust
struct Point<T> {
    x: T,
    y: T,
}
```

# Multiple Generic Type Parameters

You can use as many generic type parameters in a definition as you want, but using more than a few makes your code hard to read. If you're finding you need lots of generic types in your code, it could indicate that your code needs restructuring into smaller pieces.

```rust
struct Point<T, U> {
    x: T,
    y: U,
}
```

# In Enum Definitions

As we did with structs, we can define enums to **hold generic data types in their variants**, here are some example enums defined in the standard rust library that uses generic data types.

```rust
enum Option<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

# In Method Definitions

We can implement methods on structs and enums (as we did in Chapter 5) and use generic types in their definitions, too.

```rust
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

fn main() {
    let p = Point { x: 5, y: 10 };
    println!("p.x = {}", p.x());
}
```

Note that we have to declare `T` just after `impl` so we can use `T` to specify that we’re implementing methods on the type `Point<T>`.

# Constraints on Generic Types When Defining Methods on the Type

We could, for example, implement methods only on `Point<f32>` instances rather than on `Point<T>` instances with any generic type, notice here that we **don’t declare any types** after `impl`.

```rust
impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}
```

This code means the type `Point<f32>` will have a `distance_from_origin` method; other instances of `Point<T>` where `T` is not of type `f32` will not have this method defined.

# Struct Definition Generics vs Method Signatures Generics

The purpose of this example is to demonstrate a situation in which some generic parameters are declared with `impl` and some are declared with the method definition.

Here, the generic parameters `X1` and `Y1` are declared after `impl` because they go with the `struct` definition.

The generic parameters `X2` and `Y2` are declared after `fn mixup`, because they’re only relevant to the method.

```rust
struct Point<X1, Y1> {
    x: X1,
    y: Y1,
}

impl<X1, Y1> Point<X1, Y1> {
    fn mixup<X2, Y2>(self, other: Point<X2, Y2>) -> Point<X1, Y2> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

fn main() {
    let p1 = Point { x: 5, y: 10.4 };
    let p2 = Point { x: "Hello", y: 'c' };
    let p3 = p1.mixup(p2);

    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);
}
```

# Performance of Code Using Generics

**Monomorphization** is the process of turning generic code into specific code by filling in the concrete types that are used when compiled.

When the code runs, it performs just as it would if we had duplicated each definition by hand. The process of monomorphization makes Rust’s generics extremely efficient at runtime (like C++ templates).

