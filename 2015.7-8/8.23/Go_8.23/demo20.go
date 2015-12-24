package main

import (
	"fmt"
	"math"
)

type Float float64

func (f Float) Abs() float64 { // here it must be Float
	// because types not belong to this package can't be defined methods
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}
func main() {
	f := Float(-math.Sqrt2)
	fmt.Println(f.Abs())
}
