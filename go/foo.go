package main

import "C"

import (
	"fmt"
	"os"
)

//export Hello
func Hello() {
	fmt.Printf("hello from libfoo\n")
	for _, e := range os.Environ() {
		fmt.Println(e)
	}
}

func main() {}
