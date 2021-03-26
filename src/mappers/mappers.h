#include "mapper_0.h"
#include "../ines.h"

typedef struct {
    byte (*cpu_read_byte)(word addr);
    void (*cpu_write_byte)(word addr, byte value);

    byte (*ppu_read_byte)(word addr);
    void (*ppu_write_byte)(word addr, byte value);

} mapper;
extern mapper mmu;
void init_mapper(int mapper_num);
