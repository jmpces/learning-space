# **[Rust Lang](../Rustlang.md)**

## **Variables**

The **`let`** and **`const`** keywords is what we use in
rust to create variables, **`let`** creates variables that
are immutable by default (cannot be changed), but this can
be disabled by adding a **`mut`** keyword after it.

**`const`**
on the other hand is always immutable and cannot be change, this
value is also computed at compile time (they can only accept
constant expressions).

### **Create an immutable variable**

Will met error at compile time if we assign new
value to the variable `x`.

```rust
let x = 5;
```

### **Create a mutable variable**
```rust
let mut x = 10;
```

### **Create a constant (these are evaluated at compile time)**
```rust
const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
```

### **Shadowing - overriding a variable name in an inner scope**
```rust
let x = 5;
let x = 10; // overrides the first declaration.
{
    // use the old value then overrides the `x`
    // again, but only in the inner scope.
    let x = x * 10;
    println!("x = {x}");
}
println!("x = {x}");
```

- **Shadowing Use Case**

    Shadowing is useful when **changing a variable's type**, the difference of **Shadowing**
    over **`mut`** is that, while **`mut`** enables us to change the value
    of a variable, it won't allow us to change its type. As for **Shadowing**
    it allows us to change both of its value and type.

    ```rust
    let spaces = "   "; // string to
    let spaces = spaces.len(); // integer
    ```

    Shadowing is also useful inside block scopes, if you create another variable inside an inner scope shadowing a variable outside that scope, then you can safely access the inner scope variable that shadow the outer scope variable without the worry of accessing the outside scope variable.

    Then after leaving the inner scope you can access the outside scope variable with same state/value when you leave it to enter the inner scope.

