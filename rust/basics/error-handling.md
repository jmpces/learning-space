# Error Handling

### Quick Look

Functions?, types?, methods can return a `Result` value as a way of error handling.

`Result` is an **enumeration** often called an `enum` which is a type that can be in one of multiple possible states. We call each state a **variant**

The **`Result`**'s variants are `Ok` and `Err`.

**`Ok`** indicates success and it will contain the generated value.

**`Err`** indicates failed operation and it will contain information about how or why the operation have failed.

An instance of `Result` has an `expect` method that you can call, if an error occurs it will crash the program and display the message, else if it is a success it will return the value that the `Ok` is holding.

```rust
.expect("Failed to read line");
```