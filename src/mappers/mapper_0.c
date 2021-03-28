#include "mapper_0.h"
byte mapper0_cpu_read_byte(word addr, ines_rom *rom, byte *memory){
    if(addr>=0x8000){
        printf("tried to read: %x from prg rom, mapped to %x, and got %x\n", addr, addr-0x8000, rom->prg_rom[addr-0x8000]);
        return rom->prg_rom[addr-0x8000];
    }
    if(addr>=0x6000){
        printf("tried to read: %x from chr rom, mapped to %x, and got %x\n", addr, addr-0x6000, rom->chr_rom[addr-0x6000]);
        return rom->chr_rom[addr-0x6000];
    }
    if(addr>=0x4020){
        printf("tried to read %x from expansion rom, probably a bug\n", addr);
        return -1;
    }
    if(addr>=0x2000){
        printf("tried to read %x from io registers, not yet implemented.\n", addr);
        return 0;
    }
    printf("tried to read: %x from ram, and got %x\n", addr, memory[addr]);

    return memory[addr];
}
void mapper0_cpu_write_byte(word addr, byte value, ines_rom *rom, byte *memory){
    if(addr>=0x8000){
        printf("tried to write at %x to prg rom, mapped to %x, this is a read only section!\n", addr, addr-0x8000);
        getchar();
        return;
    }
    if(addr>=0x6000){
        printf("tried to write at %x to chr rom, mapped to %x, this is a read only section!\n", addr, addr-0x6000);
        getchar();
        return;
    }
    if(addr>=0x4020){
        printf("tried to write at %x to expansion rom, probably a bug\n", addr);
        return;
    }
    if(addr>=0x2000){
        printf("tried to write at %x to io registers, not yet implemented.\n", addr);
        return;
    }
    printf("tried to write at %x to ram\n", addr);

    memory[addr] = value;
}
