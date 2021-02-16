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
    return 2;
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
        write_memory(input, m << 1);
        change_flag(status, check_bit(read_memory(input), 7), N_flag);
    }
    else
    {
        status->A = m << 1;
        change_flag(status, check_bit(status->A, 7), N_flag);
    }
    change_flag(status, status->A == 0, Z_flag);
    return mem ? 2:0;
}

cycle_count instruction_adc(cpu_status *status, word input, bool mem)
{
    input = mem ? read_memory(input) : input; 
    
    word sum = status->A+input+check_bit(status->P, 1);
    byte result = sum&0xFF;
    change_flag(status, sum>>8, C_flag);
    change_flag(status, ((status->A^result)&(input^result)&0x80), V_flag);
    change_flag(status, check_bit(result, 7), N_flag);
    change_flag(status, !result, Z_flag);
    status->A = result;
    return 0;
    
}
cycle_count instruction_sbc(cpu_status *status, word input, bool mem){
    input = mem ? read_memory(input) : input; 
    input^=0xFF;
    
    word sum = status->A+input+check_bit(status->P, 1);
    byte result = sum&0xFF;
    change_flag(status, sum>>8, C_flag);
    change_flag(status, ((status->A^result)&(input^result)&0x80), V_flag);
    change_flag(status, check_bit(result, 7), N_flag);
    change_flag(status, !result, Z_flag);
    status->A = result;
    return 0;
}

cycle_count instruction_cmp(cpu_status *status, word input, bool mem){
    input = mem ? read_memory(input) : input;
    change_flag(status, status->A>=input, C_flag);
    change_flag(status, status->A==input, Z_flag);
    change_flag(status, check_bit(status->A-input, 7), N_flag);
    return 0;

}
cycle_count instruction_cpx(cpu_status *status, word input, bool mem){
    input = mem ? read_memory(input) : input;
    change_flag(status, status->X>=input, C_flag);
    change_flag(status, status->X==input, Z_flag);
    change_flag(status, check_bit(status->X-input, 7), N_flag);
    return 0;

}
cycle_count instruction_cpy(cpu_status *status, word input, bool mem){
    input = mem ? read_memory(input) : input;
    change_flag(status, status->Y>=input, C_flag);
    change_flag(status, status->Y==input, Z_flag);
    change_flag(status, check_bit(status->Y-input, 7), N_flag);
    return 0;

}
