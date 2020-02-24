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
	bool iPressed_;
	bool tabPressed_;
	bool mouseButtonPressed_;
	//bool showNewLevel_;

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
	Texture textureSettings_;
	Texture texturePerksMenu_;

	Sprite spriteMainMenu_;
	Sprite spriteSettings_;
	Sprite spritePerksMenu_;

	map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap_;

	resolutions resolutions_;

	void mainMenu();
	void play(Level* level);
	void chooseLevelMenu();
	void settings();
	void perksMenu();

public:
	Game();
	~Game();

	void start();
};