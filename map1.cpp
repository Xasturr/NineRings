#include "map1.h"

Map1::Map1()
{
	//.loadFromFile("./textures/tiles/map1.png");
	CreateTextureAndBitmask(texture_, "./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");

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

void Map1::buildMap(RenderWindow* window)
{
	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (tileMapElse[i][j] == ' ')
			{
			}
			else
			{
				//sprite_.setPosition(j * 32, i * 32);
				//window->draw(sprite_);

				//if (tileMapElse[i][j] == '1') sprite_.setTextureRect(IntRect(32, 0, 32, 32));
				//else if (tileMapElse[i][j] == '2') sprite_.setTextureRect(IntRect(32 * 2, 0, 32, 32));
				//else if (tileMapElse[i][j] == '3') sprite_.setTextureRect(IntRect(32 * 3, 0, 32, 32));
				//else if (tileMapElse[i][j] == '4') sprite_.setTextureRect(IntRect(32 * 4, 0, 32, 32));
				//else if (tileMapElse[i][j] == '0') sprite_.setTextureRect(IntRect(0, 0, 32, 32));

				if (tileMapElse[i][j] == '1') sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '2')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '3')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '4')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '0')  sprite_.setTexture(texture_);

				sprite_.setPosition(j * 64, i * 64);
				window->draw(sprite_);
			}
		}
	}
}

void Map1::buildMap(RenderWindow* window, Vector2f playerPos, int viewSizeX, int viewSizeY)
{
	int iMin = 0, jMin = 0, iMax = 0, jMax = 0;
	if (playerPos.x / 64 - viewSizeX / 128 - 1 < 0)
	{
		iMin = 0;
	}
	else
	{
		iMin = playerPos.x / 64 - viewSizeX / 128 - 1;
	}

	if (playerPos.x / 64 + viewSizeX / 128 + 1 >= WIDTH_MAP)
	{
		iMax = WIDTH_MAP;
	}
	else
	{
		iMax = playerPos.x / 64 + viewSizeX / 128 + 1;
	}

	if (playerPos.y / 64 - viewSizeY / 128 - 1 < 0)
	{
		jMin = 0;
	}
	else
	{
		jMin = playerPos.y / 64 - viewSizeY / 128 - 1;
	}

	if (playerPos.y / 64 + viewSizeY / 128 + 1 >= HEIGHT_MAP)
	{
		jMax = HEIGHT_MAP;
	}
	else
	{
		jMax = playerPos.y / 64 + viewSizeY / 128 + 1;
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
									  
				sprite_.setPosition(j * 64, i * 64);
				window->draw(sprite_);
			}
		}
	}
}