#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

byte read_memory(word addr);
word read_memory_word(word addr);

#endif