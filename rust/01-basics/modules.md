# Modules

By default, Rust has a set of items defined in the standard library that it brings into the scope of every program. This set is called the prelude, and you can see everything in it in the standard library documentation.

### Using a Module

This also recursively applies to submodules which are like modules used inside another module.

```rust
mod garden;

// you could also recursively apply the used module to be
// use publicly by external code by making it public

pub mod garden;
```

This in a sense is equivalent (but not really) to:

```c++
// in C++
#include <garden>
```

Or equivalent to the `import` keyword in other laguages.

### The Root Library Crate Module

The `src/lib.rs` file is the root library, all items in the `lib.rs` will not be accessible by using `mod lib;` declaration so calling its function `lib::your_function();` will not work since it is already the root library module.

Instead you need to use the name of your create e.g.;

```rust
crate_name::your_function();
```

### The `use` keyword: Using types directly.

```rust
use std::io;
```

This is equivalent to C++'s when we are directly using a type using the following syntax.

```c++
using std::io;       // uses only the `io`
// or
using namespace std; // uses everything including the `io`

// usage
io.some_method();
```

### The `use` keyword: Giving names or aliases to types.

```rust
use std::io as IO;
```

This is equivalent to C++'s type definition or type aliasing.

```c++
typedef std::io IO;
// or
using IO = std::io;

// usage
IO.some_method();
```

### The `use` keyword: Scope

```rust
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

use crate::front_of_house::hosting;

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
}
```

The examples above uses the `use` keywords to create shortcuts to the items in a module, but those shortcut will **only apply in the current scope** of a module, the `use` keyword will not propagate into the a parent module scope obviously like any other laguages, but the most important thing to remember is that, it **also does not applies** to the **inner modules scope**.

```rust
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

use crate::front_of_house::hosting;

mod customer {
    pub fn eat_at_restaurant() {
        // The compiler error shows that the shortcut
        // no longer applies within the customer module
        hosting::add_to_waitlist();
    }
}
```
# The `use` keyword : Idiomatic Widely Accepted Convention

There’s no strong reason behind these idioms: it’s just the convention that has emerged, and folks have gotten used to reading and writing Rust code this way.

- We should never directly create shortcuts for **Functions** with the `use` keywords, instead just define **only until** the **name of the module scope** where it was defined.

- For **Structs**, **Enums** and **other items** on the other hand, people normaly create direct shortcuts when using them from a module.

# Re-Exporting Names with `use` Keyword

**lib.rs**
```rust
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

pub use crate::front_of_house::hosting;
```

**main.rs**
```rust
restaurant::hosting::add_to_waitlist()
```

# Using Nested Paths to Clean Up Large use Lists

We can combine multiple shortcuts created by `use` keyword into one line using **nested paths**.

**Example 1 : Multiple Shortcuts In Different Line**
```rust
use std::cmp::Ordering;
use std::io;
```

**Example 1 : Multiple Shortcuts In One Line**
```rust
use std::{cmp::Ordering, io};
```

**Example 2 : Multiple Shortcuts In Different Line**
```rust
use std::io;
use std::io::Write;
```

**Example 2 : Multiple Shortcuts In One Line**

We could also use the `self` keyword here to bring the `use std::io` which is the module name itself which is another way that differs to example 1.

```rust
use std::io::{self, Write};
```

# The Glob Operator `*`

Like a **wildcard** the glob `*` operator brings all of the public items in a specific module scope into the current scope.

```rust
use std::collections::*;
```