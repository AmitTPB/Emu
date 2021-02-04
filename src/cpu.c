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
        free(cpu);
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

    cpu->A = 6;
    memory[0xff00] = 0x20;
    memory[0xff01] = 0x34;
    memory[0xff02] = 0x12;
    memory[0xff03] = 0xa2;
    memory[0xff04] = 0x69;

    memory[0x1234] = 0xa9;
    memory[0x1235] = 0x34;
    memory[0x1236] = 0x60;

    

    while (1)
    {
        printf("A: %x, X: %x, Y: %x, P: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC), cpu->PC);
        exec_instruction(cpu);
        getchar();
    }

    free(cpu);
}
