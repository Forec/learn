package main

import (
	"fmt"
)

func printSlice(s string, x []int) {
	fmt.Printf("%s len = %d cap = %d %v\n",
		s, len(x), cap(x), x)
}

func main() {
	var p []int = []int{2, 3, 4, 5, 6, 7}
	fmt.Println("p=", p)
	for i := 0; i < len(p); i++ {
		fmt.Printf("p[%d]==%d\n", i, p[i])
	}
	fmt.Println("p[1:4] ==", p[1:4])
	a := make([]int, 5)
	printSlice("a", a)
	b := make([]int, 0, 5)
	printSlice("b", b)
	c := b[:2]
	printSlice("c", c)
	d := c[2:5]
	printSlice("d", d)
	// slice 扩容  b := make([]int,0,5)  b=b[:cap(b)]或b=b[1:](此时len(b)=4,cap(b)=4)
	var z []int
	fmt.Println(z, len(z), cap(z))
	if z == nil {
		fmt.Println("nil!")
	}
}
