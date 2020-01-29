#include "level1.h"

Level1::Level1()
{
	map = new Map1();
}

Level1::~Level1() {}

const size_t Level1::getHeightMap()
{
	return map->getHeightMap();
}

const size_t Level1::getWidthMap()
{
	return map->getWidthMap();
}

const size_t Level1::getTileWidth()
{
	return map->getTileWidth();
}

const size_t Level1::getTileHeight()
{
	return map->getTileHeight();
}

//const size_t Level1::getMap()
//{
//	
//}

bool Level1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
		return true;

	return false;
}

Texture Level1::getTexture()
{
	return map->getTexture();
}

size_t Level1::getTextureSizeX()
{
	return map->getTextureSizeX();
}

size_t Level1::getTextureSizeY()
{
	return map->getTextureSizeY();
}

void Level1::buildMap(RenderWindow* window)
{
	map->buildMap(window);
}