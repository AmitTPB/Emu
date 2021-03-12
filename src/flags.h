#ifndef FLAGS_H
#define FLAGS_H

#include "types.h"

void set_flag(cpu_status *status, cpu_flag f);
void clear_flag(cpu_status *status, cpu_flag f);
bool check_bit(byte b, unsigned int bit);
void change_flag(cpu_status *status, bool boolean, cpu_flag f);

#endif