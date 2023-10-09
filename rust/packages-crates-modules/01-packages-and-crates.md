# Packages and Crates

The first parts of the **module system** we’ll cover are **packages** and **crates**.

# Crates

A **crate** is the smallest amount of code that the Rust compiler considers at a time.

Even if you run `rustc` rather than `cargo` and pass a **single source code file**, the compiler considers that file to be a **crate**.

Crates can contain **modules**, and the **modules** may be defined in **other files** that get compiled with the **crate**.

## Two forms of Crates

- **Binary crates** are programs you can compile to an **executable** that you can run, such as a command-line program or a server. Each **must have a function called `main`** that defines what happens when the executable runs.

- **Library crates** - library crates **don’t have a `main` function**, and they **don’t compile to an executable**. Instead, they define functionality intended to be shared with multiple projects.

Most of the time when Rustaceans say “crate”, they mean library crate, and they use “crate” interchangeably with the general programming concept of a “library".

The **crate root** is a source file that the Rust compiler starts from and makes up the root module of your crate.

# Packages

A **package** is a bundle of one or more crates that provides a set of functionality.

A package contains a `Cargo.toml` file that describes how to build those crates.

A package can contain **as many binary crates** as you like, but **at most only one library crate**.

A package **must contain at least one crate**, whether that’s a library or binary crate.

## Cargo Packages

We can create a package after we run cargo new.

There’s also a `src` directory that contains `main.rs`. Open `Cargo.toml` in your text editor, and note there’s no mention of `src/main.rs`.

### Binary Crate

The `src/main.rs` is the **crate root** of a **binary crate**, this is how the toml file will look like it it was declared explicitly.

**if written explicitly:**

_keep in mind that you don't need to make write your toml file like this explicitly, since this is already the default._

```toml
[package]
name = "hallo"
version = "0.1.0"
edition = "2018"

[[bin]]
name = "hallo"
src = "src/main.rs"
```

### Library Crate

Likewise, `src/lib.rs` is the **crate root** of a **library crate**. Cargo passes the crate root files to rustc to build the library or binary.

**if written explicitly:**

```toml
[package]
name = "hallo"
version = "0.1.0"
edition = "2018"

[lib]
name = "hallo"
path = "src/lib.rs"
```

If a package contains `src/main.rs` and `src/lib.rs`, it has two crates: a binary and a library, both with the same name as the package.

### Binary & Library Crate

**if written explicitly:**

```toml
[package]
name = "hallo"
version = "0.1.0"
edition = "2018"

[[bin]]
name = "hallo"
path = "src/main.rs"

[lib]
name = "hallo"
path = "src/lib.rs"
```

### Multiple Binary Crate

A package **can have multiple binary crates** by placing files in the `src/bin` directory: each file will be a separate binary crate.