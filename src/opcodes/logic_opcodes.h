#ifndef LOGIC_OPCODES_H
#define LOGIC_OPCODES_H
#include "../flags.h"
#include "../memory.h"

cycle_count instruction_and(cpu_status *status, word input, bool mem);
cycle_count instruction_eor(cpu_status *status, word input, bool mem);
cycle_count instruction_ora(cpu_status *status, word input, bool mem);
cycle_count instruction_lsr(cpu_status *status, word input, bool mem);

#endif