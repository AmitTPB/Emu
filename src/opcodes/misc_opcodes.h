#ifndef MISC_OPCODES_H
#define MISC_OPCODES_H
#include "../types.h"
#include "../flags.h"

cycle_count instruction_nop(cpu_status *status, word input, bool mem);

#endif