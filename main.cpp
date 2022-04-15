#include "SDL.h"
#include "Game.h"

Game* game = NULL;

const int SCREENWIDTH = 1280;
const int SCREENHEIGHT = 720;

int main(int argc, char* argv[]) {

	game = new Game();
	std::srand((unsigned)time(0));	// init the random number generator

	//init the game
	game->Init("SDLGameTest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, false);
	
	// main game loop
	while (game->Running())
	{
		game->HandleEvent();
		game->Update();
		game->Render();
	}
	game->Clean();
	return 0;
}