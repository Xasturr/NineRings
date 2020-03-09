#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"
#include "character.h"
#include "states.h"
#include "player.h"
#include "strategyAnger1.h"
#include "strategyAnger2.h"
#include "strategyPeace1.h"
#include "strategyParams.h"
#include "strategyTypes.h"
#include "Characters.h"

using namespace std;

//bridge
class PhysxImplement
{
protected:
	Strategy* strategy_;
	states states_;

public:
	//states states_;

	virtual ~PhysxImplement() {};

	virtual void interactionWithMap(Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime) = 0;
	virtual void updatePosition(Character* character, float elapsedTime) = 0;
	virtual void decision(Player* player, Character* character, float elapsedTime) = 0;
	virtual void setStrategy(int param, int charName) = 0;

	static Strategy* makeStrategy(int param, int character);
};