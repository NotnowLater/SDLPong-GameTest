#pragma once
#include "SDL.h"

class ColliderComponent;

class Collision {
public:
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);	//Axis Aligned Bounding Box
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);

};