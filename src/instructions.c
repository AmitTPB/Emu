#include "instructions.h"
instruction opcode_table[256];
cycle_count run_instruction(cpu_status *cpu, instruction *instr)
{
    byte arg1 = read_memory(cpu->PC + 1);
    byte arg2 = read_memory(cpu->PC + 2);
    word word_arg = to_little_endian(arg1, arg2);
    cycle_count cycles = 0;

    switch (instr->mode)
    {
    case ZERO_PAGE:
        cycles = 3;
        cycles += instr->function(cpu, arg1, true);
        break;
    case ZERO_PAGE_X:
        cycles = 4;
        cycles += instr->function(cpu, arg1 + cpu->X, true);
        break;
    case ZERO_PAGE_Y:
        cycles = 4;
        cycles += instr->function(cpu, arg1 + cpu->Y, true);
        break;
    case ABSOLUTE:
        cycles = 4;
        cycles += instr->function(cpu, word_arg, true);
        break;
    case INDEXED_ABSOLUTE_X:
        cycles = (word_arg >> 8 != (word_arg + cpu->X) >> 8) ? 5 : 4;
        cycles += instr->function(cpu, word_arg + cpu->X, true);
        break;
    case SPECIAL_INDEXED_ABSOLUTE_X:
        cycles = 5;
        cycles += instr->function(cpu, word_arg + cpu->X, true);
        break;
    case INDEXED_ABSOLUTE_Y:
        cycles = (word_arg >> 8 != (word_arg + cpu->Y) >> 8) ? 5 : 4;
        cycles += instr->function(cpu, word_arg + cpu->Y, true);
        break;
    case SPECIAL_INDEXED_ABSOLUTE_Y:
        cycles = 5;
        cycles += instr->function(cpu, word_arg + cpu->Y, true);
        break;
    case INDIRECT:
        cycles = 6;
        cycles += instr->function(cpu, read_memory_word(word_arg), true);
        break;
    case IMPLIED:
        cycles = 2;
        cycles += instr->function(cpu, 0, NULL);
        break;
    case ACCUMULATOR:
        cycles = 2;
        cycles += instr->function(cpu, cpu->A, false);
        break;
    case IMMEDIATE:
        cycles = 2;
        cycles += instr->function(cpu, arg1, false);
        break;
    case RELATIVE:
        cycles = 2;
        cycles += instr->function(cpu, arg1, false);
        break;
    case INDEXED_INDIRECT: // INDIRECT_X
        cycles = 6;
        cycles +=
            instr->function(cpu, read_memory_word(arg1 + cpu->X), true);
        break;
    case INDIRECT_INDEXED: // INDIRECT_Y
        cycles = (read_memory_word(arg1) >> 8 !=
                  (read_memory_word(arg1) + cpu->Y) >> 8)
                     ? 6
                     : 5;
        cycles +=
            instr->function(cpu, read_memory_word(arg1) + cpu->Y, true);
        break;
    case SPECIAL_INDIRECT_INDEXED: // INDIRECT_Y
        cycles = 6;
        cycles +=
            instr->function(cpu, read_memory_word(arg1) + cpu->Y, true);
        break;
    }

    return cycles;
}
