#include "cpu.h"

cpu_status *New_CPU()
{
    cpu_status *status = (cpu_status *)calloc(1, sizeof(cpu_status));
    status->P = 0x60;
    status->PC = read_memory_word(0xFFFC);
    status->SP = 0xFF;
    return status;
}

int exec_instruction(cpu_status *cpu, ines_rom *rom)
{
    byte opcode = read_memory(cpu->PC);
    instruction instr = opcode_table[opcode];

    if (instr.function == NULL)
    {
        printf("bad opcode: %x\n", opcode);
        free(cpu);
        free_ines_rom(rom);
        // dump_memory();
        exit(1);
    }

    run_instruction(cpu, &instr);

    cpu->PC += get_instr_length(instr.mode);
    return 0;
}

int main(int argc, char *argv[])
{
    init_opcodes();
    init_mapper(0);
    char *nes_path = "cpu_dummy_reads.nes";
    ines_rom *rom = parse_ines_rom(nes_path);
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);
    mmu.cpu_read_byte(1);

    cpu->A = 0x90;
    write_memory(cpu->PC, 0x38);

    while (69)
    {
        printf("A: %x, X: %x, Y: %x, P: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC),
               cpu->PC);
        exec_instruction(cpu, rom);
        getchar();
    }

    free(cpu);
}
