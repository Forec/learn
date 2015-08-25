package main

import (
	"fmt"
)

func myfunc(arg ...int) {
	for _, v := range arg {
		fmt.Print(v, " ")
	}
}
func main() {
	myfunc(1, 2, 3, 4, 5, 6)
	for i := 0; i < 5; i++ {
		defer fmt.Println(i)
	}
}
