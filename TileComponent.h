#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component {
public:
	TransformComponenet* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileId;
	const char* textPath;

	TileComponent() = default;
	TileComponent(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileId = id;

		switch (tileId)
		{
		case 0:
			textPath = "Assets/bg.png";
			break;
		case 1:
			textPath = "Assets/white.png";
			break;
		default:
			break;
		}
	}

	void Init() override {
		entity->AddComponent<TransformComponenet>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->GetComponent<TransformComponenet>();
		entity->AddComponent<SpriteComponent>(textPath);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};