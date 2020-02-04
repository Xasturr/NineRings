#include "map1.h"

Map1::Map1()
{
	texture_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");
	//CreateTextureAndBitmask(texture_, "./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");

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

string* Map1::getTileMapElse()
{
	return tileMapElse;
}

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

Sprite Map1::getSprite(int i, int j, string tileMap)
{
	Sprite sprite;
	//Texture texture;
	//CreateTextureAndBitmask(texture, "./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile4.png");
	//sprite.setTexture(texture);
	//sprite.setPosition(300, 128);

	if (tileMap == "tileMapElse")
	{
		if (tileMapElse[i][j] == '1')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '2')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '3')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '4')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '0')	sprite.setTexture(texture_);

		//cout << "Here" << endl;
		sprite.setPosition(j * 64, i * 64);
		//sprite.setOrigin(64, 64);
	}

	return sprite;
}

size_t Map1::getTextureSizeX()
{
	return texture_.getSize().x;
}

size_t Map1::getTextureSizeY()
{
	return texture_.getSize().y;
}

void Map1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize)
{
	int iMin = 0, jMin = 0, iMax = 0, jMax = 0;
	if (playerPos.x / TILE_WIDTH - viewSize.x / TILE_WIDTH / 2 - 1 < 0)
	{
		iMin = 0;
	}
	else
	{
		iMin = playerPos.x / TILE_WIDTH - viewSize.x / TILE_WIDTH / 2 - 1;
	}

	if (playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 1 >= WIDTH_MAP)
	{
		iMax = WIDTH_MAP;
	}
	else
	{
		iMax = playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 1;
	}

	if (playerPos.y / TILE_HEIGHT - viewSize.y / TILE_HEIGHT / 2 - 1 < 0)
	{
		jMin = 0;
	}
	else
	{
		jMin = playerPos.y / TILE_HEIGHT - viewSize.y / TILE_HEIGHT / 2 - 1;
	}

	if (playerPos.y / TILE_HEIGHT + viewSize.y / TILE_HEIGHT / 2 + 1 >= HEIGHT_MAP)
	{
		jMax = HEIGHT_MAP;
	}
	else
	{
		jMax = playerPos.y / TILE_HEIGHT + viewSize.y / TILE_HEIGHT / 2 + 1;
	}

	for (int i = jMin; i < jMax; i++)
	{
		for (int j = iMin; j < iMax; j++)
		{
			if (tileMapElse[i][j] == ' ')
			{
			}
			else
			{
				if (tileMapElse[i][j] == '1') sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '2')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '3')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '4')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '0')  sprite_.setTexture(texture_);
									  
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH);
				window->draw(sprite_);
			}
		}
	}
}