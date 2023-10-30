# Borrowing & References

### Rules:

- A **reference’s scope** starts from where it was **introduced** and continues through the **last time** that reference is **used**.

- At any given moment, you can have **only one** of the following scenarios:
    - One **mutable** reference that **does not** overlap with other reference scopes.
    - Any number of **immutable** references, and their scopes can overlap.

- References must always be valid.

## We call the action of creating a reference borrowing.

The `&` operator just like in C++ will take the reference of a variable. Rust also have a dereferencing operator `*`. (similar to C++ when dereferencing another pointer or iterator).

These ampersands `&` represent references, and they **allow** you to refer to some value **without taking ownership** of it.

Because it does not own it, the value it points to will not be dropped when the reference stops being used.

### **Creating Immutable References**
```rust
let foo = &bar;
```

### **Creating Mutable References**
```rust
let mut foo = &mut bar;
```

### **Passing Immutable to Immutable**

When functions have references as parameters instead of the actual values, we won’t need to return the values in order to give back ownership, because we never had ownership.

```rust
fn foo(param: &Bar) { /* code ... */ }

fn main() {
    let bar = Bar::new();
    foo(&bar);
}
```

### **Passing Mutable to Mutable**
```rust
fn foo(param: &mut Bar) { /* code ... */ }

fn main() {
    let mut bar = Bar::new();
    foo(&mut bar);
}
```

### **Passing Mutable to Immutable**
```rust
fn foo(param: &Bar) { /* code ... */}

fn main() {
    let mut bar = Bar::new();
    foo(&bar);
}
```

# Mutable Reference Limitation

Mutable references have one big restriction: if you **have a mutable reference** to a value, you **cannot have other references** to that value.

### Not Allowed

```rust
let mut s = String::from("hello");

let r1 = &s; // no problem
let r2 = &s; // no problem
let r3 = &mut s; // BIG PROBLEM

println!("{}, {}, and {}", r1, r2, r3);
```

### Allowed - Reference Scopes

Note that a **reference’s scope** starts from where it was **introduced** and continues through the **last time** that reference is **used**. For instance, this code will compile because the last usage of the immutable references, the `println!`, occurs before the mutable reference is introduced:

```rust
let mut s = String::from("hello");

let r1 = &s; // no problem
let r2 = &s; // no problem
println!("{} and {}", r1, r2);
// variables r1 and r2 will not be used after this point

let r3 = &mut s; // no problem
println!("{}", r3);
```

### Allowed - New Scope and New Reference

We can use curly brackets to create a new scope, allowing for multiple mutable references, just not simultaneous ones

```rust
let mut s = String::from("hello");

{
    let r1 = &mut s;
    println!("{r1}");
}

// r1 goes out of scope here, so we can make a new reference with no problems.
let r2 = &mut s;

println!("{r2}");
```

# Dangling Pointers

This code tries to create a dangling reference but it will fail to compile.

```rust
fn main() {
    let reference_to_nothing = dangle();
}

fn dangle() -> &String {
    let s = String::from("hello");

    // returns only the reference of "s", but since it's
    // just a reference, when "s" goes out of the function 
    // scope, it's heap-allocated memory will be freed
    // when the `drop` method is called, this should cause
    // a dangling reference.
    
    // But rust can detect this problem early on and
    // prevent this code from compiling.
    &s
}

fn no_dangle() -> String {
    let s = String::from("hello");

    // this is the correct way
    s
}
```

The error message this code produces refers to a feature we haven’t covered yet: `lifetimes`. We’ll discuss lifetimes in detail in Chapter 10. 