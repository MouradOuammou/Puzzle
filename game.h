#ifndef __GAME_H__
#define __GAME_H__

#include "window.h"
#include "event.h"
#include "timer.h"
#include "map.h"

#include <SDL\SDL_ttf.h>

#define NEW_CELL_DELAY	5

unsigned int _game_over;

static void		set_difficulty(map_t *map, unsigned int difficulty);
static void		print_crono(Window *win, TTF_Font *font, Timer *timer);
static int		wait_to_change_difficulty(int time_to_wait);

void	game_run(Window	*win, unsigned int difficulty);
void	game_over(Window *win, TTF_Font *font, Event event, double time);
void	game_save_score(double time, unsigned int difficulty);

#endif /* __GAME_H__ */