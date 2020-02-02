#pragma once

#include "engine.h"
#include "level1.h"

using namespace sf;
using namespace std;

class Game
{
	Engine engine_;

	int inputValue;

public:
	Game();
	~Game();

	void start();
};