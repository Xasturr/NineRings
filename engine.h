#pragma once

#include <map>
#include <math.h>
#include "button.h"
#include "windowStyle.h"
#include "gameWindow.h"
#include "level.h"
#include "player.h"
#include "collision.h"
#include "settings.h"
#include "resolutions.h"
#include "animation.h"

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

	Settings settings_;

	struct resolutions resolutions_;

public:
	Engine();
	~Engine();

	GameWindow* createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath);
	//key - resolution; value - 1) Size; 2) Position

	Button* createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, string mouseClickedTexturePath);
	//key - resolution; value - 1) Size; 2) Position

	Vector2f getPlayerPosition();
	Vector2f getViewCenter();

	Settings* getSettings();

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
	void draw(float elapsedTime);
	void drawText(Text text);
	void drawSprite(Sprite sprite);
	void drawAnimation(Animation* animation, float elapsedTime);
	void setView(int rectLeft, int rectTop, int rectWidth, int rectHeight);

	bool renderWindowIsOpen();
	bool renderWindowPollEvent();
	bool isRenderWindowFullscreen();
	bool mouseContains(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	bool isNewPlayerLevel();

	int input();
	int getCurrPlayerHealthPoints();
	int getCurrPlayerMana();
	int getCurrPlayerStamina();
	int getMaxPlayerHealthPoints();
	int getMaxPlayerMana();
	int getMaxPlayerStamina();
	int getCurrPlayerShellAmount();
	int getCurrPlayerPosX();
	int getCurrPlayerPosY();
	int getDDTimer();
	int getNewPlayerLevel();
	int getPlayerPoints();

	string getClickedButtonId(GameWindow* gameWindow);
	string getCurrPlayerShellName();

	Vector2i getResolution();

	Event* getEvent();

	Player* getPlayer();

	struct resolutions getResolutions();

	//Level* getLevel();
};