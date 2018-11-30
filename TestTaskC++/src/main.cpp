#include "Framework.h"
#include "MyFramework.hpp"

int run(Framework* game)
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;
	int width = 800;
	int heigth = 640;
	bool fullscreen = false;

	game->PreInit(width, heigth, fullscreen);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	game->Close();
	return (0);
}

int main(int argc, char *argv[])
{
	return run(new MyFramework);
}
