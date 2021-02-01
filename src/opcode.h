#ifndef OPCODE_H
#define OPCODE_H

#include "cpu.h"
#include "types.h"


typedef enum {
    ZERO_PAGE = 0,
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

struct {
    addresing_mode mode;
    byte (*function)(cpu_status *status);
}typedef instruction;

instruction opcode_table[256];

#endif