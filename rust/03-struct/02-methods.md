# Methods

Methods are similar to functions: we declare them with the `fn` keyword and a **name**, they can have **parameters** and a `return` value, and they **contain some code** that’s **run** when the method is **called** from somewhere else. 

# Defining Methods

To define the function within the context of `Rectangle`, we start an `impl` (implementation) block for `Rectangle`. Everything within this `impl` block will be associated with the `Rectangle` type.

Then we move the `area` function within the `impl` curly brackets and change the first (and in this case, only) parameter to be `self` in the signature and everywhere within the body.

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}
```

# Calling Methods

In `main`, where we called the `area` function and passed `rect1` as an argument, we use **method syntax** to call the `area` method on our `Rectangle` instance. The method syntax goes after an instance: we add a **dot followed by the method name, parentheses, and any arguments**.

```rust
fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    println!(
        "The area of the rectangle is {} square pixels.",
        rect1.area()
    );
}
```

# Method's First Parameter

In the **signature** for `area`, we use **`&self` instead of rectangle: &Rectangle.

The **`&self`** is actually **short for** **`self: &Self`**.

Within an `impl` block, the type `Self` is an alias for the type that the `impl` block is for.

Methods must have a parameter **named self** of type `Self` for their **first parameter**, so Rust lets you abbreviate this with only the name `self` in the first parameter spot. 

| 1st param | description |
| --- | --- |
| `&self` | we **don’t want to take ownership**, and we just want to **read only the data** in the struct. |
| `&mut self` | If we wanted to **change the instance and data** that we’ve called the method on as part of what the method does. |
| `self` | this technique is usually used when the method transforms `self` into something else and you want to prevent the caller from using the original instance after the transformation. |

# Method name similar to a field

Note that we can choose to give a method the same name as one of the struct’s fields.

```rust
impl Rectangle {
    fn width(&self) -> bool {
        self.width > 0
    }
}
```

# The `->` Operator in C++

Rust doesn’t have an equivalent to the `->` operator; instead, Rust has a feature called **automatic referencing and dereferencing**. Calling methods is one of the few places in Rust that has this behavior.

Here’s how it works: when you call a method with `object.something()`, Rust **automatically** adds in `&`, `&mut`, or `*` so object matches the signature of the method. In other words, the following are the same:

```rust
p1.distance(&p2);
(&p1).distance(&p2);
```

# Methods with More Parameters

```rust
impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}
```

# Multiple `impl` Blocks

Each struct is **allowed** to have **multiple `impl`** blocks. 

There’s **no reason** to separate the methods above into multiple `impl` blocks here, **but this is valid syntax**. We’ll see a case in which multiple impl blocks are useful in Chapter 10, where we discuss generic types and traits.

# Associated Function

All functions defined within an `impl` block are called **associated functions** because they’re associated with the type named after the `impl`.

We can define **associated functions** that **don’t have self** as their **first parameter** (and thus are not methods) because they don’t need an instance of the type to work with.

We’ve already used one function like this: the `String::from` function that’s defined on the `String` type.

**Associated functions** that **aren’t methods** are often **used for constructors** that will **return a new instance** of the struct. These are often called `new`, but `new` isn’t a special name and **isn’t built into the language**.

For example, we could choose to provide an **associated function** named `square` that would have one dimension parameter and use that as both width and height, thus making it easier to create a square Rectangle rather than having to specify the same value twice:

```rust
impl Rectangle {
    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let sq = Rectangle::square(3);
}
```