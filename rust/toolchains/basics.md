# Rustlang Notes

### **Installation rustup on Linux or MacOS**

I would suggest to find the link in the official rust website since this one command given below might be subjected to changes in the future.

```
$ curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
```

### **Update rust**
```
$ rustup update
```

### **Uninstall rust**
```
$ rustup self uninstall
```

### **Documentation**

Access the rust documentation.

```
rustup docs
rustup docs --book
```

### **Compiling Single File Source Code**
```
rustc main.rs
./main
```

### **Creating a Project with Cargo**
```
cargo new project_name
cd project_name
```

### **Build and Run - method 1**

Compiles the code.

Creates the `Cargo.lock,` same with `npm install` that creates a `package.json.lock` file.

by default produces a **debug build**, to enable
optimizations add the **`--release`** flag.

```
cargo build
./target/debug/project_name // run manually
```

### **Build and Run - method 2**

Compiles the code then run it automatically.

```
cargo run
```

### **Cargo File Tracking**

The `cargo build` and `cargo run` command works
like **makefiles**, similar to C and C++ where
if we run the `make` command, the changed sources
are the only one that will be recompiled.

### **Cargo Compile Time Check**

This command will check if your rust code can be
compiled, but unlike `cargo build` and `cargo run`,
`cargo check` **does not** create an executable, because
of this, it is much faster than `cargo run` and
`cargo build`.

```
cargo check
```

### **Add a Package**

- **using cargo**

    ```
    cargo add <package-name>
    ```

- **manually**

    add the name of the package to the Cargo.toml

    ```toml
    <package-name> = "major.minor.patch"
    ```

    the major.minor.patch is the version number of the package that you want to install.


### **Cargo Update Dependencies**

```shell
cargo update
```

### **Cargo Build Dependency Documentation**

Another neat feature of Cargo is that running the cargo doc --open command will build documentation provided by all your dependencies locally and open it in your browser.

```shell
cargo doc --open
```

### **Cargo format your rust code**

Fix the format of your rust code using the following command, this will format all the rust code that you use in your `main.rs` file.

```bash
cargo fmt -v
```