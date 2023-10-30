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

Rust will throw a compilation error because `r` is recently pointing to `x`, but since `x` is inside a nested scope that get's destroyed before the `println!` macro call, rust can detect that the variable `r` at that point when used by the `println!` macro is already a dangling reference. 

# Generic Lifetimes in Functions

In this function we can see that it take two parameters `x` and `y`, but `x` and `y` could have different lifetimes through out the program, for example;

**Case 1 :** `y` could exist or is instantiated only inside the same local scope where the `longest` fuction is called, then `x` could exist or is instantiated outside of that same local scope, this would mean that `x` has a longer lifetime than `y`, if inside that local scope we assign the result to another variable `z` that is outside of that same local scope, but it returned the `y`, then that would also be a dangling reference.

So Rust prevent the compilation of such function by default.

**Case 2 :** But this will also prevent the compilation of such function even if we use it on **two variables** `x` and `y` that has the **same/valid lifetime**.

On such cases what we need to do is to annotate the lifetime of out parameters and return type in the function, this way we can prevent the first case described in this section, but allow the second one.

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

**Lifetime annotations don’t change how long any of the references live**. Rather, they describe the relationships of the lifetimes of multiple references to each other without affecting the lifetimes.

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

The function signature now tells Rust that for some lifetime `'a`, the function takes two parameters, both of which are string slices that live **at least** as long as the **least given lifetime** `'a` parameter.

The **returned reference** (the return type annotation) will be the smaller lifetime reference of the two parameters `x` and `y`.

# Lifetime Annotations in Struct Definitions

We can define **structs to hold references**, but in that case **we would need to add a lifetime annotation on every reference** in the struct’s definition.

```rust
struct ImportantExcerpt<'a> {
    part: &'a str,
}

fn main() {
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let i = ImportantExcerpt {
        part: first_sentence,
    };
}
```

This annotation means an instance of `ImportantExcerpt` can’t outlive the reference it holds in its `part` field.

# Lifetime Elision Rules

You’ve learned that every reference has a lifetime and that you need to specify lifetime parameters for functions or structs that use references. However, in Chapter 4 we had a function in Listing 4-9, shown again in Listing 10-25, that compiled without lifetime annotations.

```rust
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
```

The reason this function compiles without lifetime annotations is historical: in early versions (pre-1.0) of Rust, this code wouldn’t have compiled because every reference needed an explicit lifetime. At that time, the function signature would have been written like this:

```rust
fn first_word<'a>(s: &'a str) -> &'a str {
```

After writing a lot of Rust code, the Rust team found that Rust programmers were entering the same lifetime annotations over and over in particular situations. These situations were predictable and followed a few deterministic patterns. The developers programmed these patterns into the compiler’s code so the borrow checker could infer the lifetimes in these situations and wouldn’t need explicit annotations.


_The patterns programmed into Rust’s analysis of references_ are called the **lifetime elision rules**. These aren’t rules for programmers to follow; they’re a set of particular cases that the compiler will consider, and **if your code fits these cases, you don’t need to write the lifetimes explicitly**.'

Lifetimes on function or method **parameters** are called **input lifetimes**, and lifetimes on **return** values are called **output lifetimes**.

The compiler uses three rules to figure out the lifetimes of the references when there aren’t explicit annotations.**The first rule applies to input lifetimes**, and the **second and third** rules **apply to output lifetimes**.

If the compiler gets to the end of the three rules and there are still references for which it can’t figure out lifetimes, the compiler will stop with an error. These rules apply to `fn` definitions as well as `impl` blocks.

----

- **Rule 1 :**
    
    The compiler assigns a lifetime parameter to each parameter that’s a reference.
    
    In other words, a function with one parameter gets one lifetime parameter:
    
    ```rust
    fn foo<'a>(x: &'a i32);
    ```
    
    A function with two parameters gets two separate lifetime parameters:
    
    ```rust
    fn foo<'a, 'b>(x: &'a i32, y: &'b i32);
    ```
    
    and so on.

----

- **Rule 2 :**

    If there is exactly one input lifetime parameter, that lifetime is assigned to all output lifetime parameters:
    
    ```rust
    fn foo<'a>(x: &'a i32) -> &'a i32.
    ```

----

- **Rule 3 :**

    If there are multiple input lifetime parameters, but one of them is `&self` or `&mut self` because this is a method, the lifetime of `self` is **assigned to all output lifetime parameters**. This third rule makes methods much nicer to read and write because fewer symbols are necessary.
    
----

In the example above the rules 1 and 2 is enough to determine the lifetime of the returned reference of the method `first_word`, so the rust compiler allows it's compilation even if there is no lifetime anotations.

On the other hand only the rule 1 is applicable to the method `longest`, the rules 2 and 3 is not, the rust compiler will not be able to figure out the lifetime of the returned reference just by applying the rules so it will throw a compilation error for that method.

# Lifetime Annotations in Method Definitions

