#ifndef CPU_H
#define CPU_H

#include "flags.h"
#include "ines.h"
#include "instructions.h"
#include "memory.h"
#include "opcode.h"
#include "types.h"

cpu_status *New_CPU();
int exec_instruction(cpu_status *cpu, ines_rom *rom);

#endif
