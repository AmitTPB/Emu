#include "../types.h"
#include "mapper_0.h"

typedef struct {
    byte (*read_byte)(word addr);
    word (*read_word)(word addr);
    void (*write_byte)(word addr, byte value);
    void (*write_word)(word addr, word value);
} mapper;
void init_mapper(int mapper_num, mapper *map);
