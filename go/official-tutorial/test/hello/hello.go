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
