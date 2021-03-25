#include "mappers.h"
mapper mmu;
void init_mapper(int mapper_num){
    mmu.cpu_read_byte = mapper0_cpu_read_byte;
}
