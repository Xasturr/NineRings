#pragma once

#include "strategy.h"

class StrategyPeace1 : public Strategy //for character1
{
public:
	~StrategyPeace1();

	void decision(Player* player, Character* character, states* states, float elapsedTime);
};