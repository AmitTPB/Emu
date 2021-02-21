#include "ines.h"

ines_rom *parse_ines_rom(char *filename) {
    ines_rom *rom = calloc(sizeof(ines_rom), 1);
    FILE *fp = fopen(filename, "rb");
    word magic_numbers[2];
    fread(&(magic_numbers), 2, 2, fp);
    assert(magic_numbers[0] == 0x454e && magic_numbers[1] == 0x1a53);

    // fseek(fp, 2, SEEK_SET);
    fread(&(rom->prg_size), 1, 1, fp);
    fread(&(rom->chr_size), 1, 1, fp);
    fread(rom->flags, 1, 10, fp);
    if (check_bit(rom->flags[0], 3)) fread(rom->trainer, 1, 512, fp);
    rom->prg_rom = calloc(1, ((uint32_t)rom->prg_size) * 16 * 1024);
    fread(rom->prg_rom, 16 * 1024, rom->prg_size, fp);
    rom->chr_rom = calloc(1, ((uint32_t)rom->chr_size) * 8 * 1024);
    fread(rom->chr_rom, 8 * 1024, rom->chr_size, fp);
    fclose(fp);
    return rom;
}

void free_ines_rom(ines_rom *rom) {
    if (!rom) return;
    if (rom->trainer) free(rom->trainer);
    if (rom->prg_rom) free(rom->prg_rom);
    if (rom->chr_rom) free(rom->chr_rom);
    free(rom);
}