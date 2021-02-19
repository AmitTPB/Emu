#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"
#define MEM_SIZE 65536

byte memory[MEM_SIZE];
void init_memory();
byte read_memory(word addr);
void write_memory(word addr, byte value);
word read_memory_word(word addr);
void write_memory_word(word addr, word value);
word to_little_endian(byte b1, byte b2);
void dump_memory();
void push_byte(cpu_status *status, byte value);
void push_word(cpu_status *status, word value);
byte pop_byte(cpu_status *status);
word pop_word(cpu_status *status);

#endif