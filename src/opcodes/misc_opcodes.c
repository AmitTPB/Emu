#include "misc_opcodes.h"

cycle_count instruction_nop(cpu_status *status, word input, bool mem)
{
    return 0;
}

cycle_count instruction_sei(cpu_status *status, word input, bool mem)
{
    set_flag(status, I_flag);
    return 0;
}

cycle_count instruction_sed(cpu_status *status, word input, bool mem)
{
    set_flag(status, D_flag);
    return 0;
}

cycle_count instruction_sec(cpu_status *status, word input, bool mem)
{
    set_flag(status, C_flag);
    return 0;
}

cycle_count instruction_clc(cpu_status *status, word input, bool mem)
{
    clear_flag(status, C_flag);
    return 0;
}

cycle_count instruction_cld(cpu_status *status, word input, bool mem)
{
    clear_flag(status, D_flag);
    return 0;
}

cycle_count instruction_cli(cpu_status *status, word input, bool mem)
{
    clear_flag(status, I_flag);
    return 0;
}

cycle_count instruction_clv(cpu_status *status, word input, bool mem)
{
    clear_flag(status, V_flag);
    return 0;
}
