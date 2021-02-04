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

cycle_count instruction_rol(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    change_flag(status, check_bit(m, 7), C_flag);
    if (mem)
    {
        memory[input] = m << 1 | check_bit(m, 7);
        change_flag(status, check_bit(memory[input], 7), N_flag);
    }
    else
    {
        status->A = m << 1 | check_bit(m, 7);
        change_flag(status, check_bit(status->A, 7), N_flag);
    }
    change_flag(status, status->A == 0, Z_flag);
}

cycle_count instruction_ror(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    change_flag(status, check_bit(m, 0), C_flag);
    if (mem)
    {
        memory[input] = m >> 1 | check_bit(m, 0) << 7;
        change_flag(status, check_bit(memory[input], 7), N_flag);
    }
    else
    {
        status->A = m >> 1 | check_bit(m, 0) << 7;
        change_flag(status, check_bit(status->A, 7), N_flag);
    }
    change_flag(status, status->A == 0, Z_flag);
}

cycle_count instruction_bcc(cpu_status *status, word input, bool mem)
{
    if (!check_bit(status->P, 0))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bcs(cpu_status *status, word input, bool mem)
{
    if (check_bit(status->P, 0))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_beq(cpu_status *status, word input, bool mem)
{
    if (check_bit(status->P, 1))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bmi(cpu_status *status, word input, bool mem)
{
    if (check_bit(status->P, 7))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bne(cpu_status *status, word input, bool mem)
{
    if (!check_bit(status->P, 1))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bpl(cpu_status *status, word input, bool mem)
{
    if (!check_bit(status->P, 7))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bvc(cpu_status *status, word input, bool mem)
{
    if (!check_bit(status->P, 6))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}
cycle_count instruction_bvs(cpu_status *status, word input, bool mem)
{
    if (check_bit(status->P, 6))
    {
        status->PC = input-3;
        return ((input >> 8) > 0) + 1;
    }
    return 0;
}

cycle_count instruction_pha(cpu_status *status, word input, bool mem)
{
    memory[status->SP] = status->A;
    status->SP++;
    return 1;
}

cycle_count instruction_php(cpu_status *status, word input, bool mem)
{
    memory[status->SP] = status->P;
    status->SP++;
    return 1;
}

cycle_count instruction_pla(cpu_status *status, word input, bool mem){
    status->A = memory[status->SP];
    status->SP--;

    change_flag(status, status->A==0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);
    return 2;
}

cycle_count instruction_plp(cpu_status *status, word input, bool mem){
    status->P = memory[status->SP];
    status->SP--;
    return 2;
}
