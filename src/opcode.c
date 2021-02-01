#include "opcode.h"

int get_instr_length(addresing_mode mode) {
    switch (mode) {
        case ZERO_PAGE:
            return 2;
        case ZERO_PAGE_X:
            return 2;
        case ZERO_PAGE_Y:
            return 2;
        case ABSOLUTE:
            return 3;
        case INDEXED_ABSOLUTE_X:
            return 3;
        case INDEXED_ABSOLUTE_Y:
            return 3;
        case INDIRECT:
            return 3;
        case IMPLIED:
            return 1;
        case ACCUMULATOR:
            return 1;
        case IMMEDIATE:
            return 2;
        case RELATIVE:
            return 2;
        case INDEXED_INDIRECT:
            return 2;
        case INDIRECT_INDEXED:
            return 2;
    }

    // panic("Invalid addressing mode.");
    return -1;
}

void add_opcode(byte opcode, instruction instr) {
    opcode_table[opcode] = instr;
}

void init_opcodes() {
    add_opcode(0xea, (instruction) {IMPLIED, instruction_nop});
}