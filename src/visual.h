#include "types.h"
#include "memory.h"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>



App *Init_Emulator_window();
void kill_Emulator_Window(SDL_Window *window);
void displayText(App *app, char *msg, TTF_Font *font, SDL_Color col, int msg_x, int msg_y, SDL_Rect *result);
void display_cpu_status(cpu_status *cpu, App *app);
void display_memory_status(cpu_status *cpu, App *app);
