#include <stdio.h>
#include <SDL2/SDL.h>
#include "libs/game.h"

int main(int argc, char *argv[])
{
    GHandle* game = game_setup();

    game_main_menu_draw(game);
    game_mouse_draw(game);
    game_render(game);

    int close_requested = 0;
    while(!close_requested)
    {
       game_mouse_update(game);
       close_requested = game_state_update(game);
    }

    game_clean(game);    
    SDL_Quit();

    return 0;
}