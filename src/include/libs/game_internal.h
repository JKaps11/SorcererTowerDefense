#ifndef GAME_INTERNAL_H
#define GAME_INTERNAL_H

#include "libs/game_mouse.h"

typedef struct Game{
    Mouse* mouse;
    SDL_Window* win;
    SDL_Renderer* rend;
    size_t num_textures;
    size_t max_num_textures;
    SDL_Texture* texs[1];
}Game;

#endif /* GAME_INTERNAL_H */