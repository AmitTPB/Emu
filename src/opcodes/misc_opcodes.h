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

cycle_count instruction_bcc(cpu_status *status, word input, bool mem);
cycle_count instruction_bcs(cpu_status *status, word input, bool mem);
cycle_count instruction_beq(cpu_status *status, word input, bool mem);
cycle_count instruction_bmi(cpu_status *status, word input, bool mem);
cycle_count instruction_bne(cpu_status *status, word input, bool mem);
cycle_count instruction_bpl(cpu_status *status, word input, bool mem);
cycle_count instruction_bvc(cpu_status *status, word input, bool mem);
cycle_count instruction_bvs(cpu_status *status, word input, bool mem);

cycle_count instruction_pha(cpu_status *status, word input, bool mem);
cycle_count instruction_php(cpu_status *status, word input, bool mem);
cycle_count instruction_pla(cpu_status *status, word input, bool mem);
cycle_count instruction_plp(cpu_status *status, word input, bool mem);

cycle_count instruction_jsr(cpu_status *status, word input, bool mem);
cycle_count instruction_rts(cpu_status *status, word input, bool mem);

cycle_count instruction_brk(cpu_status *status, word input, bool mem);
cycle_count instruction_rti(cpu_status *status, word input, bool mem);
#endif