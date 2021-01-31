#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

struct {
    word PC;
    word SP;
    byte A, X, Y, P;
} typedef cpu_status;

cpu_status *New_CPU();

#endif