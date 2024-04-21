#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "libs/initialize.h"
#include "libs/constants.h"
#include <SDL2/SDL_image.h>

uint8_t SDL_initialize(void) 
{
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0)
    {
        printf("error  initializing SDL: %s\n", SDL_GetError());
        return FALSE;
    }
 
    return TRUE;
}

SDL_Window* window_initialize(void)
{
    SDL_Window* win = SDL_CreateWindow("Sorcerer Tower Defense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!win)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return win;
}

SDL_Renderer* renderer_initialize(SDL_Window* win) {
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
    {
        printf("errore creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return NULL;
    }   

    return rend;
}