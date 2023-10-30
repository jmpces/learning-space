# Recoverable Errors with Result

Most errors aren’t serious enough to require the program to stop entirely. Sometimes, when a function fails, it’s for a reason that you can easily interpret and respond to. For example, if you try to open a file and that operation fails because the file doesn’t exist, you might want to create the file instead of terminating the process.

# The `Result` enum

- `T` - represents the type of the value that will be returned in a success case within the `Ok` variant.

- `E` - represents the type of the error that will be returned in a failure case within the `Err` variant. 

```rust
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

Because `Result` has these generic type parameters, we can use the `Result` type and the functions defined on it in many different situations where the successful value and error value we want to return may differ.

# Example of a function that returns `Result` enum

```rust
use std::fs::File;

fn main() {
    let greeting_file_result = File::open("hello.txt");
}
```

The return type of `File::open` is a `Result<std::fs::File, std::io::Error>`

- This return type means the call to `File::open` might succeed and return a file handle that we can read from or write to.
- The function call might also fail returning `std::io::Error`: for example, the file might not exist, or we may not have permission to access the file.

# Using the match expression with `Result` enum

```rust
use std::fs::File;

fn main() {
    let greeting_file_result = File::open("hello.txt");

    let greeting_file = match greeting_file_result {
        Ok(file) => file,
        Err(error) => panic!("Problem opening the file: {:?}", error),
    };
}
```

# Matching on Different Errors

The `enum` `io::ErrorKind` is provided by the standard library and has variants representing the different kinds of errors that might result from an io operation.

The variant we want to use is `ErrorKind::NotFound`, which indicates the file we’re trying to open doesn’t exist yet.

If we matched to `ErrorKind::NotFound` we will try to create a new file with `File::create("hello.txt")`, this function will return another `Result<std::fs::File, std::io::Error>` so we again nested another match expression to get the variants of this return type.

If we din't matched to `ErrorKing::NotFound` and instead we matched on `other_error` then we panic.

If the inner `Result<std::fs::File, std::io::Error>` match to `Ok` variant then we return the `File` contained in the `Ok()`, If on `Err` we panic.

In this code we nested three (3) match expression.

```rust
use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let greeting_file_result = File::open("hello.txt");

    let greeting_file = match greeting_file_result {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:?}", other_error);
            }
        },
    };
}
```

# Alternatives to Using match with `Result<T, E>`

That’s a lot of match! The match expression is very useful but also very much a primitive. **In Chapter 13, you’ll learn about closures, which are used with many of the methods defined on `Result<T, E>`**. These methods can be **more concise than using match when handling `Result<T, E>` values** in your code.

For example, here’s another way to write the same logic, this time using **closures** and the **`unwrap_or_else`** method:

```rust
use std::fs::File;
use std::io::ErrorKind;

fn main() {
    let greeting_file = File::open("hello.txt").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| {
                panic!("Problem creating the file: {:?}", error);
            })
        } else {
            panic!("Problem opening the file: {:?}", error);
        }
    });
}
```

# Shortcuts for Panic on Error: `unwrap`

```rust
use std::fs::File;

fn main() {
    let greeting_file = match File::open("hello.txt") {
        Ok(file) => file,
        Err(error) => panic!("Problem opening the file: {:?}", error),
    };
}
```

The `unwrap()` method of the `Result<T, E>` type is a shortcut method implemented just like the `match` expression above.

If the `Result` value is the `Ok` variant, `unwrap()` will return the value inside the `Ok`.

If the Result is the `Err` variant, `unwrap()` will call the `panic!` macro for us.

```rust
use std::fs::File;

fn main() {
    let greeting_file = File::open("hello.txt").unwrap();
}
```

# Shortcuts for Panic on Error: `expect`

**Similar to `unwrap`**, but the expect method **lets us also choose the `panic!` error message**. Using expect instead of unwrap and providing good error messages can convey your intent and make tracking down the source of a panic easier.

```rust
use std::fs::File;

fn main() {
    let greeting_file = File::open("hello.txt")
        .expect("hello.txt should be included in this project");
}
```

# Propagating Errors

**Propagating the error** is when a function’s implementation calls something that might fail, instead of handling the error within the function itself, you can **return the error from the function/method to the calling code** so that it can decide what to do.

```rust
use std::fs::File;
use std::io::{self, Read};

fn read_username_from_file() -> Result<String, io::Error> {
    let username_file_result = File::open("hello.txt");

    let mut username_file = match username_file_result {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut username = String::new();

    match username_file.read_to_string(&mut username) {
        Ok(_) => Ok(username),
        Err(e) => Err(e),
    }
}
```

# A Shortcut for Propagating Errors: the `?` Operator

This code implements a shorcut for the example above, it offers the same functionality but a more concise code.

```rust
use std::fs::File;
use std::io::{self, Read};

fn read_username_from_file() -> Result<String, io::Error> {
    let mut username_file = File::open("hello.txt")?;
    let mut username = String::new();
    username_file.read_to_string(&mut username)?;
    Ok(username)
}
```

**If the value of the `Result` is an `Ok`**, the value inside the `Ok` will be **returned from this expression**, and the program will continue.

**If the value is an `Err`**, the `Err` will be **returned from the whole function** as if we had used the `return` keyword so the error value gets propagated to the calling code.

-----

There is a difference between what the `match` expression and what the `?` operator does:

**Error values** that have the **`?` operator** called on them go through the **`from` function**, defined in the **`From` trait** in the standard library, which is **used to convert values from one type into another**.

When the **`?` operator** calls the **`from` function**, the error type received is converted into the error type defined in the return type of the current function. This is useful when a function returns one error type to represent all the ways a function might fail, even if parts might fail for many different reasons.

# Chaining `?` Operator

We could **even shorten the previous example code** above further by chaining method calls immediately after the `?` operator call, The functionality is again the same,this is just a different, more ergonomic way to write it.
```rust
use std::fs::File;
use std::io::{self, Read};

fn read_username_from_file() -> Result<String, io::Error> {
    let mut username = String::new();
    File::open("hello.txt")?.read_to_string(&mut username)?;
    Ok(username)
}
```

# Where The `?` Operator Can Be Used

The `?` operator can only be used in functions whose return type is compatible with the value the `?` is used on.

The `?` operator is defined to perform an early return of a value out of the function.

**We’re only allowed to use the `?` operator in a function that returns `Result`, `Option`, or another type that implements `FromResidual`**.


### Here is an example that uses the `Option` `enum` for the operator `?`:

```rust
fn last_char_of_first_line(text: &str) -> Option<char> {
    // returns `None` to the function if there is no line
    let first_line = text.lines().next()?;
    let last_char = first_line.chars().last();
    last_char
}
```

We could also write it on a shorter form by method chaining.

```rust
fn last_char_of_first_line(text: &str) -> Option<char> {
    text.lines().next()?.chars().last()
}
```

### `Result` enum for the `main()` function

So far, all the main functions we’ve used return `()`. The `main` function is special because it’s the entry and exit point of executable programs, and there are restrictions on what its return type can be for the programs to behave as expected.

Luckily, `main` can also return a `Result<(), E>`:

```rust
use std::error::Error;
use std::fs::File;

fn main() -> Result<(), Box<dyn Error>> {
    let greeting_file = File::open("hello.txt")?;

    Ok(())
}
```

For now, you can read `Box<dyn Error>` to mean **“any kind of error”**.

Using `?` on a `Result` value in a `main()` function with the error type `Box<dyn Error>` is allowed, because it allows any `Err` value to be returned early.

- The executable will exit with a value of `0` if `main` returns `Ok(()) `
- And will exit with a nonzero value if `main` returns an `Err` value. 

Executables written in C return integers when they exit: programs that exit successfully return the integer 0, and programs that error return some integer other than 0. Rust also returns integers from executables to be compatible with this convention.

The `main` function may return any types that implement the `std::process::Termination` trait, which contains a function report that returns an `ExitCode`. Consult the standard library documentation for more information on implementing the `Termination` trait for your own types.