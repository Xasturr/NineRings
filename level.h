#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"
//#include "player.h"
#include "physxImplEnWalk.h"
#include "physxImplEnFly.h"

using namespace std;
using namespace sf;

class Level
{
public:
	virtual ~Level() {}

	virtual const size_t getHeightMap() = 0;
	virtual const size_t getWidthMap() = 0;
	virtual const size_t getTileWidth() = 0;
	virtual const size_t getTileHeight() = 0;

	virtual string* getTileMapElse() = 0;
	virtual string* getTileMapTreasure() = 0;

	virtual bool getValue(int i, int j, char c, string tileMap[]) = 0;
	virtual bool getCollision(int i, int j, char c) = 0;
	virtual bool getInSaveZone() = 0;

	virtual Texture getTexture() = 0;

	virtual Sprite getSprite(int i, int j, string tileMap) = 0;

	virtual size_t getTextureSizeX() = 0;
	virtual size_t getTextureSizeY() = 0;

	virtual void buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime) = 0;
	virtual void updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime) = 0;
	virtual void setTreasurePoints(int treasurePoints) = 0;

	virtual Map* getMap() = 0;

	virtual int getLevelNumber() = 0;
	virtual int getCatchedCoins() = 0;
	virtual int getTreasurePoints() = 0;

	virtual Vector2i getSavedPosition() = 0;
};