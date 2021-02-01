#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define byte uint8_t
#define word uint16_t

typedef enum
{
    ZERO_PAGE,
    ZERO_PAGE_X,
    ZERO_PAGE_Y,
    ABSOLUTE,
    INDEXED_ABSOLUTE_X,
    INDEXED_ABSOLUTE_Y,
    INDIRECT,
    IMPLIED,
    ACCUMULATOR,
    IMMEDIATE,
    RELATIVE,
    INDEXED_INDIRECT,
    INDIRECT_INDEXED
} addresing_mode;

typedef enum
{
    C_flag = 1 << 1,
    Z_flag = 1 << 2,
    I_flag = 1 << 3,
    D_flag = 1 << 4,
    B_flag = 1 << 5,
    V_flag = 1 << 7,
    N_flag = 1 << 8
} flag;

typedef struct
{
    word PC;
    word SP;
    byte A, X, Y, P;
} cpu_status;

struct
{
    addresing_mode mode;
    byte (*function)(cpu_status *status);
} typedef instruction;

instruction opcode_table[256];

#endif