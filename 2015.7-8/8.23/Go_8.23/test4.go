package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func sqrt(n float64) string {
	if n < 0 {
		return ErrNegativeSqrt(n).Error()
	} else {
		return fmt.Sprintf("%v", math.Sqrt(n))
	}
}

func main() {
	fmt.Println(sqrt(-2))
}
