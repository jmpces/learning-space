# Validating References with Lifetimes

**_Lifetimes are another kind of generic that we’ve already been using._**

Rather than ensuring that a type has the behavior we want, lifetimes ensure that references are valid as long as we need them to be.

_**Most of the time, lifetimes are implicit and inferred, just like most of the time, types are inferred.**_

We must only annotate types when multiple types are possible.

In a similar way, we must annotate lifetimes when the lifetimes of references could be related in a few different ways.

# Preventing Dangling References with Lifetimes

The main aim of lifetimes is to prevent dangling references, which cause a program to reference data other than the data it’s intended to reference.

> [!NOTE]  
> Dangling Reference - A link or pointer to an instruction, table element, index item, etc. that no longer contains the same content.
>
> In C++ it is Undefined Behavior when Accessing a dangling reference
> It is illegal to access a reference to an object that has gone out of scope or been otherwise destroyed.

# The Borrow Checker

The Rust compiler has a **borrow checker** that compares scopes to determine whether all borrows are valid. 

Rust prevent compilation of programs that can produce dangling reference like the example below:

```rust
fn main() {
    let r;                // ---------+-- 'a
                          //          |
    {                     //          |
        let x = 5;        // -+-- 'b  |
        r = &x;           //  |       |
    }                     // -+       |
                          //          |
    println!("r: {}", r); //          |
}                         // ---------+
```

_The rust book docs has a not as clear explaination in this part about lifetime anotation._

# Generic Lifetimes in Functions

```rust
fn longest(x: &str, y: &str) -> &str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);
}
```

The `return` type needs a generic lifetime parameter on it because Rust can’t tell whether the reference being returned refers to `x` or `y`.

To fix this error, we’ll add **generic lifetime parameters** that define the relationship between the references so the borrow checker can perform its analysis.

# Lifetime Annotation Syntax

Lifetime annotations don’t change how long any of the references live. Rather, they describe the relationships of the lifetimes of multiple references to each other without affecting the lifetimes.

Lifetime annotations have a slightly unusual syntax: the **names of lifetime parameters** must start with an apostrophe (**`'`**) and are **usually all lowercase and very short**, like generic types.

Most people use the name `'a` for the first lifetime annotation. We place lifetime parameter annotations after the `&` of a reference, using **a space to separate the annotation from the reference’s type**.

Here are some examples:

```rust
&i32        // a reference
&'a i32     // a reference with an explicit lifetime
&'a mut i32 // a mutable reference with an explicit lifetime
```

# Lifetime Annotations in Function Signatures

To use lifetime annotations in function signatures, we need to declare the **generic lifetime parameters** inside **angle brackets** between the function name and the parameter list, just as we did with generic type parameters.

```rust
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
```

The function signature now tells Rust that for some lifetime `'a`, the function takes two parameters, both of which are string slices that live at least as long as lifetime `'a`. The function signature also tells Rust that the string slice returned from the function will live at least as long as lifetime `'a`.

The returned reference will be the smaller lifetime reference of the two parameters x and y.