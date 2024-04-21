#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <stdio.h>

#include "libs/game_internal.h"
#include "libs/game.h"

void game_mouse_initialize(Game* game){
    SDL_Surface* surface = IMG_Load("src//assets//cursor.png");
    if (!surface)
    {
        printf("error creating surface: %s\n", SDL_GetError());
        game_clean(game);
        SDL_Quit();
    }

    SDL_Cursor* cursor = SDL_CreateColorCursor(surface, 0, 0);
    SDL_SetCursor(cursor);
};

/*
struct Mouse* game_mouse_create(SDL_Renderer* ren) {
    Mouse* mouse = malloc(sizeof (Mouse));
    mouse->tex = IMG_LoadTexture(ren, "src//assets//cursor.png");
    mouse->rect.w = 25;
    mouse->rect.h = 25;
    mouse->point.w = 1;
    mouse->point.h = 1;
    //SDL_ShowCursor(SDL_DISABLE);
    return mouse;   
};

void game_mouse_update(void* ghandle){
    Game* game = (Game*) ghandle;
    SDL_GetMouseState(&(game->mouse->rect.x), &(game->mouse->rect.y));
    game->mouse->point.x = game->mouse->rect.x;
    game->mouse->point.y = game->mouse->rect.y;
};

void game_mouse_draw(void* ghandle){
    Game* game = (Game*) ghandle;
    SDL_RenderCopy(game->rend, game->mouse->tex, NULL, &(game->mouse->rect));
};
*/