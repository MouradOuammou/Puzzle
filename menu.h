#ifndef __MENU_H__
#define __MENU_H__

#include "window.h"
#include "map.h"

void	splash_screen(Window *win);

static void	get_hight_score(double *time, FILE *file);
static void	manage_engine(map_t *map);

void	main_menu(Window *win);

#endif /* __MENU_H__ */
