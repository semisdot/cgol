#include "logic.h"
#include "init.h"

/* ---------------------------------------------------------------------------------------------------- */

static void mouse_to_grid(struct events *events, int *row, int *col);
static void grid_set_cell(struct grid *grid_curr, int row, int col);

/* ---------------------------------------------------------------------------------------------------- */

void logic(struct events *events, struct game *game)
{
	switch (game->state)
	{
		case PAUSED:
			if (events->keyboard.keys[SDL_SCANCODE_SPACE])
			{
				update_game_state(events, game, RUNNING);
				return;
			}
			else if (events->keyboard.keys[SDL_SCANCODE_RETURN])
			{
				update_game_state(events, game, NEW);
				return;
			}

			if (events->mouse.buttons[SDL_BUTTON_LEFT])
			{
				int row, col;

				mouse_to_grid(events, &row, &col);
				grid_set_cell(game->grid_curr, row, col);

				// clear event
				events->mouse.buttons[SDL_BUTTON_LEFT] = 0;
			}

			break;

		case RUNNING:
		{
			static uint32_t last_update = 0;
            uint32_t now = SDL_GetTicks();

			if (events->keyboard.keys[SDL_SCANCODE_SPACE])
			{
				update_game_state(events, game, PAUSED);
				return;
			}

            if (now - last_update >= 100)  // 100 ms = 10 updates/sec
            {
                simulation_step(game);
                last_update = now;
            }

			break;
		}

		case NEW:
			init_game(game);

			update_game_state(events, game, PAUSED);
			break;
	}
}

/* ---------------------------------------------------------------------------------------------------- */

static void mouse_to_grid(struct events *events, int *row, int *col)
{
	// grid size == window size
	*row = events->mouse.y / CELL_SIZE;
	*col = events->mouse.x / CELL_SIZE;
}

static void grid_set_cell(struct grid *grid_curr, int row, int col)
{
	grid_curr->cells[row][col] = !grid_curr->cells[row][col];
}
