#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"
#define MEM_SIZE 65536

byte memory[MEM_SIZE];
byte read_memory(word addr);
word read_memory_word(word addr);

#endif