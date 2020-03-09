#pragma once

#include "physxImplement.h"

class PhysxImplEnFly : public PhysxImplement
{
	int minPosX_;
	int maxPosX_;

public:
	PhysxImplEnFly(int minPosX, int maxPosX, int charName);
	~PhysxImplEnFly();

	void interactionWithMap(Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime);
	void updatePosition(Character* character, float elapsedTime);
	void decision(Player* player, Character* character, float elapsedTime);
	void setStrategy(int param, int charName);
};