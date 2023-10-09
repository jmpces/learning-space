# Range

**Creating a range**

```rust
let teen_age = 13..=19;
```

**Using range in for loops**

```rust
for age in teen_age {
    print!("{age} ");
}
println!("");

// or

for num in 13..=19 {
    print!("{num} ");
}
println!("");
```

**Output**

```shell
1 2 3 4 5 6 7 8 9 10
```