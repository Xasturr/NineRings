#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Map
{
public:
	virtual const size_t getHeightMap() = 0;
	virtual const size_t getWidthMap() = 0;
	virtual const size_t getTileWidth() = 0;
	virtual const size_t getTileHeight() = 0;
	//virtual const size_t getMap() = 0;
	virtual bool getValue(int i, int j, char c, string tileMap[]) = 0;
	virtual Texture getTexture() = 0;
	virtual size_t getTextureSizeX() = 0;
	virtual size_t getTextureSizeY() = 0;
	virtual void buildMap(RenderWindow* window) = 0;
};