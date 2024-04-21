#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "libs/game_internal.h"
#include "libs/game.h"

struct Mouse* mouse_create(SDL_Renderer* ren) {
    Mouse* mouse = malloc(sizeof (Mouse));
    mouse->tex = IMG_LoadTexture(ren, "src//assets//cursor.png");
    mouse->rect.w = 25;
    mouse->rect.h = 25;
    mouse->point.w = 1;
    mouse->point.h = 1;
    SDL_ShowCursor(SDL_DISABLE);
    return mouse;   
};

void mouse_update(Game* game){
    SDL_GetMouseState(&(game->mouse->rect.x), &(game->mouse->rect.y));
    game->mouse->point.x = game->mouse->rect.x;
    game->mouse->point.y = game->mouse->rect.y;
};

void mouse_draw(Game* game){
    SDL_RenderClear(((Game*)game)->rend);
    SDL_RenderCopy(game->rend, game->mouse->tex, NULL, &(game->mouse->rect));
};

void game_mouse_update(void* game){
    mouse_update((Game*)game);
};

void game_mouse_draw(void* game){
    mouse_draw((Game*)game);
};