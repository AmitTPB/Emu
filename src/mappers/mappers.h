#include "mapper_0.h"

typedef struct {
    byte (*cpu_read_byte)(word addr);
    word (*cpu_read_word)(word addr);
    void (*cpu_write_byte)(word addr, byte value);
    void (*cpu_write_word)(word addr, word value);

    byte (*ppu_read_byte)(word addr);
    word (*ppu_read_word)(word addr);
    void (*ppu_write_byte)(word addr, byte value);
    void (*ppu_write_word)(word addr, word value);

} mapper;
extern mapper mmu;
void init_mapper(int mapper_num);
