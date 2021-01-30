#ifndef MEM_H
#define MEM_H
#include "cpu.h"
#define MAX_MEM 1024*64
#define Byte uint8_t
#define Word uint16_t
struct{
    Byte Data[MAX_MEM];
}typedef Memory;

Memory *Reset_Memory(){
    Memory *Mem = (Memory *) malloc(sizeof(Memory));
    for(int i=0; i<MAX_MEM;i++){
        Mem->Data[i]=0;
    }
    return Mem;

}

#endif