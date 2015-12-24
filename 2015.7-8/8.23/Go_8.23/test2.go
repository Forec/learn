package main

import (
	"fmt"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)
	pre := 0
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			var temp string = s[pre+1 : i]
			_, ok := m[temp]
			if ok == true {
				m[temp]++
			} else {
				m[temp] = 1
			}
			pre = i
		}
	}
	return m
}
func main() {
	m := WordCount("wo ai bei jing ai tian an bei jing")
	for v, _ := range m {
		fmt.Printf("%s:%d\n", v, m[v])
	}
}
