#pragma once

#include "Game.h"
#include "Components.h"


class BallComponent : public Component {
private:
	TransformComponenet *transform;
	int minX = -16;
	int maxX = 1296;
	int minY = 16;
	int maxY = 688;
public:
	void ResetBall() {
		transform->speed = 0;
		transform->position = Vector2D(632, 352);
		GetBallDirection();
		transform->speed = 5;
	}
	void Init() override {
		transform = &entity->GetComponent<TransformComponenet>();
		transform->speed = 0;
		GetBallDirection();
		ResetBall();
	}
	void Update() override {
		if (transform->position.y < minY) {
			transform->velocity.y = 1;
		}
		else if (transform->position.y > maxY) {
			transform->velocity.y = -1;
		}
	}
	void GetBallDirection() {
		if (Random::Rng(1, 100) % 2 == 0) {
			transform->velocity.x = 1;
		}else 
			transform->velocity.x = -1;
		if (Random::Rng(1, 100) % 2 == 0) {
			transform->velocity.y = 1;
		}
		else
			transform->velocity.y = -1;
	}
};