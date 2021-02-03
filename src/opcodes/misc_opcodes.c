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

cycle_count instruction_jmp(cpu_status *status, word input, bool mem)
{
    assert(mem);
    status->PC = input;
    return 0;
}

cycle_count instruction_lda(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->A = m;
    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);
    return 0;
}

cycle_count instruction_ldx(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->X = m;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}

cycle_count instruction_ldy(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->Y = m;
    change_flag(status, status->Y == 0, Z_flag);
    change_flag(status, check_bit(status->Y, 7), N_flag);
    return 0;
}

cycle_count instruction_sta(cpu_status *status, word input, bool mem)
{
    assert(mem);
    write_memory(input, status->A);
    return 0;
}

cycle_count instruction_sty(cpu_status *status, word input, bool mem)
{
    assert(mem);
    write_memory(input, status->Y);
    return 0;
}

cycle_count instruction_stx(cpu_status *status, word input, bool mem)
{
    assert(mem);
    write_memory(input, status->X);
    return 0;
}

cycle_count instruction_tax(cpu_status *status, word input, bool mem)
{
    status->X = status->A;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}

cycle_count instruction_tay(cpu_status *status, word input, bool mem)
{
    status->Y = status->A;
    change_flag(status, status->Y == 0, Z_flag);
    change_flag(status, check_bit(status->Y, 7), N_flag);
    return 0;
}

cycle_count instruction_tsx(cpu_status *status, word input, bool mem)
{
    status->X = status->SP;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}
cycle_count instruction_txa(cpu_status *status, word input, bool mem)
{
    status->A = status->X;
    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);
    return 0;
}

cycle_count instruction_txs(cpu_status *status, word input, bool mem)
{
    status->SP = status->X;
    return 0;
}

cycle_count instruction_tya(cpu_status *status, word input, bool mem)
{
    status->A = status->Y;
    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);
    return 0;
}
