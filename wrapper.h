#ifndef WRAPPER_H
#define WRAPPER_H

#include "c/source.h"
#include <stdint.h>

void wrap_foo(uintptr_t handle);
void unwrapCallback(uintptr_t, int);

#endif // WRAPPER_H
