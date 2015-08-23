package main

import (
	"fmt"
)

func fibonacci() func() int {
	f1 := 1
	f2 := 0
	return func() int {
		temp := f2
		f2 = f1
		f1 = f1 + temp
		return f1
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
