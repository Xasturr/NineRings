#pragma once

#include "player.h"
#include "states.h"

class Strategy
{
public:
	virtual ~Strategy() {}

	virtual void decision(Player* player, Character* character, states* states, float elapsedTime) = 0;
};