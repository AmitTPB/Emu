#include "arithmetic_opcodes.h"
cycle_count instruction_dex(cpu_status *status, word input, bool mem){
    status->X--;
    change_flag(status, status->X == 0, Z_flag);
    change_flag(status, check_bit(status->X, 7), N_flag);
    return 0;
}

cycle_count instruction_dey(cpu_status *status, word input, bool mem){
    status->Y--;
    change_flag(status, status->Y == 0, Z_flag);
    change_flag(status, check_bit(status->Y, 7), N_flag);
    return 0;
}
