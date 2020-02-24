#pragma once

#include "physxImplement.h"

class PhysxImplEnFly : public PhysxImplement
{
	int minPosX_;
	int maxPosX_;

public:
	PhysxImplEnFly(int minPosX, int maxPosX);
	~PhysxImplEnFly();

	void interactionWithMap(struct states* states, Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime);
	void updatePosition(Character* character, states* states, float elapsedTime);
	void decision(Player* player, Character* character, states* states, float elapsedTime);
};