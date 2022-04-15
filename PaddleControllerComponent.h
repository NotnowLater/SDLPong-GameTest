#pragma once

#include "Components.h"
#include "ECS.h"
#include "Game.h"

class PaddleControllerComponent : public Component {
private: 
	TransformComponenet* transform;
	int yMin = 21;
	int yMax = 624;
public:
	bool isPlayer1;
	PaddleControllerComponent(bool p1) {
		isPlayer1 = p1;
	}
	void Init() override {
		transform = &entity->GetComponent<TransformComponenet>();
		transform->speed = 10;
	}
	void Update() override {
		if (Game::event.type == SDL_KEYUP || (transform->position.y <= yMin || transform->position.y >= yMax)) {
			if (isPlayer1) {
				if (Game::event.key.keysym.sym == SDLK_w || transform->position.y <= yMin) {
					transform->velocity.y = 0;
				}
				if (Game::event.key.keysym.sym == SDLK_s || transform->position.y >= yMax) {
					transform->velocity.y = 0;
				}
			}
			else {
				if (Game::event.key.keysym.sym == SDLK_UP || transform->position.y <= yMin) {
					transform->velocity.y = 0;
				}
				if (Game::event.key.keysym.sym == SDLK_DOWN || transform->position.y >= yMax) {
					transform->velocity.y = 0;
				}
			}
		}
		if (Game::event.type == SDL_KEYDOWN) {
			if (isPlayer1) {
				if (transform->position.y > yMin) {
					if (Game::event.key.keysym.sym == SDLK_w) {
						transform->velocity.y = -1;
					}
				}
				if (transform->position.y < yMax) {
					if (Game::event.key.keysym.sym == SDLK_s) {
						transform->velocity.y = 1;
					}
				}
			}
			else {
				if (transform->position.y > yMin) {
					if (Game::event.key.keysym.sym == SDLK_UP) {
						transform->velocity.y = -1;
					}
				}if (transform->position.y < yMax) {
					if (Game::event.key.keysym.sym == SDLK_DOWN) {
						transform->velocity.y = 1;
					}
				}
			}
		}
	}
};