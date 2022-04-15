#include "TextureManager.h"
#include "Game.h"

// Load Texture from file and Return Texture
SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tmpSurface = IMG_Load(texture);	// for creating the texture
	SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return text;
}

TTF_Font* TextureManager::LoadFont(const char* fileName, int size) {
	return TTF_OpenFont(fileName, size);
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
	SDL_RenderCopy(Game::renderer, texture, src, dest);
}