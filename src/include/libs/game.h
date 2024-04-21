#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdint.h>

typedef void GHandle;

extern GHandle *game_setup(void);
extern void game_clean(GHandle* game);
extern void game_render(GHandle* game);

extern void game_main_menu_draw(GHandle* game);

extern uint8_t game_state_update(GHandle* game);

extern void game_mouse_update(GHandle* game);
extern void game_mouse_draw(GHandle* game);

#endif /* GAME_H */