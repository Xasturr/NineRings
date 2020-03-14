#pragma once

#include "player.h"
#include "states.h"
#include "strategyParams.h"

class Strategy
{
public:
	virtual ~Strategy() {}

	virtual void decision(Player* player, Character* character, states* states, float elapsedTime) = 0;
	virtual int getStrategyParam() = 0;
};