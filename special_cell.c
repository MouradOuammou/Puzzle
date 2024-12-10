#include "special_cell.h"

void	special_cell_red(map_t *map, int row, int col) {
	int color_to_exlose = rand() % 4;
	
	map_add_cell(map, row, col, COLOR_BLACK);

	switch (color_to_exlose) {
	case 0:
		color_to_exlose = COLOR_RED;
		break;
	case 1:
		color_to_exlose = COLOR_GREEN;
		break;
	case 2:
		color_to_exlose = COLOR_BLUE;
		break;
	case 3:
		color_to_exlose = COLOR_PUPRLE;
		break;
	default:
		;
	}
	for (int x = 0; x < map->ncell_width; ++x) {
		for (int y = 0; y < map->ncell_height; ++y) {
			if (map_get_cell(*map, x, y) == color_to_exlose) {
				map_del_cell(map, x, y);
			}
		}
	}
}

void	special_cell_blue(map_t *map, int row, int col) {
	int	is_left;
	int	start_row;
	int middle_screen = (map->ncell_width >> 1);

	map_add_cell(map, row, col, COLOR_BLACK);

	if (row < middle_screen) {
		is_left = 1;
		start_row = 0;
	}
	else {
		is_left = 0;
		start_row = middle_screen;
	}
	for (int x = start_row; (is_left) ? (x < middle_screen) : (x < map->ncell_width); ++x) {
		for (int y = 0; y < map->ncell_height; ++y) {
			map_del_cell(map, x, y);
		}
	}
}

void	special_cell_green(map_t *map, int row, int col) {
	map_add_cell(map, row, col, COLOR_BLACK);

	for (int x = row - 4; x < row + 4; ++x) {
		for (int y = col - 4; y < col + 4; ++y) {
			if (x >= 0 && y >= 0 && x < map->ncell_width && y < map->ncell_height)
				map_del_cell(map, x, y);
		}
	}
}

void	special_cell_white(map_t *map, int row, int col) {
	map_add_cell(map, row, col, COLOR_BLACK);

	for (int x = 0; x < map->ncell_width; ++x)
		for (int y = col; y < col + 5 && y < map->ncell_height; ++y)
			map_del_cell(map, x, y);
}

void	special_cell_darkgrey(map_t *map, int row, int col) {
	map_add_cell(map, row, col, COLOR_BLACK);

	for (int x = 0; x < map->ncell_width; ++x)
		for (int y = 0; y < map->ncell_height; ++y)
			map_del_cell(map, x, y);
}
