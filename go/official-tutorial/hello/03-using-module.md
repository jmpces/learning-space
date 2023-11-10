# Using The Module We Created

1. In the same parent directory as the module we created in `02` create a new go **application** module project called **`hello`**.

    ```bash
    mkdir hello
    cd hello
    go mod init example.com/hello
    touch hello.go
    ```

2. Then paste the following code that calls our `greetings` module `Hello` function, this will be our **application** module since we're using the `package main` declaration.

    ```go
    package main

    import (
        "fmt"

        // add the greetings package that we created previously
        // as a dependency in this new application package.
        "example.com/greetings"
    )

    func main() {
        // Get a greeting message and print it.
        message := greetings.Hello("Gladys")
        fmt.Println(message)
    }
    ```

3. Edit the `example.com/hello` module to use your local `example.com/greetings` module.

    In production, you’d publish the `example.com/greetings` module from its repository (with a module path that reflected its published location), where Go tools could find it and download it.

    But for now, because you haven't published the module yet, you need to adapt the `example.com/hello` module so it can find the `example.com/greetings` code on your local file system.

    To do that, we redirect Go tools from searching its default module path (where the module isn't) to the local directory (where it is).

    ```bash
    go mod edit -replace example.com/greetings=../greetings
    ```

    After you run the command, the go.mod file in the `hello` directory should include a replace directive:

    ```mod
    replace example.com/greetings => ../greetings
    ```

4. Synchronize the `example.com/hello` module's dependencies, adding those required by the code, but not yet tracked in the module.

    ```bash
    go mod tidy
    ```

    After the command completes, the `example.com/hello` module's **go.mod** file should add a new line like this:


    ```mod
    require example.com/greetings v0.0.0-00010101000000-000000000000
    ```

    The command found the local code in the `greetings` directory, then added a require directive to specify that `example.com/hello` requires `example.com/greetings`.

    The number following the module path is a pseudo-version number -- a generated number used in place of a semantic version number (which the module doesn't have yet).

    To reference a published module, a go.mod file would typically omit the replace directive and use a require directive with a tagged version number at the end.

    ```mod
    require example.com/greetings v1.1.0
    ```

5. Run the `hello` application module

    ```bash
    go run .
    ```