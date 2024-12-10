#ifndef __MAP_H__
#define __MAP_H__

#include "window.h"
#include "cell_type.h"

#define COLOR_BLACK		0x000000
#define COLOR_RED		0xFF0000
#define COLOR_GREEN		0x5FB404
#define COLOR_BLUE		0x2E64FE
#define COLOR_PUPRLE	0xB404AE

#define COLOR_WHITE			0xFFFFFF
#define COLOR_DARKGREY		0x0B173B
#define COLOR_LIGHTGREEN	0xA5DF00
#define COLOR_LIGHTBLUE		0x8292FF
#define COLOR_LIGHTRED		0xFF7863

typedef struct map_s {
	unsigned int	**arr;
	unsigned int	**arr_bool;
	unsigned int	pixels;
	int				cell_height;
	int				cell_width;
	int				ncell_width;
	int				ncell_height;
	cell_type_t		cell_type;
	SDL_Surface		*surface;
}map_t;

void	map_init(map_t *map, Window *win);
void	map_free(map_t *map);

void	map_fill(map_t *map);

void	map_add_cell(map_t *map, int x, int y, unsigned int color);
void	map_del_cell(map_t *map, int x, int y);

void	map_blit(map_t map, Window *win);

unsigned int	map_cell_is_empty(map_t map, int x, int y);
unsigned int	map_get_cell(map_t map, int x, int y);

#endif /* __MAP_H__ */
