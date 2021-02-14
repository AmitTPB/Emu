#include "../flags.h"
#include "../memory.h"

cycle_count instruction_dex(cpu_status *status, word input, bool mem);
cycle_count instruction_dey(cpu_status *status, word input, bool mem);
cycle_count instruction_dec(cpu_status *status, word input, bool mem);

cycle_count instruction_inx(cpu_status *status, word input, bool mem);
cycle_count instruction_iny(cpu_status *status, word input, bool mem);
cycle_count instruction_inc(cpu_status *status, word input, bool mem);

cycle_count instruction_asl(cpu_status *status, word input, bool mem);

cycle_count instruction_adc(cpu_status *status, word input, bool mem);
cycle_count instruction_sbc(cpu_status *status, word input, bool mem);

cycle_count instruction_cmp(cpu_status *status, word input, bool mem);
cycle_count instruction_cpx(cpu_status *status, word input, bool mem);
cycle_count instruction_cpy(cpu_status *status, word input, bool mem);