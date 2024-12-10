#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL\SDL.h>

typedef struct timer_s {
	double		time;
	char		time_char[16];
	SDL_Surface *time_print;
	SDL_Rect	rect;
	SDL_Color	color;
}	Timer;

#endif /* __TIMER_H__ */