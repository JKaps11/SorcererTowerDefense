#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <SDL2/SDL.h>
#include <stdint.h>

SDL_Window* window_initialize(void);
SDL_Renderer* renderer_initialize(SDL_Window* win);
uint8_t SDL_initialize(void);

#endif /* INITIALIZE_H */