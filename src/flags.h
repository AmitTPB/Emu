#ifndef FLAGS_H
#define FLAGS_H

#include "cpu.h"

typedef enum {
    C_flag = 1 << 1,
    Z_flag = 1 << 2,
    I_flag = 1 << 3,
    D_flag = 1 << 4,
    B_flag = 1 << 5,
    V_flag = 1 << 7,
    N_flag = 1 << 8
} flag;

void set_flag(cpu_status *status, flag f);
void clear_flag(cpu_status *status, flag f);

#endif