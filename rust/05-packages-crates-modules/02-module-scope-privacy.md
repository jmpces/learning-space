# Defining Modules to Control Scope and Privacy

We’ll talk about **modules** and other parts of the **module system** namely:

- **paths** that allow you to name items; the use keyword that brings a path into scope;

- the **`pub`** keyword to **make items public**.

We’ll also discuss the **`as`** keyword, **external packages**, and the **glob operator**.

# Reminders

- When **compiling a crate**, the compiler **first looks in the crate root file** (usually `src/lib.rs` for a **library crate** or `src/main.rs` for a **binary crate**) for code to compile.

- When **declaring modules** - say, you declare a “garden” module with `mod garden;` The compiler will look for the module’s code in these places:
    - Inline, within curly brackets that replace the semicolon following `mod garden`
    - In the file `src/garden.rs`
    - In the file `src/garden/mod.rs`

- When **declaring submodules** - In any file other than the crate root, you can declare submodules.

    For example, you might declare `mod vegetables;` in `src/garden.rs`. The compiler will look for the submodule’s code within the directory named for the parent module in these places:

    - Inline, directly following `mod vegetables`, within curly brackets instead of the semicolon
    - In the file `src/garden/vegetables.rs`
    - In the file `src/garden/vegetables/mod.rs`

- **Paths to code in modules**: Once a module is part of your crate, you can refer to code in that module from anywhere else in that same crate, as long as the privacy rules allow, using the path to the code.

    For example, an Asparagus type in the garden vegetables module would be found at `crate::garden::vegetables::Asparagus`.

- **Private vs public**: Code within a module is `private` from its parent modules by default.

    To make a module `public`, declare it with `pub mod ` instead of `mod`.
    
    To make items **within a public module** public as well, use `pub` before their declarations.

- **The `use` keyword** creates shortcuts to items reducing repetition of long paths.
    
    In any scope that can refer to `crate::garden::vegetables::Asparagus`, you can create a shortcut with `use crate::garden::vegetables::Asparagus;` and from then on you only need to write `Asparagus` to make use of that type in the scope.

# Grouping Related Code in Modules

Modules let us organize code within a crate for readability and easy reuse.

Modules also allow us to control the privacy of items, because code within a module is private by default.

**Private items are internal implementation details** not available for outside use.

We can choose to make modules and the items within them public, which exposes them to allow external code to use and depend on them.

### Defining Modules

We define a module with the `mod` keyword followed by the **name of the module**.

The body of the module then goes inside curly brackets.

**Inside modules**, we can **place other modules**.

Modules **can also hold definitions** for other items, such as **`structs`**, **`enums`**, **constants**, **traits**, and **function**.