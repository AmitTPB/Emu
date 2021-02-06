#ifndef INES_H
#define INES_H

#include "types.h"
#include "flags.h"

typedef struct {
    byte prg_size;
    byte chr_size;
    byte flags[10];
    byte *prg_rom;
    byte *chr_rom;
    byte *trainer;
} ines_rom;

ines_rom *parse_ines_rom(char *filename);

#endif