#pragma once

#include <map>
#include <math.h>
#include <SFML/Audio/Music.hpp>
#include "button.h"
#include "windowStyle.h"
#include "gameWindow.h"
#include "level.h"
#include "player.h"
#include "settings.h"
#include "resolutions.h"
#include "animation.h"
#include "saveLoad.h"

using namespace sf;
using namespace std;

class Engine
{
	RenderWindow window_;

	View view_;

	Vector2i resolution_;
	Vector2i viewSize_;

	bool isFullscreen_;

	Event event_;

	Level* level_;

	int viewSizeX_;
	int viewSizeY_;

	Player* player_;

	Settings settings_;

	SaveLoad saveLoad_;

	struct resolutions resolutions_;

	static Engine* engineInstance_;

protected:
	Engine();

public:
	~Engine();

	static Engine* getEngineInstance();

	GameWindow* createGameWindow(map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string texturePath);
	//key - resolution; value - 1) Size; 2) Position

	Button* createButton(string id, map<pair<size_t, size_t>, pair<pair<size_t, size_t>, pair<size_t, size_t>>> sizePosMap, string mouseContainsTexturePath, string mouseNotContainsTexturePath, string mouseClickedTexturePath);
	//key - resolution; value - 1) Size; 2) Position

	Vector2f getPlayerPosition();
	Vector2f getViewCenter();

	Settings* getSettings();

	float getCurrPlayerHealthPoints();
	float getCurrPlayerStamina();
	float getCurrPlayerMana();

	void createRenderWindow(VideoMode videoMode, string title, string windowStyle);
	void renderWindowClear();
	void renderWindowDisplay();
	void closeRenderWindow();
	void changeRenderWindowMode();
	void setGameWindowVisible(GameWindow* gameWindow);
	void setGameWindowInvisible(GameWindow* gameWindow);
	void createLevel(Level* level);
	void setPlayer(string charName, float posX, float posY);
	void playerMoveLeft();
	void playerMoveRight();
	void playerMoveUp();
	void playerMoveDown();
	void draw(float elapsedTime);
	void draw(Text text);
	void draw(Sprite sprite);
	void draw(Animation* animation, float elapsedTime);
	void draw(GameWindow* gameWindow);
	void draw(Button* button);
	void setView(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	void load();
	void loadNewGame();
	void setNewGame(bool flag);

	bool renderWindowIsOpen();
	bool renderWindowPollEvent();
	bool isRenderWindowFullscreen();
	bool mouseContains(int rectLeft, int rectTop, int rectWidth, int rectHeight);
	bool mouseContains(FloatRect rect);
	bool mouseContains(Sprite sprite);
	bool isNewPlayerLevel();
	bool isEndOfLevel();
	bool isNewGame();

	int input();
	int getMaxPlayerHealthPoints();
	int getMaxPlayerMana();
	int getMaxPlayerStamina();
	int getCurrPlayerShellAmount();
	int getCurrPlayerPosX();
	int getCurrPlayerPosY();
	int getDDTimer();
	int getPlayerLevel();
	int getPlayerLevelPoints();
	int getCurrLevelNumber();
	int getTreasurePoints();
	int getPlayerExp();
	int getCurrPlayerShellName();
	int update(float elapsedTime);

	string getClickedButtonId(GameWindow* gameWindow);

	Vector2i getResolution();
	Vector2i getViewSize();

	Event* getEvent();

	Player* getPlayer();

	struct resolutions getResolutions();

	struct perksInfo getPlayerPerksInfo();
};