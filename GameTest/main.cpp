#include "main.h"


int main(int argc, char **argv)
{
	Game game;
	if (!game.InitGame("Test", 400, 400, 800, 600))
		return -1;
	game.RunGame();
	SDL_Quit();
	return 0;
}

