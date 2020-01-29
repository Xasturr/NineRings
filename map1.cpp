#include "map1.h"

Map1::Map1()
{
	texture_.loadFromFile("./textures/tiles/map1.png");
	sprite_.setTexture(texture_);
}

Map1::~Map1() {}

const size_t Map1::getHeightMap()
{
	return HEIGHT_MAP;
}

const size_t Map1::getWidthMap()
{
	return WIDTH_MAP;
}

const size_t Map1::getTileWidth()
{
	return TILE_WIDTH;
}

const size_t Map1::getTileHeight()
{
	return TILE_HEIGHT;
}

//const size_t Map1::getMap()
//{
//
//}

bool Map1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
		return true;

	return false;
}

Texture Map1::getTexture()
{
	return texture_;
}

size_t Map1::getTextureSizeX()
{
	return texture_.getSize().x;
}

size_t Map1::getTextureSizeY()
{
	return texture_.getSize().y;
}

void Map1::buildMap(RenderWindow* window)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (tileMap[i][j] == ' ') sprite_.setTextureRect(IntRect(32 * 5, 0, 32, 32));

			sprite_.setPosition(j * 32, i * 32);
			window->draw(sprite_);

			if (tileMapElse[i][j] == '1') sprite_.setTextureRect(IntRect(32, 0, 32, 32));
			if (tileMapElse[i][j] == '2') sprite_.setTextureRect(IntRect(32 * 2, 0, 32, 32));
			if (tileMapElse[i][j] == '3') sprite_.setTextureRect(IntRect(32 * 3, 0, 32, 32));
			if (tileMapElse[i][j] == '4') sprite_.setTextureRect(IntRect(32 * 4, 0, 32, 32));
			if (tileMapElse[i][j] == '0') sprite_.setTextureRect(IntRect(0, 0, 32, 32));

			sprite_.setPosition(j * 32, i * 32);
			window->draw(sprite_);
		}
	}
}