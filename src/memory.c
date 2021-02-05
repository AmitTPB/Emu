#include "memory.h"

void init_memory(char *path)
{
    FILE *fp = fopen(path, "rb");
    fseek(fp, 0x10, SEEK_SET);
    fread(&memory[0x8000], sizeof(byte), 0x8000, fp);
    

}

void dump_memory()
{
    FILE *fp = fopen("memdump", "wb");
    fseek(fp, 0, SEEK_SET);
    fwrite(memory, sizeof(byte), 0xF000, fp);

}

byte read_memory(word addr)
{
    return memory[addr];
}

void write_memory(word addr, byte value)
{
    memory[addr] = value;
}

word read_memory_word(word addr)
{
    return to_little_endian(read_memory(addr), read_memory(addr + 1));
}

word to_little_endian(byte b1, byte b2) { return (((word)b2) << 8) | b1; }