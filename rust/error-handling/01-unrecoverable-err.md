# Unrecoverable Errors

Sometimes, bad things happen in your code, and there’s nothing you can do about it. In these cases, Rust has the `panic!` macro.

There are two ways to cause a panic in practice:
- by taking an action that causes our code to panic (such as accessing an array past the end)
- or by explicitly calling the `panic!` macro.

# Unwinding the Stack or Aborting in Response to a Panic

- **Undwinding** - By default, when a panic occurs, the program starts **unwinding**, _which means Rust walks back up the stack and cleans up the data from each function it encounters_. 

- **Aborting** - However, this walking back and cleanup (unwinding) is a lot of work. Rust, therefore, allows you to choose the alternative of immediately **aborting**, _which ends the program without cleaning up_.

    Memory that the program was using will then need to be cleaned up by the operating system.

If in your project you need to make the resulting binary as small as possible, you can switch from unwinding to aborting upon a panic by adding `panic = 'abort'` to the appropriate `[profile]` sections in your **Cargo.toml** file. For example, **if you want to abort on panic in release mode**, add this:

```toml
[profile.release]
panic = 'abort'
```

# Using `panic!` Macro

Causes the program to **crash and display** the **panic message**, the **exact source code file** and the **line number** where the panic occured.

```rust
fn main() {
    panic!("crash and burn");
}
```

# Using a `panic!` Backtrace

A **backtrace** is **a list of all the functions that have been called to get to a certain point**, in this case where the panic occured. Backtraces in Rust work as they do in other languages: the key to reading the backtrace is to start from the top and read until you see files you wrote. That’s the spot where the problem originated. 

```bash
RUST_BACKTRACE=1 cargo run
```