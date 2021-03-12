#include "logic_opcodes.h"

cycle_count instruction_and(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->A &= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_eor(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->A ^= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_ora(cpu_status *status, word input, bool mem)
{
    byte m = mem ? read_memory(input) : input;
    status->A |= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_lsr(cpu_status *status, word input, bool mem)
{
    byte value;

    if (mem)
    {
        value = read_memory(input);
        write_memory(input, value >> 1);
    }
    else
    {
        value = status->A;
        status->A = value >> 1;
    }

    change_flag(status, check_bit(value, 0), C_flag);

    change_flag(status, value >> 1 == 0, Z_flag);
    change_flag(status, check_bit(value >> 1, 7), N_flag);

    return mem ? 2 : 0;
}

cycle_count instruction_bit(cpu_status *status, word input, bool mem)
{
    input = read_memory(input);
    change_flag(status, check_bit(input, 6), V_flag);
    change_flag(status, check_bit(input, 7), N_flag);
    change_flag(status, (status->A & input) == 0, Z_flag);
    return 0;
}