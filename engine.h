#pragma once

#include <map>
#include <math.h>
#include "button.h"
#include "windowStyle.h"
#include "gameWindow.h"
#include "level.h"
#include "player.h"
#include "collision.h"

using namespace sf;
using namespace std;

class Engine
{
	RenderWindow window_;

	View view_;

	Vector2i resolution_;

	bool isFullscreen_;

	Event event_;

	Level* level_;

	int viewSizeX_;
	int viewSizeY_;

	Player* player_;

	void interactionWithMap(Vector2f oldPlayerPosition, Vector2f newPlayerPosition, float elapsedTime);
	void calculateVariables(float elapsedTime);

public:
	Engine();
	~Engine();

	GameWindow* createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath);
	//key - resolution; value - 1) Size; 2) Position

	Button* createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, string mouseClickedTexturePath);
	//key - resolution; value - 1) Size; 2) Position

	Vector2f getPlayerPosition();

	void drawGameWindow(GameWindow* gameWindow);
	void drawButton(Button* button);
	void createRenderWindow(VideoMode videoMode, string title, string windowStyle);
	void renderWindowClear();
	void renderWindowDisplay();
	void closeRenderWindow();
	void changeRenderWindowMode();
	void setGameWindowVisible(GameWindow* gameWindow);
	void setGameWindowInvisible(GameWindow* gameWindow);
	//void buildMap();
	void createLevel(Level* level);
	void setPlayer(string charName, float posX, float posY);
	void playerMoveLeft();
	void playerMoveRight();
	void playerMoveUp();
	void playerMoveDown();
	void update(float elapsedTime);
	void draw();
	void drawText(Text text);
	void setView(int sizeX, int sizeY);

	bool renderWindowIsOpen();
	bool renderWindowPollEvent();
	bool isRenderWindowFullscreen();

	int input();

	string getClickedButtonId(GameWindow* gameWindow);

	Vector2i getResolution();

	Event* getEvent();

	//Level* getLevel();
};