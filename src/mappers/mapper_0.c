#include "mapper_0.h"
byte mapper0_cpu_read_byte(word addr){
    printf("read!\n");
    return 0;
}
void mapper0_cpu_write_byte(word addr, byte val){
    printf("write!\n");
}
