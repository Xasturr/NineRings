#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"

using namespace std;
using namespace sf;

class Level
{
	//Map* map_;
public:
	virtual const size_t getHeightMap() = 0;
	virtual const size_t getWidthMap() = 0;
	virtual const size_t getTileWidth() = 0;
	virtual const size_t getTileHeight() = 0;

	virtual string* getTileMapElse() = 0;

	virtual bool getValue(int i, int j, char c, string tileMap[]) = 0;

	virtual Texture getTexture() = 0;

	virtual Sprite getSprite(int i, int j, string tileMap) = 0;

	virtual size_t getTextureSizeX() = 0;
	virtual size_t getTextureSizeY() = 0;

	virtual void buildMap(RenderWindow* window) = 0;
	virtual void buildMap(RenderWindow* window, Vector2f playerPos, int viewSizeX, int viewSizeY) = 0;
};