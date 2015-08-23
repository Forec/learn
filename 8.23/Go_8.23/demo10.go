package main

import (
	"fmt"
)

type Vertex struct {
	X, Y int
}

var (
	p = Vertex{1, 2}
	q = &Vertex{1, 2}
	r = Vertex{X: 1}
	s = Vertex{}
)

func main() {
	var v *Vertex = new(Vertex)
	fmt.Println(v)
	v.X, v.Y = 11, 9
	fmt.Println(v)
	fmt.Println(p, q, r, s)
}
