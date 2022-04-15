#pragma once
#include "Game.h"
class TilesMap {
public:
	TilesMap(std::string path);
	~TilesMap();

	void LoadMap(std::string path);
	void DrawMap();
private:
	SDL_Rect src, dest;

	SDL_Texture* bg;
	SDL_Texture* white;

	int map[45][80];
};
