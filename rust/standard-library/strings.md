# Strings

### UTF-8 Strings

**Create a string using the string class**

```rust
// UTF-8 string
let str = String::new();
let name = String::from("from a hard-coded string");
```

**Append to string**

```rust
str.push_str("string literal");
str.push_str(&heap_string);
str.push_str(stack_string);
str.push('c');
```

**Remove front and back white spaces**

```rust
str.trim();
```

**Converting to other types**

The `.parse()` method automatically detects the type anotation `usize` so it can convert the type accordingly.

```rust
let str_idx = String::from("102");
let index: usize = str_idx
    .trim()
    .parse()
    .expect("Index entered was not a number");
```