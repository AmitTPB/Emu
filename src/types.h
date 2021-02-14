#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define byte uint8_t
#define word uint16_t
#define cycle_count unsigned int
#define signed_byte int8_t

typedef enum {
    C_flag = 1 << 0,
    Z_flag = 1 << 1,
    I_flag = 1 << 2,
    D_flag = 1 << 3,
    B_flag = 1 << 4,
    V_flag = 1 << 6,
    N_flag = 1 << 7
} cpu_flag;

typedef struct {
    word PC;
    byte A, X, Y, P, SP;
} cpu_status;

#endif