#include "mappers.h"
void init_mapper(int mapper_num, mapper *map){
    map->read_byte = mapper0_read;
}
