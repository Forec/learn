package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X")
	case "Linux":
		fmt.Println("Linux")
	case "windows":
		fmt.Println("windows")
	default:
		fmt.Printf("%s.", os)
	}
}
