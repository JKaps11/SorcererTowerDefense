#ifndef GAME_MOUSE_H
#define GAME_MOUSE_H

#include <SDL2/SDL.h>

typedef struct Mouse{
    SDL_Texture* tex;
    SDL_Rect rect;
    SDL_Rect point;
}Mouse;

struct Mouse* mouse_create(SDL_Renderer* ren);

#endif /* GAME_MOUSE_H */