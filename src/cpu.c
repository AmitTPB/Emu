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
        dump_memory();
        exit(1);
    }

    run_instruction(cpu, &instr);

    cpu->PC += get_instr_length(instr.mode);
}


int main(int argc, char* argv[])
{
    init_opcodes();
    //init_memory();
    memory[0xFFFC] = 0x00;
    memory[0xFFFD] = 0xff;
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);
    
    cpu->X = 0x34;
    
    memory[0xff00] = 0x8e;
    memory[0xff01] = 0x33;
    memory[0xff02] = 0x33;
    memory[0xff03] = 0x20;
    memory[0xff04] = 0x34;
    memory[0xff05] = 0x12;


    memory[0x1234] = 0xa0;
    memory[0x1235] = 0x10;
    memory[0x1236] = 0xa9;
    memory[0x1237] = 0x34;
    memory[0x1238] = 0xd9;
    memory[0x1239] = 0x23;
    memory[0x123a] = 0x33;
    memory[0x123b] = 0x60;


    
    
    

    while (69)
    {
        printf("A: %x, X: %x, Y: %x, P: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC), cpu->PC);
        exec_instruction(cpu);
        getchar();
    }

    free(cpu);
}
