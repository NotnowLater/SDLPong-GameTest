#pragma once

#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static TTF_Font* LoadFont(const char* fileName, int size);
	static void DrawTexture(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);
};
