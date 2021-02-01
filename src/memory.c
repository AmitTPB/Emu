#include "memory.h"

byte read_memory(word addr)
{
	// lolpanis
	return memory[addr];
}

word read_memory_word(word addr)
{
	return (((word)read_memory(addr + 1)) << 8) | read_memory(addr);
}