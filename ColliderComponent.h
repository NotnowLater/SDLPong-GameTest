#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;
	
	TransformComponenet* transform;

	ColliderComponent(std::string t) {
		tag = t;
	}

	void Init() override{
		if (!entity->HasComponent<TransformComponenet>()) {
			entity->AddComponent<TransformComponenet>();
		}
		transform = &entity->GetComponent<TransformComponenet>();
		 
		Game::colliders.push_back(this);
	}
	void Update() override{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

};