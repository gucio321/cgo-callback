/* 
 * When I was writting this code only God and I knew
 * what it did.
 *
 * Now only He knows
 */
#include <stdio.h>
#include <stdint.h>
#include "c/source.c"
#include "wrapper.h"


void (*getFunctionPointer(uintptr_t handle))(int) {
        // Define a local function that matches the function pointer type: void (*)(int)
        void localFunction(int value) {
            //unwrapCallback(handle, value);
            fprintf(stderr, "%d\n", handle);
        }

        // Create a variable of type void (*)(int)
        void (*functionVariable)(int);

        // Assign the address of localFunction to the function pointer variable
        functionVariable = localFunction;

        // Return the function pointer
        return functionVariable;
}

void wrap_foo(uintptr_t handle) {
        void (*functionVariable)(int);

        // Assign the function pointer obtained from getFunctionPointer to functionVariable
        functionVariable = getFunctionPointer(handle);

        foo(functionVariable);
}
