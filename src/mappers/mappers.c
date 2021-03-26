#include "mappers.h"
mapper mmu;
void init_mapper(int mapper_num){
    switch(mapper_num){
    case 0:
    mmu.cpu_read_byte = mapper0_cpu_read_byte;
    mmu.cpu_write_byte = mapper0_cpu_write_byte;

    break;
    }
}
