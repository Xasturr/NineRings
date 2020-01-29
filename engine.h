#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "button.h"
#include "windowStyle.h"
#include "gameWindow.h"

using namespace sf;
using namespace std;

class Engine
{
	RenderWindow window_;

	View view_;

	Vector2i resolution_;

	bool isFullscreen_;

	Event event_;

public:
	Engine();
	~Engine();

	GameWindow* createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath);
	//key - resolution; value - 1) Size; 2) Position

	Button* createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath);
	//key - resolution; value - 1) Size; 2) Position

	void start();
	void update();
	void drawGameWindow(GameWindow* gameWindow);
	void drawButton(Button* button);
	void createRenderWindow(VideoMode videoMode, string title, string windowStyle);
	void renderWindowClear();
	void renderWindowDisplay();
	void closeRenderWindow();
	void changeRenderWindowMode();
	void setGameWindowVisible(GameWindow* gameWindow);
	void setGameWindowInvisible(GameWindow* gameWindow);

	bool renderWindowIsOpen();
	bool renderWindowPollEvent();
	bool isRenderWindowFullscreen();

	string getClickedButtonId(GameWindow* gameWindow);

	Vector2i getResolution();

	Event* getEvent();
};