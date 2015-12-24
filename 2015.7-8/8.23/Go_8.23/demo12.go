package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m = map[string]Vertex{
	"bell labs": Vertex{
		43.32532, 1431.32532,
	},
	"test forec": Vertex{
		123.4353, 0534.231,
	},
}

func main() {
	fmt.Println(m)
}

/*
var m = map[string]Vertex{
	"bell labs":  {43.32532, 1431.32532},
	"test forec": {123.4353, 0534.231},
}
*/
