# **[Rust Lang](../Rustlang.md)**

## **Control Flow**

### **`if` expressions**

Run block of code if conditions are met, in rust we call each if expressions an ***arm*** just like in `match` expressions.

```rust
let x = -2;

if x == 0 {
    println!("x is zero");
} else if x % 2 == 0 {
    println!("x is even");
} else {
    println!("x is odd");
}
```

**Notice** that in rust:

- **Parenthesis** in if expressions are **not needed**.
- **Primitive Type/POD Integers** are not a valid conditions for if-else expressions, unlike in other languages like C and C++ where `0` evaluates to `false`, In rust we should always be explicit.
    ```rust
    let number = 3;

    // if number { // error unlike in languages like C/C++

    if number != 0 { // correct
        println!("number was something other than zero");
    }
    ```

### **`If` Scope Blocks are Expressions too**

Since `if` blocks are considered as **Scope Blocks**, they are also valid expressions (returns a value), but if we are gonna do this, we need to make sure that all `if` **arm** expressions **returns** the **same type**.

**Example 1**
```rust
let condition = true;
let number = if condition { 5 } else { 6 };
```

**Example 2**
```rust
let x = 0;
let y = 1;
    
let cmp = if x > y { 
    1
} else if x == y {
    0
} else {
    -1
};
```

### **`loop` expressions**

The key word `loop {}` is equivalent to `while(true) {}` in other programming languages, it just repeats the code unless you explicitly tell it to stop with a `break` keyword.

Though `while true {}` is valid in rust, the rust compiler will throw a warning to use `loop {}` instead.

### **`break` and `continue`**

- **`break`** - Using `break` inside a `loop` can return a value. On the other hand in `while` and `for` it does not.

    ```rust
    let mut counter = 0;
    
    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };
    ```

- **`continue`** - Not much difference in other programming languages, they just skip the remaining code below it, then proceeds to the next iteration of the loop.

### **Loop Labels**

By default if you have **loops** within **loops**, `break` and `continue` apply to the innermost `loop` at that point.

In Rust we can label a loop, and `break` on a specific loop label.

To **label a loop** we use the `'` single quote, name of the loop, and a `:` colon, this might be useful when breaking out of nested loops e.g.

```rust
'counting_up: loop { /* code ... */ }
'counting_down: while cnt >= 1 { /* code ... */ }
```

To **break out of a labeled loop**, we use the `'` single quote, name of the loop, and a `;` semicolon.

```rust
fn main() {
    let mut count = 0;
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {count}");
}
```

### **`while` statements**

Yes in Rust, `while` loops are statements, unlike `loop` expressions, we **cannot return** a value using a `break` inside a `while` loop.

In general while loops in Rust are mostly the same with other programming languages like C and C++ it will run as long as it satisfies the given condition, the only difference is we can label it.

### **`for` statements**

Iterates a collection, also unlike using a `while` loop that adds runtime overhead because index bounds checking, it seems that `for` statements in rust doesn't need that.

```rust
let arr = [10, 20, 40, 80, 160, 320];

for element in arr {
    print!("{element} ");
}
println!();
```

> [!WARNING]  
> In some cases, when passing `collections` in a `for` loop statement like the `arr` in the example above (specially for types that does not implement the `Copy` trait), be reminded that it is a **move**, hence the collection will be unusable/invalid after passing it to the `for` loop statement, for example if we use a `Vec<i32>` this would be the case.
>
> On the other hand, the example above uses type `[i32; 6]` array, so there is really is no problem here since `i32` implements the `Copy` trait.
>
> If instead we use a `[String; 6]` as an array type, the similar behavious as explained in the beginning of this warning will occur.

### **`for` + `ranges`**

You could also use ranges in `for` loop and maybe use it to index `collections` or compound types like the array above, **but this is not recommended because of the performance overhead added**.

```rust
for num in 1..10 {
    print!("{num} ");
}
println!();

// using a reversed range
for number in (1..4).rev() {
    println!("{number}!");
}
println!("LIFTOFF!!!");

```