#pragma once

#include "engine.h"
#include "level1.h"
#include "level2.h"

using namespace sf;
using namespace std;

class Game
{
	Engine engine_;

	Clock clock_;

	Font bebasRegular_;

	int inputValue;

	float elapsedTime_;
	float clickTime_;

	bool showInfo_;

	Text textFPS_;
	Text textHP_;
	Text textMana_;
	Text textStamina_;
	Text textShellsAmount_;
	Text textPosX_;
	Text textPosY_;
	Text textPlay, textSettings, textExit;
	Text textDDTimer_;
	
	//chooseLevelMenu
	Text textLevel1_;
	Text textLevel2_;
	Text textBack_;

	Texture textureMainMenu_;

	Sprite spriteMainMenu_;

	void mainMenu();
	void play(Level* level);
	void chooseLevelMenu();

public:
	Game();
	~Game();

	void start();
};