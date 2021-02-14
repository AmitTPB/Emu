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
void write_memory_word(word addr, word value){
    write_memory(addr, value);
    write_memory(addr+1, value >> 8);
}

word to_little_endian(byte b1, byte b2) { return (((word)b2) << 8) | b1; }

void push_byte(cpu_status *status, byte value){
    write_memory(status->SP|0x0100, value);
    status->SP--;
}

void push_word(cpu_status *status, word value){
    write_memory_word((status->SP-1)|0x0100, value);
    status->SP-=2;
}

byte pop_byte(cpu_status *status){
    status->SP++;
    return read_memory(status->SP|0x100);
}

word pop_word(cpu_status *status){
    return read_memory_word((status->SP+1)|0x100);
    status->SP+=2;
}