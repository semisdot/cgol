#include "game.h"

/* ---------------------------------------------------------------------------------------------------- */

static int count_neighbours(struct grid *grid, int row, int col);
static void apply_rules(struct grid *grid_curr, struct grid *grid_next, int row, int col, int neighbours);
static void update_game_grid(struct game *game);

/* ---------------------------------------------------------------------------------------------------- */

void simulation_step(struct game *game)
{
	int neighbours;
	int i, j;

	for (i = 0; i < GRID_ROWS; ++i)
	{
		for (j = 0; j < GRID_COLUMNS; ++j)
		{
			neighbours = count_neighbours(game->grid_curr, i, j);

			apply_rules(game->grid_curr, game->grid_next, i, j, neighbours);
		}
	}

	update_game_grid(game);
}

/* ---------------------------------------------------------------------------------------------------- */

static int count_neighbours(struct grid *grid, int row, int col)
{
	int neighbours = 0;

	if (row > 0)
	{
		// above neighbour
		neighbours += grid->cells[row - 1][col];
	}

	if (row < GRID_ROWS - 1)
	{
		// below neighbour
		neighbours += grid->cells[row + 1][col];
	}

	if (col > 0)
	{
		// left neighbour
		neighbours += grid->cells[row][col - 1];
	}

	if (col < GRID_COLUMNS - 1)
	{
		// right neighbour
		neighbours += grid->cells[row][col + 1];
	}

	if (row > 0 && col > 0)
	{
		// above left neighbour
		neighbours += grid->cells[row - 1][col - 1];
	}

	if (row > 0 && col < GRID_COLUMNS - 1)
	{
		// above right neighbour
		neighbours += grid->cells[row - 1][col + 1];
	}

	if (row < GRID_ROWS - 1 && col > 0)
	{
		// below left neighbour
		neighbours += grid->cells[row + 1][col - 1];
	}

	if (row < GRID_ROWS - 1 && col < GRID_COLUMNS - 1)
	{
		// below right neighbour
		neighbours += grid->cells[row + 1][col + 1];
	}

	return neighbours;
}

static void apply_rules(struct grid *grid_curr, struct grid *grid_next, int row, int col, int neighbours)
{
	// rule 1
	if (neighbours < 2)
	{
		grid_next->cells[row][col] = 0;
	}
	// rule 2
	else if (grid_curr->cells[row][col] == 1 && (neighbours == 2 || neighbours == 3))
	{
		grid_next->cells[row][col] = 1;
	}
	// rule 3
	else if (grid_curr->cells[row][col] == 1 && neighbours > 3)
	{
		grid_next->cells[row][col] = 0;
	}
	// rule 4
	else if (grid_curr->cells[row][col] == 0 && neighbours == 3)
	{
		grid_next->cells[row][col] = 1;
	}
	// no change
	else
	{
		grid_next->cells[row][col] = grid_curr->cells[row][col];
	}
}

static void update_game_grid(struct game *game)
{
	struct grid *grid_temp;

	grid_temp       = game->grid_curr;
	game->grid_curr = game->grid_next;
	game->grid_next = grid_temp;
}
