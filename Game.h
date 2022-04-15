#ifndef Game_hpp
#define Game_hpp
#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Vector2D.h"
#include "random.h"
#include <iostream>
#include <vector>


class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void HandleEvent();
	void Update();
	void Render();
	void Clean();

	bool Running();

	static void AddTile(int id, int x, int y);

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;
private:
	int frameCounter = 0;
	bool isRunning;
	SDL_Window* window;
};
#endif // !Game_hpp

