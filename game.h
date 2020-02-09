#pragma once

#include "engine.h"
#include "level1.h"

using namespace sf;
using namespace std;

class Game
{
	Engine engine_;

	Clock clock_;

	Font bebasRegular_;

	int inputValue;

	float elapsedTime_;

	bool showInfo_;

	Text textFPS_;
	Text textHP_;
	Text textMana_;
	Text textStamina_;
	Text textShellsAmount_;
	Text textPosX_;
	Text textPosY_;

public:
	Game();
	~Game();

	void start();
};