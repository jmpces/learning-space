# Traits : Defining Shared Behavior

> [!NOTE]  
> The rust book says that Traits are like Interfaces (but not completely), I would say they are more like Abstract Classes + Concepts of C++.
>
> We can declare only the signature of the methods inside a trait and defer the implementation definition to the types that implements it.
>
> But it is also possible to provide a default implementation definition of the methods inside the trait right away, and can be overriden in the types that implement it if needed.

A **trait** defines functionality, a particular type has and can share with other types.

- We can use traits to define shared behavior in an abstract way.
- We can use **trait bounds** to **specify** that a **generic type** can be **any type** that **has certain behavior**.

# Defining A Trait

A type’s **behavior** consists of the methods we can call on that type. 

**Different types share the same behavior** if we can **call** the **same methods** on all of those types.

Trait definitions are a way to group method signatures together to define a set of behaviors necessary to accomplish some purpose.

```rust
pub trait Summary {
    fn summarize(&self) -> String;
}
```

# Implementing a Trait on a Type

After **`impl`**, we put the **trait name** we want to implement, then use the **`for`** keyword, and then the **name of the type**.

> [!IMPORTANT]  
> When using types that implements a certain trait, the user must also **bring the trait into scope**.

```rust
pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}
```

# TODO: know more about this coherence? and orphan rule?

# Default Implementations

**Unlike interfaces** in **Java**, we can **define** a **default method definition** for a trait in **Rust** which is also overridable in it's implementor, this is more similar to the **virtual methods** inside an **abstract class** in **C++**, .

```rust
pub trait Summary {
    fn summarize(&self) -> String {
        String::from("(Read more...)")
    }
}

impl Summary for NewsArticle {
    // we can still override the summarize
    // method here if we wanted to.
}
```

# Traits as Parameters

**Instead** of using a **concrete type** to specify a **parameter type**, we can use the `impl` keyword and the **trait name**.

This would make the **parameter only accept** the **type** that **implements** the specified **trait**.

_This indeed looks like C++ concepts - Obliviuous Me_

```rust
pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}
```

# Trait Bound Syntax

The `impl` Trait syntax works for straightforward cases but is actually syntax sugar for a longer form known as a **trait bound**.

This longer form is equivalent to the example in the previous code above but is more verbose. We place trait bounds with the declaration of the generic type parameter after a colon and inside angle brackets.

```rust
pub fn notify<T: Summary>(item: &T) {
    println!("Breaking news! {}", item.summarize());
}
```

# Trait Parameter Syntax VS Trait Bound Syntax

**The `impl` Trait syntax is convenient and makes for more concise code in simple cases.**

For example, we can have two parameters that implement a certain trait. Using `impl` Trait is appropriate if we want this function to allow `item1` and `item2` to have different types (as long as both types implement Summary).

```rust
pub fn notify(item1: &impl Summary, item2: &impl Summary) {
```

**While the fuller trait bound syntax can express more complexity in other cases.**

If we want to force both parameters to have the same type, however, we must use a trait bound, like this:

The generic type `T` specified as the type of the `item1` and `item2` parameters constrains the function such that the concrete type of the value passed as an argument for `item1` and `item2` must be the same.

```rust
pub fn notify<T: Summary>(item1: &T, item2: &T) {
```

# Specifying Multiple Trait Bounds with `+` Operator

We can also specify more than one trait bound

```rust
// trait parameter syntax
pub fn notify(item: &(impl Summary + Display)) {

// trait bound syntax
pub fn notify<T: Summary + Display>(item: &T) {
```

With the two trait bounds specified, the body of notify can call `summarize` and use `{}` to format item.

# Clearer Trait Bounds with `where` Clauses

Using too many trait bounds has its downsides. Functions with multiple generic type parameters can contain lots of trait bound information, making the function signature hard to read.

```rust
fn some_function<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {
```

For this reason, Rust has alternate syntax for specifying trait bounds.

```rust
fn some_function<T, U>(t: &T, u: &U) -> i32
where
    T: Display + Clone,
    U: Clone + Debug,
{
```

This function’s signature is less cluttered: the function name, parameter list, and return type are close together, similar to a function without lots of trait bounds.

# Returning Types that Implement Traits

We can also use the `impl` Trait syntax in the return position to return a value of some type that implements a trait.

```rust
fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("horse_ebooks"),
        content: String::from(
            "of course, as you probably already know, people",
        ),
        reply: false,
        retweet: false,
    }
}
```

The ability to specify a return type only by the trait it implements is especially useful in the context of closures and iterators, which we cover in Chapter 13. Closures and iterators create types that only the compiler knows or types that are very long to specify.

The `impl` Trait syntax lets you concisely specify that a function returns some type that implements the Iterator trait without needing to write out a very long type.

# Limitations of Returning Types that Implement Traits

We can only use `impl` Trait if we’re returning a single type,
for example the code below is not allowed.

```rust
fn returns_summarizable(switch: bool) -> impl Summary {
    if switch {
        NewsArticle {
            headline: String::from(
                "Penguins win the Stanley Cup Championship!",
            ),
            location: String::from("Pittsburgh, PA, USA"),
            author: String::from("Iceburgh"),
            content: String::from(
                "The Pittsburgh Penguins once again are the best \
                 hockey team in the NHL.",
            ),
        }
    } else {
        Tweet {
            username: String::from("horse_ebooks"),
            content: String::from(
                "of course, as you probably already know, people",
            ),
            reply: false,
            retweet: false,
        }
    }
}
```

Returning either a `NewsArticle` or a `Tweet` isn’t allowed due to restrictions around how the `impl` Trait syntax is implemented in the compiler. We’ll cover how to write a function with this behavior in the “Using Trait Objects That Allow for Values of Different Types” section of Chapter 17.

# Using Trait Bounds to Conditionally Implement Methods

`Pair<T>` only implements the `cmp_display` method if its inner type `T` implements the `PartialOrd` trait that enables comparison and the `Display` trait that enables printing.

```rust
use std::fmt::Display;

struct Pair<T> {
    x: T,
    y: T,
}

impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
        } else {
            println!("The largest member is y = {}", self.y);
        }
    }
}
```

# Blanket Implementations - Conditionally Implement a Trait

We can also conditionally [implement a trait](#implementing-a-trait-on-a-type) for any type that implements another trait.

For example, the standard library implements the `ToString` trait on all type `T` that implements the `Display` trait automatically.

```rust
impl<T: Display> ToString for T {
    // ...
}
```