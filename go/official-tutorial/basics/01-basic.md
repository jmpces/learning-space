# Creating your own GO project/module

1. **The following command will create a basic go module project**.

    ```bash
    mkdir <package-name> && cd <package-name>
    go mod init <source>/<package-name>
    touch <package-name>.go
    ```

    There is a proper module naming convention **if you want to share your module with other developers**.

    But for a **non-module project**, not setting up a `<package-name>` format in the command is usually not that important, but still it's much better to add this for formality.

2. **Paste this code in the : `<package-name>.go` file.**

    ```go
    // Declare a main package (a package is a way to group functions,
    // and it's made up of all the files in the same directory).
    package main

    // Import the popular fmt package, which contains functions for 
    // formatting text, including printing to the console.
    // This package is one of the standard library packages
    // you got when you installed Go.
    import "fmt"

    // Implement a main function to print a message to the console.
    // A main function executes by default when you run the main package.
    func main() {
        fmt.Println("Hello, World!")
    }
    ```

3. **Run the GO program**

    ```bash
    go run .
    ```

# Some Basic Go Commands

```bash
go version
go help
```

# Using other Modules Published by Developers

The https://pkg.go.dev/ is like the **npm registry** of the go programming language, you can see here different go packages or modules that you can use through out your project.

As an example we can search the "quote" package in the go package registry, click the `rsc.io/quote` and look at the function in the documentation that we can use inside our module/package in this case the `Go` function.

1. **In your Go code, import the `rsc.io/quote` package and add a call to its `Go` function.**

```go
package main

import "fmt"

// import the quote module
import "rsc.io/quote"

func main() {
    // use the quote module Go function
    fmt.Println(quote.Go())
}
```

2. **Add new module requirements and sums**

    Go will add the quote module as a requirement, as well as a go.sum file for use in authenticating the module.

    ```bash
    go mod tidy
    go run .
    ```

    When you ran `go mod tidy`, it located and downloaded the `rsc.io/quote` module that contains the package you imported. By default, it downloaded the latest version.