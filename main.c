#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "libs/mouse.h"
#include "libs/initialize.h"
#include <math.h>


int main(int argc, char *argv[])
{
    Game game = setup_game();

    Mouse mouse = initialize_mouse(game.rend);

    SDL_RenderClear(game.rend);
    SDL_RenderCopy(game.rend, game.texs[0], NULL, NULL);
    draw_mouse(game.rend, &mouse);
    SDL_RenderPresent(game.rend);


    int close_requested = 0;
    while(!close_requested)
    {
        update_mouse(&mouse);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                close_requested = 1;
            }
        }
    }

    clean_game(&game);    
    SDL_Quit();

    return 0;
}