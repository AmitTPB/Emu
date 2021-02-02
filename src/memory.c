#include "memory.h"

byte read_memory(word addr) {
    // lolpanis
    return memory[addr];
}

void write_memory(word addr, byte value) {
    // lolpanis
    memory[addr] = value;
}

word read_memory_word(word addr) {
    return to_little_endian(read_memory(addr), read_memory(addr + 1));
}

word to_little_endian(byte b1, byte b2) { return (((word)b2) << 8) | b1; }