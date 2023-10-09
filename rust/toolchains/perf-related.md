# Performance Related

# Output Assembly Code

```shell
cargo rustc --release -- --emit asm
```

File Output: `ls target/release/deps/<crate_name>-<hash>.s`

If you see multiple `<crate_name>-<hash>-<hash>.rcgu.s` files instead of a `<crate_name>-<hash>.s` file, disable incremental compilation by setting the environment variable `CARGO_INCREMENTAL=0`.

# For other architectures

```shell
cargo rustc --target aarch64-apple-ios --release -- --emit asm
cargo rustc -- --emit asm -C "llvm-args=-x86-asm-syntax=intel"
```