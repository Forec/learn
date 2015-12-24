package main

import (
	"fmt"
)

type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func main() {
	m = make(map[string]Vertex) // must use make to build a map before it is being used
	m["bell labs"] = Vertex{
		40.5234324, 6746.2342352,
	}
	fmt.Println(m[`bell labs`])
}
