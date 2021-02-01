#include "flags.h"

void set_flag(cpu_status *status, flag f) { status->P |= f; }
void clear_flag(cpu_status *status, flag f) { status->P &= ~f; }
