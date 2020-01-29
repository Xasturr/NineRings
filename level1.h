#pragma once

#include "level.h"
#include "map1.h"

class Level1 : public Level
{
	Map* map;
public:
	Level1();
	~Level1();

	const size_t getHeightMap();
	const size_t getWidthMap();
	const size_t getTileWidth();
	const size_t getTileHeight();
	//const size_t getMap();
	bool getValue(int i, int j, char c, string tileMap[]);
	Texture getTexture();
	size_t getTextureSizeX();
	size_t getTextureSizeY();
	void buildMap(RenderWindow* window);
};