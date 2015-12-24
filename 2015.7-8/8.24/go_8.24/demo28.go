package main

import "fmt"

func main() {
	c := make(chan int, 2)
	c <- 1
	c <- 2
	//c <- 3  all goroutines will sleep if this line is used
	fmt.Println(<-c)
	fmt.Println(<-c)
}
