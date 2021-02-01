#ifndef FLAGS_H
#define FLAGS_H

#include "types.h"

void set_flag(cpu_status *status, flag f);
void clear_flag(cpu_status *status, flag f);

#endif