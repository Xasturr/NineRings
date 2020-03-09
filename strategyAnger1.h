#pragma once

#include "strategy.h"

class StrategyAnger1 : public Strategy //for character1
{
public:
	~StrategyAnger1();

	void decision(Player* player, Character* character, states* states, float elapsedTime);
};