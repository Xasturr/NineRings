#pragma once

#include "level.h"
#include "map1.h"
#include "enemy.h"

class Level2 : public Level
{
	Map* map_;
	vector<Enemy*> enemies_;

public:
	Level2();
	~Level2();

	const size_t getHeightMap();
	const size_t getWidthMap();
	const size_t getTileWidth();
	const size_t getTileHeight();

	string* getTileMapElse();
	string* getTileMapTreasure();

	bool getValue(int i, int j, char c, string tileMap[]);
	bool getCollision(int i, int j, char c);
	bool getInSaveZone();

	Texture getTexture();

	Sprite getSprite(int i, int j, string tileMap);

	size_t getTextureSizeX();
	size_t getTextureSizeY();

	void buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime);
	void updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);
	void setTreasurePoints(int treasurePoints);

	Map* getMap();

	int getLevelNumber();
	int getCatchedCoins();
	int getTreasurePoints();

	Vector2i getSavedPosition();
};