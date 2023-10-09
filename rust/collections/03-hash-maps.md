# HashMap<K, V>

Many programming languages support this kind of data structure, but they often use a different name, such as hash, map, object, hash table, dictionary, or associative array, just to name a few.

# Creating a New Hash Map

```rust
use std::collections::HashMap;

let mut scores = HashMap::new();

scores.insert(String::from("Blue"), 10);
scores.insert(String::from("Yellow"), 50);
```

# Accessing Values in a Hash Map

Here, **`score`** will have the value that’s associated with the `Blue` team, and the result will be `10`.

The **`get` method returns an `Option<&V>`**; if there’s **no value** for that key in the hash map, get will **`return` `None`**.

This program handles the `Option` by calling `copied()` to get an `Option<i32>` rather than an `Option<&i32>`.

Then **`unwrap_or(0)` to set `score`** to zero **if `scores` doesn't have an entry** for the key.

```rust
let mut scores = HashMap::new();

scores.insert(String::from("Blue"), 10);
scores.insert(String::from("Yellow"), 50);

let team_name = String::from("Blue");
let score = scores.get(&team_name).copied().unwrap_or(0);
```

# Iterating Through a Hash Map

We can iterate over each key/value pair in a hash map in a similar manner as we do with vectors, using a for loop

```rust
for (key, value) in &scores {
    println!("{key}: {value}");
}
```

# Hash Maps and Ownership

For **types** that **implement the `Copy` trait**, like **`i32`**, the **values are copied into the hash map**.

For **owned values like `String`**, the **values will be moved** and the **hash map will be the new owner** of those values.

```rust
let field_name = String::from("Favorite color");
let field_value = String::from("Blue");

let mut map = HashMap::new();
map.insert(field_name, field_value);
// field_name and field_value are invalid at this point.
```

> [!IMPORTANT]  
> If we insert references to values into the hash map, the values won’t be moved into the hash map. The values that the references point to must be valid for at least as long as the hash map is valid. We’ll talk more about these issues in the “Validating References with Lifetimes” section in Chapter 10.

# Updating a Hash Map : Overwriting a Value

```rust
scores.insert(String::from("Blue"), 10);
scores.insert(String::from("Blue"), 25);
```

# Just a Little Refresher in Borrowing and References

#### Why does this code compiles?

```rust
let mut scores = HashMap::new();
scores.insert(String::from("Blue"), 10);

let val = scores.entry(String::from("Yellow")).or_insert(50);

println!("val = {}", val);
println!("{:#?}", scores);
```

#### But this code doesn't?

```rust
let mut scores = HashMap::new();
scores.insert(String::from("Blue"), 10);

let val = scores.entry(String::from("Yellow")).or_insert(50);

println!("{:#?}", scores);
println!("val = {}", val);
```

#### Explanation

The former doesn't break any laws of borrowing, but the second one does.

The variable `val` creates a **mutable reference** of the **value stored** in the **hash map** (to test this you can add a `*val = 77;` in the following line and it will change the value in the hash map).

Because of this, If we pass the `scores` in the `println!` macro, it would create another **immutable reference**.

Now the **immutable reference** is overlapping into the scope of the **mutable reference** `val`.

# Adding a Key and Value Only If a Key Isn’t Present

The return value of the entry method is an `enum` called `Entry` that represents a value that might or might not exist.

The `or_insert` method on `Entry` is defined to **return a mutable reference to the value** for the **corresponding Entry key** if that key exists.

If not, **inserts the parameter as the new value** for this key and only then **returns a mutable reference to the new value**.

```rust
let mut scores = HashMap::new();
scores.insert(String::from("Blue"), 10);

scores.entry(String::from("Yellow")).or_insert(50);

//won't do anything, value of blue is still 10
scores.entry(String::from("Blue")).or_insert(50);

println!("{:?}", scores);
```

# Updating a Value Based on the Old Value

```rust
let text = "hello world wonderful world";
let mut map = HashMap::new();

for word in text.split_whitespace() {
    // If it’s the first time we’ve seen a word,
    // we’ll first insert the value 0.
    let count = map.entry(word).or_insert(0);
    *count += 1;
}

println!("{:?}", map);
```

The `split_whitespace()` method **returns an iterator over sub-slices**, separated by whitespace, of the value in text.

The `or_insert(0)` method **returns a mutable reference (`&mut V`) to the value for the specified key**.

Here we **store that mutable reference in the `count` variable**, so in order to assign to that value, we must first **dereference `count` using the asterisk (`*`)**.

# Hashing Functions

**By default, `HashMap` uses a hashing function called SipHash** that can **provide resistance to Denial of Service (DoS) attacks involving hash tables**.

**This is not the fastest hashing algorithm available, but the trade-off for better security** that comes with the drop in performance is worth it.

If you profile your code and find that the default hash function is too slow for your purposes, you can switch to another function by specifying a different hasher.

A hasher is a type that implements the `BuildHasher` trait. We’ll talk about traits and how to implement them in Chapter 10.

You don’t necessarily have to implement your own hasher from scratch; crates.io has libraries shared by other Rust users that provide hashers implementing many common hashing algorithms.