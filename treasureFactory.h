#pragma once

#include "treasureCoin.h"

#include <map>
#include <vector>

class TreasureFactory
{
	map<string, Treasure*> treasures_;

	string currentTreasureName;

	Treasure* treasureCoin_ = nullptr;
public:
	TreasureFactory();
	~TreasureFactory();

	Treasure* getTreasure();

	void setTreasureName(string treasureName);
};