package main

import (
	"fmt"
	. "runtime"
)

func main() {
	fmt.Println(NumCPU(), GOMAXPROCS(4))
	fmt.Println(NumGoroutine())
}
