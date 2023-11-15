package main

/*
#include <stdint.h>
#include "wrapper.h"
#include "c/source.h"

extern void unwrapCallback(uintptr_t handle, int data);
*/
import "C"

import (
	"fmt"
	"runtime/cgo"
)

type Callback func(int)

//export unwrapCallback
func unwrapCallback(handle C.uintptr_t, data C.int) {
	h := cgo.Handle(handle)
	val := h.Value().(Callback)
	if val != nil {
		val(int(data))
	}
	h.Delete()
}

func wrapCallback(cb Callback) {
	h := cgo.NewHandle(cb)
	ptr := C.uintptr_t(h)
	C.wrap_foo(ptr)
}

func main() {
	fmt.Println(`
The idea of this program is to use GO function as a callback for a C programm.
	`)

	wrapCallback(func(i int) {
		fmt.Println("OMG IDK why it works: ", i)
	})
}
