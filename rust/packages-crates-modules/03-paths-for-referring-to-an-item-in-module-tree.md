# Paths for Referring to an Item in the Module Tree

To show Rust where to find an item in a module tree, we use a path in the same way we use a path when navigating a filesystem.

A path can take two forms:

- An **absolute path** is the full path starting from a crate root; for code from an external crate, the absolute path **begins with the crate name**.

    For the code from the current crate, it starts with the literal `crate`.

- A **relative path** starts from the current module and uses `self`, `super`, or an identifier in the current module.
Both absolute and relative paths are followed by one or more identifiers separated by double colons (`::`).

So by playing on these rules... on a create, we can actually access the functions and other types declared in the `main.rs` or `lib.rs` using the `crate` and the `super` keyword (_but there is really no good reason to do this_):

> [!NOTE]  
> This indeed work exactly like the files system; `./target.file` for the relative path or using an absolute path `~/Your/Path/target.file`.

```rust
fn main() {
    test();
    crate::test();
    self::test();
}

fn test() {
    println!("hello rust, from test function in main");
}
```

# Exposing Paths with the `pub` Keyword

All items in a module are **private** by default, If you want to access the items inside it, you would need to explicitly set those items as **public**.

> [!NOTE]  
> There are many considerations around managing changes to your public API to make it easier for people to depend on your crate. These considerations are out of the scope of this book; if you’re interested in this topic, see The Rust API Guidelines.

# Starting Relative Paths with `super`

We can construct relative paths that begin in the parent module, rather than the current module or the crate root, by using super at the start of the path. This is like starting a filesystem path with the `../` syntax.

```rust
fn deliver_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        super::deliver_order();
    }

    fn cook_order() {}
}
```

