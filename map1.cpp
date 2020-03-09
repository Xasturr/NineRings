#include "map1.h"

Map1::Map1()
{
	texture_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");
	textureStatue_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Details/marker_statue1.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(32, 0); // 32 == half of texture width

	treasureFactory_ = new TreasureFactory();

	catchedCoins = 0;
	savedPosition_.x = 0;
	savedPosition_.y = 0;
	treasurePoints_ = 0;

	inSaveZone_ = false;
}

Map1::~Map1()
{
	cout << "In Map1 destructor" << endl;

	delete treasureFactory_;

	if (treasure_)
	{
	//	delete treasure_;
	}
}

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

string* Map1::getTileMapTreasure()
{
	return tileMapTreasure;
}

string* Map1::getTileMapDecoration()
{
	return tileMapDecoration;
}

bool Map1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
	{
		return true;
	}

	return false;
}

bool Map1::getCollision(int i, int j, char c)
{
	if (tileMapElse[i][j] == c)
	{
		return true;
	}

	return false;
}

bool Map1::getInSaveZone()
{
	return inSaveZone_;
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

void Map1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime)
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

	if (playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 2 >= WIDTH_MAP)
	{
		iMax = WIDTH_MAP;
	}
	else
	{
		iMax = playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 2;
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

			if (tileMapTreasure[i][j] == 'x')
			{
				treasureFactory_->setTreasureName("Coin");
				treasure_ = treasureFactory_->getTreasure(Vector2f(j, i), TILE_WIDTH, TILE_HEIGHT);
				treasure_->setCurrFrame(elapsedTime);
				treasure_->spriteUpdate();

				//cout << "j: " << j << endl;
				//cout << (playerPos.x - 20) / TILE_WIDTH << endl;
				//cout << (playerPos.x + 20) / TILE_WIDTH << endl << endl;

				if ((playerPos.x + playerWidth) / TILE_WIDTH > j && (playerPos.x - playerWidth) / TILE_WIDTH < j
					&& int(playerPos.y) / TILE_HEIGHT >= i && int(playerPos.y - playerHeight / 2) / TILE_HEIGHT <= i)
				{
					tileMapTreasure[i][j] = ' ';
					catchedCoins += 1;
					treasurePoints_ += treasure_->getTreasurePoints();
				}
				else
					window->draw(treasure_->getSprite());
			}
			if (tileMapDecoration[i][j] == 's' || tileMapDecoration[i][j] == 'c')
			{
				sprite_.setTexture(textureStatue_);
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH + 3);
				window->draw(sprite_);
				inSaveZone_ = false;

				if (tileMapDecoration[i][j] == 's')
				{
					if (int(playerPos.x - 200) / TILE_WIDTH <= j && int(playerPos.x + 200) / TILE_WIDTH >= j
						&& int(playerPos.y - 300) / TILE_HEIGHT <= i && int(playerPos.x) / TILE_HEIGHT >= i)
					{
						savedPosition_.x = j;
						savedPosition_.y = i;
						tileMapDecoration[i][j] = 'c';
						inSaveZone_ = true;
					}
				}
			}
		}
	}
}

void Map1::setTreasurePoints(int treasurePoints)
{
	treasurePoints_ = treasurePoints;
}

int Map1::getCatchedCoins()
{
	return catchedCoins;
}

int Map1::getTreasurePoints()
{
	return treasurePoints_;
}

Vector2i Map1::getSavedPosition()
{
	return savedPosition_;
}