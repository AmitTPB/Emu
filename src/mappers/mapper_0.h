#include "../types.h"

byte mapper0_cpu_read_byte(word addr);
word mapper0_cpu_read_word(word addr);
void mapper0_cpu_write_byte(word addr, byte value);
void mapper0_cpu_write_word(word addr, word value);

byte mapper0_ppu_read_byte(word addr);
word mapper0_ppu_read_word(word addr);
void mapper0_ppu_write_byte(word addr, byte value);
void mapper0_ppu_write_word(word addr, word value);
