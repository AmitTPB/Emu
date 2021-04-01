#ifndef CPU_H
#define CPU_H

#include "flags.h"
#include "ines.h"
#include "instructions.h"
#include "opcode.h"
#include "visual.h"

cpu_status *New_CPU();
cycle_count exec_instruction(cpu_status *cpu);

#endif
