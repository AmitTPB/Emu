#include "memory.h"
byte *memory;
ines_rom *rom;
void init_memory(char *path)
{
    rom = parse_ines_rom(path);
    memory = malloc(MEM_SIZE * sizeof(byte));
}

void dump_memory()
{
    FILE *fp = fopen("memdump", "wb");
    fseek(fp, 0, SEEK_SET);
    fwrite(memory, sizeof(byte), 0xF000, fp);
}

void free_memory(){
    free_ines_rom(rom);
}

byte read_memory(word addr) { return mmu.cpu_read_byte(addr, rom, memory); }

void write_memory(word addr, byte value) { mmu.cpu_write_byte(addr, value, rom, memory); }

word read_memory_word(word addr)
{
    return to_little_endian(read_memory(addr), read_memory(addr + 1));
}
void write_memory_word(word addr, word value)
{
    write_memory(addr, value);
    write_memory(addr + 1, value >> 8);
}

word to_little_endian(byte b1, byte b2) { return (((word)b2) << 8) | b1; }

void push_byte(cpu_status *status, byte value)
{
    write_memory(status->SP | 0x0100, value);
    status->SP--;
}

void push_word(cpu_status *status, word value)
{
    status->SP -= 2;
    write_memory_word((status->SP + 1) | 0x0100, value);
}

byte pop_byte(cpu_status *status)
{
    status->SP++;
    return read_memory(status->SP | 0x100);
}

word pop_word(cpu_status *status)
{
    status->SP += 2;
    return read_memory_word((status->SP - 1) | 0x100);
}
