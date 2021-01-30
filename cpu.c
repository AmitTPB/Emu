#include "cpu.h"

int main(){
    CPU *cpu;
    Memory *Mem;
    cpu = Reset_CPU();
    Mem = Reset_Memory();
    for(int i=0;i<8;i++){
        printf("%d: %d\n", i, cpu->P[i]);
    }
    printf("%d %d %d\n", cpu->A, cpu->X, cpu->Y);
    printf("%x %x\n", cpu->SP, cpu->PC);
    int counter = 0;
    for(int i=0; i<MAX_MEM;i++){
        if(Mem->Data[i]==0){
            counter++;
        }
    }
    printf("%d\n", counter);

    
}
