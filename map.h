#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>

#include "treasureFactory.h"
#include "treasure.h"
//#include "player.h"

using namespace std;
using namespace sf;

class Map
{
public:
	virtual const size_t getHeightMap() = 0;
	virtual const size_t getWidthMap() = 0;
	virtual const size_t getTileWidth() = 0;
	virtual const size_t getTileHeight() = 0;

	virtual string* getTileMapElse() = 0;
	virtual string* getTileMapTreasure() = 0;

	virtual bool getValue(int i, int j, char c, string tileMap[]) = 0;
	virtual bool getCollision(int i, int j, char c) = 0;

	virtual Texture getTexture() = 0;

	virtual Sprite getSprite(int i, int j, string tileMap) = 0;

	virtual size_t getTextureSizeX() = 0;
	virtual size_t getTextureSizeY() = 0;

	virtual void buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, float elapsedTime) = 0;
	//virtual void playerInteractionWithMap(Vector2f oldPlayerPosition, Player* player, float elapsedTime) = 0;
};