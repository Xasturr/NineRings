#pragma once

#include "strategy.h"

class StrategyAnger1 : public Strategy
{
public:
	StrategyAnger1();
	~StrategyAnger1();

	void decision(Player* player, Character* character, states* states, float elapsedTime);
	int getStrategyParam();
};