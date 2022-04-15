#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component {
private:
	TransformComponenet* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:
	SpriteComponent() = default;
	SpriteComponent(const char* texturePath) {
		SetTexture(texturePath);
	}
	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}
	void SetTexture(const char* texturePath) {
		texture = TextureManager::LoadTexture(texturePath);
	}
	void SetSize(int width, int height) {
		destRect.w = width;
		destRect.h = height;
	}
	void Init() override {
		transform = &entity->GetComponent<TransformComponenet>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}
	void Update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void Draw() override {
		TextureManager::DrawTexture(texture, &srcRect, &destRect);
		
	}
};