#ifndef MISC_OPCODES_H
#define MISC_OPCODES_H
#include "../types.h"
#include "../flags.h"
#include "../memory.h"

cycle_count instruction_nop(cpu_status *status, word input, bool mem);

cycle_count instruction_sei(cpu_status *status, word input, bool mem);
cycle_count instruction_sed(cpu_status *status, word input, bool mem);
cycle_count instruction_sec(cpu_status *status, word input, bool mem);

cycle_count instruction_clc(cpu_status *status, word input, bool mem);
cycle_count instruction_cld(cpu_status *status, word input, bool mem);
cycle_count instruction_cli(cpu_status *status, word input, bool mem);
cycle_count instruction_clv(cpu_status *status, word input, bool mem);

cycle_count instruction_jmp(cpu_status *status, word input, bool mem);

cycle_count instruction_lda(cpu_status *status, word input, bool mem);
cycle_count instruction_ldx(cpu_status *status, word input, bool mem);
cycle_count instruction_ldy(cpu_status *status, word input, bool mem);

cycle_count instruction_stx(cpu_status *status, word input, bool mem);
cycle_count instruction_sty(cpu_status *status, word input, bool mem);
cycle_count instruction_sta(cpu_status *status, word input, bool mem);

cycle_count instruction_tax(cpu_status *status, word input, bool mem);
cycle_count instruction_tay(cpu_status *status, word input, bool mem);
cycle_count instruction_tsx(cpu_status *status, word input, bool mem);
cycle_count instruction_txa(cpu_status *status, word input, bool mem);
cycle_count instruction_txs(cpu_status *status, word input, bool mem);
cycle_count instruction_tya(cpu_status *status, word input, bool mem);

cycle_count instruction_rol(cpu_status *status, word input, bool mem);
cycle_count instruction_ror(cpu_status *status, word input, bool mem);
#endif