#include "cpu.h"

cpu_status *New_CPU()
{
    cpu_status *status = (cpu_status *)calloc(1, sizeof(cpu_status));
    status->P = 0x60;
    status->PC = read_memory_word(0xFFFC);
    status->SP = 0xFF;
    return status;
}

cycle_count exec_instruction(cpu_status *cpu)
{
    byte opcode = read_memory(cpu->PC);
    instruction instr = opcode_table[opcode];
    cycle_count cycles;

    if (instr.function == NULL)
    {
        printf("bad opcode: %x\n", opcode);
        free(cpu);
        free_memory();
        // dump_memory();
        exit(1);
    }

    cycles = run_instruction(cpu, &instr);

    cpu->PC += get_instr_length(instr.mode);
    return cycles;
}

int main(int argc, char *argv[])
{
    init_opcodes();
    init_mapper(0);
    char *nes_path = "cpu_dummy_reads.nes";
    init_memory(nes_path);
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);

    cpu->A = 0x90;
    while (69)
    {
        printf("A: %x, X: %x, Y: %x, P: %x SP: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P, cpu->SP);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC),
               cpu->PC);
        printf("took %d cycles!\n", exec_instruction(cpu));
        //getchar();
    }

    free(cpu);
}
