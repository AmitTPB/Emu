#include "mapper_0.h"
byte mapper0_cpu_read_byte(word addr, ines_rom *rom){
    if(addr>=0x8000){
        printf("tried to read: %x, mapped to %x, and got %x\n", addr, addr-0x8000, rom->prg_rom[addr-0x8000]);
        return rom->prg_rom[addr-0x8000];
    }
    return -1;
}
void mapper0_cpu_write_byte(word addr, byte value, ines_rom *rom){
    printf("write!\n");
}
