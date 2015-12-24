package main

import (
	"fmt"
)

func sqrt(n float64) float64 {
	x1 := float64(1)
	var x2 float64
	for i := 1; i < 20; i++ {
		x2 = x1
		x1 = (x2 + n/x2) / 2
	}
	return x1
}
func main() {
	fmt.Println(sqrt(2))
}
