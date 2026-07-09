#ifndef GAME_H
#define GAME_H


#include "sdl.h"
#include "input.h"

/* ---------------------------------------------------------------------------------------------------- */

#define GRID_WIDTH		SDL_WINDOW_WIDTH
#define GRID_HEIGHT		SDL_WINDOW_HEIGHT

#define CELL_SIZE		10

#define GRID_ROWS		(GRID_HEIGHT / CELL_SIZE)
#define GRID_COLUMNS	(GRID_WIDTH  / CELL_SIZE)

/* ---------------------------------------------------------------------------------------------------- */

enum // game states
{
	PAUSED,
	RUNNING
};

struct grid
{
	int cells[GRID_ROWS][GRID_COLUMNS];
};

struct game
{
	struct grid grid[2];
	struct grid *grid_curr;
	struct grid *grid_next;

	int state;
};

/* ---------------------------------------------------------------------------------------------------- */

void simulation_step(struct game *game);


#endif // GAME_H
