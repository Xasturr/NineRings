#pragma once

#include "strategy.h"

class StrategyAnger2 : public Strategy
{
public:
	StrategyAnger2();
	~StrategyAnger2();

	void decision(Player* player, Character* character, states* states, float elapsedTime);
	int getStrategyParam();
};