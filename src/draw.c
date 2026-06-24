#include <SDL2/SDL.h>

#include "draw.h"

/* ---------------------------------------------------------------------------------------------------- */

static void draw_cells(struct SDL *sdl, struct grid *grid);
static void draw_grid(struct SDL *sdl);

/* ---------------------------------------------------------------------------------------------------- */

void draw(struct SDL *sdl, struct game *game)
{
	draw_cells(sdl, game->grid_curr);
	draw_grid(sdl);
}

/* ---------------------------------------------------------------------------------------------------- */

static void draw_cells(struct SDL *sdl, struct grid *grid)
{
	int row, col;
	SDL_Rect rect;

	rect.w = CELL_SIZE;
	rect.h = CELL_SIZE;

	SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	for (row = 0; row < GRID_ROWS; ++row)
	{
		rect.y = row * CELL_SIZE;

		for (col = 0; col < GRID_COLUMNS; ++col)
		{
			if (grid->cells[row][col])
			{
				rect.x = col * CELL_SIZE;

				SDL_RenderFillRect(sdl->renderer, &rect);
			}
		}
	}
}

static void draw_grid(struct SDL *sdl)
{
	int i;

	SDL_SetRenderDrawColor(sdl->renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);

	for (i = 1; i < GRID_ROWS; ++i)
	{
		SDL_RenderDrawLine(sdl->renderer, 0, i * CELL_SIZE, GRID_WIDTH - 1, i * CELL_SIZE);
	}

	for (i = 1; i < GRID_COLUMNS; ++i)
	{
		SDL_RenderDrawLine(sdl->renderer, i * CELL_SIZE, 0, i * CELL_SIZE, GRID_HEIGHT - 1);
	}
}
