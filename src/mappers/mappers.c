#include "mappers.h"
mapper mmu;
void init_mapper(int mapper_num){
    mmu.read_byte = mapper0_read_byte;
}
