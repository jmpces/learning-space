# Create a Go module

In this tutorial you'll create two modules.

- The first is a **library** which is intended to be imported by other libraries or applications, these types of Go programs uses the `package greetings` above the very first line of code.

- The second is a caller **application** which will use the first, these types of Go programs uses the `package main` above the very first line of code.


Go code is grouped into packages, and packages are grouped into modules, example:

```bash
module
├── package1
│   ├── code1.go
│   ├── code2.go
│   └── code3.go
├── package2
│   └── code1.go
└── packageN
    ├── code1.go
    └── code2.go
```

Your module specifies dependencies needed to run your code, including the Go version and the set of other modules it requires.

As you add or improve functionality in your module, you publish new versions of the module. Developers writing code that calls functions in your module can import the module's updated packages and test with the new version before putting it into production use.

# Our example `greetings` library module

1. Initialize the go project.

    ```bash
    mkdir greetings
    cd greetings
    go mod init example.com/greetings
    touch greetings.go
    ```

2. Paste the following code into your `greetings.go` file and save the file.

    ```go
    package greetings

    import "fmt"

    // Hello returns a greeting for the named person.
    func Hello(name string) string {
        // Return a greeting that embeds the name in a message.
        message := fmt.Sprintf("Hi, %v. Welcome!", name)
        return message
    }
    ```

    - In go a function whose name starts with a capital letter is known as an **exported name**, these functions can be called by other go modules.

    - In Go, the `:=` operator is a shortcut for declaring and initializing a variable in one line (Go uses the value on the right to determine the variable's type). Taking the long way, you might have written this as:

        ```go
        var message string
        message = fmt.Sprintf("Hi, %v. Welcome!", name)
        ```

    - Use the `fmt` package's `Sprintf` function to create a greeting `message`. The first argument is a format string, and `Sprintf` substitutes the name parameter's value for the `%v` format verb. Inserting the value of the name parameter completes the greeting text.

_My question is does the form below not allowed in go? (look this up)_

```go
var message = fmt.Sprintf("Hi, %v. Welcome!", name)
```

