#pragma once
#include "Game.h"
#include "ECS.h"
#include "TextureManager.h"
#include "Components.h"



class TextComponent : public Component {
private:
	TransformComponenet* transform;
	SDL_Texture* texture;
	SDL_Rect destRect;
	int tmpW, tmpH = 0;
	int fontSize = 0;
	const char* fontPath;
	SDL_Color color = { 255, 255 ,255 ,255 };
public:
	
	TextComponent() = default;
	TextComponent(const char* path, int size, const char * message, int r, int g, int b){
		fontPath = path;
		TTF_Font* font = TTF_OpenFont(fontPath, size);
		SDL_Color tmpColor = { r, g, b };
		color = tmpColor;
		SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_QueryTexture(texture, NULL, NULL, &tmpW, &tmpH);
		destRect.w = tmpW;
		destRect.h = tmpH;
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
	}
	~TextComponent() {
		SDL_DestroyTexture(texture);
	}

	void ChangeText(const char* text, int size) {
		TTF_Font* font = TTF_OpenFont(fontPath, size);
		SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_QueryTexture(texture, NULL, NULL, &tmpW, &tmpH);
		destRect.w = tmpW;
		destRect.h = tmpH;
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
	}

	void Init() override {
		transform = &entity->GetComponent<TransformComponenet>();

	}
	void Update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
	}
	void Draw() override {
		SDL_RenderCopy(Game::renderer, texture, NULL, &destRect);
	}
};