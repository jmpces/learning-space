# Rust I/O

## Standard Input

`read_line` takes whatever the user types into standard input and append that into a string (without overwriting its contents).

The string argument needs to be mutable so the method can change the string’s content.

```rust
std::io::stdin().read_line(&mut variable);
```

## Output

Only **variables** are **allowed** to be placed inside the `{}` when using print macros.

On the other hand, **Expressions** are not allowed to be placed inside the **placeholder** (`{}`) instead we leave the curly-braces empty, then we pass the expression in the succeeding parameters.

The number and order of the empty curly-braces inside the `""` and the succeeding expressions passed to the succeeding parameters should match each other.

```rust
// macro for printing with new-line
println!("this variable is equal to = {variable}");

// without new line
print!("this expresion {x} + {y} = {}", x + y);
```

