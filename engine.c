#include "engine.h"
#include "game.h"
#include "cell_type.h"
#include "special_cell.h"

#include <time.h>


int		engine_need_update(int fps) {
	static unsigned int	start_ticks = 0, ticks;

	ticks = SDL_GetTicks();

	if (ticks - start_ticks < 1000 / fps)
		return 0;

	start_ticks = ticks;
	return 1;
}

void	engine_move_tile(map_t *map) {
	int				x, y;
	unsigned int	current_cell, below_cell, current_cell_color;

	for (x = 0; x < map->ncell_width; ++x)
		for (y = 0; y < map->ncell_height; ++y)
			map->arr_bool[x][y] = COLOR_BLACK;

	for (x = 0; x < map->ncell_width; ++x) {
		for (y = 0; y < map->ncell_height; ++y) {
			below_cell = map_get_cell(*map,x, y + 1);
			current_cell = map->arr_bool[x][y];
			current_cell_color	= map_get_cell(*map, x, y);

			if (current_cell == 0 && below_cell == 0 
				&& y < (map->ncell_height - 1) * map->cell_height) {
				
				map_del_cell(map, x, y);
				map_add_cell(map, x, y + 1, current_cell_color);

				map->arr_bool[x][y + 1] = 1;
				map->arr_bool[x][y] = 0;
			}

			if (map_get_cell(*map, x, 0) != COLOR_BLACK && map_get_cell(*map, x, 1) != COLOR_BLACK && map_get_cell(*map, x, 2) != COLOR_BLACK)
				_game_over = 1;
		}
	}
}

void	engine_add_cell_rand(map_t *map) {
	int			 x,
				 chance_special_cell;
	unsigned int color;

	x = rand() % map->ncell_width;

	color = rand() % 5;

	switch (color) {
	case 1:
		color = COLOR_BLUE;
		break;
	case 2:
		color = COLOR_RED;
		break;
	case 3:
		color = COLOR_GREEN;
		break;
	case 4:
		color = COLOR_PUPRLE;
		break;
	default:
		color = COLOR_BLACK;
	}

	if (map->cell_type.cell_white) {
		chance_special_cell = rand() % 400;
		if (chance_special_cell == 200)
			color = COLOR_WHITE;
	}
	else if (map->cell_type.cell_darkblue) {
		chance_special_cell = rand() % 2706;
		if (chance_special_cell == 1998)
			color = COLOR_DARKGREY;
	}
	if (map->cell_type.cell_lightblue) {
		chance_special_cell = rand() % 800;
		if (chance_special_cell == 400)
			color = COLOR_LIGHTBLUE;
	}	
	if (map->cell_type.cell_lightred) {
		chance_special_cell = rand() % 1000;
		if (chance_special_cell == 500)
			color = COLOR_LIGHTRED;
	}
	if (map->cell_type.cell_lightgreen) {
		chance_special_cell = rand() % 600;
		if (chance_special_cell == 300)
			color = COLOR_LIGHTGREEN;
	}
	map_add_cell(map, x, 0, color);
}

void	engine_add_cell(map_t *map, int delay) {
	static unsigned char new_cell_delay = 0;

	if (++new_cell_delay > (unsigned char)delay) {
		engine_add_cell_rand(map);
		new_cell_delay = 0;
	}
}

void	blast_cell_mouse(map_t *map, int mouse_x, int mouse_y) {
	int hit_cell_row, hit_cell_col;

	hit_cell_row = mouse_x / map->cell_width;
	hit_cell_col = mouse_y / map->cell_height;

	if (hit_cell_col > map->ncell_height)
		hit_cell_col = map->ncell_height;
	if (hit_cell_row > map->ncell_width)
		hit_cell_row = map->ncell_width;

	init_blast_cell(map, hit_cell_row, hit_cell_col);
}

void	init_blast_cell(map_t *map, int row, int col) {
	unsigned int color = map_get_cell(*map, row, col);

	if (color == COLOR_WHITE)
		special_cell_white(map, row, col);

	else if (color == COLOR_DARKGREY)
		special_cell_darkgrey(map, row, col);

	else if (color == COLOR_LIGHTGREEN)
		special_cell_green(map, row, col);

	else if (color == COLOR_LIGHTRED)
		special_cell_red(map, row, col);

	else if (color == COLOR_LIGHTBLUE)
		special_cell_blue(map, row, col);

	else if (color != COLOR_BLACK) {
		if (row > 0 && map_get_cell(*map, row - 1, col) == color
			|| col > 0 && map_get_cell(*map, row, col - 1) == color
			|| row < map->ncell_width - 1 && map_get_cell(*map, row + 1, col) == color
			|| col < map->ncell_height - 1 && map_get_cell(*map, row, col + 1) == color) {
			map_del_cell(map, row, col);
			rec_cell_blast(map, row, col, color);
		}
		else {
			for (int i = 0; i < map->ncell_height; ++i) {
				engine_add_cell_rand(map);
			}
		}
	}
	else {
		for (int i = 0; i < map->ncell_height; ++i)
			engine_add_cell_rand(map);
	}
}

void	blast_cell(map_t *map, int row, int col) {
	unsigned int color = map_get_cell(*map, row, col);

	if (color != COLOR_BLACK) {
		map_del_cell(map, row, col);
		rec_cell_blast(map, row, col, color);
	}
}

void	rec_cell_blast(map_t *map, int row, int col, unsigned int color) {
	if (row > 0 && map_get_cell(*map, row - 1, col) == color)
		blast_cell(map, row - 1, col);

	if (col > 0 && map_get_cell(*map, row, col - 1) == color)
		blast_cell(map, row, col - 1);

	if (row < map->ncell_width-1 && map_get_cell(*map, row + 1, col) == color)
		blast_cell(map, row + 1, col);

	if (col < map->ncell_height-1 && map_get_cell(*map, row, col + 1) == color)
		blast_cell(map, row, col + 1);
}
