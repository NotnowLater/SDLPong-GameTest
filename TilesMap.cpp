#include "TilesMap.h"
#include "TextureManager.h"
#include "Game.h"
#include <fstream>

TilesMap::TilesMap(std::string path) {
	bg = TextureManager::LoadTexture("Assets/bg.png");
	white = TextureManager::LoadTexture("Assets/white.png");

	LoadMap(path);

	src.x = src.y = 0;
	src.w = dest.w = 16;
	src.h = dest.h = 16;

	dest.x = dest.y = 0;
}
TilesMap::~TilesMap() {
	SDL_DestroyTexture(bg);
	SDL_DestroyTexture(white);
}
void TilesMap::LoadMap(std::string path) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	for (int row = 0; row < 45; row++) {
		for (int col = 0; col < 80; col++) {
			mapFile.get(tile);
			map[row][col] = tile - '0';
			mapFile.ignore();
		}
		mapFile.ignore();
	}
	mapFile.close();
}
void TilesMap::DrawMap() {
	int type = 0;
	for (int row = 0; row < 45; row++) {
		for (int col = 0; col < 80; col++) {

			type = map[row][col];
			dest.x = col * 16;
			dest.y = row * 16;
			switch (type)
			{
			case 0:
				TextureManager::DrawTexture(bg, &src, &dest);
				break;
			case 1:
				TextureManager::DrawTexture(white, &src, &dest);
				break;
			default:
				break;
			}
		}
	}
}