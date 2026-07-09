#include <SDL2/SDL.h>
#include <time.h>

#include "sdl.h"
#include "input.h"
#include "logic.h"
#include "draw.h"
#include "init.h"
#include "game.h"

/* ---------------------------------------------------------------------------------------------------- */

#define FPS 30

/* ---------------------------------------------------------------------------------------------------- */

int main(void)
{
	struct SDL sdl;
	struct events events;
	struct game game;

	srand(time(NULL));

	init_sdl(&sdl);
	init_game(&game);

	update_game_state(&events, &game, PAUSED);

	while (1)
	{
		SDL_SetRenderDrawColor(sdl.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(sdl.renderer);

		input(&events);
		logic(&events, &game);
		draw(&sdl, &game);

		SDL_RenderPresent(sdl.renderer);
		SDL_Delay(1000 / FPS);
	}

	return 0;
}
