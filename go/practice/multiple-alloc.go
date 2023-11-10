package main

import "fmt"

func allocate_slice_inside() int {
	s := make([]uint64, 10, 10)
	return len(s)
}

func main() {
	var sum = 0
	for true {
		sum += allocate_slice_inside()
		fmt.Println("Sum = ", sum)
	}
}
