#include "cpu.h"
#include "types.h"

cpu_status *New_CPU()
{

    /* initialize cpu as stated in power up state.
     * returns a cpu_status pointer to the initialized cpu.
     */
    cpu_status *status = (cpu_status *)calloc(1, sizeof(cpu_status));
    status->P = 0x34;
    status->PC = read_memory_word(0xFFFC);
    status->SP = 0xFD;
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
    cycle_count cpu_cycles = 0;
    long int cycle_counter = 0;


    int single_step=0;

    App *app = Init_Emulator_window();

    while (69)
    {

        // draws the cpu status onto the sdl screen
        display_status(cpu, app);

        doInput();

        //if(getchar()=='s') break;

        /* this is a debugging tool.
         * to set a breakpoint, enter an address in the command line as a hex number
         * example: ./run 0x1234 would set a breakpoint in address 1234.
         * after you reach the breakpoint, entering 'r' + enter in stdin would set mode to single step.
         * every single enter press after would single step through the program.
         * at each step, you can enter 'o' + enter to go back into normal execution mode.
         */
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
        printf("this is cpu cycle number %ld\n", cycle_counter);
        /* instruction should only be executed if cpu is free.
         * we count cycles to know if cpu is free.
         * cycles being zero means we can execute.
         * upon execution, exec_instruction returns the amount of cycles needed,
         * and we dont execute instructions for the next correct amount of cycles.
         */
        if(cpu_cycles==0){
            printf("current instruction is %x at %x\n", read_memory(cpu->PC),
                    cpu->PC);
            cpu_cycles = exec_instruction(cpu);
            printf("A: %x, X: %x, Y: %x, P: %x SP: %x\n", cpu->A, cpu->X, cpu->Y, cpu->P, cpu->SP);
            printf("takes %d cycles!\n", cpu_cycles);
        }

        cpu_cycles--;

        /* if single_step is on, stop execution, as detailed in debugger */
        if(single_step){
            getchar();
        }
        cycle_counter++;
    }
    kill_Emulator_Window(app->window);
    free(cpu);
    free(app);
}
