#include "visual.h"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

App *Init_Emulator_window(){
    App *app = malloc(sizeof(App));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
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

void displayText(App *app, char *msg, int msg_x, int msg_y, int size){
    if(TTF_Init() != 0){
        printf("Couldnt init SDL_ttf: %s\n", TTF_GetError());
        exit(1);
    }
    TTF_Font *font = TTF_OpenFont("../resources/comicSans.ttf", size);
    if(!font){
        printf("Couldn't load font\n");
        exit(1);
    }

    SDL_Color col_white;
    col_white.r = 255;
    col_white.g = 255;
    col_white.b = 255;
    col_white.a = 255;

    SDL_Surface *text = TTF_RenderUTF8_Blended(font, msg, col_white);

    SDL_RenderClear(app->renderer);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, text);
    SDL_FreeSurface(text);
    text=NULL;
    SDL_Rect dest;

    dest.x = msg_x;
    dest.y = msg_y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app->renderer, texture, NULL, &dest);

    SDL_DestroyTexture(texture);
    texture=NULL;
    SDL_RenderPresent(app->renderer);
}
