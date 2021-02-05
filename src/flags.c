#include "flags.h"

void set_flag(cpu_status *status, flag f) { status->P |= f; }
void clear_flag(cpu_status *status, flag f) { status->P &= ~f; }
bool check_bit(byte b, unsigned int bit) { return (b & (1 << bit)) != 0; }
void change_flag(cpu_status *status, bool boolean, flag f)
{
    if (boolean)
    {
        set_flag(status, f);
    }
    else
    {
        clear_flag(status, f);
    }
}