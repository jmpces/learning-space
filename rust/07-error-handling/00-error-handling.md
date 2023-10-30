# Error Handling

Rust groups errors into two major categories: 

- **Recoverable Errors** - Rust doesn’t have exceptions. Instead, it has the type `Result<T, E>` for recoverable errors.
- **Unrecoverable Errors** - And `panic!` macro that stops execution when the program encounters an unrecoverable error.