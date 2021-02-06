#ifndef CPU_H
#define CPU_H

#include "instructions.h"
#include "flags.h"
#include "memory.h"
#include "opcode.h"
#include "types.h"

cpu_status *New_CPU();
int exec_instruction(cpu_status *cpu);

#endif