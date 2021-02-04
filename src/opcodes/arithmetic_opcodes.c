#include "arithmetic_opcodes.h"
cycle_count instruction_dex(cpu_status *status, word input, bool mem)
{
    status->X--;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}

cycle_count instruction_dey(cpu_status *status, word input, bool mem)
{
    status->Y--;
    change_flag(status, status->Y == 0, Z_flag);
    change_flag(status, check_bit(status->Y, 7), N_flag);
    return 0;
}

cycle_count instruction_dec(cpu_status *status, word input, bool mem)
{
    assert(mem);
    write_memory(input, read_memory(input) - 1);
    change_flag(status, read_memory(input) - 1 == 0, Z_flag);
    change_flag(status, check_bit(read_memory(input) - 1, 7), N_flag);
    return 0;
}

cycle_count instruction_inx(cpu_status *status, word input, bool mem)
{
    status->X++;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}

cycle_count instruction_iny(cpu_status *status, word input, bool mem)
{
    status->Y++;
    change_flag(status, status->Y == 0, Z_flag);
    change_flag(status, check_bit(status->Y, 7), N_flag);
    return 0;
}

cycle_count instruction_inc(cpu_status *status, word input, bool mem)
{
    assert(mem);
    write_memory(input, read_memory(input) + 1);
    change_flag(status, read_memory(input) + 1 == 0, Z_flag);
    change_flag(status, check_bit(read_memory(input) + 1, 7), N_flag);
    return 0;
}

cycle_count instruction_asl(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    change_flag(status, check_bit(m, 7), C_flag);
    if (mem)
    {
        memory[input] = m << 1;
        change_flag(status, check_bit(memory[input], 7), N_flag);
    }
    else
    {
        status->A = m << 1;
        change_flag(status, check_bit(status->A, 7), N_flag);
    }
    change_flag(status, status->A == 0, Z_flag);
}
