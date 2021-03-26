#include "../types.h"

byte mapper0_cpu_read_byte(word addr);
void mapper0_cpu_write_byte(word addr, byte value);

byte mapper0_ppu_read_byte(word addr);
void mapper0_ppu_write_byte(word addr, byte value);
