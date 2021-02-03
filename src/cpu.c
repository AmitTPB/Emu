#include "cpu.h"

cpu_status *New_CPU()
{
    cpu_status *status = (cpu_status *)calloc(1, sizeof(cpu_status));
    status->P = 0x60;
    status->PC = read_memory_word(0xFFFC);
    status->SP = 0x00FF;
    return status;
}

int exec_instruction(cpu_status *cpu)
{
    byte opcode = read_memory(cpu->PC);
    instruction instr = opcode_table[opcode];

    if (instr.function == NULL)
    {
        printf("bad opcode: %x\n", opcode);
        exit(1);
    }

    run_instruction(cpu, &instr);

    cpu->PC += get_instr_length(instr.mode);
}


int main()
{
    init_opcodes();
    memory[0xFFFC] = 0x00;
    memory[0xFFFD] = 0xff;
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);

    cpu->X = 2;

    memory[0x90] = 0x69;

    memory[0xff00] = 0x78;
    memory[0xff01] = 0x58;
    while (1)
    {
        printf("A: %x, X: %x, Y: %x, P: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC), cpu->PC);
        exec_instruction(cpu);
        getchar();
    }

    free(cpu);
}
