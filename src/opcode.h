#ifndef OPCODE_H
#define OPCODE_H

#include "instructions.h"
#include "opcodes/arithmetic_opcodes.h"
#include "opcodes/logic_opcodes.h"
#include "opcodes/misc_opcodes.h"
#include "types.h"

instruction *New_instruction();
int get_instr_length(addresing_mode mode);
void add_opcode(byte opcode, instruction instr);
void init_opcodes();

#endif