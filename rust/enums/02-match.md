# The `match` Control Flow Construct

_This is just like the `switch` statement in C/C++ and other programming languages_.

The `match` **expressions** allow you to **compare** a **value** against a **series of patterns** and then **execute code** based on which **pattern matches**.

**Patterns** can be made up of **literal values**, **variable names**, **wildcards**, and many other things; Chapter 18 of the Rust Book covers all the different kinds of patterns and what they do.

**Arms** are the condition where patterns could match. When the match expression executes, it **compares** the resultant value against the pattern of each arm, in order. If a **pattern matches** the value, **the code associated with that pattern is executed**. If that **pattern doesn’t match** the value, execution **continues to the next arm**.

_We don’t typically use curly brackets if the match arm code is short_.

```rust
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}
```

# Patterns That Bind to Values

Another useful feature of match arms is that they can bind to the parts of the values that match the pattern. This is how we can extract values out of enum variants.

```rust
#[derive(Debug)] // so we can inspect the state in a minute
enum UsState {
    Alabama,
    Alaska,
    // --snip--
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,

        // binding the "value" of the "enum variant Quarter"
        // to the variable "state"
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        }
    }
}


fn main() {
    value_in_cents(Coin::Quarter(UsState::Alabama));
}
```

### Output:

```bash
Coin::Dime = 10
------------------------------------
State quarter from Alabama!
Coin::Quarter = 25
```

# Matching with Generic Enums : `Option<T>`

We can also handle `Option<T>` using `match`, we’ll compare the variants of `Option<T>`.

```rust
fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

let five = Some(5);
let six = plus_one(five);
let none = plus_one(None);
```

# Matches Are Exhaustive

There’s **one other aspect of match** we need to discuss: **the arms’ patterns must cover all possibilities**. Consider this version of our `plus_one` `function`, which has a bug and won’t compile:

```rust
fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        Some(i) => Some(i + 1),
    }
}
```

Rust prevents us from forgetting to explicitly handle the None case (**exhaustive checking**), it protects us from assuming that we have a value when we might have null.

# Catch-all Patterns and the `_` Placeholder (C++ `switch` `default`'s)

Using `enums`, we can also take **special actions for a few particular values**, but **for all other values** take **one default action**.

We can do this by simply naming out last arm variable `other => move_player(other),`.

```rust
let dice_roll = 9;
match dice_roll {
    3 => add_fancy_hat(),
    7 => remove_fancy_hat(),
    other => move_player(other),
}

fn add_fancy_hat() {}
fn remove_fancy_hat() {}
fn move_player(num_spaces: u8) {}
```

The catch all pattern lets you to use all the other values in the match expression, however if you don't want to use all the other values then we can use the `_` instead to catch all variants or values in the patterns without using them:

```rust
other => move_player(other),
```