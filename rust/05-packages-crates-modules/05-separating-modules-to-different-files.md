# Separating Modules to Different Files

### Directory

```bash
src
├── front_of_house
│   └── hosting.rs
├── front_of_house.rs
├── lib.rs
└── main.rs
```

### main.rs
```rust
fn main() {
    restaurant::eat_at_restaurant();
}
```

### lib.rs
```rust
////////////////////////////////////////////////////////
///                    OLD CODE                      ///

/* The declaration and definition of the submodule
`front_of_house` is inside the root crate module `lib.rs`

mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}*/

////////////////////////////////////////////////////////
///                    NEW CODE                      ///

// include/load the `front_of_house.rs` module file.
mod front_of_house;

////////////////////////////////////////////////////////

pub use crate::front_of_house::hosting;

pub fn eat_at_restaurant() {
    println!("eat_at_restaurant()");
    hosting::add_to_waitlist();
}
```

### front_of_house.rs

```rust
////////////////////////////////////////////////////////
///                    OLD CODE                      ///

/* The declaration and definition of the submodules
is in the same module file.

pub mod hosting {
    pub fn add_to_waitlist() {
        println!("add_to_waitlist()");
    }
}
*/

////////////////////////////////////////////////////////
///                    NEW CODE                      ///

/* load the hosting.rs module into the
`front_of_house.rs` module definition

isolates the declaration of the
submodule to a different file.  */

pub mod hosting;

```

### hosting.rs

```rust
// The isolated submodule declarations
pub fn add_to_waitlist() {
    println!("add_to_waitlist()");
}
```