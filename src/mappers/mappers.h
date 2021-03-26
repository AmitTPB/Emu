#include "mapper_0.h"

typedef struct {
    byte (*cpu_read_byte)(word addr, ines_rom *rom, byte *memory);
    void (*cpu_write_byte)(word addr, byte value, ines_rom *rom, byte *memory);

    byte (*ppu_read_byte)(word addr);
    void (*ppu_write_byte)(word addr, byte value);

} mapper;
extern mapper mmu;
void init_mapper(int mapper_num);
