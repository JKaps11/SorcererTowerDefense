#include <SDL2/SDL.h>
#include <stdio.h>
#include "libs/initialize.h"
#include "libs/constants.h"
#include <assert.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>

int initialize_SDL(void) 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error  initializing SDL: %s\n", SDL_GetError());
        return FALSE;
    }
 
    return TRUE;
}

SDL_Window* initialize_window(void)
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

SDL_Renderer* initialize_renderer(SDL_Window* win) {
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

int create_image_texture(Game* game, char image_path[])
{ 
    SDL_Surface* surface = IMG_Load(image_path);
    if (!surface)
    {
        printf("error creating surface: %s\n", SDL_GetError());
        clean_game(game);
        SDL_Quit();
        return FALSE;
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game->rend, surface);
    SDL_FreeSurface(surface);
    if(!tex)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        clean_game(game);
        SDL_Quit();
        return FALSE;
    }

    // reallocate space if game->texs is full
    if(game->max_num_textures == game->num_textures)
    {
        game->max_num_textures += 5;
        game->texs = realloc(game->texs, game->max_num_textures * sizeof(SDL_Texture*));
    }
    
    game->texs[game->num_textures] = tex;
    game->num_textures++;
    return TRUE;
}

void clean_game(Game* game)
{
    SDL_DestroyRenderer(game->rend);
    SDL_DestroyWindow(game->win);

    for(int i = 0; i < game->num_textures; i++)
    {
        SDL_DestroyTexture(game->texs[i]);
    }
    free(game->texs);

}

struct Game setup_game()
{
    Game game;

    assert(initialize_SDL() == TRUE);

    game.win = initialize_window();
    game.rend = initialize_renderer(game.win);
    game.texs = (SDL_Texture**) malloc(5*sizeof(SDL_Texture*));
    game.num_textures = 0;
    game.is_running = TRUE;
    game.max_num_textures = 5;

    if(!game.rend || !game.win)
    {
        game.is_running = FALSE;
    }

    // setting up backround image
    if(create_image_texture(&game,"src\\assets\\Main_Menu_Background.jpg") == FALSE)
    {
        game.is_running = FALSE;
    }

    return game;
}