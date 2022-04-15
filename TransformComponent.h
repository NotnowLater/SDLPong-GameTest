#pragma once
#include "ECS.h"
#include "Vector2D.h"
class TransformComponenet : public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int height = 16;
	int width = 16;
	int scale = 1;

	int speed = 0;

	TransformComponenet() {
		position.Zero();
	}
	TransformComponenet(float x, float y) {
		position.x = x;
		position.y = y;
	}
	TransformComponenet(float x, float y, int w, int h, float s) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = s;
	}
	void Init() override {
		velocity.Zero();
	}
	void Update() {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
	
};