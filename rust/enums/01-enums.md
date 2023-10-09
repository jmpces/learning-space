# Enums

# Defining Enum

Enums give you a way of saying a value is one of a possible set of values. 

Say we need to work with IP addresses. Currently, two major standards are used for IP addresses: version four and version six. 

Because these are the only possibilities for an IP address that our program will come across, we can enumerate all possible variants, which is where enumeration gets its name.

We can express this concept in code by defining an `IpAddrKind` enumeration and listing the possible kinds an IP address can be, **V4** and **V6**. These are the **variants** of the `enum`:

```rust
enum IpAddrKind {
    V4,
    V6,
}
```

# Instantiating and Enum

We can create instances of each of the two variants of `IpAddrKind` like this:

```rust
let four = IpAddrKind::V4;
let six  = IpAddrKind::V6;
```

# Passing Enum's to Functions

We can then, for instance, define a function that takes any `IpAddrKind`:

```rust
fn route(ip_kind: IpAddrKind) {}
```

And we can call this function with either **variant**:

```rust
route(IpAddrKind::V4);
route(IpAddrKind::V6);
```

# Enum with Values

Representing with just an `enum` is more concise: rather than an `enum` inside a `struct`, we can put data directly into each `enum` variant. This new definition of the `IpAddr` `enum` says that both `V4` and `V6` **variants** will have associated `String` values.

Here, The name of each `enum` variant that we define also becomes a function that constructs an instance of the `enum`. That is, `IpAddr::V4()` is a function call that takes a `String` argument and returns an instance of the `IpAddr` type. We automatically get this **constructor** function defined as a result of defining the `enum`.

```rust
enum IpAddr {
    V4(String),
    V6(String),
}

let home     = IpAddr::V4(String::from("127.0.0.1"));
let loopback = IpAddr::V6(String::from("::1"));
```

# Enums variants that holds different data types

There’s another advantage to using an `enum` rather than a `struct`:

**Each variant can have different data types and amounts of associated data**.

Version four IP addresses will always have four numeric components that will have values between `0` and `255`. If we wanted to store `V4` addresses as **four** `u8` values but still express `V6` addresses as one `String` value, we wouldn’t be able to with a `struct`. Enums handle this case with ease:

```rust
enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

let home     = IpAddr::V4(127, 0, 0, 1);
let loopback = IpAddr::V6(String::from("::1"));
```

# Enum with Structs

As it **turns out, wanting to store IP addresses and encode which kind they are is so common that the standard library has a definition we can use!**.

Let’s look at how the standard library defines `IpAddr` it embeds the address data inside the **variants** in the form of two different **structs**, which are defined differently for each variant:

This code illustrates that **you can put any kind of data** inside an `enum` variant, **You can even include another `enum`!**.

```rust
struct Ipv4Addr {
    // --snip--
}

struct Ipv6Addr {
    // --snip--
}

enum IpAddr {
    V4(Ipv4Addr),
    V6(Ipv6Addr),
}
```

# Adding Methods to Enums

We’re also able to define methods on enums. Here’s a method named `call` that we could define on our `Message` `enum`.

The body of the method would use `self` to get the value that we called the method on.

```rust
enum Message {
    // has no data associated with it at all.
    Quit,

    // has named fields, like a struct does.
    Move { x: i32, y: i32 },

    // includes a single String.
    Write(String),

    // includes three `i32` values.
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        // method body would be defined here
    }
}

let m = Message::Write(String::from("hello"));
m.call();
```

# Enums with Generics, The `Option` Enum vs Null

The `Option` `enum` type encodes the very common scenario in which a value could be something or it could be nothing.

Rust does not have `NULL`, but it does have an `enum` that can encode the concept of a value being present or absent. This `enum` is `Option<T>`, and it is defined by the standard library as the code below.

The `Option<T>` `enum` is so useful that it’s even included in the **prelude**; you don’t need to bring it into **scope explicitly**. Its **variants** are also included in the prelude: you can use `Some` and `None` directly without the `Option::` prefix. 

```rust
enum Option<T> {
    None,
    Some(T),
}
```

The `<T>` is a **generic type parameter** (like templates in C++). 

```rust
let some_number = Some(5); // of type Option<i32>
let some_char = Some('e'); // of type Option<char>

let absent_number: Option<i32> = None;
```

In general, in order to use an `Option<T>` value, you want to have code that will handle each **variant**.

You want some code that will run only when you have a `Some(T)` value, and this code is allowed to use the inner `T`.

You want some other code to run only if you have a `None` value, and that code doesn’t have a `T` value available.

The **match expression** is a control flow construct that does just this when used with `enums`: it will run different code depending on which **variant** of the `enum` it has, and that code can use the data inside the matching value.

# Enums variants as public or private

On the other hand, if we make an `enum` public in a module, all of its variants are then public. We only need the `pub` before the `enum` keyword.

This is in contrast with `struct` where all of its members and methods are set to **private** by default if it comes from a module.

```rust
mod back_of_house {
    pub enum Appetizer {
        Soup,
        Salad,
    }
}

pub fn eat_at_restaurant() {
    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;
}
```