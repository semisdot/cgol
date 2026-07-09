#include "init.h"

/* ---------------------------------------------------------------------------------------------------- */

static void init_game_grid(struct grid *grid);
static void place_gosper_glider_gun(struct grid *grid);
static void place_random(struct grid *grid);

/* ---------------------------------------------------------------------------------------------------- */

void init_game(struct game *game)
{
	game->grid_curr = &game->grid[0];
	game->grid_next = &game->grid[1];

	init_game_grid(game->grid_curr);
}

/* ---------------------------------------------------------------------------------------------------- */

static void init_game_grid(struct grid *grid)
{
	memset(grid->cells, 0, sizeof(grid->cells));

	place_gosper_glider_gun(grid);
	// place_random(game->grid_curr);
}

static void place_gosper_glider_gun(struct grid *grid)
{
	// Gosper Glider Gun live-cell coordinates as {row, col}
    const int gun[][2] =
	{
		{0, 24},
		{1, 22}, {1, 24},
		{2, 12}, {2, 13}, {2, 20}, {2, 21}, {2, 34}, {2, 35},
		{3, 11}, {3, 15}, {3, 20}, {3, 21}, {3, 34}, {3, 35},
		{4, 0},  {4, 1},  {4, 10}, {4, 16}, {4, 20}, {4, 21},
		{5, 0},  {5, 1},  {5, 10}, {5, 14}, {5, 16}, {5, 17},
		{5, 22}, {5, 24},
		{6, 10}, {6, 16}, {6, 24},
		{7, 11}, {7, 15},
		{8, 12}, {8, 13}
    };

    const int count = sizeof(gun) / sizeof(gun[0]);
	int row, col;
	int i;

    for (i = 0; i < count; ++i)
    {
        row = gun[i][0];
        col = gun[i][1];

        grid->cells[row][col] = 1;
    }
}

static void place_random(struct grid *grid)
{
	int i, j;

	for (i = 0; i < GRID_ROWS; ++i)
	{
		for (j = 0; j < GRID_COLUMNS; ++j)
		{
			grid->cells[i][j] = rand() % 2;
		}
	}
}
