#include <libs/mouse.h>
#include <SDL2/SDL.h>

struct Mouse initialize_mouse(SDL_Renderer* ren) {
    Mouse mouse;
    mouse.tex = IMG_LoadTexture(ren, "src//assets//cursor.png");
    mouse.rect.w = 25;
    mouse.rect.h = 25;
    mouse.point.w = 1;
    mouse.point.h = 1;
    SDL_ShowCursor(SDL_DISABLE);
    return mouse;   
};

void update_mouse(Mouse* mouse){
    SDL_GetMouseState(&mouse->rect.x, &mouse->rect.y);
    mouse->point.x = mouse->rect.x;
    mouse->point.y = mouse->rect.y;
};

void draw_mouse(SDL_Renderer* ren, Mouse* mouse){
    SDL_RenderCopy(ren, mouse->tex, NULL, &mouse->rect);
};