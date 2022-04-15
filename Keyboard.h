#pragma once

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyBoardController : public Component {
public:
	TransformComponenet* transform;
	bool isPlayer2 = false;
	void Init() override{
		transform = &entity->GetComponent<TransformComponenet>();
	}

	
};