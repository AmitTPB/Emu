#ifndef INES_H
#define INES_H

#include "types.h"

typedef struct {
    unsigned int prg_size;
    unsigned int chr_size;
    byte flags[10];
    byte *prg_rom;
    byte *chr_rom;
} ines_rom;

ines_rom parse_ines_file(char *filename);

#endif