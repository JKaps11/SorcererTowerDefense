#ifndef GAME_INTERNAL_H
#define GAME_INTERNAL_H

typedef struct Game{
    SDL_Window* win;
    SDL_Renderer* rend;
    size_t num_textures;
    size_t max_num_textures;
    SDL_Texture* texs[1];
}Game;

void game_mouse_initialize(Game* game);

#endif /* GAME_INTERNAL_H */