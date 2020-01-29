#pragma once

#include "engine.h"

using namespace sf;
using namespace std;

class Game
{
	Engine engine_;

public:
	Game();
	~Game();

	void start();
};