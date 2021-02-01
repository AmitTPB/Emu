#include "cpu.h"

cpu_status *New_CPU() {
    cpu_status *status = (cpu_status *)calloc(1, sizeof(cpu_status));
    status->PC = read_memory(0xFFFC);
    status->SP = 0x00FF;
    return status;
}

int exec_instruction(cpu_status *cpu) {
    byte opcode = read_memory(cpu->PC);
    instruction instr = opcode_table[opcode];

    if(instr.function == NULL) {
        printf("bad opcode %x\n", opcode);
        exit(1);
    }
    
    run_instruction(cpu, &instr);

    cpu->PC += get_instr_length(instr.mode);
    
}

int main() {
    init_opcodes();
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);

    memory[0x90] = 0x69;

    memset(memory, 0xea, 5);
    memory[5] = 0x88;
    
    while(true) {
        printf("A: %x, X: %x, Y: %x, P: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC), cpu->PC);
        exec_instruction(cpu);
        getchar();
    }

    free(cpu);
}
