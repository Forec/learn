package main

import (
	"fmt"
)

type myFilter interface {
	std() string
	filt(s int) int
}

type Human struct {
	name string
	age  int
}

type MyInt int

func (e MyInt) filt(s int) int {
	a := int(e)
	return a * s
}

func (h Human) filt(s int) int {
	return h.age * s
}

func (e MyInt) std() string {
	return fmt.Sprintf("%v", e)
}

func (h Human) std() string {
	return h.name
}

func main() {
	var t1, t2 myFilter
	t1 = Human{"Forec", 11}
	t2 = MyInt(3)
	fmt.Println("t1.filt(2)=", t1.filt(2))
	fmt.Println("t1.std()=", t1.std())
	fmt.Println("t2.filt(2)=", t2.filt(2))
	fmt.Println("t2.std()=", t2.std())
}
