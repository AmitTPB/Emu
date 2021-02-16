#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "types.h"
#include "memory.h"

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

typedef struct {
    addresing_mode mode;
    cycle_count (*function)(cpu_status *status, word input, bool mem);
    cycle_count cycle_fix;
}instruction;

cycle_count run_instruction(cpu_status *cpu, instruction *instr);

instruction opcode_table[256];

#endif