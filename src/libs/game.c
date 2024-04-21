#include <stdint.h>
#include <assert.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "libs/constants.h"
#include "libs/game_internal.h"
#include "libs/game.h"
#include "libs/game_mouse.h"
#include "libs/initialize.h"
#include "libs/texture_codes.h"

void game_clean(void* game)
{
    SDL_DestroyRenderer(((Game*)game)->rend);
    SDL_DestroyWindow(((Game*)game)->win);

    for(int i = 0; i < ((Game*)game)->num_textures; i++)
    {
        SDL_DestroyTexture(((Game*)game)->texs[i]);
    }
    free(game);
}

uint8_t image_texture_create(Game* game, char image_path[])
{
    SDL_Surface* surface = IMG_Load(image_path);
    if (!surface)
    {
        printf("error creating surface: %s\n", SDL_GetError());
        game_clean(game);
        SDL_Quit();
        return FALSE;
    }
    
    SDL_Texture* tex = SDL_CreateTextureFromSurface(game->rend, surface);
    SDL_FreeSurface(surface);
    if(!tex)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        game_clean(game);
        SDL_Quit();
        return FALSE;
    }

    // reallocate space if game->texs is full
    if(game->max_num_textures == game->num_textures)
    {
        game->max_num_textures += 5;
        game = realloc(game,  sizeof (*game) + sizeof(SDL_Texture*) * game->max_num_textures);
    }
    
    game->texs[game->num_textures] = tex;
    game->num_textures++;

    return TRUE;
}

void game_main_menu_draw(void* game){
    SDL_RenderClear(((Game*)game)->rend);
    SDL_RenderCopy(((Game*)game)->rend, ((Game*)game)->texs[BACKROUND_PICTURE], NULL, NULL);
}

void game_render(void* game){
    SDL_RenderPresent(((Game*)game)->rend);
}

uint8_t game_state_update(void* game){
    uint8_t close_requested = 0;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                close_requested = 1;
                break;
        }
    }

    game_render((Game*)game);
    return close_requested;
}

void *game_setup(void)
{
    // add extra space for 4 aditional textures
    Game* game = malloc(sizeof (Game) + sizeof(SDL_Texture*) * 4);

    assert(SDL_initialize() == TRUE);

    game->win = window_initialize();
    game->rend = renderer_initialize(game->win);
    game->num_textures = 0;
    game->max_num_textures = 5;

    game->mouse = mouse_create(game->rend);

    // setting up backround image
    image_texture_create(game,"src\\assets\\Main_Menu_Background.jpg");

    return (void*)game;
}