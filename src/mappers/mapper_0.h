#include "../types.h"
#include "../ines.h"
byte mapper0_cpu_read_byte(word addr, ines_rom *rom, byte *memory);
void mapper0_cpu_write_byte(word addr, byte value, ines_rom *rom, byte *memory);

byte mapper0_ppu_read_byte(word addr);
void mapper0_ppu_write_byte(word addr, byte value);

