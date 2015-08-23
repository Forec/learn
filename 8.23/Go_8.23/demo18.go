package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("When's Tuesday?")
	today := time.Now().Weekday()
	switch time.Tuesday {
	case today + 0:
		fmt.Println("Today")
	case today + 1:
		fmt.Println("Tomorrow")
	case today + 2:
		fmt.Println("In two days")
	default:
		fmt.Println("Too far away")
	}

	// 没有条件的switch 和 switch true一样
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good Morning!")
	case t.Hour() < 18:
		fmt.Println("Good afternoon")
	default:
		fmt.Println("Good evening")
	}
}
