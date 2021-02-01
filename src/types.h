#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define byte uint8_t
#define word uint16_t
#define cycle_count unsigned int
#define signed_byte int8_t

typedef enum {
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

typedef enum {
    C_flag = 1 << 0,
    Z_flag = 1 << 1,
    I_flag = 1 << 2,
    D_flag = 1 << 3,
    B_flag = 1 << 4,
    V_flag = 1 << 6,
    N_flag = 1 << 7
} flag;

typedef struct {
    word PC;
    word SP;
    byte A, X, Y, P;
} cpu_status;

struct {
    addresing_mode mode;
    cycle_count (*function)(cpu_status *status, word input, bool mem);
} typedef instruction;

instruction opcode_table[256];

#endif