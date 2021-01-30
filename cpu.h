#ifndef CPU_H
#define CPU_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "flags.h"
#include "memory.h"

#define Byte uint8_t
#define Word uint16_t
typedef enum{
    unset,
    set
} Flag;
struct{
    Word PC;
    Word SP;
    Byte A,X,Y;
    Flag P[6];

        

}typedef CPU;

void Reset_flags(CPU *cpu){
    for(int i=0;i<8;i++){
        cpu->P[i] = unset;
    }
}

CPU *Reset_CPU(){
    CPU *cpu = calloc(1, sizeof(CPU));
    cpu->PC = 0xFFFC;
    cpu->SP = 0x00FF;
    Reset_flags(cpu);
    return cpu;
}

#endif