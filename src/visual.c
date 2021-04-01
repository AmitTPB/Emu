#include "visual.h"
#include "memory.h"
#include "types.h"

App *Init_Emulator_window(){
    App *app = malloc(sizeof(App));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
	}
    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize TTF: %s\n", TTF_GetError());
        exit(1);
	}
    app->window = SDL_CreateWindow("Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(!app->window)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);

    if (!app->renderer)
	{
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
	}

    SDL_SetRenderDrawColor(app->renderer, 0x00, 0x1a, 0x51, 0xFF);
    SDL_RenderClear(app->renderer);
    SDL_RenderPresent(app->renderer);

    return app;
}

void kill_Emulator_Window(SDL_Window *window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void displayText(App *app, char *msg, TTF_Font *font, SDL_Color col, int msg_x, int msg_y, SDL_Rect *result){

    SDL_Surface *text = TTF_RenderUTF8_Blended(font, msg, col);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, text);
    SDL_FreeSurface(text);
    text=NULL;
    SDL_Rect *dest = malloc(sizeof(SDL_Rect));

    dest->x = msg_x;
    dest->y = msg_y;

    SDL_QueryTexture(texture, NULL, NULL, &dest->w, &dest->h);
    if(msg_x<0){
        dest->x = SCREEN_WIDTH - dest->w + msg_x + 1;
    }
    if(msg_y<0){
        dest->y = SCREEN_HEIGHT - dest->h + msg_y + 1;
    }


    SDL_RenderCopy(app->renderer, texture, NULL, dest);

    SDL_DestroyTexture(texture);
    texture=NULL;
    result->h=dest->h;
    result->w=dest->w;
    result->x=dest->x;
    result->y=dest->y;
    free(dest);
    return;
}

void display_cpu_status(cpu_status *cpu, App *app){
    char buf[40];
    int curr_y = 0;
    SDL_Color col_white = {255, 255, 255, 255};
    TTF_Font *font = TTF_OpenFont("../resources/comicSans.ttf", 20);
    SDL_Rect *rect = malloc(sizeof(SDL_Rect));

    sprintf(buf, "value of A register is: %x", cpu->A);
    displayText(app, buf, font, col_white, -5, curr_y, rect);
    curr_y+=rect->h;

    sprintf(buf, "value of X register is: %x", cpu->X);
    displayText(app, buf, font, col_white, -5, curr_y, rect);
    curr_y+=rect->h;

    sprintf(buf, "value of Y register is: %x", cpu->Y);
    displayText(app, buf, font, col_white, -5, curr_y, rect);
    curr_y+=rect->h;

    sprintf(buf, "Current instruction is %x at %x", read_memory(cpu->PC), cpu->PC);
    displayText(app, buf, font, col_white, -5, curr_y, rect);
    curr_y+=rect->h;

    TTF_CloseFont(font);
    free(rect);
}

void display_memory_status(cpu_status *cpu, App *app){
    word start = cpu->PC - cpu->PC%0x80;
    int curr_y = 0;
    char buf[30];
    SDL_Color col_white = {255, 255, 255, 255};
    TTF_Font *font = TTF_OpenFont("../resources/comicSans.ttf", 20);
    SDL_Rect *rect = malloc(sizeof(SDL_Rect));
    for(int row = 0;row<15;row++){
        int curr_x = 0;
        sprintf(buf, "%x:", start + row);
        displayText(app, buf, font, col_white, 0, curr_y, rect);
        curr_x+=rect->w + 5;
        for(int column = 0;column<15;column++){
            byte read_byte = read_memory(start+0xF*row+column);
            if(read_byte<=0xf){
               sprintf(buf, "0x0%x", read_byte);
            }
            else{
                sprintf(buf, "0x%x", read_byte);
            }
            displayText(app, buf, font, col_white, curr_x, curr_y, rect);
            if(start+0xF*row+column==cpu->PC){
                SDL_SetRenderDrawColor(app->renderer, 0x93, 0x26, 0x00, 255);
                SDL_RenderFillRect(app->renderer, rect);
                SDL_SetRenderDrawColor(app->renderer, 0x00, 0x1a, 0x51, 0xFF);
                displayText(app, buf, font, col_white, curr_x, curr_y, rect);
            }
            curr_x+=rect->w + 5;
        }
        curr_y+=rect->h;
    }
    TTF_CloseFont(font);
    free(rect);
}
