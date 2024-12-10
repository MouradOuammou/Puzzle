#include "save.h"
#include "comp.h"

#include <stdio.h>
#include <stdlib.h>

static FILE	*_file = NULL;
static FILE *_file_shop = NULL;

static void create_files(void) {
	int err = 0;

	if (!_file) {
		_file = fopen("res/save/save.px", "w");
		fprintf(_file, "0.0 0.0 0.0");
		err = 1;
	}
	if (!_file_shop) {
		_file_shop = fopen("res/save/shop.px", "w");
		fprintf(_file_shop, "0 0 0 0 0 0 0");
		err = 1;
	}
	if (err == 1) {
		save_close();
		_file = fopen("res/save/save.px", "r+");
		_file_shop = fopen("res/save/shop.px", "r+");
	}
}

void	save_open(void) {
	_file = fopen("res/save/save.px", "r+");
	_file_shop = fopen("res/save/shop.px", "r+");

	create_files();
}

void	save_close(void) {
	fclose(_file);
	fclose(_file_shop);
}

void	save_game_score(double time, unsigned int difficulty) {
	double	diff[3] = { 0 };

	if (_file) {
		rewind(_file);

		fscanf(_file, "%lf", &diff[0]);
		fscanf(_file, "%lf", &diff[1]);
		fscanf(_file, "%lf", &diff[2]);

		rewind(_file);

		if (difficulty == 1 && cmpDoubles(diff[0], time) == 1)
			fprintf(_file, "%lf ", time);
		else
			fprintf(_file, "%lf ", diff[0]);

		if (difficulty == 2 && cmpDoubles(diff[1], time) == 1)
			fprintf(_file, "%lf ", time);
		else
			fprintf(_file, "%lf ", diff[1]);

		if (difficulty == 3 && cmpDoubles(diff[2], time) == 1)
			fprintf(_file, "%lf ", time);
		else
			fprintf(_file, "%lf ", diff[2]);
	}
}

void	save_pixels(int pixels) {
	int		pixels_save;

	rewind(_file_shop);
	
	fscanf(_file_shop, "%d ", &pixels_save);
	rewind(_file_shop);
	fprintf(_file_shop, "%d ", pixels + pixels_save);
}

void	save_get_game_score(double *time) {
	rewind(_file);
	fscanf(_file, "%lf %lf %lf", &time[0], &time[1], &time[2]);
}

void	save_cell_pixels_unlocked(cell_type_t cell_type, int pixels) {
	rewind(_file_shop);

	fprintf(_file_shop, "%d %d %d %d %d %d ", pixels , cell_type.cell_white , cell_type.cell_lightgreen, cell_type.cell_lightblue, cell_type.cell_lightred, cell_type.cell_darkblue);
}

void	save_get_game_cell_unlock(cell_type_t *cell_type) {
	unsigned int	color_is_unlocked;

	rewind(_file_shop);

	fscanf(_file_shop, "%*d");

	fscanf(_file_shop, "%d", &color_is_unlocked);
		cell_type->cell_white = color_is_unlocked;
	fscanf(_file_shop, "%d", &color_is_unlocked);
		cell_type->cell_lightgreen = color_is_unlocked;	
	fscanf(_file_shop, "%d", &color_is_unlocked);
		cell_type->cell_lightblue = color_is_unlocked;
	fscanf(_file_shop, "%d", &color_is_unlocked);
		cell_type->cell_lightred = color_is_unlocked;
	fscanf(_file_shop, "%d", &color_is_unlocked);
		cell_type->cell_darkblue = color_is_unlocked;
}

int save_get_pixels(void) {
	int pixels;

	rewind(_file_shop);

	fscanf(_file_shop, "%d", &pixels);

	return pixels;
}
