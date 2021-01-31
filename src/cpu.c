#include "cpu.h"
#include "flags.h"
#include "memory.h"


cpu_status *New_CPU() {
	cpu_status *status = (cpu_status *) calloc(1, sizeof(cpu_status));
	status->PC = read_memory(0xFFFC);
	status->SP = 0x00FF;
	return status;
}

int main() {
	cpu_status *cpu = New_CPU();
	byte opcode;
	clear_flag(cpu, C_flag);
	while(69) {
		opcode = read_memory(cpu->PC);
		printf("poop %x", opcode);
	}
}
