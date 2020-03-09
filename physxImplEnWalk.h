#pragma once

#include "physxImplement.h"

class PhysxImplEnWalk : public PhysxImplement
{
	float stayingTime_;
	float runningTime_;

	void updateDecisionTime(float elapsedTime);

public:
	PhysxImplEnWalk(int charName);
	~PhysxImplEnWalk();

	void interactionWithMap(Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime);
	void updatePosition(Character* character, float elapsedTime);
	void decision(Player* player, Character* character, float elapsedTime);
	void setStrategy(int param, int character);
};