#include "map.h"
#include "window.h"
#include "save.h"
#include "memory.h"

#include <stdlib.h>

void	map_init(map_t *map, Window	 *win) {
	int x, y;

	map->cell_height = (int)win->height / map->ncell_height;
	map->cell_width = (int)win->height / map->ncell_width;

	map->arr = xmalloc(map->ncell_height * sizeof(unsigned int));
	map->arr_bool = xmalloc(map->ncell_height * sizeof(unsigned int));

	for (x = 0; x < map->ncell_height; ++x) {
		map->arr[x] = xmalloc(map->ncell_width * sizeof(unsigned int *));
		map->arr_bool[x] = xmalloc(map->ncell_width * sizeof(unsigned int *));
	}

	for (x = 0; x < map->ncell_width; ++x) {
		for (y = 0; y < map->ncell_height; ++y) {
			map->arr[x][y] = COLOR_BLACK;
			map->arr_bool[x][y] = 0;
		}
	}

	save_get_game_cell_unlock(&map->cell_type);
	
	map->surface = SDL_CreateRGBSurface(SDL_HWSURFACE, map->cell_width, map->cell_height, 32, 0, 0, 0, 0);
}

void	map_free(map_t *map) {
	for (int i = 0; i < map->ncell_height; ++i) {
		xfree(map->arr[i]);
		xfree(map->arr_bool[i]);
	}

	xfree(map->arr);
	xfree(map->arr_bool);

	SDL_FreeSurface(map->surface);
}

void	map_fill(map_t *map) {
	for (int x = 0; x < map->ncell_width; ++x)
		for (int y = 0; y < map->ncell_height; ++y)
			if (map->arr[x][y] != COLOR_BLACK)
				map->arr[x][y] = COLOR_BLACK;
}

void	map_add_cell(map_t *map, int x, int y, unsigned int color) {
	map->arr[x][y] = color;
}

void	map_del_cell(map_t *map, int x, int y) {
	map->arr[x][y] = COLOR_BLACK;
}

void	map_blit(map_t map, Window *win) {
	SDL_Rect	rect;

	for (int x = 0; x < map.ncell_width; ++x) {
		for (int y = 0; y < map.ncell_height; ++y) {

			rect.x = x * map.cell_width;
			rect.y = y * map.cell_height;

			SDL_FillRect(map.surface, NULL, map_get_cell(map, x, y));

			SDL_BlitSurface(map.surface, NULL, win->screen, &rect);
		}
	}
}

unsigned int	map_cell_is_empty(map_t map, int x, int y) {
	return map.arr[x][y] != COLOR_BLACK;
}

unsigned int	map_get_cell(map_t map, int x, int y) {
	return map.arr[x][y];
}
