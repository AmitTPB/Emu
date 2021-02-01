#include "logic_opcodes.h"

cycle_count instruction_and(cpu_status *status, word input, bool mem) {
    byte m = mem ? read_memory(input) : input;
    status->A &= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_eor(cpu_status *status, word input, bool mem) {
    byte m = mem ? read_memory(input) : input;
    status->A ^= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_ora(cpu_status *status, word input, bool mem) {
    byte m = mem ? read_memory(input) : input;
    status->A |= m;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return 0;
}

cycle_count instruction_lsr(cpu_status *status, word input, bool mem) {
    byte m = mem ? read_memory(input) : input;
    change_flag(status, check_bit(status->A, 0), C_flag);
    status->A >>= 1;

    change_flag(status, status->A == 0, Z_flag);
    change_flag(status, check_bit(status->A, 7), N_flag);

    return mem ? 2 : 0;
}