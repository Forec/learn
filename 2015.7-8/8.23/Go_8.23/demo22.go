package main

import (
	"fmt"
	"math"
)

type Abser interface {
	Abs() float64
}

type Float float64

func main() {
	var a Abser
	f := Float(-math.Sqrt2)
	v := Vertex{3, 4}
	a = f  // a Float implements Abser
	a = &v // a *Vertex implements Abser
	//	a = v  // a Vertex,does NOT implements Abser
	fmt.Println(a.Abs())
}
func (f Float) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

type Vertex struct {
	X, Y float64
}

func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
