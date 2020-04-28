#pragma once

#include "player.h"
#include "level1.h"
#include "level2.h"

#include <iostream>
#include <fstream>
#include <istream>

class SaveLoad
{
	ifstream ifs;
	ofstream ofs;

	bool checkSavePosition(Player* player);
public:
	void save(Level* level, Player* player);
	void load(Level** level, Player** player);
	void loadNewGame(Level** level, Player** player);
};