#pragma once

#include "level.h"
#include "map1.h"
#include "enemy.h"

class Level1 : public Level
{
	Map* map_;
	vector<Enemy*> enemies_;

public:
	Level1();
	~Level1();

	const size_t getHeightMap();
	const size_t getWidthMap();
	const size_t getTileWidth();
	const size_t getTileHeight();

	string* getTileMapElse();

	bool getValue(int i, int j, char c, string tileMap[]);
	bool getCollision(int i, int j, char c);

	Texture getTexture();

	Sprite getSprite(int i, int j, string tileMap);

	size_t getTextureSizeX();
	size_t getTextureSizeY();

	void buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize);
	void updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime);

	Map* getMap();

	//vector<Enemy*> getEnemies();
};