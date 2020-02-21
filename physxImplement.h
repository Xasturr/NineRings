#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"
#include "character.h"
#include "states.h"
#include "player.h"

using namespace std;

//bridge
class PhysxImplement
{
public:
	virtual ~PhysxImplement() {};

	virtual void interactionWithMap(struct states* states, Character* character, Vector2f oldEnemyPosition, Map* map, float elapsedTime) = 0;
	virtual void updatePosition(Character* character, states* states, float elapsedTime) = 0;
	virtual void decision(Player* player, Character* character, states* states, float elapsedTime) = 0;
};