# Struct

# Defining Structs

- fields - in other programming languages like C++ we call this data members.

```rust
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}
```

# Instantiation of Structs

We create an instance by stating the name of the struct and then add curly brackets containing key: value pairs, where the keys are the names of the fields and the values are the data we want to store in those fields.

We don’t have to specify the fields in the same order in which we declared them in the struct.

```rust
fn main() {
    let user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };
}
```

# Mutable Structs & Accessing Fields

To **get a specific value** from a struct, we use **dot notation**. For example, to access this user’s email address, we use `user1.email`.

If the instance is **mutable**, we can **change** a value by using the dot notation and assigning into a particular field. 

```rust
fn main() {
    let mut user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };

    user1.email = String::from("anotheremail@example.com");
}
```

Note that the entire instance must be mutable; Rust doesn’t allow us to mark only certain fields as mutable.

# Function That Instantiate Struct

As with any expression, we can construct a new instance of the struct as the last expression in the function body to implicitly return that new instance.

```rust
fn build_user(email: String, username: String) -> User {
    User {
        active: true,
        username: username,
        email: email,
        sign_in_count: 1,
    }
}
```

# Using the Field Init Shorthand

Because the **parameter names** and the **struct field names** are **exactly the same**, we can use the **field init shorthand syntax**.

This would automatically use the similar names as a value to the similar field name of the struct.

```rust
fn build_user(email: String, username: String) -> User {
    User {
        active: true,
        username,
        email,
        sign_in_count: 1,
    }
}
```

# Creating Instances from Other Instances

Using **struct update syntax** as shown below. The syntax `..` specifies that the remaining fields not explicitly set should have the same value as the fields in the given instance.

```rust
fn main() {
    let user2 = User {
        email: String::from("another@example.com"),
        ..user1
    };
}
```

The `..user1` must come last to specify that any remaining fields should get their values from the corresponding fields.

> [!Note]  
> Remember that the struct update syntax uses `=` like an assignment; this is because **it moves the data**.
>
> In this example, we can no longer use `user1` **as a whole** after creating `user2` because **the `String` in the `username` field** of `user1` was **moved into `user2`**.
>
> If we had given `user2` **new String values for both email and username**, and thus only used the active and sign_in_count values from `user1`, then `user1` would still be valid after creating `user2`.
>
> **Both `active` and `sign_in_count` are types that implement the Copy trait** so it was not moved but was trivially copied.

# Tuple Structs - Structs Without Named Fields

Rust also supports structs that look similar to tuples, called **tuple structs**. Tuple structs have the added meaning the struct name provides but don’t have names associated with their fields; rather, they just have the types of the fields.

Tuple structs are useful when you want to give the whole tuple a name and make the tuple a different type from other tuples, and when naming each field as in a regular struct would be verbose or redundant.

```rust
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);

    let Color(r, g, b) = black;
    let Point(x, y, z) = origin;

    println!("black   = ({r}, {g}, {b})");
    println!("x, y, z = ({x}, {y}, {z})");
}
```

# Unit-Like Structs Without Any Fields

You can also define **structs that don’t have any fields!** These are called **unit-like structs** because they behave similarly to `()`.

Unit-like structs can be useful when you need to **implement** a **trait** on some type **but don’t have any data** that you want to store in the type itself. We’ll discuss traits in Chapter 10.

Here’s an example of declaring and instantiating a unit struct named `AlwaysEqual`:

```rust
struct AlwaysEqual;

fn main() {
    let subject = AlwaysEqual;
}
```

# Ownership of Struct Data

In the User struct definition in the [very fist example](#defining-structs), we used the `String` type rather than the `&str` **string slice type**. This is a deliberate choice because we want each instance of this struct to own all of its data and for that data to be valid for as long as the entire struct is valid.

**It’s also possible** for structs **to store references** to data owned by something else, **but to do so requires** the use of **lifetimes**, a Rust feature that we’ll discuss in Chapter 10.

**Lifetimes** ensure that the data referenced by a struct is valid for as long as the struct is. Let’s say you try to store a reference in a struct without specifying lifetimes, like the following; this won’t work:

```rust
struct User {
    active: bool,
    username: &str,
    email: &str,
    sign_in_count: u64,
}

fn main() {
    let user1 = User {
        active: true,
        username: "someusername123",
        email: "someone@example.com",
        sign_in_count: 1,
    };
}
```

The compiler will complain that it needs lifetime specifiers

# Adding Useful Functionality with Derived Traits

The `Debug` trait enables us to print our struct in a way that is useful for developers so we can see its value while we’re debugging our code.

Rust does include functionality to print out debugging information, but we have to explicitly opt in to make that functionality available for our struct. To do that, we add the outer attribute `#[derive(Debug)]` just before the struct definition.

Putting the specifier `:?` or a `:#?` inside the curly brackets tells `println!` we want to use an output format called `Debug`.

**printing in the standard out**

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    println!("reac1 : format 1 = {:?}", rect1);
    println!("reac1 : format 2 = {:#?}", rect1);
}
```

**printing in the standard err**

The `dbg!` macro is useful when debugging code
- it will print the filename and the line number where it was called
- it will print the code passed inside its `()`
- it will print the equivalent value of that variable.

> [!Note]  
> Calling the `dbg!` macro prints to the **standard error console stream (stderr)**, as opposed to `println!`, which prints to the _standard output console stream (stdout)_.

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let scale = 2;
    let rect1 = Rectangle {
        width: dbg!(30 * scale),
        height: 50,
    };

    dbg!(&rect1);
}
```

We use a reference to `rect1` in the next call. Here’s what the output of this example looks like:

# Struct Member Access Modifiers

`struct` members and methods are **public** by default on the **same module** scope it was defined.

But if you are using a `struct` that comes from a **separate module**, all of its **members** and **methods** would be **private** by **default**.

Meaning you wouldn't be able to [normaly initialize a struct (as show above)](#creating-instances-from-other-instances) that comes from a module, you would need to set all of its **members** first to **public** explicitly using the `pub` keyword.

And to access a method of a `struct` that comes from a module  you would need to set the method to **public** using the `pub` keyword again.

```rust
mod back_of_house {
    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}

pub fn eat_at_restaurant() {
    // Order a breakfast in the summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // Change our mind about what bread we'd like
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // The next line won't compile if we uncomment it; we're not allowed
    // to see or modify the seasonal fruit that comes with the meal
    // meal.seasonal_fruit = String::from("blueberries");
}
```