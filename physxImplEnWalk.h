#pragma once

#include "physxImplement.h"

class PhysxImplEnWalk : public PhysxImplement
{
	float stayingTime_;
	float runningTime_;

	void updateDecisionTime(states* states, float elapsedTime);

public:
	PhysxImplEnWalk();
	~PhysxImplEnWalk();

	void interactionWithMap(struct states* states, Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime);
	void updatePosition(Character* character, states* states, float elapsedTime);
	void decision(Player* player, Character* character, states* states, float elapsedTime);
};