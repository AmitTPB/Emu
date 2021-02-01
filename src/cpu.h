#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "opcode.h"




typedef struct {
    word PC;
    word SP;
    byte A, X, Y, P;
}cpu_status;

cpu_status *New_CPU();





#endif