package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

type Muls struct {
	Number  int
	Count   int
	Product int
}

func main() {
	const ROWS = 10
	const COLS = 10

	var correct_answers = 0
	var table [ROWS][COLS]Muls
	for i := 0; i < ROWS; i++ {
		for j := 0; j < COLS; j++ {
			table[i][j] = Muls{
				Number:  (i + 1),
				Count:   (j + 1),
				Product: (i + 1) * (j + 1),
			}
		}
	}

	reader := bufio.NewReader(os.Stdin)

	// choice
	fmt.Print("Select Mode | 'display' or 'answer' | : ")
	choice, _ := reader.ReadString('\n')
	choice = choice[:len(choice)-1]

	switch choice {
	case "display":
		fmt.Print("Multiplication Table : 10x10\n\n")
		for i := 0; i < ROWS; i++ {
			for j := 0; j < COLS; j++ {
				fmt.Printf("%v * %v = %v\t", table[i][j].Number, table[i][j].Count, table[i][j].Product)
			}
			fmt.Println()
		}
	case "answer":
		var wrong_answers = make([]Muls, 0)

		for i := range table {
			for j := range table[i] {
				rni := rand.Intn(len(table))
				rnj := rand.Intn(len(table[i]))
				table[i][j], table[rni][rnj] = table[rni][rnj], table[i][j]
			}
		}

		fmt.Print("Answer the multiplication table questions as fast a possible\n\n")

		var num = 1
		for i := 0; i < ROWS; i++ {
			for j := 0; j < COLS; j++ {
				fmt.Printf("%v.) %v x %v = ? : ", num, table[i][j].Number, table[i][j].Count)

				text, _ := reader.ReadString('\n')
				answer, _ := strconv.Atoi(text[:len(text)-1])

				if answer == table[i][j].Product {
					fmt.Print("your answer ", answer, " is correct\n\n")
					correct_answers++
				} else {
					fmt.Print(answer, " != ", table[i][j].Product, " | wrong \n\n")
					wrong_answers = append(wrong_answers, table[i][j])
				}

				num++
			}
		}

		fmt.Println("\nWrong Answers : ")
		for _, v := range wrong_answers {
			fmt.Printf("%v x %v = %v\t", v.Number, v.Count, v.Product)
		}

		fmt.Println("\nScore : ", correct_answers, "/", ROWS*COLS)
	default:
		fmt.Println("Invalid Choice")
	}
}
