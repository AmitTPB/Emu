#ifndef OPCODE_H
#define OPCODE_H

#include "types.h"

instruction *New_instruction();
int get_instr_length(addresing_mode mode);
void add_opcode(byte opcode, instruction instr);

#endif