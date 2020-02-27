#pragma once

#include "treasureCoin.h"

#include <map>
#include <vector>

class TreasureFactory
{
	map<pair<int, int>, Treasure*> treasures_;

	string currentTreasureName;
public:
	TreasureFactory();
	~TreasureFactory();

	Treasure* getTreasure(Vector2f position, int tileWith, int tileHeight);

	void setTreasureName(string treasureName);
};