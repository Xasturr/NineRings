#pragma once

#include "engine.h"
#include "level1.h"

using namespace sf;
using namespace std;

class Game
{
	Engine engine_;

	Clock clock_;

	int inputValue;

	float elapsedTime_;

public:
	Game();
	~Game();

	void start();
};