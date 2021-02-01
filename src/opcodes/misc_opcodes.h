#ifndef MISC_OPCODES_H
#define MISC_OPCODES_H
#include "../types.h"
#include "../flags.h"

cycle_count instruction_nop(cpu_status *status, word input, bool mem);

cycle_count instruction_sei(cpu_status *status, word input, bool mem);
cycle_count instruction_sed(cpu_status *status, word input, bool mem);
cycle_count instruction_sec(cpu_status *status, word input, bool mem);

cycle_count instruction_clc(cpu_status *status, word input, bool mem);
cycle_count instruction_cld(cpu_status *status, word input, bool mem);
cycle_count instruction_cli(cpu_status *status, word input, bool mem);
cycle_count instruction_clv(cpu_status *status, word input, bool mem);

#endif