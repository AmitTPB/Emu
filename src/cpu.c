#include "cpu.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

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
    atexit(SDL_Quit);
    init_opcodes();
    init_mapper(0);
    char *nes_path = "../resources/cpu_dummy_reads.nes";
    init_memory(nes_path);
    cpu_status *cpu = New_CPU();
    clear_flag(cpu, C_flag);
    int single_step=0;
    App *app = Init_Emulator_window();
    while (69)
    {
        printf("A: %x, X: %x, Y: %x, P: %x SP: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P, cpu->SP);
        printf("current instruction is %x at %x\n", read_memory(cpu->PC),
               cpu->PC);
        SDL_RenderClear(app->renderer);
        display_cpu_status(cpu, app);
        display_memory_status(cpu, app);
        SDL_RenderPresent(app->renderer);
        doInput();
        SDL_Delay(500);
        
        /*
        if(getchar()=='s'){
            break;
        }*/
        
        for(int i=1;i<argc;i++){
            if (cpu->PC == (int)strtol(argv[i], NULL, 16)){
                char inp = getchar();
                if(inp=='r'){
                    single_step=1;
                }
                if(inp=='o'){
                    single_step=0;
                }
            }
        }
        printf("took %d cycles!\n", exec_instruction(cpu));
        if(single_step){
            getchar();
        }
    }
    kill_Emulator_Window(app->window);
    free(cpu);
    free(app);
}
